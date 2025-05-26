#include <iostream>
#include <cstdlib>
#include <stdio.h>


void male_litery(char *ciag) {
    while (*ciag) {
        if ('A' <= *ciag && *ciag <= 'Z') {
            *ciag += ('a' - 'A');

        }
        ciag++;
    }
}

void wielkie_litery(char *ciag) {
    while (*ciag) {
        if ('a' <= *ciag && *ciag <= 'z') {
            *ciag -= ('a' - 'A');
        }
        ciag++;
    }
}
void liczenie_tekstu(const char *const ciag, int *dlugosc){
    const char *ptr =ciag;
    *dlugosc =0;
    while(*ptr != '\0'){
        (*dlugosc++);
        ptr++;
    }
}


int main() {

    char tekst[] = "luBIE plACki";
   /* printf("tekst: %s\n", tekst);
    male_litery(tekst);
    printf("zmodyfikowany tekst: %s\n", tekst);
    wielkie_litery(tekst);
    printf("zmodyfikowany tekst: %s\n", tekst); */
    int wielkosc =0;
    printf("tekst: %s\n", tekst);
    liczenie_tekstu(tekst, &wielkosc);
    printf("dlugosc tekstu: %d\n", wielkosc);
    return 0;
};