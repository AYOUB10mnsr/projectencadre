#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure Voiture
typedef struct Voiture {
    char marque[50];
    char modele[50];
    int annee;
    float prixlocationparjour;
    char carburant[20];
    int nombrdeplaces;
    char disponibilite[20];
    int id;
    char nomdutilisateur[50];
    char transmission[20];
} voiture;

// ~~~~~~~~~~~~~~~~~~~~~~Fonction pour afficher le menu du programme~~~~~~~~~~~~~~~~~~~~~~
void menu(void) {
         printf("╔════════════════════════════╗\n");
         printf("║    GESTION DES VOITURES    ║\n");
         printf("╚════════════════════════════╝\n");
    printf("**************************************************\n");
         printf("╭──────────────────────────────────╮\n");
         printf("│          Menu Principal          │\n");
         printf("╰──────────────────────────────────╯\n");
         printf("entrez votre choix\n");
         printf("1- ➕ Ajouter une voiture\n");
         printf("2- ➖ Supprimer une voiture\n");
         printf("3- ✏ Modifier une voiture\n");
         printf("4- 📋 Afficher la liste des voitures\n");
         printf("5- 🔍 Rechercher une voiture par indice\n");
         printf("6- 🔀 Trier les voitures\n");
         printf("0- ❌ Quitter le programme\n");

     printf("**************************************************\n");
}

// ~~~~~~~~~~~~~~~~~~~~~~Fonction pour ajouter une voiture~~~~~~~~~~~~~~~~~~~~~~~~
void ajouter(voiture *voit, int n) {
    FILE *fichier = fopen("voitures.csv", "a"); // Ouvrir le fichier en mode ajout

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        // Demander et enregistrer les informations de la voiture
        printf("Entrez la marque de la voiture : ");
        scanf("%s", voit[i].marque);
        fprintf(fichier, "%s\n", voit[i].marque);
        
        printf("Entrez le modèle de la voiture : ");
        scanf("%s", voit[i].modele);
        fprintf(fichier, "%s\n", voit[i].modele);

        printf("Entrez l'année de la voiture : ");
        scanf("%d", &voit[i].annee);
        fprintf(fichier, "%d\n", voit[i].annee);

        printf("Entrez le prix de location par jour : ");
        scanf("%f", &voit[i].prixlocationparjour);
        fprintf(fichier, "%.2f\n", voit[i].prixlocationparjour);

        printf("Entrez le type de carburant : ");
        scanf("%s", voit[i].carburant);
        fprintf(fichier, "%s\n", voit[i].carburant);

        printf("Entrez le nombre de places : ");
        scanf("%d", &voit[i].nombrdeplaces);
        fprintf(fichier, "%d\n", voit[i].nombrdeplaces);

        printf("Entrez la disponibilite : ");
        scanf("%s", voit[i].disponibilite);
        fprintf(fichier, "%s\n", voit[i].disponibilite);

        printf("Entrez l'ID : ");
        scanf("%d", &voit[i].id);
        fprintf(fichier, "%d\n", voit[i].id);

        printf("Entrez le nom de l'utilisateur : ");
        scanf("%s", voit[i].nomdutilisateur);
        fprintf(fichier, "%s\n", voit[i].nomdutilisateur);

        printf("Entrez la transmission : ");
        scanf("%s", voit[i].transmission);
        fprintf(fichier, "%s\n", voit[i].transmission);
    }

    fclose(fichier); // Fermer le fichier
}
// ~~~~~~~~~~~~~~~~~~~~~~ fin de Fonction pour ajouter une voiture~~~~~~~~~~~~~~~~~~~~~~~~

