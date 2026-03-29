 /**
 * @file    joystick_servo.ino
 * @author  Moumni Chama
 * @date    Janvier 2026
 * @version 2.0
 * @brief   Pilotage d'une tourelle motorisée (2 axes) par joystick.
 * 
 * @details
 * Ce programme lit les positions d'un joystick sur les entrées analogiques A0 et A1.
 * Il convertit chaque valeur analogique (0-1023) en une largeur d'impulsion
 * comprise entre 500 µs et 2400 µs, puis envoie ces impulsions à deux servomoteurs.
 * Les angles correspondants (0° à 180°) sont affichés dans le moniteur série.
 * 
 * @note    Projet réalisé dans le cadre du TIPE.
 *          Simulation disponible sur Wokwi et code hébergé sur GitHub.
 */

#include <Servo.h>

// ============================================================================
//  CONSTANTES
// ============================================================================

// Broches de commande des servomoteurs
const int PIN_SERVO_HORIZONTAL = 9;
const int PIN_SERVO_VERTICAL   = 10;

// Entrées analogiques du joystick
const int PIN_JOYSTICK_HORIZONTAL = A0;
const int PIN_JOYSTICK_VERTICAL   = A1;

// Plage des valeurs analogiques lues (0 à 1023)
const int ANALOG_MIN = 0;
const int ANALOG_MAX = 1023;

// Plage des impulsions PWM pour les servos (µs)
const int PULSE_MIN = 500;   // 500 µs  -> 0°
const int PULSE_MAX = 2400;  // 2400 µs -> 180°

// Calcul de la plage d'impulsion effective (pour conversion en angle)
const int PULSE_RANGE = PULSE_MAX - PULSE_MIN;  // = 1900 µs

// Vitesse de communication série (bauds)
const long SERIAL_BAUD = 9600;

// Délai entre deux itérations de la boucle principale (millisecondes)
const int LOOP_DELAY_MS = 500;

// ============================================================================
//  OBJETS
// ============================================================================

Servo servo_horizontal;  ///< Servomoteur commandant l'axe horizontal (gauche/droite)
Servo servo_vertical;    ///< Servomoteur commandant l'axe vertical (haut/bas)

// ============================================================================
//  FONCTIONS
// ============================================================================

/**
 * @brief   Initialisation du microcontrôleur.
 * 
 * Active la communication série et attache les servomoteurs à leurs broches.
 */
void setup() {
  Serial.begin(SERIAL_BAUD);
  
  servo_horizontal.attach(PIN_SERVO_HORIZONTAL);
  servo_vertical.attach(PIN_SERVO_VERTICAL);
}

/**
 * @brief   Boucle principale : lecture du joystick, conversion et commande des servos.
 * 
 * Lit les valeurs analogiques du joystick, les convertit en largeurs d'impulsion,
 * puis en angles pour affichage. Envoie les impulsions aux servomoteurs.
 */
void loop() {
  // 1. Acquisition des positions du joystick
  int pos_horizontal = analogRead(PIN_JOYSTICK_HORIZONTAL);
  int pos_vertical   = analogRead(PIN_JOYSTICK_VERTICAL);
  
  // 2. Conversion analogique -> largeur d'impulsion (µs)
  int pulse_horizontal = map(pos_horizontal, ANALOG_MIN, ANALOG_MAX, PULSE_MIN, PULSE_MAX);
  int pulse_vertical   = map(pos_vertical,   ANALOG_MIN, ANALOG_MAX, PULSE_MIN, PULSE_MAX);
  
  // 3. Calcul des angles correspondants (0° à 180°)
  //    Formule : angle = (pulse - PULSE_MIN) * 180.0 / PULSE_RANGE
  float angle_horizontal = ((float)(pulse_horizontal - PULSE_MIN)) * 180.0 / PULSE_RANGE;
  float angle_vertical   = ((float)(pulse_vertical   - PULSE_MIN)) * 180.0 / PULSE_RANGE;
  
  // 4. Application des impulsions aux servomoteurs
  servo_horizontal.writeMicroseconds(pulse_horizontal);
  servo_vertical.writeMicroseconds(pulse_vertical);
  
  // 5. Affichage des angles dans le moniteur série (pour débogage et validation)
  Serial.print("position horizontal: ");
  Serial.println(angle_horizontal);   // 0° = gauche, 90° = centre, 180° = droite
  Serial.print("position vertical: ");
  Serial.println(angle_vertical);     // 0° = haut, 90° = centre, 180° = bas
  
  // 6. Temporisation pour éviter une surcharge de la communication série
  delay(LOOP_DELAY_MS);
} 