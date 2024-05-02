#include <stdio.h>
#include "menu.h"
#include "car_operations.h"
#include "globals.h"

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
    printf("6. Loan Menu:\n");
    printf("\t a. Display Loan List\n");
    printf("\t b. Update Loan List\n");
    printf("\t c. Retourner au menu principal\n");
    printf("7. Sell Cars Exceeding Threshold (80 000)\n");
    printf("8. Insurrance Payement \n");
    printf("9. Loan Payment \n");
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


void deleteMenu() {
    char deleteChoice;
                printf("Choisissez l'option de suppression :\n");
                printf("a. Supprimer par ID\n");
                printf("b. Supprimer la dernière voiture\n");
                printf("c. Retourner au menu principal\n");
                scanf(" %c", &deleteChoice);
                switch (deleteChoice) {
                    case 'a':
                        int id;
                        printf("Veuillez entrer l'ID a supprimer :");
                        scanf("%d",&id);
                        DeleteByID("carlist.csv", id);
                        break;
                    case 'b':
                        // Delete the last car
                        DeleteLastCar("carlist.csv");
                        break;
                    case 'c':
                        // Return to main menu
                        break;
                    default:
                        printf("Choix invalide.\n");
                }
}





void sortMenu() {
    printf("\n------ Trier les Voitures ------\n"); 
    printf("1. Trier par Marque\n");
    printf("2. Trier par Prix de Location\n");
    printf("3. Retourner au menu principal\n");
    printf("------------------------------------------------\n");
    char searchChoice;
    scanf(" %c", &searchChoice);
    switch (searchChoice) {
                    case 'a':
                        sortByBrand("carlist.csv");
                        break;
                    case 'b':
                        sortByRentalPrice("carlist.csv");
                        break;
                    case 'c':
                        printf("Returning to menu principal...\n");
                        break;
                    default:
                        printf("Choix invalide.\n");
                }  
}


void LoanMenu() {
    printf("\n------ Loan Menu ------\n"); 
    printf("1. Display Loan List\n");
    printf("2. Update all Loan List\n");
    printf("3. Main menu\n");
    printf("------------------------------------------------\n");
    char searchChoice;
    scanf(" %c", &searchChoice);
    switch (searchChoice) {
                    case 'a':
                        DisplayFileContents("cars_on_loan.csv");
                        break;
                    case 'b':
                        ProcessLoanDetails("carlist.csv");
                        break;
                    case 'c':
                        printf("Returning to Main menu...\n");
                        break;
                    default:
                        printf("Choix invalide.\n");
                }  
}