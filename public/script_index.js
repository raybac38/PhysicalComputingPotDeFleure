function Charger_menu_pots() {
    window.location.href = "Menu_Pots.html";
}

function Charger_menu_principale() {
    window.location.href = "index.html";
}

function load()
{
    ///Fonction s'occupant du chargement
    //document.getElementById("thermometre_ascii_art")

    fetch("/ascii_art/thermometre.txt")
    .then((res) => res.text())
    .then((text) => {
        document.getElementById("thermometre_ascii_art").innerText = text;
    })
    .catch((e) => console.error(e));


    
}


