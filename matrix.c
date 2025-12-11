#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void inputMatrix(int a[MAX][MAX],int r,int c,char name) 
{
    int i,j;
    printf("Enter elements of Matrix %c (%dx%d):\n",name,r,c);
    for(i=0;i<r;i++) 
	{
        for(j=0;j<c;j++) 
		{
            scanf("%d",&a[i][j]);
        }
    }
}
void printMatrix(int a[MAX][MAX],int r,int c) 
{
    int i,j;
    for(i=0;i<r;i++) 
	{
        for(j=0;j<c;j++) 
		{
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void addMatrix(int a[MAX][MAX],int b[MAX][MAX],int r,int c) 
{
    int i,j,res[MAX][MAX];
    for(i=0;i<r;i++)
        for(j = 0; j < c; j++)
            res[i][j] = a[i][j] + b[i][j];
    printf("\nAddition Result:\n");
    printMatrix(res,r,c);
}
void multiplyMatrix(int a[MAX][MAX],int b[MAX][MAX],int r1,int c1,int r2,int c2) 
{
    int i,j,k,res[MAX][MAX]={0};
    for(i=0;i<r1;i++) 
	{
        for(j=0;j<c2;j++) 
		{
            res[i][j]=0;
            for(k=0;k<c1;k++) 
			{
                res[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    printf("\nMultiplication Result (%dx%d):\n",r1,c2);
    printMatrix(res,r1,c2);
}
void transposeMatrix(int a[MAX][MAX],int r,int c) 
{
    int i,j,t[MAX][MAX];
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            t[j][i]=a[i][j];
    printf("\nTranspose (%dx%d -> %dx%d):\n",r,c,c,r);
    printMatrix(t,c,r);
}
int main() 
{
    int A[MAX][MAX],B[MAX][MAX];
    int r1,c1,r2,c2,choice;
    printf("===Matrix Operations ===\n");
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d",&r1,&c1);
    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d",&r2,&c2);
    inputMatrix(A,r1,c1,'A');
    inputMatrix(B,r2,c2,'B');
    while (1) 
	{
        printf("\nMENU\n");
        printf("1.Addition\n");
        printf("2.Multiplication\n");
        printf("3.Transpose of A\n");
        printf("4.Transpose of B\n");
        printf("5.Display Matrices A & B\n");
        printf("6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) 
		{
            case 1:
                if(r1==r2&&c1==c2)
                    addMatrix(A,B,r1,c1);
                else
                    printf("Addition not possible: Matrix sizes must match.\n");
                break;
            case 2:
                if(c1==r2)
                    multiplyMatrix(A,B,r1,c1,r2,c2);
                else
                    printf("Multiplication not possible: Columns of A must equal rows of B.\n");
                break;
            case 3:
                transposeMatrix(A,r1,c1);
                break;
            case 4:
                transposeMatrix(B,r2,c2);
                break;
            case 5:
                printf("\nMatrix A:\n");
                printMatrix(A,r1,c1);
                printf("\nMatrix B:\n");
                printMatrix(B,r2,c2);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
