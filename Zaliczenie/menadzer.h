//
// Created by Filip on 14.06.2025.
//

#ifndef MENADZER_H
#define MENADZER_H

#include <stdbool.h>


struct Zadanie {
    char opis[100];
    bool status;
};

void PokazZadania(struct Zadanie zadania[], int liczbaZadan);
void ZmianaStatusu(struct Zadanie zadania[], int *liczbaZadan);
int DodawanieZadania(struct Zadanie zadania[], int maxLiczbaZadan, int *aktualnaLiczbaZadan);
int UsuwanieZadania(struct Zadanie zadania[], int *liczbaZadan);
int ZapisywanieZadania(struct Zadanie zadania[], int liczbaZadan);
int WczytywanieZadania(struct Zadanie zadania[], int maxLiczbaZadan, int *aktualnaLiczbaZadan);
#endif //MENADZER_H