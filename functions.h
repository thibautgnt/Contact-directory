#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

// Structure de l'annuaire
struct Personne {
    char prenom[20];
    char nom[20];
    char email[30];
    struct Personne *prev;
    struct Personne *next;
};

void AjouterPersonne(); // Fonction d'ajout d'un contact
void Afficher(); // Fonction d'affichage de l'annuaire
void ModifierPersonne(); // Fonction de modification d'un contact
void SupprimerPersonne(); // Fonction de suppression d'un contact
void RechercherPersonne(); // Fonction de recherche d'un contact
void Sauvegarder(); // Fonction de sauvegarde de la liste entière dans un fichier txt
void Charger(); // Fonction de chargement de la liste entière depuis un fichier txt
void Vider(); //Fonction de vider la liste

#endif