#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "car_operations.h"

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

void ModifyCarInfo(const char *filename, int id) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    FILE *tempFile = fopen("temp.csv", "w");
    if (tempFile == NULL) {
        fclose(file);
        printf("Error creating temporary file.\n");
        return;
    }

    Car car;
    int modified = 0; // Flag to track if any modification occurred

    char line[256]; // Buffer to read each line from file
    int isFirstLine = 1; // Flag to track if it's the first line (header)

    // Read each line from the file
    while (fgets(line, sizeof(line), file) != NULL) {
        if (isFirstLine) {
            // Skip the first line (header)
            isFirstLine = 0;
            continue;
        }

        printf("Read line: %s", line); // Debugging output
        // Tokenize the line based on the ';' delimiter
        char *token = strtok(line, ";");    

        // Extract and convert each field to the corresponding Car structure field
        if (token != NULL) {
            car.id = atoi(token);
            token = strtok(NULL, ";");
            if (token != NULL) {
                strncpy(car.brand, token, sizeof(car.brand) - 1);
                car.brand[sizeof(car.brand) - 1] = '\0';
                token = strtok(NULL, ";");
            }
            if (token != NULL) {
                strncpy(car.username, token, sizeof(car.username) - 1);
                car.username[sizeof(car.username) - 1] = '\0';
                token = strtok(NULL, ";");
            }
            if (token != NULL) {
                strncpy(car.model, token, sizeof(car.model) - 1);
                car.model[sizeof(car.model) - 1] = '\0';
                token = strtok(NULL, ";");
            }
            if (token != NULL) {
                strncpy(car.fuelType, token, sizeof(car.fuelType) - 1);
                car.fuelType[sizeof(car.fuelType) - 1] = '\0';
                token = strtok(NULL, ";");
            }
            if (token != NULL) {
                car.numSeats = atoi(token);
                token = strtok(NULL, ";");
            }
            if (token != NULL) {
                strncpy(car.transmission, token, sizeof(car.transmission) - 1);
                car.transmission[sizeof(car.transmission) - 1] = '\0';
                token = strtok(NULL, ";");
            }
            if (token != NULL) {
                car.rentalPrice = atof(token);
                token = strtok(NULL, ";");
            }
            if (token != NULL) {
                car.availability = atoi(token);
            }

            // Check if car ID matches the specified ID for modification
            if (car.id == id) {
                modified = 1; // Set flag to indicate modification
                printf("Enter new car information:\n");
                clearInputBuffer();
                printf("Brand: ");
                fgets(car.brand, sizeof(car.brand), stdin);
                car.brand[strcspn(car.brand, "\n")] = '\0'; // Remove newline

                printf("Username: ");
                fgets(car.username, sizeof(car.username), stdin);
                car.username[strcspn(car.username, "\n")] = '\0'; // Remove newline

                printf("Model: ");
                fgets(car.model, sizeof(car.model), stdin);
                car.model[strcspn(car.model, "\n")] = '\0'; // Remove newline

                printf("Fuel type: ");
                fgets(car.fuelType, sizeof(car.fuelType), stdin);
                car.fuelType[strcspn(car.fuelType, "\n")] = '\0'; // Remove newline

                printf("Number of seats: ");
                scanf("%d", &car.numSeats);
                getchar(); // Consume newline left by scanf

                printf("Transmission: ");
                fgets(car.transmission, sizeof(car.transmission), stdin);
                car.transmission[strcspn(car.transmission, "\n")] = '\0'; // Remove newline

                printf("Rental price: ");
                scanf("%f", &car.rentalPrice);
                getchar(); // Consume newline left by scanf

                printf("Availability (1 for available, 0 for not available): ");
                scanf("%d", &car.availability);
                getchar(); // Consume newline left by scanf
            }
        }

        // Write the car (modified or not) to the temporary file
        fprintf(tempFile, "%d;%s;%s;%s;%s;%d;%s;%.2f;%d\n",
                car.id, car.brand, car.username, car.model, car.fuelType,
                car.numSeats, car.transmission, car.rentalPrice, car.availability);
    }

    fclose(file);
    fclose(tempFile);

    if (!modified) {
        printf("No car found with ID %d.\n", id);
        remove("temp.csv"); // Remove temporary file if no modification occurred
    } else {
        remove(filename); // Remove original file
        rename("temp.csv", filename); // Rename temporary file to original filename
        printf("Car with ID %d has been modified.\n", id);
    }
}



