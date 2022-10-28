// Inputs 3
// Output 1 if different from each other
// output 0 if repeated atleast once
#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    // we need to pass N number of test cases that's why we can use here loop
    while(t--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        printf("%d",(a!=b && a!=c && b!=c));
    }
    return 0;
}

/*
Pass This way Test cases
4
100 5 100
50 25 25
1 6 1
4 7 0
/*
