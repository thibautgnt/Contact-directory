#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


struct Personne *tete = NULL;  // Pointeur de tête
struct Personne *queue = NULL; // Pointeur de queue

void AjouterPersonne() {
    struct Personne *newPersonne =
        (struct Personne *)malloc(sizeof(struct Personne));
    printf("Entrer le prenom : ");
    scanf("%s", newPersonne->prenom);
    printf("Entrer le nom de famille : ");
    scanf("%s", newPersonne->nom);
    printf("Entrer email : ");
    scanf("%s", newPersonne->email);

    newPersonne->prev = NULL; // On initialise les pointeurs à NULL
    newPersonne->next = NULL;

  // On ajoute la personne à la fin de la liste
    if (tete == NULL) {
        tete = newPersonne;
        queue = newPersonne;
    }
    else {
        queue->next = newPersonne;
        newPersonne->prev = queue;
        queue = newPersonne;
    }
}

void Afficher() {
    struct Personne *current = tete;
    printf("\n                  ANNUAIRE                  \n");
    printf("____________________________________________\n\n");
    // On parcourt la liste et on affiche chaque personne
    while (current != NULL) {
        printf("%s - %s - %s\n", current->prenom, current->nom, current->email);
        current = current->next;
    }
    //Si l'annuaire est vide, on affiche un message
    if (tete == NULL) {
        printf("L'annuaire est vide.\n");
    }
  printf("____________________________________________\n\n");
}


void ModifierPersonne() {
    char prenom[20];
    char nom[20];
    printf("ENtrer le prenom de la personne a modifier : ");
    scanf("%s", prenom);
    printf("Entrer le nom de famille de la personne a modifier : ");
    scanf("%s", nom);

    // On parcourt la liste et on modifie les informations de la personne
    struct Personne *current = tete;
    while (current != NULL) {
        if (strcmp(current->prenom, prenom) == 0 &&
            strcmp(current->nom, nom) == 0) {
        printf("Entrer le nouveau prenom : ");
        scanf("%s", current->prenom);
        printf("Entrer le nouveau nom : ");
        scanf("%s", current->nom);
        printf("Entrer le nouvel email : ");
        scanf("%s", current->email);
        printf("Personne modifiée !\n");
        return;
        }
        current = current->next; // On passe à la personne suivante
    }
    printf("Personne introuvable\n");
}


void SupprimerPersonne() {
    char prenom[20];
    char nom[20];
    printf("\nQui voulez-vous supprimer ?");
    printf("\nEntrer le prenom de la personne a supprimer : ");
    scanf("%s", prenom);
    printf("Entrer le nom de famille de la Personne a supprimer: ");
    scanf("%s", nom);

    // On parcourt la liste et on supprime la personne
    struct Personne *current = tete;
    while (current != NULL) {
        if (strcmp(current->prenom, prenom) == 0 &&
            strcmp(current->nom, nom) == 0) {
        if (current == tete) {
            tete = current->next;
            if (tete != NULL) {
            tete->prev = NULL;
            } else {
            queue = NULL;
            }
        } else if (current == queue) {
            queue = current->prev;
            queue->next = NULL;
        } else {
            current->prev->next =
                current->next; // On relie les deux personnes adjacentes
            current->next->prev = current->prev;
        }
        free(current);
        printf("Personne supprimee !\n");
        return;
        }
        current = current->next; // On passe à la personne suivante
    }
    printf("Personne introuvable\n");
}


void RechercherPersonne() {
    char prenom[20];
    char nom[20];
    printf("Entrer le prenom de la personne a rechercher : ");
    scanf("%s", prenom);
    printf("Entrer le nom de famille de la personne a rechercher : ");
    scanf("%s", nom);

    // On parcourt la liste et on affiche les informations de la personne
    struct Personne *current = tete;
    while (current != NULL) {
        if (strcmp(current->prenom, prenom) == 0 &&
            strcmp(current->nom, nom) == 0) {
        printf("\nPersonne trouvee !\n");
        printf("Prenom : %s - Nom : %s - Email : %s \n\n", current->prenom,
               current->nom, current->email); // On affiche les informations
        return;
        }
        current = current->next; // On passe à la personne suivante
    }
    printf("Personne introuvable\n");
}


void Sauvegarder() {
    FILE *fichier = fopen("annuaire.txt", "w");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }
    // On parcourt la liste et on sauvegarde chaque personne
    struct Personne *current = tete;
    while (current != NULL) {
        fprintf(fichier, "%s - %s - %s\n", current->prenom, current->nom,
                current->email);
        current = current->next;
    }
    fclose(fichier);
    printf("\nListe sauvegardee dans le fichier annuaire.txt !\n\n");
}


void Charger() {
    // On demande le nom du fichier à charger
    char FileToOpen[20];
    printf("Entrer le nom du fichier a charger (test.txt pour l'exemple) : ");
    scanf("%s", FileToOpen);

    // On ouvre le fichier
    FILE *fichier = fopen(FileToOpen, "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }
    char prenom[20];
    char nom[20];
    char email[30];
    // On parcourt le fichier et on ajoute chaque personne à la liste
    while (fscanf(fichier, "%s - %s - %s ", prenom, nom, email) != EOF) {
        struct Personne *newPersonne =
            (struct Personne *)malloc(sizeof(struct Personne));
        strcpy(newPersonne->prenom, prenom);
        strcpy(newPersonne->nom, nom);
        strcpy(newPersonne->email, email);
        newPersonne->prev = NULL;
        newPersonne->next = NULL;

        // On ajoute la personne à la fin de la liste
        if (tete == NULL) {
        tete = newPersonne;
        queue = newPersonne;
        } else {
        queue->next = newPersonne;
        newPersonne->prev = queue;
        queue = newPersonne;
        }
    }
    fclose(fichier);
    printf("\nListe chargee depuis le fichier %s !\n\n", FileToOpen);
}


void Vider() {
    struct Personne *current = tete;
    while (current != NULL) {
        struct Personne *next = current->next;
        free(current);
        current = next;
    }
    tete = NULL;
    queue = NULL;
    printf("\nListe videe !\n\n");
}
