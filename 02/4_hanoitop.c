#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int hanoi(int n, char from, char tmp, char to){
   if (n==1) printf("���� 1�� %c���� %c�� �ű�\n", from, to);
   else{
    hanoi(n-1, from, to, tmp);
    printf("���� %d�� %c���� %c�� �ű�\n", n, from, to);
    hanoi(n-1, tmp, from, to);
   }
}
int main(void){
    int n;

    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');

    return 0;
    
}