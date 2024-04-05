/// PIN assignement

int PIN_TEMP = A0;
int PIN_LUM = A1;
int PIN_HUM_AIR = A2;
int PIN_HUM_TERRE = A3;

int MOTEUR = 13;

#define PIN_SCE 12
#define PIN_RESET 11
#define PIN_DC 10
#define PIN_SDIN 9
#define PIN_SCLK 8
#define LCD_COMMAND 0
#define LCD_DATA 1
// Setting the screen size (84x48 pixels)
#define LCD_X 84
#define LCD_Y 48

// Hexadecimal values for pixel assignment of characters and letters
static const byte ASCII[][5] = {
    {0x00, 0x00, 0x00, 0x00, 0x00}, // 20 ,
    {0x00, 0x00, 0x5f, 0x00, 0x00}, // 21 ! ,
    {0x00, 0x07, 0x00, 0x07, 0x00}, // 22 " ,
    {0x14, 0x7f, 0x14, 0x7f, 0x14}, // 23 # ,
    {0x24, 0x2a, 0x7f, 0x2a, 0x12}, // 24 $ ,
    {0x23, 0x13, 0x08, 0x64, 0x62}, // 25 % ,
    {0x36, 0x49, 0x55, 0x22, 0x50}, // 26 & ,
    {0x00, 0x05, 0x03, 0x00, 0x00}, // 27 ' ,
    {0x00, 0x1c, 0x22, 0x41, 0x00}, // 28 ( ,
    {0x00, 0x41, 0x22, 0x1c, 0x00}, // 29 ) ,
    {0x14, 0x08, 0x3e, 0x08, 0x14}, // 2a * ,
    {0x08, 0x08, 0x3e, 0x08, 0x08}, // 2b + ,
    {0x00, 0x50, 0x30, 0x00, 0x00}, // 2c , ,
    {0x08, 0x08, 0x08, 0x08, 0x08}, // 2d - ,
    {0x00, 0x60, 0x60, 0x00, 0x00}, // 2e . ,
    {0x20, 0x10, 0x08, 0x04, 0x02}, // 2f / ,
    {0x3e, 0x51, 0x49, 0x45, 0x3e}, // 30 0 ,
    {0x00, 0x42, 0x7f, 0x40, 0x00}, // 31 1 ,

    {0x42, 0x61, 0x51, 0x49, 0x46}, // 32 2 ,
    {0x21, 0x41, 0x45, 0x4b, 0x31}, // 33 3 ,
    {0x18, 0x14, 0x12, 0x7f, 0x10}, // 34 4 ,
    {0x27, 0x45, 0x45, 0x45, 0x39}, // 35 5 ,
    {0x3c, 0x4a, 0x49, 0x49, 0x30}, // 36 6 ,
    {0x01, 0x71, 0x09, 0x05, 0x03}, // 37 7 ,
    {0x36, 0x49, 0x49, 0x49, 0x36}, // 38 8 ,
    {0x06, 0x49, 0x49, 0x29, 0x1e}, // 39 9 ,
    {0x00, 0x36, 0x36, 0x00, 0x00}, // 3a : ,
    {0x00, 0x56, 0x36, 0x00, 0x00}, // 3b ; ,
    {0x08, 0x14, 0x22, 0x41, 0x00}, // 3c < ,
    {0x14, 0x14, 0x14, 0x14, 0x14}, // 3d = ,
    {0x00, 0x41, 0x22, 0x14, 0x08}, // 3e > ,
    {0x02, 0x01, 0x51, 0x09, 0x06}, // 3f ? ,
    {0x32, 0x49, 0x79, 0x41, 0x3e}, // 40 @ ,
    {0x7e, 0x11, 0x11, 0x11, 0x7e}, // 41 A ,
    {0x7f, 0x49, 0x49, 0x49, 0x36}, // 42 B ,
    {0x3e, 0x41, 0x41, 0x41, 0x22}, // 43 C ,
    {0x7f, 0x41, 0x41, 0x22, 0x1c}, // 44 D ,
    {0x7f, 0x49, 0x49, 0x49, 0x41}, // 45 E ,
    {0x7f, 0x09, 0x09, 0x09, 0x01}, // 46 F ,
    {0x3e, 0x41, 0x49, 0x49, 0x7a}, // 47 G ,
    {0x7f, 0x08, 0x08, 0x08, 0x7f}, // 48 H ,
    {0x00, 0x41, 0x7f, 0x41, 0x00}, // 49 I ,
    {0x20, 0x40, 0x41, 0x3f, 0x01}, // 4a J ,
    {0x7f, 0x08, 0x14, 0x22, 0x41}, // 4b K ,
    {0x7f, 0x40, 0x40, 0x40, 0x40}, // 4c L ,
    {0x7f, 0x02, 0x0c, 0x02, 0x7f}, // 4d M ,
    {0x7f, 0x04, 0x08, 0x10, 0x7f}, // 4e N ,
    {0x3e, 0x41, 0x41, 0x41, 0x3e}, // 4f O ,
    {0x7f, 0x09, 0x09, 0x09, 0x06}, // 50 P ,
    {0x3e, 0x41, 0x51, 0x21, 0x5e}, // 51 Q ,
    {0x7f, 0x09, 0x19, 0x29, 0x46}, // 52 R ,
    {0x46, 0x49, 0x49, 0x49, 0x31}, // 53 S ,
    {0x01, 0x01, 0x7f, 0x01, 0x01}, // 54 T ,
    {0x3f, 0x40, 0x40, 0x40, 0x3f}, // 55 U ,
    {0x1f, 0x20, 0x40, 0x20, 0x1f}, // 56 V ,

    {0x3f, 0x40, 0x38, 0x40, 0x3f}, // 57 W ,
    {0x63, 0x14, 0x08, 0x14, 0x63}, // 58 X ,
    {0x07, 0x08, 0x70, 0x08, 0x07}, // 59 Y ,
    {0x61, 0x51, 0x49, 0x45, 0x43}, // 5a Z ,
    {0x00, 0x7f, 0x41, 0x41, 0x00}, // 5b [ ,
    {0x02, 0x04, 0x08, 0x10, 0x20}, // 5c BACKSLASH ,
    {0x00, 0x41, 0x41, 0x7f, 0x00}, // 5d ] ,
    {0x04, 0x02, 0x01, 0x02, 0x04}, // 5e ^ ,
    {0x40, 0x40, 0x40, 0x40, 0x40}, // 5f _ ,
    {0x00, 0x01, 0x02, 0x04, 0x00}, // 60 ` ,
    {0x20, 0x54, 0x54, 0x54, 0x78}, // 61 a ,
    {0x7f, 0x48, 0x44, 0x44, 0x38}, // 62 b ,
    {0x38, 0x44, 0x44, 0x44, 0x20}, // 63 c ,
    {0x38, 0x44, 0x44, 0x48, 0x7f}, // 64 d ,
    {0x38, 0x54, 0x54, 0x54, 0x18}, // 65 e ,
    {0x08, 0x7e, 0x09, 0x01, 0x02}, // 66 f ,
    {0x0c, 0x52, 0x52, 0x52, 0x3e}, // 67 g ,
    {0x7f, 0x08, 0x04, 0x04, 0x78}, // 68 h ,
    {0x00, 0x44, 0x7d, 0x40, 0x00}, // 69 i ,
    {0x20, 0x40, 0x44, 0x3d, 0x00}, // 6a j ,
    {0x7f, 0x10, 0x28, 0x44, 0x00}, // 6b k ,
    {0x00, 0x41, 0x7f, 0x40, 0x00}, // 6c l ,
    {0x7c, 0x04, 0x18, 0x04, 0x78}, // 6d m ,
    {0x7c, 0x08, 0x04, 0x04, 0x78}, // 6e n ,
    {0x38, 0x44, 0x44, 0x44, 0x38}, // 6f o ,
    {0x7c, 0x14, 0x14, 0x14, 0x08}, // 70 p ,
    {0x08, 0x14, 0x14, 0x18, 0x7c}, // 71 q ,
    {0x7c, 0x08, 0x04, 0x04, 0x08}, // 72 r ,
    {0x48, 0x54, 0x54, 0x54, 0x20}, // 73 s ,
    {0x04, 0x3f, 0x44, 0x40, 0x20}, // 74 t ,
    {0x3c, 0x40, 0x40, 0x20, 0x7c}, // 75 u ,
    {0x1c, 0x20, 0x40, 0x20, 0x1c}, // 76 v ,
    {0x3c, 0x40, 0x30, 0x40, 0x3c}, // 77 w ,
    {0x44, 0x28, 0x10, 0x28, 0x44}, // 78 x ,
    {0x0c, 0x50, 0x50, 0x50, 0x3c}, // 79 y ,
    {0x44, 0x64, 0x54, 0x4c, 0x44}, // 7a z ,
    {0x00, 0x08, 0x36, 0x41, 0x00}, // 7b { ,
    {0x00, 0x00, 0x7f, 0x00, 0x00}, // 7c | ,
    {0x00, 0x41, 0x36, 0x08, 0x00}, // 7d } ,
    {0x10, 0x08, 0x08, 0x10, 0x08}, // 7e ~ ,
    {0x78, 0x46, 0x41, 0x46, 0x78}, // 7f DEL
};
// put your setup code here, to run once:
/// Demarage de l'ARDUINO : POWER UP

