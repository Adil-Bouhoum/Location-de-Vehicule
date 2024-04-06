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
