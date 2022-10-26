#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int factorial(int n){

    if(n==1)
        return 1;

    else
        return factorial(n-1)*n;
}
int main(void){
    int n;

    scanf("%d", &n);
    printf("%d\n", factorial(n));
}