void setup()
{

    /// Lancement des protocoles de communication externe
    LCDInit();
    Serial.begin(19200);

    /// Initialisation des entrée analogue
    pinMode(PIN_TEMP, INPUT);
    pinMode(PIN_LUM, INPUT);
    pinMode(PIN_HUM_AIR, INPUT);
    pinMode(PIN_HUM_TERRE, INPUT);
}
/// Variable de donnée

float temperature = 0;
byte luminosity = 0;
int air_humidity = 0;
float terre_humidity = 0;


bool is_motor_on = false;
bool is_motor_auto = true;

bool is_active_mode = true;

bool is_lcd_on = true;

bool is_arrosage = false;

const long int active_timer = 1000;
const long int auto_timer = 300000; // 5 minute

long int starting_timer = 0;
String word_key = "";
char inputChar;
void loop()
{
    while (Serial.available() > 0)
    {
        inputChar = Serial.read();
        if (inputChar != '\n')
        {
            word_key += inputChar;
            
        }
        else
        {
            Execute_commande(word_key);
            word_key = "";
        }
    }

  long int delta = abs(millis()- starting_timer);

    if((delta > active_timer && (is_active_mode || is_arrosage)) || delta > auto_timer)
    {
      /// WAKE UP, TIME TO SHINE !
      routine();
      starting_timer = millis();

    }

}


