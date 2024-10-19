#include<stdio.h>

void sum(int mat1[][20], int r1, int c1);
void product(int mat1[][20], int r1, int c1);
void transpose(int mat[][20], int r, int c);

int main() {
    int mat[20][20];
    int i, j, ex = 0;
    int r, c, s;
    printf("rows=");
    scanf("%d", &r);
    printf("columns=");
    scanf("%d", &c);
    printf("enter the elements: ");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    while(ex == 0) {
        printf("\n1. Sum\n2. Product\n3. Transpose\n4. Exit\n");
        scanf("%d", &s);
        switch(s) {
            case 1:
                sum(mat, r, c);
                break;
            case 2:
                product(mat, r, c);
                break;
            case 3:
                transpose(mat, r, c);
                break;
            case 4:
                ex = 1;
                break;
            default:
                printf("Invalid response\n");
        }
    }   
    return 0;
}

void sum(int mat1[][20], int r1, int c1) {
    int mat2[20][20], mat3[20][20];
    int i, j, r2, c2;

    printf("Enter the second matrix:\n");
    printf("rows=");
    scanf("%d", &r2);
    printf("columns=");
    scanf("%d", &c2);
    if(r1 == r2 && c1 == c2) {
        printf("Enter elements of the second matrix: ");
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c1; j++) {
                scanf("%d", &mat2[i][j]);
            }
        }
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c1; j++) {
                mat3[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
        printf("Sum:\n");
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c1; j++) {
                printf("%d\t", mat3[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("Matrices must have the same dimensions for addition.\n");
    }       
}

void transpose(int mat[][20], int r, int c) {
    int i, j, temp = 0;
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
    printf("Transpose:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void product(int mat1[][20], int r1, int c1) {
    int mat2[20][20], mat3[20][20];
    int i, j, k, r2, c2, p = 0;
    printf("Enter the second matrix:\n");
    printf("rows=");
    scanf("%d", &r2);
    printf("columns=");
    scanf("%d", &c2);
    if(c1 == r2) {
        printf("Enter elements of the second matrix: ");
        for(i = 0; i < r2; i++) {
            for(j = 0; j < c2; j++) {
                scanf("%d", &mat2[i][j]);
            }
        }
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c2; j++) {
                p = 0;
                for(k = 0; k < c1; k++) {
                    p += mat1[i][k] * mat2[k][j];
                }
                mat3[i][j] = p;
            }
        }
        printf("Product:\n");
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c2; j++) {
                printf("%d\t", mat3[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("Matrices dimensions are incompatible for multiplication.\n");
    }
}
