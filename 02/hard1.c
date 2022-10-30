#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int cnt_digit(int n)
{
    int i;

    for (i = 0; n > 0; i++)
    {
        n /= 10;
    }
    return i;
}
void mul3(char e[], int *cnt, int *flag)
{
    int i, sum = 0, digit;

    //아스키코드 이용해 e의 각자리수 합 구하기
    for (i = 0; e[i] != '\0'; i++)
    {
        sum = sum + e[i] - '0';
        printf("check sum, e[%d]: %c\n", i, e[i]);
    }
    printf("sum: %d\n", sum);
    //더한 횟수 구하기(최종출력값)
    *cnt = *cnt + 1;
    // printf("sum: %d\n", sum);

    // 3의 배수인지 flag를 이용해 확인하기
    if (sum % 3 == 0)
        *flag = 1;

    //자릿수의 합이 일의자리수면 return
    if (sum < 10)
        return;
    else
    {
        digit = cnt_digit(sum); //합이 일의자리수가 아닐때 자릿수 계산
        // printf("digit: %d\n", digit);
        e[digit] = '\0';//문자열 마지막에 NULL값 넣기

        for(i=digit-1;i>=0;i--){ //자릿수에 맞춰서 e에 문자열 넣어주기
             e[i] = sum % 10 + '0';
            sum = sum / 10;
            printf("e[%d]: %c\n", i, e[i]);
        }

        mul3(e, cnt, flag); //재귀호출
    }
}
int main(void)
{
    char enter[8];         //숫자 문자열로 입력받음
    int cnt = 0, flag = 0, n; //cnt는 합의 횟수, flag는 3의 배수 확인용, n은 일의자리수 3의배수인지 확인용

    scanf("%s", enter);

    if (strlen(enter) > 1)//입력받은 문자열의 크기가 1보다 클때
    {
        mul3(enter, &cnt, &flag);//반복
    }
    else{ //입력받은 문자열의 크기가 1의자리 일때 값을 구해서 3의 배수 인지 확인
        int n = enter[0] - '0';
        if(n%3==0)
            flag = 1;
    }

    printf("%d\n", cnt);

    if (flag == 1)
            printf("YES\n");
        else
            printf("NO\n");
            
    return 0;
}