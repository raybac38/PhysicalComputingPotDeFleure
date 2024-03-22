light_level = 0;


const socket = io();
function Charger_menu_pots() {
    window.location.href = "pots.html";
}

function Charger_menu_principale() {
    window.location.href = "menu.html";
}

function load() {
    ///Fonction s'occupant du chargement
    //document.getElementById("thermometre_ascii_art")

}


function show_light_level_ui(level)
{
    link_code = "/ascii_art/";
    switch (level) {
        case 0:
            link_code += "luny";
            break;
        case 1:
            link_code += "cloudy";
            break;
        case 2:
            link_code += "cloudy&sunny";
            break;        
        case 3:
            link_code += "sunny";
            break;    
        default:
            link_code += "error";
            break;
    }
    link_code += ".txt";

    fetch(link_code)
    .then((res) => res.text())
    .then((text) => {
        document.getElementById("brightness").innerText = text;
    })
    .catch((e) => console.error(e));
}

///////////////////
/// EVENT FROM SERVER


socket.on('light_level', (data) =>
{
    console.log("Reciving light level data : " + data);

    if(data != light_level)
    {
        light_level = data;
        show_light_level_ui(data);
        console.log("mise a jours de L UI");
    }
});