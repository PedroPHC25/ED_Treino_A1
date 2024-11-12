#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

// Estruturas
typedef struct Node
{
    int* arriData;
    Node* ptrNext;
} Node;

typedef struct Queue
{
    Node* ptrFirst;
    Node* ptrLast;
} Queue;

// Protótipos
Node* newNode(int*);
Queue* newQueue();
bool isQueueEmpty(Queue*);
void showAllElements(Queue*);
void enQueue(Queue*, int*);
void deQueue(Queue*);
void enQueueFront(Queue*, int*);
bool areArraysEqual(int*, int*);
void removeElement(Queue*, int*);
void invertQueue(Queue*);
bool isThereElement(Queue*, int*);


int main()
{
    cout << "------------ 1 ------------" << endl;
    Queue* queue = newQueue();
    showAllElements(queue);
    deQueue(queue);
    invertQueue(queue);

    cout << "------------ 2 ------------" << endl;
    int arriData1[3] = {1, 2, 3};
    enQueue(queue, arriData1);
    showAllElements(queue);
    invertQueue(queue);
    showAllElements(queue);

    cout << "------------ 3 ------------" << endl;
    deQueue(queue);
    showAllElements(queue);

    cout << "------------ 4 ------------" << endl;
    int arriData6[3] = {1, 2, 3};
    enQueueFront(queue, arriData6);
    showAllElements(queue);

    cout << "------------ 5 ------------" << endl;
    int arriData2[3] = {4, 5, 6};
    enQueue(queue, arriData2);
    int arriData3[3] = {7, 8, 9};
    enQueue(queue, arriData3);
    int arriData4[3] = {10, 11, 12};
    enQueue(queue, arriData4);
    int arriData5[3] = {13, 14, 15};
    enQueue(queue, arriData5);    

    showAllElements(queue);

    cout << "------------ 6 ------------" << endl;
    deQueue(queue);
    showAllElements(queue);

    cout << "------------ 7 ------------" << endl;
    int arriData7[3] = {1, 2, 3};
    enQueueFront(queue, arriData7);
    showAllElements(queue);

    cout << "------------ 8 ------------" << endl;
    int arriData8[3] = {1, 2, 3};
    int arriData9[3] = {1, 2, 3};
    cout << areArraysEqual(arriData8, arriData9) << endl;
    
    cout << "------------ 9 ------------" << endl;

    int arriData10[3] = {1, 2, 3};
    int arriData11[3] = {1, 2, 3};
    int arriData12[3] = {1, 2, 3};
    enQueueFront(queue, arriData10);
    enQueueFront(queue, arriData11);
    enQueueFront(queue, arriData12);

    showAllElements(queue);

    int arriData13[3] = {1, 2, 3};
    removeElement(queue, arriData13);

    showAllElements(queue);

    cout << "------------ 10 ------------" << endl;

    Queue* queue2 = newQueue();

    int arriData14[3] = {1, 2, 3};
    int arriData15[3] = {0, 0, 0};
    int arriData16[3] = {1, 2, 3};
    int arriData17[3] = {1, 2, 3};
    int arriData18[3] = {0, 0, 0};
    int arriData19[3] = {1, 2, 3};
    int arriData20[3] = {1, 2, 3};

    enQueue(queue2, arriData14);
    enQueue(queue2, arriData15);
    enQueue(queue2, arriData16);
    enQueue(queue2, arriData17);
    enQueue(queue2, arriData18);
    enQueue(queue2, arriData19);
    enQueue(queue2, arriData20);

    showAllElements(queue2);

    removeElement(queue2, arriData13);
    
    showAllElements(queue2);

    cout << "------------ 11 ------------" << endl;

    Queue* queue3 = newQueue();

    enQueue(queue3, arriData14);
    enQueue(queue3, arriData14);
    enQueue(queue3, arriData14);
    enQueue(queue3, arriData14);
    enQueue(queue3, arriData14);

    showAllElements(queue3);

    removeElement(queue3, arriData14);

    showAllElements(queue3);

    cout << "------------ 12 ------------" << endl;

    showAllElements(queue);
    removeElement(queue, arriData14);
    showAllElements(queue);

    cout << "------------ 13 ------------" << endl;

    showAllElements(queue);
    invertQueue(queue);
    showAllElements(queue);

    cout << "------------ 14 ------------" << endl;

    Queue* queue4 = newQueue();

    enQueue(queue4, arriData14);
    enQueue(queue4, arriData15);

    showAllElements(queue4);
    invertQueue(queue4);
    showAllElements(queue4);

    cout << "------------ 15 ------------" << endl;

    cout << isThereElement(queue4, arriData14) << endl;
    cout << isThereElement(queue4, arriData3) << endl;


    return 0;
}

// Função para criar um novo nó
Node* newNode(int* arriData)
{
    Node* temp = (Node*) malloc(sizeof(Node));

    temp -> arriData = arriData;
    temp -> ptrNext = NULL;

    return temp;
}

// Função para criar uma nova fila
Queue* newQueue()
{
    Queue* temp = (Queue*) malloc(sizeof(Queue));

    temp -> ptrFirst = NULL;
    temp -> ptrLast = NULL;

    return temp;
}

// Função para checar se a fila está vazia
bool isQueueEmpty(Queue* const queue)
{
    return (queue -> ptrFirst == NULL);
}

