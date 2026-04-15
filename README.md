# TIPE – Tourelle de visée motorisée

Conception et réalisation d’une tourelle motorisée pilotée par joystick.  
Projet mené dans le cadre de mon TIPE (2025-2026).

## 📁 Structure du dépôt

- `code/` : code Arduino (C++ embarqué) et simulation Wokwi (schéma + programme)
- `cad/` : modèles 3D FreeCAD (pièces, assemblage, composants génériques)
- `docs/` : documentation technique (descriptions provisoires, études à venir)
- `images/` : photos du montage réel et captures d’écran (à venir)

## 🛠️ Technologies utilisées

- Arduino / C++ embarqué
- Wokwi (simulation)
- FreeCAD (modélisation 3D)
- Électronique : soudure, câblage, servomoteurs

## 🧩 État d’avancement

- [x] Simulation Wokwi (code + schéma)
- [x] Câblage sur breadboard, soudure du joystick et connexion à la carte Arduino
- [x] Modélisation 3D :
    - [x] Pièce 0 (base)
    - [x] Pièce 1 (capot / support servo horizontal)
    - [x] Pièce 2 
    - [ ] Pièce 3 – *en cours*
    - [ ] Assemblage virtuel – *à faire*
- [ ] Étude cinématique (graphe de liaison, schéma) – *en cours*
- [x] Mesures électroaimant (résistance R, inductance L) et dimensionnement de la capacité C 
- [ ] Rédaction du rapport final – *à faire*
- [ ] Prototypage physique (impression 3D, montage final) – *à faire*

## 🔗 Liens utiles

- [Code Arduino](./code/joystick_servo.ino)
- [Schéma Wokwi](./code/diagram.json)
- [Description provisoire des pièces](./docs/description_pieces.md)
- [Simulation : Commande de servomoteur par joystick](https://wokwi.com/projects/456061970656974849)

## 📝 Notes

- La documentation définitive (étude cinématique, calculs électroaimant) sera rédigée en LaTeX et ajoutée ultérieurement dans `docs/`.
- Ce dépôt est régulièrement mis à jour au fil de l’avancement du projet.
