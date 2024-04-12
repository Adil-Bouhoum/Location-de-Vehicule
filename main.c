
#include <stdio.h>
#include "car_operations.h"
#include "menu.h"

int main() {
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
                int id;
                printf("Entrez l'ID a changer:");
                scanf("%d",&id);
                ModifyCarInfo("carlist.csv",id);
                break;
            case 3:
                deleteMenu();
                break;
            case 4:
                displayMenu2();
                break;
            case 5:
                searchMenu();
                break;
            case 6:
                sortMenu();//stil needed
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