void routine()
{
  /// Y'a du boulot sur la planche
  MesurerTemperature();
  Mesurer_lumiere();
  Mesurer_air_humidity();
  Mesurer_terre_humidity();

  Routine_serial();

  Routine_ecran();

  Routine_arrosage();
}

/// Execution d'une commande

/*
 * Commande reconnaissable par la arduino
 *
 * help
 *
 * screen on
 * screen off
 *
 * moteur on
 * moteur off
 * moteur auto
 *
 * mode actif
 * mode auto
 *
 */

void Execute_commande(String cmd)
{
    if (cmd.equals("help"))
    {
        Serial.println(F("Commandes disponibles :"));
        Serial.println(F("Pour le contrôle de l'écran : "));
        Serial.println(F("$screen on : Allumer l'écran"));
        Serial.println(F("$screen off : Éteindre l'écran"));
        Serial.println(F("Pour le contrôle du moteur : "));
        Serial.println(F("$moteur on : Activer le moteur"));
        Serial.println(F("$moteur off : Désactiver le moteur"));
        Serial.println(F("$moteur auto : Mode automatique du moteur"));
        Serial.println(F("Pour le changement de mode de l'arduino : "));
        Serial.println(F("$mode actif : Mode actif"));
        Serial.println(F("$mode auto : Mode automatique"));
    }
    else if (cmd.equals("screen on"))
    {
        Serial.println("L'écran est allumé.");
        is_lcd_on = true;
        Routine_ecran();
        
        
    }
    else if (cmd.equals("screen off"))
    {
        Serial.println("L'écran est éteint.");
        is_lcd_on = false;
        Routine_ecran();
        
    }
    else if (cmd.equals("moteur on"))
    {
        Serial.println("Le moteur est activé.");
        is_motor_on = true;
        is_motor_auto = false;
        Activation_moteur(true);
        
    }
    else if (cmd.equals("moteur off"))
    {
        Serial.println("Le moteur est désactivé.");
        is_motor_on = false;
        is_motor_auto = false;
        Activation_moteur(false);
    }
    else if (cmd.equals("moteur auto"))
    {
        Serial.println("Le moteur est en mode automatique.");
        is_motor_auto = true;
        
    }
    else if (cmd.equals("mode actif"))
    {
        Serial.println("L'Arduino est en mode actif.");
        is_active_mode = true;
    }
    else if (cmd.equals("mode auto"))
    {
        Serial.println("L'Arduino est en mode automatique.");
        is_active_mode = false;
    }
    else
    {
        Serial.println("Commande non reconnue.");
    }
}

