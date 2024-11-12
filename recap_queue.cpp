#include <iostream>
#include <cstdlib>

using std::cout;
using std::string;
using std::endl;

// Fila
    // 1. Estrutura da fila
    // 2. Estrutura do nó
    // 3. Função para criar uma fila
    // 4. Função para criar um nó
    // 5. Função para inserir elemento
    // 6. Função para exibir o primeiro elemento
    // 7. Função para exibir o último elemento
    // 8. Função para exibir todos os elementos
    // 9. Função para remover um elemento

// Estrutura de um nó
typedef struct Node
{
    int iData;
    Node* ptrNext;
} Node;

// Estrutura de uma fila
typedef struct Queue
{
    Node* ptrFirst;
    Node* ptrLast;
} Queue;

// Função para criar uma fila
Queue* newQueue()
{
    Queue* temp = (Queue*) malloc(sizeof(Queue));
    temp -> ptrFirst = NULL;
    temp -> ptrLast = NULL;

    return temp;
}

// Função para criar um nó
Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp -> iData = iValue;
    temp -> ptrNext = NULL;

    return temp;
}

// Função para conferir se a fila está vazia
bool isQueueEmpty(Queue* queue)
{
    if (queue -> ptrFirst == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Função para mostrar o primeiro elemento
void showFirstElement(Queue* queue)
{
    if (isQueueEmpty(queue))
    {
        cout << "Fila vazia" << endl;
    }
    else
    {
        cout << "Primeiro elemento: " << queue -> ptrFirst -> iData << endl;
    }
}

// Função para mostrar o último elemento
void showLastElement(Queue* queue)
{
    if (isQueueEmpty(queue))
    {
        cout << "Fila vazia" << endl;
    }
    else
    {
        cout << "Ultimo elemento: " << queue -> ptrLast -> iData << endl;
    }
}

// Função para exibir todos os elementos
void showAllElements(Queue* queue)
{
    if (isQueueEmpty(queue))
    {
        cout << "Fila vazia" << endl;
    }
    else
    {
        Node* current = queue -> ptrFirst;
        int position = 1;

        while (current != NULL)
        {
            cout << "Elemento " << position << ": " << current -> iData << endl;
            current = current -> ptrNext;
            position = position + 1;
        }
    }
}

// Função para enfileirar um nó
void enQueue(Queue* queue, int iValue)
{
    Node* temp = newNode(iValue);

    if (isQueueEmpty(queue))
    {
        queue -> ptrFirst = temp;
        queue -> ptrLast = temp;

        return;
    }

    queue -> ptrLast -> ptrNext = temp;
    queue -> ptrLast = temp;
}

// Função que desenfileira um nó
void deQueue(Queue* queue)
{
    if (isQueueEmpty(queue))
    {
        cout << "Fila vazia" << endl;
    }
    else if (queue -> ptrFirst -> ptrNext == NULL)
    {
        Node* temp = queue -> ptrFirst;

        queue -> ptrFirst = NULL;
        queue -> ptrLast = NULL;

        free(temp);
    }
    else
    {
        Node* temp = queue -> ptrFirst;

        queue -> ptrFirst = queue -> ptrFirst -> ptrNext;

        free(temp);
    }
}


int main()
{
    Queue* queue = newQueue();
    showFirstElement(queue);
    showLastElement(queue);
    showAllElements(queue);

    deQueue(queue);

    cout << "=========================" << endl;

    enQueue(queue, 1);

    showFirstElement(queue);
    showLastElement(queue);
    showAllElements(queue);

    deQueue(queue);

    showFirstElement(queue);
    showLastElement(queue);
    showAllElements(queue);

    cout << "=========================" << endl;

    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);

    showFirstElement(queue);
    showLastElement(queue);
    showAllElements(queue);

    showFirstElement(queue);
    showLastElement(queue);
    showAllElements(queue);

    cout << "=========================" << endl;

    return 0;
}