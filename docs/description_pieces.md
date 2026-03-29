# Description provisoire des pièces mécaniques

Ce document décrit brièvement le rôle de chaque pièce modélisée sur FreeCAD.  
Une version définitive (schéma cinématique, graphe de liaisons) sera rédigée en LaTeX.

## Pièce 0 – Base
- Fixation du breadboard, de la carte Arduino et du joystick.
- Assure la stabilité de la tourelle.

## Pièce 1 – Capot / support servo horizontal
- Protège les câblages et composants électroniques (fixé sur la pièce 0).
- Supporte le servomoteur chargé du mouvement horizontal (pan).

## Pièce 2 – Support servo vertical (en cours)
- Fixée sur le rotor du servomoteur horizontal.
- Entraîne le mouvement vertical (tilt).

## Pièce 3 – Porte-électroaimant (en cours)
- Fixée sur le servomoteur vertical.
- Porte l’électroaimant.
- Liaison pivot avec la pièce 2.

---

*Document provisoire – une version plus complète (graphe de liaison, schéma cinématique) viendra dans `docs/cinematique/` en LaTeX.*
