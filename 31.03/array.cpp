//
// Created by Student on 31.03.2025.
//
#include <stdio.h>
#define SIZE 5

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
void Showarray(int array[], int size) {
    printf("Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
}
void BiggestValue(int array[], int size){
    int big = array[0];
    for (int i = 1; i < SIZE; i++) {
        if (array[i] > big) {
            big = array[i];

        }
        printf("Biggest value: %d\n", big);
    }


    }
void SmallestValue(int array[], int size) {
    int small = array[0];
    for (int i = 1; i < SIZE; i++) {
        if (array[i] < small) {
            small = array[i];
        }
    }

    printf("Smallest value: %d\n", small);
}

void Avarage(int array[], int size){
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += array[i];
    }
    float average = (float)sum / SIZE;
    printf("Average: %.2f\n", average);
}
void Median(int array[], int size){
    qsort(array, SIZE, sizeof(int), compare);
    if (SIZE % 2 == 1) {
        printf("Median: %d\n", array[SIZE / 2]);
    } else {
        float median = (array[SIZE / 2 - 1] + array[SIZE / 2]) / 2.0;
        printf("Median: %.2f\n", median);
    }
}
int SaveArray(int array[]){
    FILE *fptr=NULL;
    fptr = fopen("../array.tx", "w");
    if (fptr==NULL) {
        printf("Error opening file\n");
    return 1;
    }
    for(int i=0; i<SIZE; i++){
        fprintf(fptr,"%d\n",array[i]);
    }
    fclose(fptr);
    return 0;
}
int LoadArray(int array[]) {
    FILE *fptr = NULL;
    if (fptr == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    for (int i = 0; i < SIZE; ++i) {
        if (fscanf(fptr, "%d", &array[i]) != 1) {
fclose(fptr);
return 2;
        }

    }
    fclose(fptr);
    return 0;
}