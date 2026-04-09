
# wordle_filter

> Filtreur de mots pour Wordle en ligne de commande, écrit en C.

![C](https://img.shields.io/badge/langage-C-blue) ![GCC](https://img.shields.io/badge/compilateur-GCC-orange)

---

## À propos

Ce programme charge une base de mots de 5 lettres (tirée du fichier `ressource/bdd_wordle.txt`) et permet de filtrer ces mots selon différents critères.  
Il est conçu pour aider à résoudre les grilles de **Wordle** en affinant la liste des mots possibles à chaque essai.

Fonctionnalités :
- Filtrer les mots qui **contiennent** certaines lettres
- Filtrer les mots qui **ne contiennent pas** certaines lettres
- Filtrer les mots qui contiennent une **sous‑chaîne** (ex: `"at"`, `"ing"`)
- Combiner les critères d’inclusion et d’exclusion

---

## Installation

```bash
# Cloner le dépôt (ou télécharger les fichiers)
cd ~/Documents
git clone https://github.com/serginikov/Wordle_Solver_Sergio.git
```

## Compilation

```bash
cd ~/Documents/wordle_filter
mkdir -p bin
gcc -o bin/filter -I include/ src/main.c src/fonctions.c
```

## Lancer le programme

```bash
cd ~/Documents/wordle_filter
bin/filter
```

---

## Utilisation

Une fois lancé, le programme affiche un menu interactif :

1. **Filtrer les mots qui contiennent des lettres spécifiques**  
   Exemple : saisir `aeiou` → mots contenant toutes ces voyelles.
2. **Filtrer les mots qui ne contiennent pas certaines lettres**  
   Exemple : saisir `xyz` → mots sans aucun de ces caractères.
3. **Filtrer les mots qui contiennent une sous‑chaîne**  
   Exemple : saisir `at` → mots comme `"catch"`, `"batty"`, etc.
4. **Filtrer avec inclusion ET exclusion**  
   Saisissez d’abord les lettres obligatoires, puis celles à exclure.
5. **Quitter**

Chaque filtre affiche le nombre de mots trouvés et la liste (si elle n’est pas trop longue).

---

## Structure du projet

```
wordle_filter/
├── include/
│   └── fonctions.h
├── src/
│   ├── main.c
│   └── fonctions.c
├── ressource/
│   └── bdd_wordle.txt      # fichier source des mots (5 lettres)
└── bin/
    └── filter              # généré à la compilation
```

> **Note** : Le fichier `bdd_wordle.txt` peut contenir du texte supplémentaire (en‑têtes, publicités). Le programme extrait automatiquement toutes les lignes composées exactement de 5 lettres.

---

## Exemple de session

```
=== FILTREUR DE MOTS WORDLE ===
Base de données : 2309 mots de 5 lettres chargés

1. Filtrer les mots qui contiennent des lettres spécifiques
2. Filtrer les mots qui ne contiennent pas certaines lettres
3. Filtrer les mots qui contiennent une sous-chaîne
4. Filtrer les mots qui contiennent et ne contiennent pas certaines lettres
5. Quitter

Votre choix : 4
Entrez les lettres à inclure (ex: 'aeiou') : aro
Entrez les lettres à exclure (ex: 'xyz') : et

--- Mots contenant 'aro' et ne contenant pas 'et' ---
aroma
arose
...
Nombre de mots trouvés : 12
```

---

## Remarques

- Le dictionnaire utilisé contient **plus de 12 000 mots** bruts, mais seuls ceux de **5 lettres** sont chargés (environ 2 300 mots, correspondant aux solutions officielles de Wordle).
- Le programme ne modifie pas le fichier source.
- Pour réinitialiser la recherche, quittez et relancez l’exécutable.

# Ateurs

    Harena Sergio