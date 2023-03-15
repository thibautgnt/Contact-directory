// Projet - Programmation en C - B1 CEH CS1
// Par Thibaut GENET, tous droits réservés (c) 2023
// Annuaire sous forme de liste double-chainée

// Bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure de l'annuaire
struct Personne {
    char prenom[20];
    char nom[20];
    char email[30];
    struct Personne *prev;
    struct Personne *next;
};

struct Personne *tete = NULL;  // Pointeur de tête
struct Personne *queue = NULL; // Pointeur de queue

// Fonction d'ajout d'un contact
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

// Fonction d'affichage de l'annuaire
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

// Fonction de modification d'un contact
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

// Fonction de suppression d'un contact
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

// Fonction de recherche d'un contact
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

// Fonction de sauvegarde de la liste entière dans un fichier txt
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

// Fonction de chargement de la liste entière depuis un fichier txt
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

//Fonction de vider la liste
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