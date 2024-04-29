#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void menu(void) {
    printf("******************\n");
    printf("entrez votre choix\n");
    printf("1- ajouter une voiture\n");
    printf("2- supprimer une voiture\n");
    printf("3- modifier une voiture\n");
    printf("4- afficher la liste des voitures\n");
    printf("5- rechercher une voiture par indice\n");
    printf("6- trier les voitures\n");
    printf("0- quitter le programme\n");
    printf("******************\n");
}

void ajouter(voiture *voit, int n) {
    FILE *fichier = fopen("voitures.txt", "a"); // Ouvrir le fichier en mode ajout

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
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

void afficherListe(voiture *voit, int n) {
    printf("Liste des voitures :\n");
    for (int i = 0; i < n; i++) {
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

void supprimer(voiture *voit, int *n, int indice) {
    if (indice < 0 || indice >= *n) {
        printf("Indice invalide.\n");
        return;
    }

    for (int i = indice; i < *n - 1; i++) {
        voit[i] = voit[i + 1];
    }

    (*n)--;
}

void modifier(voiture *voit, int n, int indice) {
    if (indice < 0 || indice >= n) {
        printf("Indice invalide.\n");
        return;
    }

    printf("Entrez la nouvelle marque de la voiture : ");
    scanf("%s", voit[indice].marque);

    printf("Entrez le nouveau modèle de la voiture : ");
    scanf("%s", voit[indice].modele);

    printf("Entrez la nouvelle année de la voiture : ");
    scanf("%d", &voit[indice].annee);

    printf("Entrez le nouveau prix de location par jour : ");
    scanf("%f", &voit[indice].prixlocationparjour);

    printf("Entrez le nouveau type de carburant : ");
    scanf("%s", voit[indice].carburant);

    printf("Entrez le nouveau nombre de places : ");
    scanf("%d", &voit[indice].nombrdeplaces);

    printf("Entrez la nouvelle disponibilite : ");
    scanf("%s", voit[indice].disponibilite);

    printf("Entrez le nouvel ID : ");
    scanf("%d", &voit[indice].id);

    printf("Entrez le nouveau nom de l'utilisateur : ");
    scanf("%s", voit[indice].nomdutilisateur);

    printf("Entrez la nouvelle transmission : ");
    scanf("%s", voit[indice].transmission);
}

void rechercherParIndice(voiture *voit, int n, int indice) {
    if (indice < 0 || indice >= n) {
        printf("Indice invalide.\n");
        return;
    }

    printf("Voiture %d :\n", indice + 1);
    printf("Marque : %s\n", voit[indice].marque);
    printf("Modèle : %s\n", voit[indice].modele);
    printf("Année : %d\n", voit[indice].annee);
    printf("Prix de location par jour : %.2f\n", voit[indice].prixlocationparjour);
    printf("Carburant : %s\n", voit[indice].carburant);
    printf("Nombre de places : %d\n", voit[indice].nombrdeplaces);
    printf("Disponibilité : %s\n", voit[indice].disponibilite);
    printf("ID : %d\n", voit[indice].id);
    printf("Nom de l'utilisateur : %s\n", voit[indice].nomdutilisateur);
    printf("Transmission : %s\n", voit[indice].transmission);
}


int comparePrix(const void *a, const void *b) {
    const voiture *voitA = (const voiture *)a;
    const voiture *voitB = (const voiture *)b;
    return (voitA->prixlocationparjour > voitB->prixlocationparjour) - (voitA->prixlocationparjour < voitB->prixlocationparjour);
}

int compareAnnee(const void *a, const void *b) {
    const voiture *voitA = (const voiture *)a;
    const voiture *voitB = (const voiture *)b;
    return (voitA->annee > voitB->annee) - (voitA->annee < voitB->annee);
}

void trier(voiture *voit, int n, int critere) {
    switch (critere) {
        case 1:
            qsort(voit, n, sizeof(voiture), comparePrix);
            printf("Voitures triées par prix de location par jour.\n");
            break;
        case 2:
            qsort(voit, n, sizeof(voiture), compareAnnee);
            printf("Voitures triées par année de fabrication.\n");
            break;
        default:
            printf("Option de tri invalide.\n");
    }
}

int main() {
    int choix, N;
    voiture *voitures = malloc(sizeof(voiture) * 100);

    menu();
    printf("Donnez votre choix : ");
    scanf("%d", &choix);

    while (choix != 0) {
        switch (choix) {
            case 1:
                printf("Entrez le nombre de voitures à ajouter : ");
                scanf("%d", &N);
                ajouter(voitures, N);
                break;
            case 2: {
                int indice;
                printf("Entrez l'indice de la voiture à supprimer : ");
                scanf("%d", &indice);
                supprimer(voitures, &N, indice);
                break;
            }
            case 3: {
                int indice;
                printf("Entrez l'indice de la voiture à modifier : ");
                scanf("%d", &indice);
                modifier(voitures, N, indice);
                break;
            }
            case 4:
                afficherListe(voitures, N);
                break;
            case 5: {
                int indice;
                printf("Entrez l'indice de la voiture à rechercher : ");
                scanf("%d", &indice);
                rechercherParIndice(voitures, N, indice);
                break;
            }
            case 6:
                trier(voitures, N);
                break;
            default:
                printf("Choix invalide.\n");
        }

        menu();
        printf("Donnez votre choix : ");
        scanf("%d", &choix);
    }

    free(voitures); 

    return 0;
}