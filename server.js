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

var stored_light_level = 0;
var stored_temperature = 0;
var stored_air_humidity = 0;
var stored_dirt_humidity = 0;

///////////

//Socket IO 


function send_light_level(data)
{
    stored_light_level = data;
    io.emit('light_level', data);
    console.log("nouveau niveau de lumiere envoyer");
}
function send_temperature(data)
{
    stored_temperature = data;
    io.emit('temperature', data);
    console.log("changement de temperature envoyer");
}
function send_air_humidity(data)
{
    stored_air_humidity = data;
    io.emit('air_humidity', data);
    console.log("changement d'humiditer de l'air");
}
function send_dirt_humidity(data)
{
    stored_dirt_humidity = data;
    io.emit('dirt_humidity', data);
    console.log("changement d'humiditer de la terre");
}






///////////////
const { SerialPort } = require('serialport');


const port = new SerialPort(
    {
        path: '/dev/ttyACM0',
        baudRate: 9600,
        dataBits: 8,
        parity: 'none',
        stopBits: 1,
        flowControl: false
    });

buffer = '';

port.on('open', () => {
    console.log('Serial Port Open');
});

port.on('data', (data) => {
    buffer += data.toString();
    if (buffer.includes('\n')) {
        console.log("Serial data recived : " + buffer);
        decypher_arduino(buffer);
        buffer = '';
    }
});




////////////////////:

//Fonction

function decypher_arduino(cmd)
{
    cmd_parts = cmd.split(':');
    if(cmd_parts.length != 2) return;


    switch (cmd_parts[0]) {
        case 'light level':
            send_light_level(parseInt(cmd_parts[1]));
            break;
        case 'temperature':
            send_temperature(parseFloat(cmd_parts[1]));
        case 'air humidity':

        default:
            break;
    }
}

