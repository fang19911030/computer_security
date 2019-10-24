#include <stdio.h>

void q1(){
    long a=3;
    long b=5;
    long c=0;
    c = a*b-a/2;
    printf("%d", c);
}

void q2(){
    long arr[] = {12, 15, 221,3,432, 64, 16, 67};
    int max = 0;
    int i = 0;
    while(i<=7){
        if(arr[i] >=max){
            max = arr[i];
        }
        i += 1;
    }
    printf("max: %d\n", max);
}
void q3(){
    int i =100;
    for(;i<=999;i++){
        int a = i/100;
        int b = (i-a*100)/10;
        int c = i%10;
        if(i == (a*a*a + b*b*b + c*c*c)){
            printf("%d\n", i);
        }
    }
}
int func1(int *lst, int b1, int b2){


    int x = 0;
    int y = 0;
    int c;
    int i;
    for (i = 0; i < b1; ++i)
    {
        c = 1;
        while (c < b2)
        {
            while (!lst[y])
                y = (y + 1) % b1;
            ++c;
            y = (y + 1) % b1;
        }
        while (!lst[y])
            y = (y + 1) % b1;
        x = lst[y];
        lst[y] = 0;
    }
    return x;
}
int q4(){
    int res;
    int lst[100];
    int a, b, i;

    b = 7;
    a = 100;
    for (i = 0; i < a; ++i) {
        lst[i] = i + 1;
    }
    res = func1(lst, a, b);
    printf("%d\n", res);
    return 0;
}
int main(int argc, const char **argv, const char **envp){
    q4();
    return 0;
}