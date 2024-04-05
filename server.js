const express = require('express');
const path = require('path');
const http = require('http');
const SocketIO = require('socket.io');

const app = express();
const server = http.createServer(app);
const io = SocketIO(server);

// Répertoire des fichiers statiques
app.use(express.static(path.join(__dirname, 'public')));

// Route pour la page d'accueil
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'menu.html'));
});

io.on('connection', (socket) => {
    console.log('Client connecté');


    send_light_level(stored_light_level);
    send_temperature(stored_temperature);
    send_air_humidity(stored_air_humidity);
    send_dirt_humidity(stored_dirt_humidity);
    send_is_motor_on_off(stored_is_motor_on_off);
    send_is_motor_auto(stored_is_motor_auto);
    send_is_arrosage(stored_is_arrosage);
    send_is_active_mode(stored_is_active_mode);
    send_is_lcd_on(stored_is_lcd_on);


    ///Envoyer l'état du port Serial

    socket.emit('is_arduino_connected', arduino_connected);

    socket.on('cmd_arduino', (message) =>
    {
        send_cmd_arduino(message);
    });


    socket.on('disconnect', () => {
        console.log('Client déconnecté');
    });
});

// Démarrer le serveur sur un port spécifique
const PORT = process.env.PORT || 3000;
server.listen(PORT, () => {
    console.log(`Serveur démarré sur le port ${PORT}`);

});


/////////

//Constante 

var stored_light_level = 3;
var stored_temperature = 100;
var stored_air_humidity = 100;
var stored_dirt_humidity = 100;
var stored_is_active_mode = true;
var stored_is_motor_auto = true;
var stored_is_arrosage = false;
var stored_is_motor_on_off = true;
var stored_is_lcd_on = true;


///////////

//Socket IO 


function send_light_level(data) {
    stored_light_level = data;
    io.emit('light_level', data);
    console.log("nouveau niveau de lumiere envoyer");
}
function send_temperature(data) {
    stored_temperature = data;
    io.emit('temperature', data);
    console.log("changement de temperature envoyer");
}
function send_air_humidity(data) {
    stored_air_humidity = data;
    io.emit('air_humidity', data);
    console.log("changement d'humiditer de l'air");
}
function send_dirt_humidity(data) {
    stored_dirt_humidity = data;
    io.emit('dirt_humidity', data);
    console.log("changement d'humiditer de la terre");
}

function send_is_motor_on_off(data) {
    stored_is_motor_on_off = data;
    io.emit('motor_on_off', data);
    console.log("changement d'etat du moteur");
}

function send_is_motor_auto(data) {
    stored_is_motor_auto = data;
    io.emit('motor_auto', data);
    console.log("changement d'etat du moteur");
}

function send_is_arrosage(data) {
    stored_is_arrosage = data;
    io.emit('arrosage', data);
    console.log("changement de l'arrosage");
}

function send_is_active_mode(data) {
    stored_is_active_mode = data;
    io.emit('is_active_mode', data);
    console.log("changement d'etat de l'arduino");
}

function send_is_lcd_on(data) {
    stored_is_lcd_on = data;
    io.emit('is_lcd_on', data);
    console.log("changement de l'état de l'écran");
}



function send_cmd_arduino(cmd)
{
    port.write(cmd + "\n");
    console.log("message envoyer : "+cmd);
}



///////////////
const { SerialPort } = require('serialport');


const port = new SerialPort(
    {
        path: '/dev/ttyACM0',
        baudRate: 19200,
        dataBits: 8,
        parity: 'none',
        stopBits: 1,
        flowControl: false
    });

buffer = '';

var arduino_connected = false;

port.on('error', (err) => {
    console.error('Error opening serial port:', err.message);
    console.log('Waiting for Arduino to connect...');
    arduino_connected = false;
});

port.on('open', () => {
    console.log('Serial Port Open');
    arduino_connected = true;
});

port.on('close', () => {
    console.log('Arduino disconnected');
    arduino_connected = false;
});


let receivedString = '';
port.on('data', (data) => {
    const receivedData = data.toString('utf-8');

    for (let i = 0; i < receivedData.length; i++) {
        const char = receivedData.charAt(i);

        if (char === '\n') {
            console.log('Message reçu:', receivedString);
            decypher_arduino(receivedString);
            receivedString = ''; // Réinitialiser la chaîne pour la prochaine lecture
        } else {
            receivedString += char; // Ajouter le caractère à la chaîne en cours de construction
        }
    }
});




////////////////////:

//Fonction

function decypher_arduino(cmd) {
    cmd_parts = cmd.split(':');
    if (cmd_parts.length != 2) return;


    switch (cmd_parts[0]) {
        case 'l':
            send_light_level(parseInt(cmd_parts[1]));
            break;
        case 't':
            send_temperature(parseFloat(cmd_parts[1]));
            break;
        case 'a_h':
            send_air_humidity(parseInt(cmd_parts[1]));
            break;
        case 't_h':
            send_dirt_humidity(parseFloat(cmd_parts[1]) * 100);
            break;
        case 'm_of':
            send_is_motor_on_off(parseInt(cmd_parts[1]));
            break;
        case 'm_a':
            send_is_motor_auto(parseInt(cmd_parts[1]));
            break;
        case 'arr':
            send_is_arrosage(parseInt(cmd_parts[1]));
            break;
        case 'a_m':
            send_is_active_mode(parseInt(cmd_parts[1]));
            break;
        case 's_o':
            send_is_lcd_on(parseInt(cmd_parts[1]));
            break;
        default:
            console.log("Pas de commande reconnu\n");
            break;
    }
}


