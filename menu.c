#include <stdio.h>
#include "menu.h"

void displayMenu() {
    printf("\n------ Gestion de la Location de Voitures ------\n");
    printf("1. Ajouter\n");
    printf("2. Modifier\n");
    printf("3. Supprimer\n");
    printf("\t a. Supprimer par ID\n");
    printf("\t b. Supprimer la dernière voiture\n");
    printf("\t c. Retourner au menu principal\n");
    printf("4. Afficher la liste\n");
    printf("\t a. Afficher par Marque\n");
    printf("\t b. Afficher par Disponibilité\n");
    printf("\t c. Afficher par Type de Carburant\n");
    printf("\t d. Afficher tout le fichier\n");
    printf("\t e. Retourner au menu principal\n");
    printf("5. Trier les voitures\n");
    printf("\t a.Trier par Marque\n");
    printf("\t b. Trier par Prix de Location\n");
    printf("\t c. Retourner au menu principal\n");
    printf("0. Quitter\n");
    printf("------------------------------------------------\n");
}

void displayMenu2() {
   char displayChoice;
                printf("Choisissez l'option d'affichage :\n");
                printf("a. Afficher par Marque\n");
                printf("b. Afficher par Disponibilité\n");
                printf("c. Afficher par Type de Carburant\n");
                printf("d. Afficher tout le fichier\n");
                printf("e. Retourner au menu principal\n");
                scanf(" %c", &displayChoice);
                switch (displayChoice) {
                    case 'a':
                        // Display cars by brand
                        DisplayCarsByMark("carlist.csv");
                        break;
                    case 'b':
                        // Display cars by availability
                        DisplayCarsByAvailability("carlist.csv");
                        break;
                    case 'c':
                        // Display cars by fuel type
                        DisplayCarsByFuelType("carlist.csv");
                        break;
                    case 'd':
                        // Display entire file
                        DisplayFileContents("carlist.csv");
                        break;
                    case 'e':
                        // Return to main menu
                        break;
                    default:
                        printf("Choix invalide.\n");
                }
}

void searchMenu() {
    int searchID;
                char searchBrand[50];
                printf("Choisissez le critère de recherche :\n");
                printf("a. Rechercher par ID\n");
                printf("b. Rechercher par Marque\n");
                printf("c. Retourner au menu principal\n");
                char searchChoice;
                scanf(" %c", &searchChoice);
                switch (searchChoice) {
                    case 'a':

                        break;
                    case 'b':

                        break;
                    case 'c':
                        // Return to main menu
                        break;
                    default:
                        printf("Choix invalide.\n");
                }
}