#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure  stocker les informations 
struct Car {
    int id;
    char brand[50];
    char username[50];
    char model[50];
    char fuelType[20];
    int numSeats;
    char transmission[20];
    float rentalPrice;
    int availability; //1->dispo   0->non dispo
};

// Fonction  menu
void displayMenu() {
    printf("\n------ Gestion de la Location de Voitures ------\n");
    printf("1. Ajouter \n");
    printf("2. Modifier \n");
    printf("3. Supprimer \n");
    printf("4. Afficher la liste\n");
    printf("5. Rechercher\n");
    printf("6. Trier les voitures\n");
    printf("0. Quitter\n");
    printf("------------------------------------------------\n");
}

// Fonction ajouter 
void addCar(struct Car *cars, int *carCount) {

}

// Fonction modifier 
void modifyCar(struct Car *cars, int carCount) {
    
}

// Fonction supprimer 
void deleteCar(struct Car *cars, int *carCount) {
    
}

// Fonction afficher la liste
void displayCars(struct Car *cars, int carCount) {
    
}

// Fonction rechercher par marque / disponibilité
void searchCars(struct Car *cars, int carCount) {
    // Code rechercher
}

// Fonction trier  par marque / prix de location par jour
void sortCars(struct Car *cars, int carCount) {
    
}

int main() {
    int carCount = 0;
    int choice;

    printf("Veuillez entrez le numero de voitures pour initialiser le programme: \n");
    scanf("%d", &carCount);

    struct Car cars[carCount]; 

    do {
        displayMenu();
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar(cars, &carCount);
                break;
            case 2:
                modifyCar(cars, carCount);
                break;
            case 3:
                deleteCar(cars, &carCount);
                break;
            case 4:
                displayCars(cars, carCount);
                break;
            case 5:
                searchCars(cars, carCount);
                break;
            case 6:
                sortCars(cars, carCount);
                break;
            case 0:
                printf("Merci d'avoir utilisé l'application. Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un choix valide.\n");
        }
    } while (choice != 0);

    return 0;
}