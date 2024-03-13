function Charger_menu_pots() {
    window.location.href = "pots.html";
}

function Charger_menu_principale() {
    window.location.href = "menu.html";
}

function load()
{
    ///Fonction s'occupant du chargement
    //document.getElementById("thermometre_ascii_art")

    fetch("/ascii_art/thermometre.txt")
    .then((res) => res.text())
    .then((text) => {
        document.getElementById("thermometre").innerText = text;
    })
    .catch((e) => console.error(e));

    fetch("/ascii_art/sunny.txt")
    .then((res) => res.text())
    .then((text) => {
        document.getElementById("brightness").innerText = text;
    })
    .catch((e) => console.error(e));

}

class Data
{
    constructor(){}
    temperature = 0;
    luminosity = 0;
    air_humidity = 0;
    floor_humidity = 0;
}



