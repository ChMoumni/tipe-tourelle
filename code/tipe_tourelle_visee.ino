#include <Servo.h>
#include <Pixy2.h>

// === Déclarations des objets ===
Servo servo_horizontal;
Servo servo_vertical;
Pixy2 pixy;

// === Variables de contrôle ===
bool modeAuto = false;
float angleHorizontal = 90;
float angleVertical = 90;
float oldAngleHorizontal = 90;
float oldAngleVertical = 90;

// === Paramètres du joystick ===
const int pinJoystickX = A0;
const int pinJoystickY = A1;
const int zoneMorte = 60;

// === Paramètres de vitesse ===
const float vitesseH = 1.2;
const float vitesseV = 1.2;

// === Paramètres du PID ===
float erreurPrecedenteX = 0;
float erreurPrecedenteY = 0;

unsigned long dernierAffichage = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("=== Systeme de visee motorisee ===");
  Serial.println("Mode Manuel par defaut. Utilisez le joystick.");
  Serial.println("Tapez 'a' pour mode Auto (suivi d'objet)");
  Serial.println("Tapez 'm' pour revenir en mode Manuel");
  Serial.println("Tapez 'c' pour centrer la tourelle");
  Serial.println("--------------------------------------");
  
  servo_horizontal.attach(9);
  servo_vertical.attach(10);
  
  servo_horizontal.write(angleHorizontal);
  servo_vertical.write(angleVertical);

  // === Laser (broche 8) ===
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);  // Allumé au démarrage
  
  pixy.init();
  delay(100);
}

void loop() {
  // === Changement de mode ===
  if (Serial.available()) {
    char commande = Serial.read();
    if (commande == 'a' || commande == 'A') {
      modeAuto = true;
      Serial.println(">>> Mode AUTOMATIQUE active <<<");
    } else if (commande == 'm' || commande == 'M') {
      modeAuto = false;
      Serial.println(">>> Mode MANUEL active <<<");
    } else if (commande == 'c' || commande == 'C') {
      angleHorizontal = 90;
      angleVertical = 90;
      servo_horizontal.write(90);
      servo_vertical.write(90);
      Serial.println(">>> Centrage effectue <<<");
    }
  }
  
  if (modeAuto) {
    // ==================== MODE AUTOMATIQUE ====================
    pixy.ccc.getBlocks();
    
    if (pixy.ccc.numBlocks > 0) {
      int x = pixy.ccc.blocks[0].m_x;
      int y = pixy.ccc.blocks[0].m_y;
      
      int erreurX = x - 158;  // Centre de l'image Pixy (316/2)
      int erreurY = y - 104;  // Hauteur Pixy (208/2)
      
      float correctionX = erreurX * 0.015 + (erreurX - erreurPrecedenteX) * 0.05;
      float correctionY = erreurY * 0.015 + (erreurY - erreurPrecedenteY) * 0.05;
      
      erreurPrecedenteX = erreurX;
      erreurPrecedenteY = erreurY;

      oldAngleHorizontal = angleHorizontal;
      oldAngleVertical = angleVertical;
      
      angleHorizontal = constrain(angleHorizontal - correctionX, 10, 170);
      angleVertical = constrain(angleVertical + correctionY, 10, 170);
      
      // Filtrer les mouvements trop brusques
      if (abs(angleHorizontal - oldAngleHorizontal) < 15 && abs(angleVertical - oldAngleVertical) < 15) {
          servo_horizontal.write(angleHorizontal);
          servo_vertical.write(angleVertical);
      }
      
      unsigned long maintenant = millis();
      if (maintenant - dernierAffichage > 300) {
        Serial.print("AUTO - Objet: X=");
        Serial.print(x);
        Serial.print(" Y=");
        Serial.print(y);
        Serial.print(" | Servos: H=");
        Serial.print(angleHorizontal);
        Serial.print("° V=");
        Serial.println(angleVertical);
        dernierAffichage = maintenant;
      }
    } else {
      unsigned long maintenant = millis();
      if (maintenant - dernierAffichage > 1000) {
        Serial.println("AUTO - Aucun objet detecte");
        dernierAffichage = maintenant;
      }
    }

  } else {
    // ==================== MODE MANUEL ====================
    
    int valeurX = analogRead(pinJoystickX);
    int valeurY = analogRead(pinJoystickY);
    
    // Application de la zone morte
    int deltaX_brut = (abs(valeurX - 512) < zoneMorte) ? 0 : (valeurX - 512);
    int deltaY_brut = (abs(valeurY - 512) < zoneMorte) ? 0 : (valeurY - 512);
    
    float deltaX = deltaX_brut / 512.0;
    float deltaY = deltaY_brut / 512.0;
    
    angleHorizontal = constrain(angleHorizontal + deltaX * vitesseH, 10, 170);
    angleVertical   = constrain(angleVertical - deltaY * vitesseV, 10, 170);
    
    servo_horizontal.write(angleHorizontal);
    servo_vertical.write(angleVertical);
    
    unsigned long maintenant = millis();
    if (maintenant - dernierAffichage > 300) {
      Serial.print("MANUEL - Joystick: X=");
      Serial.print(valeurX);
      Serial.print(" Y=");
      Serial.print(valeurY);
      Serial.print(" | Servos: H=");
      Serial.print(angleHorizontal);
      Serial.print("° V=");
      Serial.println(angleVertical);
      dernierAffichage = maintenant;
    }
  }
  
  delay(20);
}
