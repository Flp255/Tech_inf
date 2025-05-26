#include <iostream>
#include <cstdio>
int compare (const void * a, const void * b)
{
    return (*(int*)a - *(int*)b );
}

void pokazElement (int tab[]){
    printf("tablica:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", tab[i]);
    }
}


int main() {
    int num[10] = {0, 1,2,3,4,5,6,7,8,9};
    pokazElement(num);
    int big = num[0], small = num[0];

    for(int i = 1; i < 10; i++){

            if (num[i] > big)
        {
            big = num[i];
        }
            if (num[i] < small){
                small = num[i];
        }


    }

    printf("Najwieksza wartosc %d\n",big);
    printf("Najmniejsza wartosc: %d\n",small);


    int n;
    qsort (num, 10, sizeof(int), compare);
    for (n=0; n<10; n++)
    { printf ("%d\n", num[n]); }
    printf ("mediana=%d", num[10/2]);

    return 0;

}
