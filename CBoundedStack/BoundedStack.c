#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include "BoundedStack.h"

struct BS
{
    int size;
    int capacity;
    char **items;
};

extern int errno;
int MAX_CAPACITY = 256;
int MAX_ITEM_LENGTH = 3;

BoundedStack createBoundedStack(int capacity)
{
    if (capacity > MAX_CAPACITY || capacity <= 0)
    {
        fprintf(stderr, "Value of errno: %d\n", errno);
        printf("Stack capacity must be between 1 and 256, inlusive.");
        fprintf(stderr, "Stack is too large or too small. Exiting...\n");
        exit(EXIT_FAILURE);
    }
    BoundedStack boundedStack = (BoundedStack)calloc(1, sizeof(struct BS));
    boundedStack->capacity = capacity;
    boundedStack->size = 0;
    boundedStack->items = (char **)malloc(sizeof(char *) * MAX_ITEM_LENGTH);
    return boundedStack;
}

bool isFull(BoundedStack stack)
{
    return stack->size >= stack->capacity ? true : false;
}

bool isEmpty(BoundedStack stack)
{
    return stack->size <= 0 ? true : false;
}

void push(BoundedStack stack, char *item)
{
    if (isFull(stack))
    {
        fprintf(stderr, "Value of errno: %d\n", 0);
        fprintf(stderr, "Cannot push to a full stack. Exiting...\n");
        exit(EXIT_FAILURE);
    }
    if (strlen(item) > MAX_ITEM_LENGTH || strlen(item) <= 0)
    {
        fprintf(stderr, "Value of errno: %d\n", 1);
        fprintf(stderr, "Item is too large or too small. Exiting...\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->size] = item;
}

char *pop(BoundedStack stack)
{
    if (isEmpty(stack))
    {
        fprintf(stderr, "Value of errno: %d\n", 1);
        fprintf(stderr, "Cannot pop from an empty stack. Exiting...\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->size--];
}

char *peek(BoundedStack stack)
{
    if (isEmpty(stack))
    {
        printf("Cannot peek at an empty stack.");
        fprintf(stderr, "Stack is empty. Exiting...\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->size];
}

int main()
{
    struct BS *stack = createBoundedStack(2);

    push(stack, "HELLO");
    printf("%s peeked from stack\n", peek(stack));

    push(stack, "WORLD");
    // push(stack, "!");
    printf("%s peeked from stack\n", peek(stack));

    printf("%s popped from stack\n", pop(stack));

    return 0;
}