/// Liste des procédure appelable

const float trigger_humidity_level_on = 0.50;
const float trigger_humidity_level_off = 0.60;


void Routine_arrosage()
{
  if(!is_motor_auto) return;

  if(terre_humidity < trigger_humidity_level_on)
  {
    is_arrosage = true;
    Activation_moteur(true);
    
  }
  else if(terre_humidity > trigger_humidity_level_off)
  {
    is_arrosage = false;
    Activation_moteur(false);
  }
}



void Routine_ecran()
{

  char charArray[13]; 
  LCDClear();

  if(!is_lcd_on) return;

  String text = "";
  positionXY(0, 0);
  
  text = "t= " + String(temperature, 2) + "C";

  text.toCharArray(charArray, text.length() + 1);
  
  LCDString(charArray);

  positionXY(0, 1);

  text = "l= " + String(luminosity + 1) + "/4";
  text.toCharArray(charArray, text.length() + 1);
  LCDString(charArray);
  positionXY(0, 2);

  text = "a_h= " + String(air_humidity) + "%";
  text.toCharArray(charArray, text.length() + 1);
  LCDString(charArray);
  positionXY(0, 3);
  
  text = "t_h= " + String((terre_humidity * 100),2) + "%";
  text.toCharArray(charArray, text.length() + 1);
  LCDString(charArray);
 
}

void Routine_serial()
{
  Serial.print("t:");
  Serial.println(temperature);
  Serial.print("l:");
  Serial.println(luminosity);
  Serial.print("a_h:");
  Serial.println(air_humidity);
  Serial.print("t_h:");
  Serial.println(terre_humidity);
  Serial.print("m_of:");
  Serial.println(is_motor_on);
  Serial.print("m_a:");
  Serial.println(is_motor_auto);
  Serial.print("arr:");
  Serial.println(is_arrosage);
  Serial.print("a_m:");
  Serial.println(is_active_mode);
  Serial.print("s_o:");
  Serial.println(is_lcd_on);
}

void Activation_moteur(int etat)
{
  if(etat != 1 && etat != 0) return;
  
  digitalWrite(MOTEUR, etat);
}



void MesurerTemperature()
{
  int val = analogRead(PIN_TEMP);
  temperature = (float)val / 10.0 - 9.0;  /// Convertion tension => temperature
}


void Mesurer_lumiere()
{
    int val = analogRead(PIN_LUM);
    double sqrt_val = sqrt(val);

    if (sqrt_val < 8)
    {
        luminosity = 0;
    }
    else if (sqrt_val < 16)
    {
        luminosity = 1;
    }
    else if (sqrt_val < 24)
    {
        luminosity = 2;
    }
    else
    {
        luminosity = 3;
    }
}

void Mesurer_air_humidity()
{

    int val = analogRead(PIN_HUM_AIR);

    air_humidity = Get_humidity(temperature, val);
}

void Mesurer_terre_humidity()
{
    const float resistance_sec = 6000.0;
    const float resistance_humide = 60000.0;
    const float resistance_pont_diviseur = 33000.0;

    int val = analogRead(PIN_HUM_TERRE);
    float tension = (float)val * 5.0 / 1023.0; /// convertion en tension de plage [0, 5] V

    float tension_sec = (5.0 * resistance_sec) / (resistance_sec + resistance_pont_diviseur);
    float tension_humide = (5.0 * resistance_humide) / (resistance_humide + resistance_pont_diviseur);

    if (tension < tension_sec)
    {
        terre_humidity = 0.0;
        return;
    }
    if (tension > tension_humide)
    {
        terre_humidity = 1.0;
        return;
    }

    terre_humidity = (tension - tension_sec) / (tension_humide - tension_sec);
}

