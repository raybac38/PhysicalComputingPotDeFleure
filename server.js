const express = require('express');
const path = require('path');
const http = require('http');
const SocketIO = require('socket.io');


const serialPort = require('serialport');
const readline = require('@serialport/parser-readline');

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

    socket.on('disconnect', () =>{
        console.log('Client déconnecté');
    });

    socket.on("hello", (arg, callback) => {
        console.log(arg); // "world"
        callback("got it");
      });
});

// Démarrer le serveur sur un port spécifique
const PORT = process.env.PORT || 3000;
server.listen(PORT, () => {
    console.log(`Serveur démarré sur le port ${PORT}`);
});
