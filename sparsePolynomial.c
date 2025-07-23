#include <stdio.h>
#define MAX 100

// Define struct Term before using it
struct Term {
    int coef;
    int expo;
};

void input(struct Term a[], int n, int j){
    printf("Enter the terms of Polynomial %d (coefficient and exponent):\n", j);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a[i].coef, &a[i].expo);
    }
}

void sort(struct Term a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j].expo < a[j+1].expo){
                struct Term temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void add(struct Term a[], struct Term b[], struct Term c[], int n1, int n2, int *n3){
    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2){
        if(a[i].expo == b[j].expo){
            c[k].coef = a[i].coef + b[j].coef;
            c[k].expo = a[i].expo;
            i++; j++; k++;
        } else if(a[i].expo > b[j].expo){
            c[k] = a[i];
            i++; k++;
        } else {
            c[k] = b[j];
            j++; k++;
        }
    }

    while(i < n1) c[k++] = a[i++];
    while(j < n2) c[k++] = b[j++];

    *n3 = k;
}

void print(struct Term a[], int n){
    printf("Resultant Polynomial: ");
    for(int i = 0; i < n; i++){
        if(a[i].coef == 0) continue;

        printf("%dx^%d", a[i].coef, a[i].expo);

        // Don't print '+' after last non-zero term
        int next = i + 1;
        while (next < n && a[next].coef == 0) next++;

        if (next < n) printf(" + ");
    }
    printf("\n");
}

int main(){
    int n1, n2, n3;
    struct Term poly1[MAX], poly2[MAX], result[MAX];

    printf("Enter the number of terms in Polynomial 1 and Polynomial 2: ");
    scanf("%d %d", &n1, &n2);

    input(poly1, n1, 1);
    input(poly2, n2, 2);

    sort(poly1, n1);
    sort(poly2, n2);

    add(poly1, poly2, result, n1, n2, &n3);
    
    sort(result, n3);
    print(result, n3);
    

    return 0;
}