int Get_humidity(float temp, int V)
{
    int RH = 0;
    if (temp < 5)
    {
        if (V < 10)
        {
            RH = 30;
        }
        else if (V < 19)
        {
            RH = 35;
        }
        else if (V < 72)
        {
            RH = 40;
        }
        else if (V < 128)
        {
            RH = 45;
        }
        else if (V < 221)
        {
            RH = 50;
        }
        else if (V < 345)
        {
            RH = 55;
        }
        else if (V < 473)
        {
            RH = 60;
        }
        else if (V < 606)
        {
            RH = 65;
        }
        else if (V < 772)
        {
            RH = 70;
        }
        else if (V < 794)
        {
            RH = 75;
        }
        else if (V < 864)
        {
            RH = 80;
        }
        else if (V < 910)
        {
            RH = 85;
        }
        else
        {
            RH = 90;
        }
    }
    else if (temp < 10)
    {
        if (V < 5)
        {
            RH = 25;
        }
        else if (V < 11)
        {
            RH = 30;
        }
        else if (V < 27)
        {
            RH = 35;
        }
        else if (V < 99)
        {
            RH = 40;
        }
        else if (V < 172)
        {
            RH = 45;
        }
        else if (V < 276)
        {
            RH = 50;
        }
        else if (V < 411)
        {
            RH = 55;
        }
        else if (V < 547)
        {
            RH = 60;
        }
        else if (V < 671)
        {
            RH = 65;
        }
        else if (V < 772)
        {
            RH = 70;
        }
        else if (V < 841)
        {
            RH = 75;
        }
        else if (V < 892)
        {
            RH = 80;
        }
        else if (V < 933)
        {
            RH = 85;
        }
        else
        {
            RH = 90;
        }
    }
    else if (temp < 15)
    {
        if (V < 7)
        {
            RH = 25;
        }
        else if (V < 17)
        {
            RH = 30;
        }
        else if (V < 38)
        {
            RH = 35;
        }
        else if (V < 127)
        {
            RH = 40;
        }
        else if (V < 211)
        {
            RH = 45;
        }
        else if (V < 325)
        {
            RH = 50;
        }
        else if (V < 473)
        {
            RH = 55;
        }
        else if (V < 606)
        {
            RH = 60;
        }
        else if (V < 713)
        {
            RH = 65;
        }
        else if (V < 805)
        {
            RH = 70;
        }
        else if (V < 864)
        {
            RH = 75;
        }
        else if (V < 910)
        {
            RH = 80;
        }
        else if (V < 944)
        {
            RH = 85;
        }
        else
        {
            RH = 90;
        }
    }
    else if (temp < 20)
    {
        if (V < 5)
        {
            RH = 20;
        }
        else if (V < 10)
        {
            RH = 25;
        }
        else if (V < 23)
        {
            RH = 30;
        }
        else if (V < 51)
        {
            RH = 35;
        }
        else if (V < 164)
        {
            RH = 40;
        }
        else if (V < 263)
        {
            RH = 45;
        }
        else if (V < 386)
        {
            RH = 50;
        }
        else if (V < 531)
        {
            RH = 55;
        }
        else if (V < 655)
        {
            RH = 60;
        }
        else if (V < 761)
        {
            RH = 65;
        }
        else if (V < 841)
        {
            RH = 70;
        }
        else if (V < 893)
        {
            RH = 75;
        }
        else if (V < 931)
        {
            RH = 80;
        }
        else if (V < 953)
        {
            RH = 85;
        }
        else
        {
            RH = 90;
        }
    }
    else if (temp < 25)
    {
        if (V < 8)
        {
            RH = 20;
        }
        else if (V < 16)
        {
            RH = 25;
        }
        else if (V < 30)
        {
            RH = 30;
        }
        else if (V < 62)
        {
            RH = 35;
        }
        else if (V < 208)
        {
            RH = 40;
        }
        else if (V < 316)
        {
            RH = 45;
        }
        else if (V < 451)
        {
            RH = 50;
        }
        else if (V < 593)
        {
            RH = 55;
        }
        else if (V < 704)
        {
            RH = 60;
        }
        else if (V < 794)
        {
            RH = 65;
        }
        else if (V < 867)
        {
            RH = 70;
        }
        else if (V < 906)
        {
            RH = 75;
        }
        else if (V < 944)
        {
            RH = 80;
        }
        else if (V < 968)
        {
            RH = 85;
        }
        else
        {
            RH = 90;
        }
    }
    else if (temp < 30)
    {
        if (V < 11)
        {
            RH = 20;
        }
        else if (V < 22)
        {
            RH = 25;
        }
        else if (V < 41)
        {
            RH = 30;
        }
        else if (V < 82)
        {
            RH = 35;
        }
        else if (V < 255)
        {
            RH = 40;
        }
        else if (V < 375)
        {
            RH = 45;
        }
        else if (V < 512)
        {
            RH = 50;
        }
        else if (V < 655)
        {
            RH = 55;
        }
        else if (V < 751)
        {
            RH = 60;
        }
        else if (V < 794)
        {
            RH = 65;
        }
        else if (V < 887)
        {
            RH = 70;
        }
        else if (V < 928)
        {
            RH = 75;
        }
        else if (V < 955)
        {
            RH = 80;
        }
        else if (V < 975)
        {
            RH = 85;
        }
        else
        {
            RH = 90;
        }
    }
    else if (temp < 35)
    {
        if (V < 14)
        {
            RH = 20;
        }
        else if (V < 27)
        {
            RH = 25;
        }
        else if (V < 54)
        {
            RH = 30;
        }
        else if (V < 107)
        {
            RH = 35;
        }
        else if (V < 303)
        {
            RH = 40;
        }
        else if (V < 427)
        {
            RH = 45;
        }
        else if (V < 569)
        {
            RH = 50;
        }
        else if (V < 704)
        {
            RH = 55;
        }
        else if (V < 782)
        {
            RH = 60;
        }
        else if (V < 860)
        {
            RH = 65;
        }
        else if (V < 906)
        {
            RH = 70;
        }
        else if (V < 939)
        {
            RH = 75;
        }
        else if (V < 962)
        {
            RH = 80;
        }
        else if (V < 980)
        {
            RH = 85;
        }
        else
        {
            RH = 90;
        }
    }
    else if (temp < 40)
    {
        if (V < 17)
        {
            RH = 20;
        }
        else if (V < 36)
        {
            RH = 25;
        }
        else if (V < 70)
        {
            RH = 30;
        }
        else if (V < 128)
        {
            RH = 35;
        }
        else if (V < 354)
        {
            RH = 40;
        }
        else if (V < 477)
        {
            RH = 45;
        }
        else if (V < 606)
        {
            RH = 50;
        }
        else if (V < 741)
        {
            RH = 55;
        }
        else if (V < 829)
        {
            RH = 60;
        }
        else if (V < 880)
        {
            RH = 65;
        }
        else if (V < 918)
        {
            RH = 70;
        }
        else if (V < 949)
        {
            RH = 75;
        }
        else if (V < 968)
        {
            RH = 80;
        }
        else if (V < 983)
        {
            RH = 85;
        }
        else
        {
            RH = 90;
        }
    }
    else if (temp < 45)
    {
        if (V < 23)
        {
            RH = 20;
        }
        else if (V < 48)
        {
            RH = 25;
        }
        else if (V < 89)
        {
            RH = 30;
        }
        else if (V < 167)
        {
            RH = 35;
        }
        else if (V < 417)
        {
            RH = 40;
        }
        else if (V < 526)
        {
            RH = 45;
        }
        else if (V < 647)
        {
            RH = 50;
        }
        else if (V < 782)
        {
            RH = 55;
        }
        else if (V < 854)
        {
            RH = 60;
        }
        else if (V < 892)
        {
            RH = 65;
        }
        else if (V < 927)
        {
            RH = 70;
        }
        else if (V < 955)
        {
            RH = 75;
        }
        else if (V < 973)
        {
            RH = 80;
        }
        else if (V < 987)
        {
            RH = 85;
        }
        else
        {
            RH = 90;
        }
    }
    else if (temp < 50)
    {
        if (V < 29)
        {
            RH = 20;
        }
        else if (V < 59)
        {
            RH = 25;
        }
        else if (V < 116)
        {
            RH = 30;
        }
        else if (V < 212)
        {
            RH = 35;
        }
        else if (V < 465)
        {
            RH = 40;
        }
        else if (V < 563)
        {
            RH = 45;
        }
        else if (V < 663)
        {
            RH = 50;
        }
        else if (V < 817)
        {
            RH = 55;
        }
        else if (V < 880)
        {
            RH = 60;
        }
        else if (V < 907)
        {
            RH = 65;
        }
        else if (V < 939)
        {
            RH = 70;
        }
        else if (V < 966)
        {
            RH = 75;
        }
        else if (V < 982)
        {
            RH = 80;
        }
        else if (V < 992)
        {
            RH = 85;
        }
        else
        {
            RH = 90;
        }
    }
    else
    { // Températures >= 50 dernière colonne du tableau
        if (V < 35)
        {
            RH = 20;
        }
        else if (V < 70)
        {
            RH = 25;
        }
        else if (V < 139)
        {
            RH = 30;
        }
        else if (V < 250)
        {
            RH = 35;
        }
        else if (V < 531)
        {
            RH = 40;
        }
        else if (V < 606)
        {
            RH = 45;
        }
        else if (V < 713)
        {
            RH = 50;
        }
        else if (V < 841)
        {
            RH = 55;
        }
        else if (V < 894)
        {
            RH = 60;
        }
        else if (V < 924)
        {
            RH = 65;
        }
        else if (V < 953)
        {
            RH = 70;
        }
        else if (V < 973)
        {
            RH = 75;
        }
        else if (V < 989)
        {
            RH = 80;
        }
        else if (V < 1000)
        {
            RH = 85;
        }
        else
        {
            RH = 90;
        }
    }
    return RH;
}

