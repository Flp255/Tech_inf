//
// Created by Student on 31.03.2025.
//
#include "arrayoperation.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
void ShowArray(int array[], int size) {
    printf("Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void BiggestValue(int array[], int size){
    int big = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > big) {
            big = array[i];

        }

    }
    printf("Biggest value: %d\n", big);

}
void SmallestValue(int array[], int size) {
    int small = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < small) {
            small = array[i];
        }
    }

    printf("Smallest value: %d\n", small);
}

void Avarage(int array[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    float average = (float)sum / SIZE;
    printf("Average: %.2f\n", average);
}
void Median(int array[], int size){
    int n;
    qsort(array, size, sizeof(int), compare);
    for (n = 0; n < size; n++)
    {
        printf("%d\n", array[n]);
    }
    printf("median=%d ", array[size / 2]);
}

int SaveArray(int array[]){
    FILE *fptr=NULL;
    fptr = fopen("../array.txt", "w");
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
    FILE *fptr = fopen("../array.txt", "r");
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


void EnterTheNumbers(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter the number %d:\n", i + 1);
        scanf("%d", &array[i]);
    }
}
void modify_array(int* write_ptr, int index, int new_value) {
    *(write_ptr + index) = new_value;
}