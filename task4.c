#include <stdio.h>
#include <stdlib.h>

int *stack = NULL;
int top = 0;

void push(int input);
void pop();
void display();

int main() {
    char condition;

    stack = (int *)malloc(sizeof(int));
    if (!stack) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    while (1) { 
        printf("Enter a command (p: push, o: pop, d: display, e: exit): ");
        scanf(" %c", &condition);

        switch (condition) {
            case 'p': {
                int input;
                printf("Enter an integer: ");
                scanf("%d", &input);
                push(input);
                break;
            }
            case 'o':
                pop();
                break;
            case 'd':
                display(); 
                break;
            case 'e':
                free(stack);
                stack = NULL;
                return 0; 
            default:
                printf("choose valid option.\n");
                break;
        }
    }

    free(stack);
    return 0;
}

void push(int input) {
    stack = realloc(stack, (top + 1) * sizeof(int));
    if (!stack) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(1);
    }
    stack[top] = input;
    top++;
}

void pop() {
    if (top > 0) {
        top--;
        stack = realloc(stack, top * sizeof(int));
    } else {
        printf("Stack is empty.\n");
    }
}

void display() {
    if (top == 0) {
        printf("Stack is empty.\n");
    } else {
        for (int i = 0; i < top; i++) {
            printf("%d\n", stack[i]);
        }
    }
}
