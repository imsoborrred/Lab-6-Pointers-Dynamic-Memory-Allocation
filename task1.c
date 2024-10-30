#include <stdio.h>
#include <stdlib.h>

void calculate(int a, int b, int n, int *x, int *y, int *z);

int main() {
    int n, a, b;
    printf("Enter size of vector: ");
    	scanf("%d", &n);

    printf("Enter value of scalar a: ");
   	 scanf("%d", &a);
    printf("Enter value of scalar b: ");
    	scanf("%d", &b);

    int *x = malloc(n * sizeof(int));
	int *y = malloc(n * sizeof(int));
   int *z = malloc(n * sizeof(int));

	if(x == NULL || y == NULL || z == NULL){
		printf("no memory allocated");
	}


    printf("Enter elements of vector X: \n");
    for (int i=0; i<n; i++) {
        printf("Enter element[%d]: ", i);
        scanf("%d", &x[i]);
    }

  printf("Enter elements of vector Y: \n");
    for (int i=0; i<n; i++) {
        printf("Enter element[%d]: ", i);
        scanf("%d", &y[i]);
    }


    calculate(a, b, n, x, y, z);

  printf("Result vector Z: ");
   for (int i = 0; i < n; i++) {
        printf("z[%d]: %d ", i, z[i]);
    }
    printf("\n");

    free(x);
   	free(y);
    	free(z);

    return 0;
}

void calculate(int a, int b, int n, int *x, int *y, int *z) {
    for (int i = 0; i < n; i++) {
        z[i] = a * x[i] + b * y[i];
    }
}



