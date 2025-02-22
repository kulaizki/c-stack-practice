#include "../../../include/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10 // can change this, it's private

struct Stack
{
  char data[MAX];
  int top;
};

typedef struct Stack *Stack;

void push(Stack s, char elem);
void pop(Stack s);
char top(Stack s);
bool isEmpty(Stack s);
bool isFull(Stack s);
Stack init(void);
void displayStack(Stack s);

/**
 * @brief Adds the specified element to the top of the stack.
*/
void push(Stack s, char elem)
{
  if (s->top < MAX - 1)
  {
    s->data[++s->top] = elem;
  }
}

/**
 * @brief Removes the element at the top of the stack.
*/
void pop(Stack s)
{
  if (s->top >= 0)
  {
    s->top--;
  }
}

/**
 * @brief Returns the element at the top of the stack, otherwise (-1) if the stack is empty.
*/
char top(Stack s)
{
  return (!isEmpty(s) ? s->data[s->top] : '\0');
}

/**
 * @brief Returns true (1) if the stack is empty, otherwise false (0).
*/
bool isEmpty(Stack s)
{
  return s->top == -1;
}

/**
 * @brief Returns true (1) if the stack is full, otherwise false (0).
*/
bool isFull(Stack s)
{
  return s->top >= MAX - 1;
}

/**
 * @brief Returns a new instance of a Stack.
*/
Stack init(void)
{
  Stack s = (Stack)malloc(sizeof(struct Stack));
  s->top = -1;
  return s;
}

/**
 * @brief Pretty prints the stack's elements, starting from the top-most element to the bottom.
*/
void displayStack(Stack s)
{
  int x;
  for (x = s->top; x >= 0; x--)
  {
    printf("%c ", s->data[x]);
  }
  printf("\n");
}

/**
 * @brief Returns the length of the stack
*/
int length(Stack s)
{
  return s->top + 1;
}

/**
 * @brief Prints a statement to debug the connection between main.c and stack.h with their private implementations.
 */
void debugPrint(void)
{
  printf("\e[0;34m");
  puts("I'm in /src/stack/array/stack.c!\n");
  printf("\e[0m");
}
