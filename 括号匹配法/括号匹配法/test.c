#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 100
#define true 1
#define false 0
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void init(Stack* s)
{
    s->top = -1;
}

int is_empty(Stack* s)
{
    return s->top == -1;
}

int is_full(Stack* s) 
{
    return s->top == MAX_SIZE - 1;
}

void push(Stack* s, char c) {
    if (is_full(s)) 
    {
        printf("Stack is full.\n");
        return;
    }
    s->data[++s->top] = c;
}

char pop(Stack* s) {
    if (is_empty(s)) 
    {
        printf("Stack is empty.\n");
        return '\0';
    }
    return s->data[s->top--];
}

int match(char left, char right) {
    if (left == '(' && right == ')') 
        return true;
    if (left == '[' && right == ']')
        return true;
    if (left == '{' && right == '}')
        return true;
    return false;
}

int check_brackets(char* str) {
    Stack s;
    init(&s);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            push(&s, str[i]);
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (is_empty(&s) || !match(pop(&s), str[i])) 
                return false;
        }
    }
    return is_empty(&s);
}

int main() {
    char str1[MAX_SIZE] = "";
    gets(str1);
    if (check_brackets(str1))
        printf("y\n");
    else
        printf("n\n");
    return 0;
}

