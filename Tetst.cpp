#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1000





typedef struct Car{
    int id;
    char brand[50];
    char username[50];
    char model[50];
    char fuelType[20];
    int numSeats;
    char transmission[20];
    float rentalPrice;
    int availability; //1->dispo   0->non dispo
} Car;




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

void Addcar(const char *filename) {
    Car newCar;
      printf("Enter Car ID: ");
    scanf("%d", &newCar.id);

    printf("Enter Brand: ");
    scanf("%s", newCar.brand);

    printf("Enter Username: ");
    scanf("%s", newCar.username);

    printf("Enter Model: ");
    scanf("%s", newCar.model);

    printf("Enter Fuel Type: ");
    scanf("%s", newCar.fuelType);

    printf("Enter Number of Seats: ");
    scanf("%d", &newCar.numSeats);

    printf("Enter Transmission Type: ");
    scanf("%s", newCar.transmission);

    printf("Enter Rental Price: ");
    scanf("%f", &newCar.rentalPrice);

    printf("Enter Availability (1->dispo, 0->non dispo): ");
    scanf("%d", &newCar.availability);

    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

     fprintf(file, "%d;%s;%s;%s;%s;%d;%s;%.2f;%d\n",
            newCar.id, newCar.brand, newCar.username, newCar.model,
            newCar.fuelType, newCar.numSeats, newCar.transmission,
            newCar.rentalPrice, newCar.availability);


    fclose(file);
}




// Function to delete the first car from the list
void DeleteFirstCar(const char *filename) {
    FILE *file = fopen(filename, "r"); // Open the file in read mode
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Create a temporary file
    FILE *tempFile = fopen("temp.csv", "w");
    if (tempFile == NULL) {
        fclose(file);
        printf("Error creating temporary file.\n");
        return;
    }

    char line[MAX_LINE];
    int lineNumber = 0;

    // Copy the header line to the temporary file
    if (fgets(line, sizeof(line), file) != NULL) {
        fputs(line, tempFile);
        lineNumber++;
    }

    // Copy all lines except the first one to the temporary file
    while (fgets(line, sizeof(line), file)) {
        if (lineNumber != 1) {
            fputs(line, tempFile);
        }
        lineNumber++;
    }

    fclose(file);
    fclose(tempFile);

    // Replace the original file with the temporary file
    remove(filename);
    rename("temp.csv", filename);
}



void ShowCarList(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[MAX_LINE];
    printf("Car List:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

int main(){
    int choice;
 do {
        displayMenu();
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Addcar("carlist.csv");
                break;
            case 2:

                break;
            case 3:
                 DeleteFirstCar("carlist.csv");
                break;
            case 4:
               ShowCarList("carlist.csv");
                break;
            case 5:

                break;
            case 6:

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