// Função para mostrar todos os elementos
void showAllElements(Queue* const queue)
{
    if (isQueueEmpty(queue))
    {
        cout << "Fila vazia" << endl;
    }
    else
    {
        Node* current = queue -> ptrFirst;
        cout << "Elementos: ";

        while (current != NULL)
        {
            cout << "[";
            for (int i = 0; i <= 1; i++)
            {
                cout << current -> arriData[i] << ",";
            }
            cout << current -> arriData[2] << "]; ";
            current = current -> ptrNext;
        }
        cout << endl;
    }
}

// Função para enfileirar um nó
void enQueue(Queue* queue, int* arriData)
{
    Node* temp = newNode(arriData);

    if (isQueueEmpty(queue))
    {
        queue -> ptrFirst = temp;
        queue -> ptrLast = temp;
    }
    else
    {
        queue -> ptrLast -> ptrNext = temp;
        queue -> ptrLast = temp;
    }
}

// Função para desenfileirar um nó
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

        queue -> ptrFirst = temp -> ptrNext;

        free(temp);
    }
}

// Função para inserir um nó na frente da fila
void enQueueFront(Queue* queue, int* arriData)
{
    // Criando o nó
    Node* temp = newNode(arriData);

    // Se a fila está vazia...
    if (isQueueEmpty(queue))
    {
        // Ele passa a ser o primeiro e o último
        queue -> ptrFirst = temp;
        queue -> ptrLast = temp;
    }
    // Se não...
    else
    {
        // Ele passa a apontar para o primeiro
        temp -> ptrNext = queue -> ptrFirst;
        // E depois passa a ser o primeiro
        queue -> ptrFirst = temp;
    }
}

// Função para conferir se o conteúdo de dois arrays são iguais
bool areArraysEqual(int* arriData1, int* arriData2)
{
    // Booleano a ser retornado
    bool bAreEquals = true;

    // Para todos os elementos dos arrays
    for (int i = 0; i < 3; i++)
    {
        // Se os correspondentes forem diferentes
        if (arriData1[i] != arriData2[i])
        {
            // Não são mais iguais
            bAreEquals = false;
        }
    }

    return bAreEquals;
}

// Função para remover todas as cópias de um elemento específico
void removeElement(Queue* queue, int* arriData)
{
    // Se a fila está vazia, não faz nada
    if (isQueueEmpty(queue))
    {
        cout << "Fila vazia" << endl;
        return;
    }

    // Enquanto o primeiro elemento for igual ao especificado...
    while (areArraysEqual(queue -> ptrFirst -> arriData, arriData))
    {
        // Desenfileira ele
        deQueue(queue);
        // Se a fila se torna vazia depois disso, encerra a função
        if (isQueueEmpty(queue))
        {
            return;
        }
    }

    // Ponteiros para iterar sobre o meio da fila
    Node* current = queue -> ptrFirst;
    Node* previous = NULL;

    // Enquanto não chega ao último elemento...
    while (current -> ptrNext != NULL)
    {
        // Se ele é igual ao especificado...
        if (areArraysEqual(current -> arriData, arriData))
        {
            // Cria um temporário para fazer o free
            Node* temp = current;
            // "Costura" a fila
            previous -> ptrNext = current -> ptrNext;
            // Meu previous fica parado, mas meu current avança
            current = current -> ptrNext;
            free(temp);
        }
        // Se não...
        else
        {
            // Apenas avança os dois normalmente
            previous = current;
            current = current -> ptrNext;
        }
    }

    // Se o último elemento for igual ao especificado...
    if (areArraysEqual(queue -> ptrLast -> arriData, arriData))
    {
        // O penúltimo passa a ser o último
        queue -> ptrLast = previous;
        // O penúltimo passa a apontar para nulo
        previous -> ptrNext = NULL;
        free(current);
    }

    return;
}

// Função para inverter uma lista
void invertQueue(Queue* queue)
{
    // Se a fila está vazia, não faz nada
    if (isQueueEmpty(queue))
    {
        cout << "Fila vazia" << endl;
    }
    // Se ela tiver só um elemento, também não
    else if (queue -> ptrFirst -> ptrNext == NULL)
    {
        return;
    }
    // Se ela tiver mais de um elemento...
    else
    {
        // Ponteiros para iterar sobre a fila
        Node* previous = NULL;
        Node* current = queue -> ptrFirst;
        Node* next = queue -> ptrFirst -> ptrNext;
        // O primeiro elemento passa a ser o último
        queue -> ptrLast = current;

        // Enquanto não chega ao último...
        while (current -> ptrNext != NULL)
        {
            // O meu atual passa a apontar para o anterior
            current -> ptrNext = previous;
            // Avança na fila
            previous = current;
            current = next;
            next = next -> ptrNext;
        }

        // O último aponta para o penúltimo
        current -> ptrNext = previous;
        // O último passa a ser o primeiro
        queue -> ptrFirst = current;
    }
}

// Função para checar se um elemento está na lista
bool isThereElement(Queue* const queue, int* arriData)
{
    // Ponteiro para percorrer a fila
    Node* current = queue -> ptrFirst;

    // Enquanto não sai da fila...
    while (current != NULL)
    {
        // Se o valor do nó for igual ao especificado...
        if (areArraysEqual(current -> arriData, arriData))
        {
            return true;
        }
        // Avança na fila
        current = current -> ptrNext;
    }

    return false;
}