#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1000
#include<Structs.c>

void displayMenu();
void Addcar(const char *filename);
void DeleteByID(const char *filename, int id);
void DeleteLastCar(const char *filename);
void ModifyCarInfo(const char *filename, int id);
void DisplayFileContents(const char *filename);
void DisplayCarsByMark(const char *filename);
void DisplayCarsByAvailability(const char *filename);
void DisplayCarsByFuelType(const char *filename);
void DeleteFirstCar(const char *filename);
void ShowCarList(const char *filename);