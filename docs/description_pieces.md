# Description des pièces mécaniques

Ce document décrit le rôle de chaque pièce modélisée sur FreeCAD et Fusion 360.  
Une version définitive (schéma cinématique, graphe de liaisons) sera rédigée dans le rapport final.

---

## Pièce 0 – Bâti (base fixe)

![Pièce 0 - Bâti](../images/piece0_base.png)

**Rôle :**  
- Base fixe de la tourelle, constituant le référentiel fixe du système.  
- Accueille le breadboard, la carte Arduino et le joystick.  
- Un cube saillant porte le joystick ; des trous de fixation en façade solidarisent la carte Arduino.  
- Aux quatre coins, quatre logements cylindriques reçoivent chacune une colonne (pièce 1).

**Liaisons :**  
- Fixe par rapport au bâti (référentiel absolu).

---

## Pièce 1 – Colonnes (4 exemplaires)

![Pièce 1 - Colonne](../images/piece1_colonne.png)

**Rôle :**  
- Colonne cylindrique creuse imprimée en quatre exemplaires.  
- Sert de support pour maintenir la pièce 2 au-dessus de la pièce 0.

**Liaisons :**  
- Encastrement dans les logements de la pièce 0.  
- Support en compression pour la pièce 2.

---

## Pièce 2 – Plateau intermédiaire

![Pièce 2 - Plateau intermédiaire](../images/piece2_plateau.png)

**Rôle :**  
- Porte le premier servomoteur (mouvement horizontal).  
- Ses quatre coins comportent des logements qui s'emboîtent sur les colonnes (pièce 1).  
- L'orifice circulaire central reçoit le joystick.  
- Le logement latéral accueille le corps du servomoteur horizontal, fixé par deux vis sur chaque ailette.  
- Deux fentes rectangulaires en sous-face permettent le passage des câbles.  
- Assure également la protection des composants électroniques sous-jacents.

**Liaisons :**  
- Encastrement sur les colonnes (pièce 1).  
- Liaison pivot avec la pièce 3 (via l'arbre du servomoteur horizontal).

---

## Pièce 3 – Bras tournant

![Pièce 3 - Bras tournant](../images/piece3_bras.png)

**Rôle :**  
- Plateau tournant encastré sur l'axe du premier servomoteur (mouvement horizontal).  
- Un logement en sous-face reçoit le bras du servo.  
- Porte le second servomoteur (mouvement vertical), fixé par deux vis sur chaque ailette.  
- Un logement circulaire reçoit le roulement à billes, qui assure la liaison pivot entre les pièces 3 et 4.

**Liaisons :**  
- Encastrement sur l'arbre du servo horizontal.  
- Liaison pivot avec la pièce 4 (via roulement à billes).

---

## Pièce 4 – Tête de la tourelle

![Pièce 4 - Tête](../images/piece4_tete.png)

**Rôle :**  
- Fixée sur le bras du servomoteur vertical, lui-même encastré sur l'axe par vissage.  
- Supporte la caméra Pixy2, le module laser (trou circulaire) et le **canon électromagnétique (coilgun)** (deux trous triangulaires).  
- Deux trous permettent la fixation de la pièce 5 par vissage.

**Liaisons :**  
- Encastrement sur l'arbre du servo vertical.  
- Liaison pivot avec la pièce 3 (via roulement à billes).  
- Liaison encastrement avec la pièce 5 (vissée).

---

## Pièce 5 – Pièce de jonction

![Pièce 5 - Jonction](../images/piece5_jonction.png)

**Rôle :**  
- Pièce vissée sur la pièce 4.  
- Assure la jonction entre les pièces 3 et 4.  
- Comporte à son extrémité un cylindre qui vient se loger dans le roulement à billes de la pièce 3, réalisant ainsi la liaison pivot entre ces deux pièces.

**Liaisons :**  
- Encastrement par vissage sur la pièce 4.  
- Liaison pivot avec la pièce 3 (via le cylindre qui s'insère dans le roulement).

---

## Récapitulatif

| Pièce | Nom | Qté | Mouvement | Actionneur |
|-------|-----|-----|-----------|------------|
| 0 | Bâti | 1 | Fixe | - |
| 1 | Colonne | 4 | Fixe | - |
| 2 | Plateau intermédiaire | 1 | Fixe | - |
| 3 | Bras tournant | 1 | Rotation horizontale (pan) | Servo H |
| 4 | Tête | 1 | Rotation verticale (tilt) | Servo V |
| 5 | Jonction | 1 | Fixe (liaison pivot) | - |

---

*Document basé sur le rapport TIPE (pages 5-6). Les photos seront ajoutées après impression 3D.*

