#include <stdio.h>
#include <stdlib.h>
#include "globals.h"

float caisse = 1000000; // Default value of caisse

// Save the value of caisse to a file
void saveCaisseValue(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for saving caisse value.\n");
        return;
    }

    fprintf(file, "%.2f", caisse); // Save the value with two decimal places
    fclose(file);
}

// Load the value of caisse from a file
void loadCaisseValue(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Warning: File for loading caisse value not found. Initializing with default value.\n");
        return;
    }

    if (fscanf(file, "%f", &caisse) != 1) {
        printf("Error: Failed to read caisse value from file.\n");
        caisse = 1000000; // Reset to default value if reading fails
    }

    fclose(file);
}
