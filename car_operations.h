// car_operations.h
#ifndef CAR_OPERATIONS_H
#define CAR_OPERATIONS_H

#define MAX_LINE 1000
#define MAX_RECORDS 100
#define KMSEUIL 80000



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
    float km;
    float val;
    char insurance_type; //A, B or C
    int isOnLoan; // 1->on loan   0->not on loan
    float monthlyPayment;
    int remainingMonths;

} Car;



void Addcar(const char *filename);
void ProcessLoanDetails(const char *filename);
void ModifyCarInfo(const char *filename, int id);
void deleteMenu(); //MUST ADD
void DeleteFirstCar(const char *filename);
void DeleteByID(const char *filename, int id);
void DeleteLastCar(const char *filename);
void DisplayFileContents(const char *filename);
void DisplayCarsByMark(const char *filename);
void DisplayCarsByAvailability(const char *filename);
void DisplayCarsByFuelType(const char *filename);
void ShowCarList(const char *filename);
void sortMenu();
void swapCars( Car *index1, Car *index2);
void sortByBrand(const char *filename);
void sortByRentalPrice(const char *filename);
void sortByAvailability(const char *filename);
void sortByNumSeats(const char *filename);
void SellCarsByMilage(const char *filename);
void PayInsurance(const char *filename, int id);
void ProcessLoanPayment(const char *filename, int id);

#endif
