#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include <Arduino.h>
#include <Servo.h>
#include "Config.h"

/**
 * @file MotorControl.h
 * @brief Gestion des moteurs et de leur contrôle via ESC.
 */
class MotorControl {
public:

    /**
     * @brief Constructeur de la classe MotorControl.
     * @param pinAvD Pin pour l'ESC du moteur Avant Droit.
     * @param pinAvG Pin pour l'ESC du moteur Avant Gauche.
     * @param pinArD Pin pour l'ESC du moteur Arrière Droit.
     * @param pinArG Pin pour l'ESC du moteur Arrière Gauche.
     */
    MotorControl(int pinAvD, int pinAvG, int pinArD, int pinArG);

    /**
     * @brief Initialise les ESC et effectue la séquence d'initialisation.
     */
    void setupESC();

    /**
     * @brief Effectue une montée progressive en vitesse sans limitation de durée.
     * @param v_set Pourcentage de puissance (0-100%).
     * @param t_set Temps de montée en régime (ms).
     * @param t_set_preLoad Temps avant démarrage du moteur (ms).
     */
    void unlimitedLoad(int v_set, int t_set, int t_set_preLoad);

    /**
     * @brief Effectue une montée en vitesse limitée dans le temps.
     * @param v_set Pourcentage de puissance (0-100%).
     * @param t_set Temps de montée en régime (ms).
     * @param t_set_load Temps à puissance maximale avant arrêt (ms).
     * @param t_set_preLoad Temps avant démarrage du moteur (ms).
     */
    void load(int v_set, int t_set, int t_set_load, int t_set_preLoad);

    /**
     * @brief Stoppe les moteurs en envoyant un signal minimum aux ESC.
     */
    void unload();

    /**
     * @brief Active/désactive chaque moteur via des commandes série.
     */
    void setMotors();

    /**
     * @brief Renvoie l'état des moteurs.
     */
    void reportMotorStates();

private:
    Servo ESC_AvD, ESC_AvG, ESC_ArD, ESC_ArG; ///< Objets Servo pour les ESC des moteurs.
    bool State_AvD, State_AvG, State_ArD, State_ArG; ///< État de chaque moteur (actif/inactif).
};

#endif


