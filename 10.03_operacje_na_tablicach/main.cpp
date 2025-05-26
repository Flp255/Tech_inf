#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include "arrayoperation.h"

#define SIZE 5



void menu() {
    printf("MENU:\n\n");
    printf("1. Show array\n");
    printf("2. Show the biggest value\n");
    printf("3. Show the smallest value\n");
    printf("4. Calculate average\n");
    printf("5. Calculate median\n");
    printf("6. Save the array\n");
    printf("7. Load the array\n");
    printf("8. Modify the array\n");
    printf("0. Exit\n");
    printf("Choose your option: ");
}



int main() {
    int num[] = {-1, 2, 6, 4, 15};
    int option;

    do {
        menu();
        scanf("%d", &option);
        switch (option) {
            case 0:
                break;
            case 1:
                ShowArray(num, SIZE);
            break;
            case 2:
                BiggestValue(num, SIZE);
            break;
            case 3:
                SmallestValue(num, SIZE);
            break;
            case 4:
                Avarage(num, SIZE);

            break;

            case 5:
                Median(num, SIZE);

            break;

            case 6:
                SaveArray(num);
            break;

            case 7:
                LoadArray(num);
            break;


            case 8:
                modify_array(num, 2, 99);
            EnterTheNumbers(num, SIZE);
            break;
            default:
                printf("Invalid option. Try again.\n");
            break;

        }

    } while (option != 0);

    return 0;
}
