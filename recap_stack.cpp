#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

// Pilha
    // 1. Estrutura de um nó
    // 2. Estrutura de uma pilha
    // 3. Função para criar um nó
    // 4. Função para criar uma pilha
    // 5. Função para adicionar um elemento (push)
    // 6. Função para remover um elemento (pop)
    // 7. Função para exibir o primeiro elemento
    // 8. Função para exibir todos os elementos


typedef struct Node
{
    int iData;
    Node* ptrNext;
} Node;

typedef struct Stack
{
    Node* ptrTop;
} Stack;


Node* newNode(int);
Stack* newStack();
bool isStackEmpty(Stack*);
void showTopElement(Stack*);
void showAllElements(Stack*);
void push(Stack*, int);
void pop(Stack*);


int main()
{
    Stack* stack = newStack();

    showTopElement(stack);
    showAllElements(stack);

    cout << "================" << endl;

    push(stack, 1);

    showTopElement(stack);
    showAllElements(stack);

    cout << "================" << endl;

    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    showTopElement(stack);
    showAllElements(stack);

    cout << "================" << endl;

    pop(stack);

    showTopElement(stack);
    showAllElements(stack);

    return 0;
}



Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));

    temp -> iData = iValue;
    temp -> ptrNext = NULL;

    return temp;
}

Stack* newStack()
{
    Stack* temp = (Stack*) malloc(sizeof(Stack));

    temp -> ptrTop = NULL;

    return temp;
}

bool isStackEmpty(Stack* stack)
{
    return stack -> ptrTop == NULL;
}

void showTopElement(Stack* stack)
{
    if (isStackEmpty(stack))
    {
        cout << "Pilha vazia" << endl;
    }
    else
    {
        cout << "Elemento do topo: " << stack -> ptrTop -> iData << endl;
    }
}

void showAllElements(Stack* stack)
{
    if (isStackEmpty(stack))
    {
        cout << "Pilha vazia" << endl;
    }
    else
    {
        Node* current = stack -> ptrTop;
        int position = 1;

        while (current != NULL)
        {
            cout << "Elemento " << position << ": " << current -> iData << endl;
            current = current -> ptrNext;
            position = position + 1;
        }
    }
}

void push(Stack* stack, int iValue)
{
    Node* temp = newNode(iValue);

    temp -> ptrNext = stack -> ptrTop;
    stack -> ptrTop = temp;
}

void pop(Stack* stack)
{
    if (isStackEmpty(stack))
    {
        cout << "Pilha vazia" << endl;
        return;
    }

    Node* temp = stack -> ptrTop;

    stack -> ptrTop = stack -> ptrTop -> ptrNext;

    free(temp);
}