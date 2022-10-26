#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int hanoi(int n, char from, char tmp, char to){
   if (n==1) printf("원판 1을 %c에서 %c로 옮김\n", from, to);
   else{
    hanoi(n-1, from, to, tmp);
    printf("원판 %d을 %c에서 %c로 옮김\n", n, from, to);
    hanoi(n-1, tmp, from, to);
   }
}
int main(void){
    int n;

    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');

    return 0;
    
}