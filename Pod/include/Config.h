
#ifndef CONFIG_H
#define CONFIG_H

/**
 * @file Config.h
 * @brief Fichier de configuration contenant les constantes et définitions des pins.
 */

// Définition des pins utilisées dans le projet
#define PIN_BP 13       ///< Bouton poussoir
#define PIN_PS A0       ///< Capteur de tension batterie
#define PIN_ESC_AVD 6   ///< ESC (Electronic Speed Controller) Avant Droit
#define PIN_ESC_AVG 5   ///< ESC Avant Gauche
#define PIN_ESC_ARD 9   ///< ESC Arrière Droit
#define PIN_ESC_ARG 10  ///< ESC Arrière Gauche

// Paramètres moteur
const int MOTOR_KV = 1200;           ///< KV du moteur (RPM par Volt)
const float BAT_LEVEL_VALUE = 18.6;  ///< Niveau de tension nominale de la batterie (en Volts)
const int ESC_MIN = 5;               ///< Seuil minimum du signal ESC
const int V_OFFSET_M = 45;           ///< Décalage tension moteur

// Délais pour la gestion de l'accélération
const int V_RISE_DELAY = 5000;       ///< Temps d'accélération (ms)
const int V_LOAD_DELAY = 2000;       ///< Temps à vitesse maximale (ms)
const int V_PRELOAD_DELAY = 2000;    ///< Temps avant démarrage du moteur (ms)

#endif

