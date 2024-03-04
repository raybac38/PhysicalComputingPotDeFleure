const express = require('express');
const path = require('path');
const socketIO = require('socket.io');
const http = require('http');

const app = express();
const server = http.createServer(app);
const io = socketIo(server);

const serialPort = require('serialport');
const readline = require('@serialport/parser-readline');

const port = new SerialPort('/dev/ttyACM0', {
    baudRate: 9600 
  });

const parser = port.pipe(new Readline({ delimiter: '\r\n' }));

// Définir le répertoire contenant les fichiers statiques (publics)
app.use(express.static(path.join(__dirname, 'public')));

// Route pour la page d'accueil
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'index.html'));
});

io.on('connection', (socket) => {
    console.log('client connected');

    socket.on('disconnect', () =>{
        console.log('client disconnect');
    })

    //socket.on('event name', (data) => {}); Permet de recevoire un message
    //io.emit('event name', data) //envoie un message 

})

// Démarrer le serveur sur un port spécifique
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
    console.log(`Serveur démarré sur le port ${PORT}`);
});

