#include<stdio.h>
int main(){
    int a[3][3],b[3][3],transpose[3][3];
    printf("Enter values of first 3x3 matrix\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter values of second 3x3 matrix");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            scanf("%d",&b[i][j]);
        }
    }
    printf("Values : A\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("Values : B\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    printf("\n\nAddition\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%2d ",a[i][j]+b[i][j]);
        }
        printf("\n");
    }
    printf("\n\nSubtraction\n");
    for(int i=0; i<3; i++){
        for(int j=0;j<3;j++){
            printf("%2d ", a[i][j]-b[i][j]);
        }
        printf("\n");
    }
    printf("\n\nTranspose\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            transpose[i][j]=a[j][i];
            printf("%d ",transpose[i][j]);
        }
        printf("\n");
    }


}