/*
 * This module defines a type called BoundedStack.
 */

typedef struct BS *BoundedStack;

BoundedStack createBoundedStack(int capacity);
bool isFull(BoundedStack stack);
bool isEmpty(BoundedStack stack);
void push(BoundedStack stack, char *item);
char *pop(BoundedStack stack);
char *peek(BoundedStack stack);
