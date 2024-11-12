#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

// Lista escadeada
    // 1. Estrutura da lista encadeada
    // 2. Estrutura do nó
    // 3. Função para criar uma lista encadeada
    // 4. Função para criar um nó
    // 5. Função para inserir um elemento
    // 6. Função para remover um elemento
    // 7. Função para exibir o primeiro elemento
    // 8. Função para exibir o último elemento
    // 9. Função para exibir todos os elementos


typedef struct Node
{
    int iData;
    Node* ptrNext;
} Node;

typedef struct LinkedList
{
    Node* ptrFirst;
} LinkedList;


Node* newNode(int);
LinkedList* newLinkedList();
void showFirstElement(LinkedList*);
void showLastElement(LinkedList*);
void showAllElements(LinkedList*);
void addElement(LinkedList*, int, int);
void removeElement(LinkedList*, int);


int main()
{
    LinkedList* linkedlist = newLinkedList();
    LinkedList* nulllinkedlist = NULL;

    showFirstElement(linkedlist);
    showFirstElement(nulllinkedlist);
    
    showLastElement(linkedlist);
    showAllElements(linkedlist);

    removeElement(linkedlist, 5);

    cout << "=====================" << endl;

    addElement(linkedlist, 1, 1);

    showFirstElement(linkedlist);
    showLastElement(linkedlist);
    showAllElements(linkedlist);

    removeElement(linkedlist, 1);

    showFirstElement(linkedlist);
    showLastElement(linkedlist);
    showAllElements(linkedlist);

    cout << "=====================" << endl;

    addElement(linkedlist, 2, 1);

    showFirstElement(linkedlist);
    showLastElement(linkedlist);
    showAllElements(linkedlist);

    cout << "=====================" << endl;

    addElement(linkedlist, 3, 2);

    showFirstElement(linkedlist);
    showLastElement(linkedlist);
    showAllElements(linkedlist);

    cout << "=====================" << endl;

    addElement(linkedlist, 78, 10);

    cout << "=====================" << endl;

    addElement(linkedlist, 78, 3);
    addElement(linkedlist, 11, 5);
    addElement(linkedlist, 8, 1);
    addElement(linkedlist, 17, 6);
    addElement(linkedlist, 582, 2);

    showFirstElement(linkedlist);
    showLastElement(linkedlist);
    showAllElements(linkedlist);

    cout << "=====================" << endl;

    removeElement(linkedlist, 582);

    showFirstElement(linkedlist);
    showLastElement(linkedlist);
    showAllElements(linkedlist);

    cout << "=====================" << endl;

    removeElement(linkedlist, 13);

    showFirstElement(linkedlist);
    showLastElement(linkedlist);
    showAllElements(linkedlist);

    return 0;
}



Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));

    temp -> iData = iValue;
    temp -> ptrNext = NULL;

    return temp;
}

LinkedList* newLinkedList()
{
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));

    temp -> ptrFirst = NULL;

    return temp;
}

bool isLinkedListEmpty(LinkedList* linkedlist)
{
    return linkedlist -> ptrFirst == NULL;
}

void showFirstElement(LinkedList* linkedlist)
{
    if (linkedlist == NULL)
    {
        cout << "Lista inexistente" << endl;
    }
    else if (isLinkedListEmpty(linkedlist))
    {
        cout << "Lista vazia" << endl;
    }
    else
    {
        cout << "Primeiro elemento: " << linkedlist -> ptrFirst -> iData << endl;
    }
}

void showLastElement(LinkedList* linkedlist)
{
    if (linkedlist == NULL)
    {
        cout << "Lista inexistente" << endl;
    }
    else if (isLinkedListEmpty(linkedlist))
    {
        cout << "Lista vazia" << endl;
    }
    else
    {
        Node* current = linkedlist -> ptrFirst;

        while (current -> ptrNext != NULL)
        {
            current = current -> ptrNext;
        }

        cout << "Ultimo elemento: " << current -> iData << endl;
    }
}

void showAllElements(LinkedList* linkedlist)
{
    if (linkedlist == NULL)
    {
        cout << "Lista inexistente" << endl;
    }
    else if (linkedlist -> ptrFirst == NULL)
    {
        cout << "Lista vazia" << endl;
    }
    else
    {
        Node* current = linkedlist -> ptrFirst;
        int position = 1;

        while (current != NULL)
        {
            cout << "Elemento " << position << ": " << current -> iData << endl;
            current = current -> ptrNext;
            position++;
        }
    }
}

// Adiciona um elemento numa posição específica
void addElement(LinkedList* linkedlist, int iValue, int iPosition)
{
    Node* temp = newNode(iValue);

    // Se a posição não é positiva, não faz sentido
    if (iPosition <= 0)
    {
        cout << "Posicao invalida" << endl;
        return;
    }

    // Se a lista está vazia, só é válida a posição 1
    if (isLinkedListEmpty(linkedlist))
    {
        if (iPosition == 1)
        {
            linkedlist -> ptrFirst = temp;
            return;
        }
        else
        {
            cout << "Posicao invalida" << endl;
            return;
        }
    }

    // Caso para quando quero inserir na primeira posição
    if (iPosition == 1)
    {
        temp -> ptrNext = linkedlist -> ptrFirst;
        linkedlist -> ptrFirst = temp;
        return;
    }

    Node* current = linkedlist -> ptrFirst;

    // Caminha até a posição anterior à que eu quero
    for (int i = 2; i < iPosition; i++)
    {
        current = current -> ptrNext;
        // Se a lista acabar, a posição é inválida
        if (current == NULL)
        {
            cout << "Posicao invalida" << endl;
            return;
        }
    }

    // Coloca o nó naquela posição
    temp -> ptrNext = current -> ptrNext;
    current -> ptrNext = temp;
}

void removeElement(LinkedList* linkedlist, int iValue)
{
    // Caso de lista inexistente
    if (linkedlist == NULL)
    {
        cout << "Lista inexistente" << endl;
        return;
    }
    
    // Caso de lista vazia
    if (isLinkedListEmpty(linkedlist))
    {
        cout << "Lista vazia" << endl;
        return;
    }

    // Caso o elemento que eu quero seja o primeiro da lista
    if (linkedlist -> ptrFirst -> iData == iValue)
    {
        Node* temp = linkedlist -> ptrFirst;
        linkedlist -> ptrFirst = linkedlist -> ptrFirst -> ptrNext;
        free(temp);
        return;
    }

    Node* current = linkedlist -> ptrFirst;

    // Caminhando até o nó anterior ao que eu quero
    while (current -> ptrNext -> iData != iValue)
    {
        current = current -> ptrNext;
        // Se chegar no final da fila, o elemento não existe
        if (current -> ptrNext == NULL)
        {
            cout << "Elemento inexistente" << endl;
            return;
        }
    }

    // Removendo o nó
    Node* temp = current -> ptrNext;
    current -> ptrNext = temp -> ptrNext;
    free(temp);
}