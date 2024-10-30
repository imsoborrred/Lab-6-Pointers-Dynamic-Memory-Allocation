#include <stdio.h>
#include <stdlib.h>

int main() {
    int *x = (int*) malloc(1 * sizeof(int));
    char y = 'Y';
    int count = 0;
    int sum = 0;

    if (x == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    while (y == 'Y' || y == 'y') {
        printf("Enter an integer: ");
        scanf("%d", &x[count]);
        sum += x[count];
        count++;
        x = realloc(x, (count + 1) * sizeof(int));

        printf("Do you want to enter another number? (Y or N): ");
        scanf(" %c", &y);
    }

    printf("You entered:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    float average =  (float) sum / count;
    printf("Calculated average (DC value): %f\n", average);

    for (int i = 0; i < count; i++) {
        int adjusted_value = x[i] - average;
        printf("%d\n", adjusted_value);
    }

    free(x);
    return 0;
}

