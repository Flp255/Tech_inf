#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void menu() {
    printf("\nMENU:\n");
    printf("1. Dodaj na stos (Push)\n");
    printf("2. Zdejmij ze stosu (Pop)\n");
    printf("3. Dodaj do kolejki (Enqueue)\n");
    printf("4. Usun z kolejki (Dequeue)\n");
    printf("5. Wyswietl liste\n");
    printf("6. Wyczysc liste\n");
    printf("0. Wyjscie\n");
    printf("Wybierz opcje: ");
}

int main() {
    int opcja, wartosc;
    while (1) {
        menu();
        if (scanf("%d", &opcja) != 1) {
            printf("Niepoprawny wybor!\n");
            while (getchar() != '\n');
            continue;
        }
        switch (opcja) {
            case 1:
                printf("Podaj wartosc do stosu: ");
            scanf("%d", &wartosc);
            insertFront(wartosc);
            break;
            case 2:
                if (deleteFront() == 0) printf("Zdjeto ze stosu.\n");
                else printf("Stos pusty!\n");
            break;
            case 3:
                printf("Podaj wartosc do kolejki: ");
            scanf("%d", &wartosc);
            insertBack(wartosc);
            break;
            case 4:
                if (deleteFront() == 0) printf("Usunieto z kolejki.\n");
                else printf("Kolejka pusta!\n");
            break;
            case 5:
                printf("Zawartosc listy: ");
            printList();
            break;
            case 6:
                clearList();
            printf("Lista wyczyszczona.\n");
            break;
            case 0:
                clearList();
            return 0;
            default:
                printf("Niepoprawna opcja!\n");
        }
    }
    return 0;
}
