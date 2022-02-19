#include<bits/stdc++.h>

using namespace std;

class Stack {
    public:
        int top;
        unsigned int capacity;
        char* array;
}

Stack* createStack(unsigned int capacity) {
    Stack* stack = new Stack();
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = new char[stack->capacity];
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
    }

int isEmpty(Stack* stack) {
    return stack->top == -1; 
    }

void push(Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char pop(Stack* stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

string reverse(string s) {
    string reversed = "";
    int n = sizeof(s)/sizeof(s[0]) - 1;
    Stack* stack = createStack(n);
    for (int i = 0; i < n; i++) {
        push(stack, s[i]);
    }
    for (int i = 0; i < n; i++) {
        reversed += pop(stack);
    }
    return reversed;
    

}

int main() {
    string s = "algo";
    cout << reverse(s) << endl;
    return 0;
}

// Reverse a string using stacks

