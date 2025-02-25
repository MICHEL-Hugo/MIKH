# MIKH - Maquette IKos Hyperloop

## 📖 Sommaire
1. [Présentation](#-présentation)
2. [Composition du projet](#-composition-du-projet)
3. [Structure du dépôt Git](#-structure-du-dépôt-git)
4. [Programmation orientée objet & PlatformIO](#-programmation-orientée-objet-oo--platformio)
5. [Installation et configuration](#-installation-et-configuration)
6. [Contribution](#-contribution)
7. [Licence](#-licence)
8. [Conclusion](#-conclusion)

---

## 📌 Présentation

**MIKH** est un projet de maquette d'Hyperloop illustrant les principes de sustentation et de propulsion magnétiques. Ce modèle vise à expliquer le fonctionnement d'un système Hyperloop de manière pédagogique et interactive lors d'événements et de salons.

### 🔹 Objectifs
- Mettre en avant les principes de sustentation et de propulsion magnétiques.
- Proposer une maquette simple et sécurisée pour des démonstrations en public.
- Illustrer concrètement le concept de l'Hyperloop.

---

## 🏗️ Composition du projet

La maquette se compose de deux sous-systèmes :

- **🚄 Le Pod** : Capsule en sustentation.
- **🛤️ La Track** : Voie magnétique sur laquelle évolue le Pod.

### ✨ Principe de sustentation
Le Pod utilise la **sustentation électrodynamique (EDS)**. Six aimants montés sur quatre moteurs tournants génèrent des **courants de Foucault** dans la Track, composée de **deux bandes d'aluminium inclinées**, permettant ainsi la lévitation et le guidage du Pod.

### ⚡ Principe de propulsion
La propulsion est assurée par **deux moteurs linéaires à induction**, placés de part et d’autre de la Track. Ces moteurs interagissent avec une **plaque en aluminium** sous le Pod, générant ainsi un déplacement sans friction.

---

## 📂 Structure du dépôt Git

```bash
MIKH/
│── archives/       # Archives des versions initiales
│── pod/            # Projet PlatformIO du Pod
│   ├── src/        # Code source (.cpp)
│   ├── include/    # Fichiers d'en-tête (.h)
│── track/          # Projet PlatformIO de la Track
│   ├── src/        # Code source (.cpp)
│   ├── include/    # Fichiers d'en-tête (.h)
│── MIKH.code-workspace  # Espace de travail préconfiguré
```

---

## 🧑‍💻 Programmation orientée objet (OO) & PlatformIO

### 🔍 Pourquoi l'OO ?
L'approche **orientée objet (OO)** apporte plusieurs avantages pour un projet comme MIKH :
- **Modularité** : Chaque composant du système est indépendant.
- **Réutilisabilité** : Facilite l'intégration et l'évolution du code.
- **Maintenance simplifiée** : Meilleure organisation et lisibilité du code.

### 🏗️ Implémentation dans PlatformIO
Dans ce projet, l'OO est appliquée ainsi :
- **Encapsulation des sous-systèmes** (Pod et Track) dans des classes.
- **Gestion modulaire des capteurs et moteurs** avec des objets distincts.
- **Séparation des responsabilités** pour un code clair et facile à déboguer.

---

## 🛠️ Installation et configuration

### 📌 Prérequis
1. Installer **PlatformIO** :
   - VS Code : Ajouter l'extension PlatformIO depuis le Marketplace.
   - CLI : [Instructions d'installation](https://platformio.org/install/cli).

2. Cloner le dépôt :
   ```sh
   git clone https://github.com/ton-repo/MIKH.git
   ```

3. Ouvrir l’espace de travail dans VS Code :
   - Lancer VS Code.
   - Ouvrir **MIKH.code-workspace**.

4. Compilation et téléversement :
   - **Depuis VS Code** via l’interface PlatformIO.
   - **Via CLI** :
     ```sh
     cd pod
     pio run --target upload
     ```
     ```sh
     cd track
     pio run --target upload
     ```

---

## 📜 Licence

Ce projet est la propriété de **IKOS Lab** et est soumis aux règles de propriété intellectuelle de l'entreprise.
Toute reproduction, modification ou diffusion sans autorisation explicite d'IKOS Lab est interdite.
Pour toute demande d'utilisation ou de contribution externe, veuillez contacter **IKOS Lab**.


