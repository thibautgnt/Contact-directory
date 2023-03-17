// Projet - Programmation en C - B1 CEH CS1
// Par Thibaut GENET, tous droits réservés © 2023
// Annuaire sous forme de liste double-chainée

// Bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Fonction principale
int main() {

    // Menu
    int choix = 0;
    printf(" ____  _                                        _ \n");
    printf("| __ )(_) ___ _ ____   _____ _ __  _   _  ___  | |\n");
    printf("|  _ \\| |/ _ \\ '_ \\ \\ / / _ \\ '_ \\| | | |/ _ \\ | |\n");
    printf("| |_) | |  __/ | | \\ V /  __/ | | | |_| |  __/ |_|\n");
    printf("|____/|_|\\___|_| |_|\\_/ \\___|_| |_|\\__,_|\\___| (_)\n\n");                                               

    printf("Bonjour ! Bienvenue dans l'annuaire des annees 2000 !\n");
    printf("Vous pouvez ajouter, modifier, supprimer, rechercher et sauvegarder des contacts.\n");
    printf("Vous pouvez aussi charger une liste de contacts depuis un fichier texte.\n\n");
    while (1) {
        printf("\n[============================================]\n");
        printf("                MENU PRINCIPAL                \n");
        printf("[============================================]\n\n");
        printf("1. Ajouter un contact dans l'annuaire\n");
        printf("2. Afficher l'annuaire\n");
        printf("3. Modifier un contact\n");
        printf("4. Supprimer un contact\n");
        printf("5. Rechercher un contact\n");
        printf("6. Sauvegarder dans un fichier et l'ouvrir\n");
        printf("7. Charger l'annuaire depuis le fichier texte\n");
        printf("8. Vider l'annuaire\n");
        printf("9. Ne pas choisir\n");
        printf("10. Sortir\n");
        printf("\n[============================================]\n");
        printf("\nEntrer votre choix : ");
        scanf("%d", &choix);

    // Switch case pour les choix
    switch (choix) {
    case 1:
        printf("Choix : Ajout d'une personne\n\n");
        AjouterPersonne();
        Sauvegarder();
        break;
    case 2:
        printf("Choix : Affichage de l'annuaire\n\n");
        Afficher();
        Sauvegarder();
        break;
    case 3:
        printf("Choix : Modification d'une personne\n\n");
        Afficher();
        ModifierPersonne();
        Sauvegarder();
        break;
    case 4:
        printf("Choix : Suppression d'une personne\n\n");
        printf("Voici toutes les personnes de l'annuaire :\n");
        Afficher();
        printf("\n");
        SupprimerPersonne();
        Sauvegarder();
        break;
    case 5:
        printf("Choix : Recherche d'une personne\n\n");
        RechercherPersonne();
        Sauvegarder();
        break;
    case 6:
        printf("Choix : Sauvegarde de l'annuaire\n\n");
        Sauvegarder();
        // On ouvre le fichier avec le bloc note
        system("notepad annuaire.txt");
        break;
    case 7:
        printf("Choix : Chargement de l'annuaire\n\n");
        Charger();
        break;
    case 8:
        printf("Choix : Vider l'annuaire\n\n");
        Vider();
        break;
    case 9:
        printf("\n\nQuestion de culture generale !\n");
        char reponse[6];
        printf("\nVrai ou Faux : Le langage de programmation C est un langage de programmation oriente objet.\n");
        scanf("%s", reponse);
        if (strcmp(reponse, "Faux") == 0) {
            system("start https://www.youtube.com/watch?v=p7YXXieghto");
        }
        else {
            printf("Eh non ... !\n\n\n");
            break;
        }
    case 10:
        printf("Bye !\n");
        exit(0);
        break;
    default:
        printf("Choix inccorect\n");
    }
  }

  return 0;
}