// ~~~~~~~~~~~~~~~~~~~~~~Fonction pour afficher la liste des voitures~~~~~~~~~~~~~~~~~~~~~~
void afficherListe(voiture *voit, int n) {
    printf("Liste des voitures :\n");
    for (int i = 0; i < n; i++) {
        // Afficher les informations de chaque voiture
        printf("Voiture %d :\n", i+1);
        printf("Marque : %s\n", voit[i].marque);
        printf("Modèle : %s\n", voit[i].modele);
        printf("Année : %d\n", voit[i].annee);
        printf("Prix de location par jour : %.2f\n", voit[i].prixlocationparjour);
        printf("Carburant : %s\n", voit[i].carburant);
        printf("Nombre de places : %d\n", voit[i].nombrdeplaces);
        printf("Disponibilité : %s\n", voit[i].disponibilite);
        printf("ID : %d\n", voit[i].id);
        printf("Nom de l'utilisateur : %s\n", voit[i].nomdutilisateur);
        printf("Transmission : %s\n", voit[i].transmission);
        printf("\n");
    }
}
// ~~~~~~~~~~~~~~~~~~~~~~fin de Fonction pour afficher la liste des voitures~~~~~~~~~~~~~~~~~~~~~~

// ~~~~~~~~~~~~~~~~~~~~~~Fonction pour supprimer une voiture~~~~~~~~~~~~~~~~~~~~~~
// Fonction pour supprimer une voiture par son ID
void supprimer(voiture *voit, int *n, int id) {
    int indice = -1;
    for (int i = 0; i < *n; i++) {
        if (voit[i].id == id) {
            indice = i;
            break;
        }
    }
    if (indice != -1) {
        for (int i = indice; i < *n - 1; i++) {
            voit[i] = voit[i + 1];
        }
        (*n)--;
        printf("Voiture supprimée avec succès.\n");
    } else {
        printf("Voiture non trouvée.\n");
    }
}


// ~~~~~~~~~~~~~~~~~~~~~~ fin de Fonction pour supprimer une voiture~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~ Fonction pour modifier les informations d'une voiture~~~~~~~~~~~~~~~~~~~~~~
void modifier(voiture *voit, int n, int id) {
    int trouve = 0;
    for (int i = 0; i < n; i++) {
        if (voit[i].id == id) {
            printf("Entrez la nouvelle marque de la voiture : ");
            scanf("%s", voit[i].marque);

            printf("Entrez le nouveau modèle de la voiture : ");
            scanf("%s", voit[i].modele);

            printf("Entrez la nouvelle année de la voiture : ");
            scanf("%d", &voit[i].annee);

            printf("Entrez le nouveau prix de location par jour : ");
            scanf("%f", &voit[i].prixlocationparjour);

            printf("Entrez le nouveau type de carburant : ");
            scanf("%s", voit[i].carburant);

            printf("Entrez le nouveau nombre de places : ");
            scanf("%d", &voit[i].nombrdeplaces);

            printf("Entrez la nouvelle disponibilite : ");
            scanf("%s", voit[i].disponibilite);

            printf("Entrez le nouvel ID : ");
            scanf("%d", &voit[i].id);

            printf("Entrez le nouveau nom de l'utilisateur : ");
            scanf("%s", voit[i].nomdutilisateur);

            printf("Entrez la nouvelle transmission : ");
            scanf("%s", voit[i].transmission);

            trouve = 1;
            printf("Voiture modifiée avec succès.\n");
            break;
        }
    }
    if (!trouve) {
        printf("Voiture non trouvée.\n");
    }
}

//~~~~~~~~~~~~~~~~~~~~~~fin de Fonction pour modifier les informations d'une voiture~~~~~~~~~~~~~~~~~~~~~~

