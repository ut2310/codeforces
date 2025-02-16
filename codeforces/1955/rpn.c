#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* newNode(int data) {
    Node* stackNode = (Node*)malloc(sizeof(Node));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(Node* root) {
    return !root;
}
void printStackHelper(Node* root, Node* og) {
    if (root == NULL) {
        return;
    }
    printStackHelper(root->next, og); 
    if(root == og)
    {
        printf("%d", root->data);
    }
    else
    {
        printf("%d, ", root->data);
    }
}

void printStack(Node* root) {
    printf("[");
    printStackHelper(root, root); 
    printf("]\n");
}
void push(Node** root, int data) {
    Node* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

int pop(Node** root) {
    if (isEmpty(*root))
        return -1;
    Node* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    
    return popped;
}

int operate(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '%': return operand1 % operand2;
        default: return 0;
    }
}



int main() {
    char buffer[5000005];
    Node* root = NULL;

    while (fgets(buffer, 5e6, stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        char* token = strtok(buffer, " ");

        while (token != NULL) {
            if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) 
            {
                push(&root, atoi(token));
                //printStack(root);
            }
            else if (strchr("+-*%", token[0]) != NULL && strlen(token) == 1) 
            {
                if (isEmpty(root) || isEmpty(root->next)) 
                {
                    printStack(root);
                    return 0;
                }
                int operand2 = pop(&root);
                int operand1 = pop(&root);
                int result = operate(operand1, operand2, token[0]);
                push(&root, result);
                //printStack(root);

            } else 
            {
                printStack(root);
                return 0;
            }
            token = strtok(NULL, " ");
        }
    }
    printStack(root);
    return 0;
}