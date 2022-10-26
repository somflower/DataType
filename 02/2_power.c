#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int power(int x, int n){
    if(x==0)
        return 0;
    else if(x==1)
        return 1;
    else{
        if (n==1)
            return x;
        else
            return power(x, n-1)*x;
    }
}
int main(void){
    int x, n;

    scanf("%d %d", &x, &n);
    printf("%d\n", power(x, n));

    return 0;
    
}