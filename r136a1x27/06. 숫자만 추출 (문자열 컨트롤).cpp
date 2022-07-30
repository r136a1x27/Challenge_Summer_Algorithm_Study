/* 문자와 숫자가 섞여있는 문자열이 주어지면 그 중 숫자만 추출하여 그 순서대로 자연수를 만듭니다.
/ 만들어진 자연수와 그 자연수의 약수 개수를 출력합니다. 
/ 만약 "t0e0a1c2her"에서 숫자만 추출하면 0, 0, 1, 2이고 이것을 자연수로 만들면 12가 됩니다.
/ 즉, 첫 자리 0은 자연수와 할 때 무시합니다.
/ 출력은 12를 출력하고 다음 줄에 12의 약수의 개수를 출력하면 됩니다.
/ 추출하여 만들어지는 자연수는 100,000,000을 넘지 않습니다.
*/


// 입력설명: 첫 줄에 숫자가 섞인 문자열이 주어집니다. 문자열의 길이는 50을 넘지 않습니다.
// 출력설명: 첫 줄에 자연수를 출력하고, 두 번째 줄에 약수의 개수를 출력합니다.

// 입력 예제: g0en2Ts8eSoft
// 출력 예제: 28 6

/* 알고리즘 생각해보기
/ 문자열을 한 글자씩 접근하여 a~z면 저장 안하고 0~9만 저장하기
/ 스택에 저장해서 위에서부터 꺼내서 스택 크기 보고 자리만큼 x1000 x100 x10 하면 될 것 같음
/ 또는 문자열로 저장하고 string to int 사용하면...(이래서 파이썬이 편하구나)
*/

/* 알고리즘 (강사)
/ 문자열을 한 글자씩 접근하여 a~z면 저장 안하고 0~9만 저장하기
/ res = res*10 + 숫자; 를 활용하여 10씩 증가시켜서 왼쪽으로 이동 시킴 => 14 => 140+n 이 되는 식
*/

#include <iostream>
using namespace std;
int main()
{
    char a[100];
    int res=0, cnt=0, i;
    scanf("%s", &a);

    // 숫자만 추출하여 숫자로 변환
    for(i=0; a[i]!='\0';i++){
        if(a[i]>=48 && a[i]<=57){ // ASCII 코드로 0~9를 의미
            res = res*10 + (a[i]-48);
        }
    }
    printf("%d\n", res);
    // 약수 구하기
    for(i=1; i<=res/2; i++){
        if(res%i==0) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
