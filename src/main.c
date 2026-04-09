#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fonctions.h"
#define MAX_MOTS 10000
#define MAX_TAILLE 100

void filtrerMotsAvecLettres();
void filtrerMotsSansLettres();
void filtrerMotsAvecSousChaine();

int main() {
    
    FILE *f = fopen("ressource/bdd_wordle.txt", "r");
    
    if (f == NULL) {
        printf("Erreur ouverture fichier\n");
        return 1;
    }
    
    char mots[MAX_MOTS][MAX_TAILLE];
    int nb_mots = 0;
    int choix;
    char input[100];
    

    char temp[MAX_TAILLE];
    while (fscanf(f, "%s", temp) == 1) {
   
        if (strlen(temp) == 5) {
            strcpy(mots[nb_mots], temp);
            nb_mots++;
        }
    }
    
    fclose(f);
    system("clear");
    
    printf(" \33[1;37m=== FILTREUR DE MOTS WORDLE ===\33[0m\n");
    printf(" \33[1;36mBase de données : %d mots de 5 lettres chargés\33[0m\n\n", nb_mots);
    system("sleep 2");
    
    while (1) {
        
        printf("\n \33[1;34m --- MENU PRINCIPAL ---\33[0m\n"
                "                           \n"
                "1. Filtrer les mots qui contiennent des lettres spécifiques\n"
                "2. Filtrer les mots qui ne contiennent pas certaines lettres\n"
                "3. Filtrer les mots qui contiennent une sous-chaîne (ex: 'at', 'ing')\n"
                "4. Filtrer les mots qui contiennent et ne contiennent pas certaines lettres\n"
                "5. Quitter\n"


                "Votre choix : "
            );
        
        scanf("%d", &choix);
        getchar();
        
        switch(choix) {
            case 1:
                printf("Entrez les lettres à inclure (ex: 'aeiou' pour les voyelles) : ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                filtrerMotsAvecLettres(mots, nb_mots, input);
                break;
                
            case 2:
                printf("Entrez les lettres à exclure (ex: 'xyz' pour exclure x,y,z) : ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                filtrerMotsSansLettres(mots, nb_mots, input);
                break;
                
            case 3:
                printf("Entrez la sous-chaîne à rechercher (ex: 'at', 'ing') : ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                filtrerMotsAvecSousChaine(mots, nb_mots, input);
                break;
                
            case 4: {
                char incluses[100], exclues[100];
                printf("Entrez les lettres à inclure (ex: 'aeiou') : ");
                fgets(incluses, sizeof(incluses), stdin);
                incluses[strcspn(incluses, "\n")] = 0;
                
                printf("Entrez les lettres à exclure (ex: 'xyz') : ");
                fgets(exclues, sizeof(exclues), stdin);
                exclues[strcspn(exclues, "\n")] = 0;
                
                printf("\n--- Mots contenant '%s' et ne contenant pas '%s' ---\n", incluses, exclues);
                int count = 0;
                for (int i = 0; i < nb_mots; i++) {
                    if (withAll(mots[i], incluses) && withOut(mots[i], exclues)) {
                        printf("%s\n", mots[i]);
                        count++;
                    }
                }
                printf("\n \33[1;31mNombre de mots trouvés : %d\33[0m\n", count);
                break;
            }
                
            case 5:
                system("clear");
                
                printf("Au revoir !\n");
                
                system("sleep 2 && clear");

                return 0;
                
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    }
    
    return 0;
}

void filtrerMotsAvecLettres(char mots[MAX_MOTS][MAX_TAILLE], int nb_mots, char lettres[]) {
    printf("\n--- Mots contenant les lettres '%s' ---\n", lettres);
    int count = 0;
    
    for (int i = 0; i < nb_mots; i++) {
        if (withAll(mots[i], lettres)) {
            printf("%s\n", mots[i]);
            count++;
        }
    }
    
    printf("\n \33[1;31mNombre de mots trouvés : %d\33[0m\n", count);
}

void filtrerMotsSansLettres(char mots[MAX_MOTS][MAX_TAILLE], int nb_mots, char lettres[]) {
    printf("\n--- Mots ne contenant PAS les lettres '%s' ---\n", lettres);
    int count = 0;
    
    for (int i = 0; i < nb_mots; i++) {
        if (withOut(mots[i], lettres)) {
            printf("%s\n", mots[i]);
            count++;
        }
    }
    
    printf("\n \33[1;31mNombre de mots trouvés : %d\33[0m\n", count);
}

void filtrerMotsAvecSousChaine(char mots[MAX_MOTS][MAX_TAILLE], int nb_mots, char sub[]) {
    printf("\n--- Mots contenant la sous-chaîne '%s' ---\n", sub);
    int count = 0;
    
    for (int i = 0; i < nb_mots; i++) {
        if (search(mots[i], sub)) {
            printf("%s\n", mots[i]);
            count++;
        }
    }
    
    printf("\n \33[1;31mNombre de mots trouvés : %d\33[0m\n", count);
}
