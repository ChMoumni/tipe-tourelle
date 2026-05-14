# TIPE – Tourelle de visée motorisée

<p align="center">
  <img src="images/systeme_complet.png" alt="Système complet" width="600"/>
</p>

Conception et réalisation d'une tourelle motorisée pilotée par joystick, avec suivi automatique d'objet par caméra Pixy2.  
Projet mené dans le cadre de mon TIPE (2025-2026).

## 🎯 Objectif du projet

Développer un système de visée motorisé capable de :
- Être piloté manuellement via un joystick
- Suivre automatiquement un objet coloré en temps réel
- Servir de plateforme d'étude pour l'asservissement et la cinématique

## 📁 Structure du dépôt

\```
tipe-tourelle/
├── code/               # Code Arduino et simulation Wokwi
│   └── tipe_tourelle_visee.ino
├── cad/                # Modèles 3D FreeCAD
├── images/             # Photos et captures d'écran
│   ├── systeme_complet.jpg
│   └── comparaison_modelisation_reel.jpg
├── docs/               # Documentation
└── README.md
\```

## 🛠️ Technologies utilisées

- **Microcontrôleur** : Arduino Uno
- **Langage** : C++ embarqué
- **Capteur** : Pixy2 CMUcam (reconnaissance couleur)
- **Actionneurs** : 2 servomoteurs
- **Entrée** : Joystick analogique 2 axes
- **Simulation** : Wokwi
- **CAO** : FreeCAD

## 🎮 Fonctionnalités

### Mode Manuel
- Pilotage horizontal/vertical par joystick
- Zone morte configurable
- Vitesse progressive

### Mode Automatique
- Détection d'objets colorés
- Asservissement PD
- Commutation manuel/auto par série

### Commandes série
- `a` : Mode automatique
- `m` : Mode manuel  
- `c` : Centrer la tourelle

## 🔧 Installation

1. Cloner le dépôt
2. Câbler selon schéma (servos pins 9/10, joystick A0/A1)
3. Téléverser le code Arduino
4. Ouvrir le moniteur série (115200 bauds)

## 📊 Résultats

<p align="center">
  <img src="images/comparaison_modelisation_reel.jpg" alt="Comparaison" width="800"/>
</p>

## 🧩 État d'avancement

- [x] Simulation Wokwi
- [x] Câblage et tests
- [x] Modélisation 3D complète
- [x] Impression 3D
- [x] Assemblage final
- [x] Code fonctionnel (manuel + auto)
- [ ] Rapport final (en cours)

