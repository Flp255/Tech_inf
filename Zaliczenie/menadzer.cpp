//
// Created by Filip on 14.06.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menadzer.h"


void PokazZadania(struct Zadanie zadania[], int liczbaZadan) {
    printf("\n--- Lista Zadan ---\n");
    if (liczbaZadan == 0) {
        printf("Brak zadan do wyswietlenia.\n");
        return;
    }
    for (int i = 0; i < liczbaZadan; i++) {

        printf("%d. %s [%s]\n", i + 1, zadania[i].opis, zadania[i]. status ? "ZROBIONE" : "NIEZROBIONE");
    }
}

void ZmianaStatusu(struct Zadanie zadania[], int *liczbaZadan) {
    if (liczbaZadan == 0) {
        printf("Brak zadan do wyswietlenia.\n");
        return;
    }
        PokazZadania(zadania, *liczbaZadan);
        int numerZadania;
    if (scanf("%d",&numerZadania ) != 1) {
        printf("Nieprawidlowe wejscie. Podaj liczbe.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n') {}

    zadania[numerZadania - 1]. status = !zadania[numerZadania - 1]. status;

    printf("Status zadania '%s' zmieniono na: %s.\n",
           zadania[numerZadania - 1].opis,
           zadania[numerZadania - 1]. status ? "ZROBIONE" : "NIEZROBIONE");
}


int DodawanieZadania(struct Zadanie zadania[], int maxLiczbaZadan, int *aktualnaLiczbaZadan) {
    if (*aktualnaLiczbaZadan >= maxLiczbaZadan) {
        printf("Brak miejsca na dodanie nowego zadania. Lista pelna!\n");
        return 1;
    }

    printf("Wpisz zadanie do dodania: ");

    if (fgets(zadania[*aktualnaLiczbaZadan].opis, sizeof(zadania[*aktualnaLiczbaZadan].opis), stdin) == NULL) {
        printf("Blad odczytu zadania.\n");
        return 1;
    }
    zadania[*aktualnaLiczbaZadan].opis[strcspn(zadania[*aktualnaLiczbaZadan].opis, "\n")] = '\0';
    zadania[*aktualnaLiczbaZadan]. status = false;
    printf("Zadanie '%s' dodano do listy.\n", zadania[*aktualnaLiczbaZadan].opis);
    (*aktualnaLiczbaZadan)++;
    return 0;
}
int UsuwanieZadania(struct Zadanie zadania[], int *liczbaZadan) {
    if (*liczbaZadan == 0) {
        printf("Lista jest pusta!\n");
        return 1;
    }

    PokazZadania(zadania, *liczbaZadan);

    printf("Podaj numer zadania do usuniecia: ");
    int numerZadania;
    if (scanf("%d", &numerZadania) != 1) {
        printf("Nieprawidlowe wejscie. Podaj liczbe.\n");
        while (getchar() != '\n') {}
        return 1;
    } while (getchar() != '\n') {}
    char usuniety_opis[100];
    for (int i = numerZadania - 1; i < *liczbaZadan - 1; i++) {
        zadania[i] = zadania[i + 1];
    }
    (*liczbaZadan)--;
    printf("Zadanie '%s' zostalo usuniete z listy.\n", usuniety_opis);
    return 0;
}
    int ZapisywanieZadania(struct Zadanie zadania[], int liczbaZadan){
        FILE *fptr = NULL;
        fptr = fopen("../zadania.txt", "w");
        if (fptr == NULL) {
            printf("Blad otwarcia pliku do zapisu! Upewnij sie, ze masz prawa zapisu.\n");
            return -1;
        }
        for (int i = 0; i < liczbaZadan; i++) {
            fprintf(fptr, "%s %d\n", zadania[i].opis, zadania[i]. status);
        }
        fclose(fptr);
        printf("Zadania zapisano do pliku zadania.txt\n");
        return 0;
    }

int WczytywanieZadania(struct Zadanie zadania[], int maxLiczbaZadan, int *aktualnaLiczbaZadan) {
    FILE *fptr = fopen("../zadania.txt", "r");
    if (fptr == NULL) {
        printf("Blad otwarcia pliku do odczytu");
        *aktualnaLiczbaZadan = 0;
        return -1;
    }

    int wczytaneZadania = 0;
    char linia[200];
    while (wczytaneZadania < maxLiczbaZadan && fgets(linia, sizeof(linia), fptr)) {
        char opis[100];
        int status;

        char *ostatni_spacja = strrchr(linia, ' ');
        if (ostatni_spacja == NULL) continue;

        status = atoi(ostatni_spacja + 1);
        *ostatni_spacja = '\0';

        strncpy(zadania[wczytaneZadania].opis, linia, sizeof(zadania[wczytaneZadania].opis) - 1);
        zadania[wczytaneZadania].opis[sizeof(zadania[wczytaneZadania].opis) - 1] = '\0';
        zadania[wczytaneZadania]. status = (status == 1);

        wczytaneZadania++;
    }

    fclose(fptr);
    *aktualnaLiczbaZadan = wczytaneZadania;
    printf("Wczytano %d zadanie(a) z pliku zadania.txt.\n", wczytaneZadania);
    return wczytaneZadania;
}

