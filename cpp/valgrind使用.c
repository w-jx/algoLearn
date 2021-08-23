#include "stdio.h"
#include "stdlib.h"
#include "memory.h"

int main(){
    int *a  =(int*)malloc(sizeof(int));
    *a =10;
    printf("a=%d",*a);
}