void DeleteFirstCar(const char *filename){
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

void DeleteByID(const char *filename, int id) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening main file.\n");
        return;
    }

    FILE *tempFile = fopen("temp.csv", "w");
    if (tempFile == NULL) {
        fclose(file);
        printf("Error creating temporary file.\n");
        return;
    }

    FILE *deletedFile = fopen("deleted_cars.csv", "a");
    if (deletedFile == NULL) {
        fclose(file);
        fclose(tempFile);
        printf("Error opening deleted cars file.\n");
        return;
    }

    char line[MAX_LINE];
    int found = 0;
    int isFirstLine = 1;
    char copiedLine[MAX_LINE];

    while (fgets(line, sizeof(line), file)) {
        printf("The line is : %s\n", line);
        if (isFirstLine) {
            // Skip the first line (header)
            isFirstLine = 0;
            continue;
        }
        printf("The line is : %s\n", line);
        strcpy(copiedLine, line);
        printf("The copied line is : %s\n", copiedLine);
        char *token = strtok(copiedLine, ";");
        int carID = atoi(token);

        if (carID == id) {
            // Write the line to the deleted cars file
            printf("The line to delete is : %s\n", line);
            fputs(line, deletedFile);
            found = 1;
        } else {
            // Write non-deleted lines to the temporary file
            printf("The line to keep is : %s\n", line);
            fputs(line, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);
    fclose(deletedFile);

    if (!found) {
        printf("Car with ID %d not found.\n", id);
        remove("temp.csv");
    } else {
        // Remove the original file and rename the temporary file
        remove(filename);
        rename("temp.csv", filename);
        printf("Car with ID %d moved to deleted cars list.\n", id);
    }
}

void DeleteLastCar(const char *filename) {
            FILE *file = fopen(filename, "r");
            if (file == NULL) {
                printf("Error opening file.\n");
                return;
            }

            FILE *tempFile = fopen("temp.csv", "w");
            if (tempFile == NULL) {
                fclose(file);
                printf("Error creating temporary file.\n");
                return;
            }

            FILE *deletedFile = fopen("deleted_cars.csv", "a"); // Open in append mode
            if (deletedFile == NULL) {
                fclose(file);
                fclose(tempFile);
                printf("Error opening deleted cars file.\n");
                return;
            }

            char line[MAX_LINE];
            char lastLine[MAX_LINE];
            lastLine[0] = '\0';

            while (fgets(line, sizeof(line), file)) {
                strcpy(lastLine, line);
                fputs(line, tempFile);
            }

            // Write the last line to the deleted cars file
            fputs(lastLine, deletedFile);

            fclose(file);
            fclose(tempFile);
            fclose(deletedFile);

            remove(filename);
            rename("temp.csv", filename);
        }


void DisplayFileContents(const char *filename) {
   FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Contents of %s:\n", filename);
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

void DisplayCarsByMark(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[MAX_LINE];
    printf("Enter the brand name you would like to search for: ");
    char searchBrand[50];
    scanf("%s", searchBrand);

    printf("Cars List based on Marque (%s):\n", searchBrand);
    int found = 0; // Flag to check if any cars with the given brand are found

    while (fgets(line, sizeof(line), file)) {
        // Extract car information from the line
        int id, numSeats, availability;
        char brand[50], username[50], model[50], fuelType[20], transmission[20];
        float rentalPrice;

        sscanf(line, "%d;%49[^;];%49[^;];%49[^;];%19[^;];%d;%19[^;];%f;%d\n",
               &id, brand, username, model, fuelType, &numSeats, transmission, &rentalPrice, &availability);

        // Check if the car meets the brand criteria
        if (strcmp(brand, searchBrand) == 0) {
            printf("ID: %d, Marque: %s, Username: %s, Model: %s, Type de Carburant: %s, Nombre de sièges: %d, Transmission: %s, Prix de location: %.2f, Disponibilité: %s\n",
                   id, brand, username, model, fuelType, numSeats, transmission, rentalPrice, (availability == 1) ? "Disponible" : "Non disponible");
            found = 1; // Set flag to indicate at least one car is found
        }
    }

    if (!found) {
        printf("No cars found with the brand: %s\n", searchBrand);
    }

    fclose(file);
}

void DisplayCarsByAvailability(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[MAX_LINE];
    printf("Cars List based on Disponibilité:\n");
    int searchAvailability;
    printf("Enter 1 for available cars or 0 for unavailable cars: ");
    scanf("%d", &searchAvailability);

    while (fgets(line, sizeof(line), file)) {
        // Extract car information from the line
        int id, numSeats, availability;
        char brand[50], username[50], model[50], fuelType[20], transmission[20];
        float rentalPrice;

        sscanf(line, "%d;%49[^;];%49[^;];%49[^;];%19[^;];%d;%19[^;];%f;%d\n",
               &id, brand, username, model, fuelType, &numSeats, transmission, &rentalPrice, &availability);

        // Check if the car meets the availability criteria
        if (availability == searchAvailability) {
            printf("ID: %d, Marque: %s, Disponibilité: %s\n",
                   id, brand, (availability == 1) ? "Disponible" : "Non disponible");
        }
    }

    fclose(file);
}

void DisplayCarsByFuelType(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[MAX_LINE];
    printf("Cars List based on Type de Carburant:\n");
    char searchFuelType[20];
    printf("Enter the fuel type you would like to search for: ");
    scanf("%s", searchFuelType);

    while (fgets(line, sizeof(line), file)) {
        // Extract car information from the line
        int id, numSeats, availability;
        char brand[50], username[50], model[50], fuelType[20], transmission[20];
        float rentalPrice;

        sscanf(line, "%d;%49[^;];%49[^;];%49[^;];%19[^;];%d;%19[^;];%f;%d\n",
               &id, brand, username, model, fuelType, &numSeats, transmission, &rentalPrice, &availability);

        // Check if the car meets the fuel type criteria
        if (strcmp(fuelType, searchFuelType) == 0) {
            printf("ID: %d, Marque: %s, Type de Carburant: %s\n",
                   id, brand, fuelType);
        }
    }

    fclose(file);
}

void ShowCarList(const char *filename) {
    // Function implementation
}


void swapCars(FILE *file, int index1, int index2) {
    // Seek to the positions of the two cars in the file
    fseek(file, index1 * sizeof(Car), SEEK_SET);
    Car car1;
    fread(&car1, sizeof(Car), 1, file);

    fseek(file, index2 * sizeof(Car), SEEK_SET);
    Car car2;
    fread(&car2, sizeof(Car), 1, file);

    // Swap the cars in the file
    fseek(file, index1 * sizeof(Car), SEEK_SET);
    fwrite(&car2, sizeof(Car), 1, file);

    fseek(file, index2 * sizeof(Car), SEEK_SET);
    fwrite(&car1, sizeof(Car), 1, file);
}


void sortByBrand(const char *filename) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Car currentCar, nextCar;
    int fileSize = 0;

    // Get the file size
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    rewind(file);

    int numCars = fileSize / sizeof(Car);

    for (int i = 0; i < numCars - 1; i++) {
        for (int j = 0; j < numCars - i - 1; j++) {
            // Read current and next cars
            fseek(file, j * sizeof(Car), SEEK_SET);
            fread(&currentCar, sizeof(Car), 1, file);

            fseek(file, (j + 1) * sizeof(Car), SEEK_SET);
            fread(&nextCar, sizeof(Car), 1, file);

            // Compare brands and swap if necessary
            if (strcmp(currentCar.brand, nextCar.brand) > 0) {
                swapCars(file, j, j + 1);
            }
        }
    }

    fclose(file);
    printf("Cars sorted by brand.\n");
}

void sortByAvailability(const char *filename) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Car currentCar, nextCar;
    int fileSize = 0;

    // Get the file size
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    rewind(file);

    int numCars = fileSize / sizeof(Car);

    for (int i = 0; i < numCars - 1; i++) {
        for (int j = 0; j < numCars - i - 1; j++) {
            // Read current and next cars
            fseek(file, j * sizeof(Car), SEEK_SET);
            fread(&currentCar, sizeof(Car), 1, file);

            fseek(file, (j + 1) * sizeof(Car), SEEK_SET);
            fread(&nextCar, sizeof(Car), 1, file);

            // Compare disponibility and swap if necessary
            if (currentCar.availability < nextCar.availability) {
                swapCars(file, j, j + 1);
            }
        }
    }

    fclose(file);
    printf("Cars sorted by availability.\n");
}

void sortByRentalPrice(const char *filename) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Car currentCar, nextCar;
    int fileSize = 0;

    // Get the file size
    fseek(file, 0, SEEK_END);   
    fileSize = ftell(file);
    rewind(file);

    int numCars = fileSize / sizeof(Car);

    for (int i = 0; i < numCars - 1; i++) {
        for (int j = 0; j < numCars - i - 1; j++) {
            // Read current and next cars
            fseek(file, j * sizeof(Car), SEEK_SET);
            fread(&currentCar, sizeof(Car), 1, file);
            printf("%f\n", currentCar.rentalPrice);


            
            fseek(file, (j + 1) * sizeof(Car), SEEK_SET);
            fread(&nextCar, sizeof(Car), 1, file);
            printf("%f\n", nextCar.rentalPrice);

            // Compare rental prices and swap if necessary
            if (currentCar.rentalPrice > nextCar.rentalPrice) {
                swapCars(file, j, j + 1);
            }
        }
    }

    fclose(file);
    printf("Cars sorted by rental price.\n");
}



void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Keep reading characters until newline or end of file (EOF) is encountered
    }
}
