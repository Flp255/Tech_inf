#include <iostream>
#include <stdio.h>

void showElements (const int *const read_ptr, int size){
    printf("Tab:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", *(read_ptr+i));
    }
}
void EnterTheNumbers(int tab[], int size){
    for (int i = 0; i < size; i++) {
        printf("Enter the number %d:\n", i + 1);
        scanf("%d", &tab[i]);
    }
}
void modify_array(int *write_ptr, int index, int new_value){
    *(write_ptr + index)=new_value;
}

int main(){
    int numbers[]={0,1,2,3,4,5,6,7,8,9,};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    modify_array(numbers, 2,99);
    EnterTheNumbers(numbers, size);
    showElements(numbers, size);


    return 0;




}