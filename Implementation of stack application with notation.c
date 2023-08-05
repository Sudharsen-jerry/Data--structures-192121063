#include <stdio.h>
#include <stdlib.h>
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}
int evaluatePostfixExpression(char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));
    if (!stack)
        return -1;

    for (int i = 0; postfix[i]; ++i) {
        if (isdigit(postfix[i]))
            push(stack, postfix[i] - '0');
        else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            switch (postfix[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }
    }

    int result = pop(stack);
    free(stack);
    return result;
}

int main() {
    char postfix[] = "52+3*";

    int result = evaluatePostfixExpression(postfix);

    printf("Output: %d\n", result);

    return 0;
}
