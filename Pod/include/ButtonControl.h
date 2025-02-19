#ifndef BUTTONCONTROL_H
#define BUTTONCONTROL_H

#include <Arduino.h>
#include "MotorControl.h"

/**
 * @file ButtonControl.h
 * @brief Gestion du bouton poussoir pour démarrer/arrêter les moteurs.
 */
class ButtonControl {
public:
    /**
     * @brief Constructeur de la classe ButtonControl.
     * @param pinButton Pin du bouton poussoir.
     * @param motorControl Référence à l'objet MotorControl pour interagir avec les moteurs.
     */
    ButtonControl(int pinButton, MotorControl& motorControl);

    /**
     * @brief Vérifie l'état du bouton poussoir et déclenche les moteurs si nécessaire.
     */
    void checkButton();

private:
    int pinBP;         ///< Pin du bouton poussoir.
    bool BP_Flag;      ///< Indicateur d'état pour éviter plusieurs déclenchements successifs.
    MotorControl& motor; ///< Référence à l'objet MotorControl pour commander les moteurs.
};

#endif

