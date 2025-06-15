#include <iostream>
#include <stdio.h>
#include "menadzer.h"

#define MAX_ZADAN 10

int aktualnaLiczbaZadan = 0;

struct Zadanie Lista_zadan[MAX_ZADAN] = {};

void menu() {
    printf("\n----  Menadzer Zadan  ----\n");
    printf("1. Pokaz rzeczy do zrobienia\n");
    printf("2. Zmien status zadania\n");
    printf("3. Dodaj rzeczy do listy\n");
    printf("4. Usun rzeczy z listy\n");
    printf("5. Zapisz w pliku\n");
    printf("6. Wczytaj liste z pliku\n");
    printf("0. Wyjdz\n\n");

    printf("Wybierz opcje: ");
}

int main() {
    int option;

    do {
        menu();
        scanf("%d", &option);
        while (getchar() != '\n') {}

        switch (option) {
            case 0:
                printf("Dziekuje za uzytkowanie menadzera zadan. Do zobaczenia!\n");
                break;
            case 1:
                PokazZadania(Lista_zadan, aktualnaLiczbaZadan);
                break;
            case 2:
                ZmianaStatusu(Lista_zadan, &aktualnaLiczbaZadan);
                break;
            case 3:
                DodawanieZadania(Lista_zadan, MAX_ZADAN, &aktualnaLiczbaZadan);
                break;
            case 4:
                UsuwanieZadania(Lista_zadan,&aktualnaLiczbaZadan);
                break;
            case 5:
                ZapisywanieZadania(Lista_zadan, aktualnaLiczbaZadan);
                break;
            case 6:
                WczytywanieZadania(Lista_zadan, MAX_ZADAN, &aktualnaLiczbaZadan);
                break;
            default:
                printf("Nieprawidlowa opcja. Sprobuj ponownie.\n");
                break;
        }
    } while (option != 0);

    return 0;
}