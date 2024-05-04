
#include <stdio.h>
#include "car_operations.h"
#include "menu.h"
#include "globals.h"



int main() {
    int choice;
    printf("Welcome to Roads Agency!\n");
    printf("Booting...\n");
    loadCaisseValue("Caisse_value.txt");
    do {
        displayMenu();
        printf("Balance: %.2f\n",caisse);
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                Addcar("carlist.csv");
                break;
            case 2:{
                int id1;
                printf("Entrez l'ID a changer:");
                scanf("%d",&id1);
                ModifyCarInfo("carlist.csv",id1);}
                break;
            case 3:
                deleteMenu();
                break;
            case 4:
                displayMenu2();
                break;
            case 5:
                sortMenu();
                break;
            case 6:
                LoanMenu();
                break;
            case 7:
                SellCarsByMilage("carlist.csv");
                break;    
            case 8:
                int id2;
                printf("Enter car ID:");
                scanf("%d",&id2);
                PayInsurance("carlist.csv",id2);
                break;
            case 9:
                int id3;
                printf("Enter car ID:");
                scanf("%d",&id3);
                ProcessLoanPayment("cars_on_loan.csv",id3);
                break;
            case 0:
                printf("Thanks for using Roads, Goodbye!");
                saveCaisseValue("Caisse_value.txt");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un choix valide.\n");
        }
    } while (choice != 0);

    return 0;
}