/*
 * Nous utilisons une bout de code externe pour l'utilisation de l'écrant LCD
 */

// LCDClear
// LCDString
// Move cursor to specified position
void positionXY(int x, int y)
{
    LCDWrite(0, 0x80 | x);
    LCDWrite(0, 0x40 | y);
}

// Accepts a single character and searches in the table for the
// matching hexadecimal value
void LCDCharacter(char character)
{
    LCDWrite(LCD_DATA, 0x00);
    for (int index = 0; index < 5; index++)
    {
        LCDWrite(LCD_DATA, ASCII[character - 0x20][index]);
    }
    LCDWrite(LCD_DATA, 0x00);
}
// Accepts the input and forwards it letter by letter
void LCDString(char *characters)
{
    while (*characters)
    {
        LCDCharacter(*characters++);
    }
}
// resets all entries on the display
void LCDClear()
{
    for (int index = 0; index < (LCD_X * LCD_Y / 8); index++)
    {
        LCDWrite(LCD_DATA, 0x00);
    }
    positionXY(0, 0);
}

void LCDInit()
{
    pinMode(PIN_SCE, OUTPUT);
    pinMode(PIN_RESET, OUTPUT);
    pinMode(PIN_DC, OUTPUT);
    pinMode(PIN_SDIN, OUTPUT);
    pinMode(PIN_SCLK, OUTPUT);
    digitalWrite(PIN_RESET, LOW);
    digitalWrite(PIN_RESET, HIGH);
    LCDWrite(LCD_COMMAND, 0x21);
    LCDWrite(LCD_COMMAND, 0xB0);
    LCDWrite(LCD_COMMAND, 0x04);
    LCDWrite(LCD_COMMAND, 0x14);
    LCDWrite(LCD_COMMAND, 0x20);
    LCDWrite(LCD_COMMAND, 0x0C);
}

void LCDWrite(byte data_or_command, byte data)
{
    digitalWrite(PIN_DC, data_or_command);
    digitalWrite(PIN_SCE, LOW);
    shiftOut(PIN_SDIN, PIN_SCLK, MSBFIRST, data);
    digitalWrite(PIN_SCE, HIGH);
}