// ~~~~~~~~~~~~~~~~~~~~~~Fonction pour rechercher une voiture par son indice~~~~~~~~~~~~~~~~~~~~~~
// Fonction pour rechercher une voiture par son ID
   void rechercherParID(voiture *voit, int n, int id) {
    int trouve = 0;
    for (int i = 0; i < n; i++) {
        if (voit[i].id == id) {
            printf("Voiture trouvée :\n");
            printf("Marque : %s\n", voit[i].marque);
            printf("Modèle : %s\n", voit[i].modele);
            printf("Année : %d\n", voit[i].annee);
            printf("Prix de location par jour : %.2f\n", voit[i].prixlocationparjour);
            printf("Carburant : %s\n", voit[i].carburant);
            printf("Nombre de places : %d\n", voit[i].nombrdeplaces);
            printf("Disponibilité : %s\n", voit[i].disponibilite);
            printf("ID : %d\n", voit[i].id);
            printf("Nom de l'utilisateur : %s\n", voit[i].nomdutilisateur);
            printf("Transmission : %s\n", voit[i].transmission);
            trouve = 1;
            break;
        }
    }
    if (!trouve) {
        printf("╔═══════════════════════════════════════════╗\n");
       printf("║        Erreur : Voiture non trouvée       ║\n");
       printf("╚═══════════════════════════════════════════╝\n");

        return;
    }
}
// ~~~~~~~~~~~~~~~~~~~~~~fin de Fonction pour rechercher des voitures par marque et disponibilité~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~ Fonction pour trier les voitures par marque puis par prix de location~~~~~~~~~~~~~~~~~~~~~~
void trierParMarquePrixLocation(voiture *voit, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Trie d'abord par marque
            if (strcmp(voit[j].marque, voit[j + 1].marque) > 0) {
                // Échange des éléments
                voiture temp = voit[j];
                voit[j] = voit[j + 1];
                voit[j + 1] = temp;
            }
            // Si les marques sont les mêmes, trie par prix de location par jour
            else if (strcmp(voit[j].marque, voit[j + 1].marque) == 0 && voit[j].prixlocationparjour > voit[j + 1].prixlocationparjour) {
                // Échange des éléments
                voiture temp = voit[j];
                voit[j] = voit[j + 1];
                voit[j + 1] = temp;
            }
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~fin de Fonction pour trier les voitures par marque puis par prix de location~~~~~~~~~~~~~~~~~~~~~~
int main() {
    int choix, N;
    char nomUtilisateur[50];
    voiture *voitures = malloc(sizeof(voiture) * 100); // Allouer de la mémoire pour le tableau de voitures
    printf("  W   W  EEEEE  L      CCCC  OOO  M   M  EEEEE\n");
    printf("  W   W  E      L     C     O   O MM MM  E    \n");
    printf("  W W W  EEE    L     C     O   O M M M  EEE  \n");
    printf("  W W W  E      L     C     O   O M   M  E    \n");
    printf("   W W   EEEEE  LLLLL  CCCC  OOO  M   M  EEEEE\n");
     printf("Bienvenue dans l'application de gestion des voitures.\n");
    printf("Veuillez saisir votre nom : ");
    scanf("%s", nomUtilisateur);
    menu(); // Afficher le menu du programme
    printf("Donnez votre choix : ");
    scanf("%d", &choix);

    // Boucle principale du programme
    while (choix != 0) {
        switch (choix) {
            case 1:
                printf("Entrez le nombre de voitures à ajouter : ");
                scanf("%d", &N);
                ajouter(voitures, N); // Appeler la fonction pour ajouter des voitures
                break;
            case 2: {
                int id_supprimer;
                printf("Entrez l'ID de la voiture à supprimer : ");
                scanf("%d", &id_supprimer);
                supprimer(voitures, &N, id_supprimer);
                break;
            }
            case 3: {
                int id_modifier;
                printf("Entrez l'ID de la voiture à modifier : ");
                scanf("%d", &id_modifier);
                modifier(voitures, N, id_modifier);
                break;
            }
            case 4:
                afficherListe(voitures, N); // Appeler la fonction pour afficher la liste des voitures
                break;
            case 5: {
                int id_rechercher;
                printf("Entrez l'ID de la voiture à rechercher : ");
                scanf("%d", &id_rechercher);
                rechercherParID(voitures, N, id_rechercher);
                 break;
            }
            case 6:
                 trierParMarquePrixLocation(voitures, N); // Appeler la fonction pour trier les voitures
                 afficherListe(voitures, N); // Afficher la liste triée des voitures
                break;
            default:
                printf("Choix invalide.\n");
        }

        menu(); // Afficher à nouveau le menu
        printf("Donnez votre choix : ");
        scanf("%d", &choix);
    }

    free(voitures); // Libérer la mémoire allouée pour le tableau de voitures

    return 0;
}
