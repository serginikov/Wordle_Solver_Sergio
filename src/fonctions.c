#include "fonctions.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int with(char mot[], char lettre) {
    for (int i = 0; mot[i] != '\0'; i++) {
        if (mot[i] == lettre) {
            return 1;
        }
    }
    return 0;
}

int withAll(char mot[], char lettres[]) {
    for (int i = 0; lettres[i] != '\0'; i++) {
        if (!with(mot, lettres[i])) {
            return 0;
        }
    }
    return 1;
}


int withOut(char mot[], char lettres[]) {
    for (int i = 0; lettres[i] != '\0'; i++) {
        if (with(mot, lettres[i])) {
            return 0;
        }
    }
    return 1;
}


int search(char mot[], char sub[]) {
    return strstr(mot, sub) != NULL;
}

