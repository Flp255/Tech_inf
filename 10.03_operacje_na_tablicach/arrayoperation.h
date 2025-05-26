//
// Created by Student on 07.04.2025.
//

#ifndef ARRAY_ARRAYOPERATION_H
#define ARRAY_ARRAYOPERATION_H
int compare(const void *a, const void *b);
void ShowArray(int array[], int size);
void BiggestValue(int array[], int size);
void SmallestValue(int array[], int size);
void Avarage(int array[], int size);
void Median(int array[], int size);
int SaveArray(int array[]);
int LoadArray(int array[]);
void EnterTheNumbers(int array[], int size);
void modify_array(int *write_ptr, int index, int new_value);

#endif //ARRAY_ARRAYOPERATION_H
