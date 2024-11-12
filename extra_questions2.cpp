#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

typedef struct Piece
{
    int iNum;
    Piece* ptrNext;
} Piece;

typedef struct Stack
{
    Piece* ptrTop;
} Stack;

typedef struct Hanoi
{
    Stack* ptrStack1;
    Stack* ptrStack2;
    Stack* ptrStack3;
} Hanoi;

Piece* newPiece(int);
Stack* newStack();
Hanoi* newHanoi(Stack*, Stack*, Stack*);
void showHanoi(Hanoi*);
void push(Stack*, int);
void pop(Stack*);
bool isStackEmpty(Stack*);
void movePiece(Hanoi*, int, int);
void play(Hanoi*);
bool checkVictory(Stack*);


int main()
{
    Stack* ptrStack1 = newStack();
    Stack* ptrStack2 = newStack();
    Stack* ptrStack3 = newStack();

    Hanoi* ptrHanoi = newHanoi(ptrStack1, ptrStack2, ptrStack3);

    push(ptrStack1, 5);
    push(ptrStack1, 4);
    push(ptrStack1, 3);
    push(ptrStack1, 2);
    push(ptrStack1, 1);

    play(ptrHanoi);
    
    return 0;
}


Piece* newPiece(int iNum)
{
    Piece* temp = (Piece*) malloc(sizeof(Piece));

    temp -> iNum = iNum;
    temp -> ptrNext = NULL;

    return temp;
}

Stack* newStack()
{
    Stack* temp = (Stack*) malloc(sizeof(Stack));

    temp -> ptrTop = NULL;

    return temp;
}

Hanoi* newHanoi(Stack* ptrStack1, Stack* ptrStack2, Stack* ptrStack3)
{
    Hanoi* temp = (Hanoi*) malloc(sizeof(Hanoi));

    temp -> ptrStack1 = ptrStack1;
    temp -> ptrStack2 = ptrStack2;
    temp -> ptrStack3 = ptrStack3;

    return temp;
}

void showHanoi(Hanoi* ptrHanoi)
{
    Piece* current = ptrHanoi -> ptrStack1 -> ptrTop;
    cout << "Pilha 1: ";
    while (current != NULL)
    {
        cout << current -> iNum << " ";
        current = current -> ptrNext;
    }
    cout << endl;

    current = ptrHanoi -> ptrStack2 -> ptrTop;
    cout << "Pilha 2: ";
    while (current != NULL)
    {
        cout << current -> iNum << " ";
        current = current -> ptrNext;
    }
    cout << endl;

    current = ptrHanoi -> ptrStack3 -> ptrTop;
    cout << "Pilha 3: ";
    while (current != NULL)
    {
        cout << current -> iNum << " ";
        current = current -> ptrNext;
    }
    cout << endl;
}

void push(Stack* ptrStack, int iNum)
{
    Piece* temp = newPiece(iNum);

    temp -> ptrNext = ptrStack -> ptrTop;
    ptrStack -> ptrTop = temp;
}

bool isStackEmpty(Stack* ptrStack)
{
    return (ptrStack -> ptrTop == NULL);
}

void pop(Stack* ptrStack)
{
    if (isStackEmpty(ptrStack))
    {
        cout << "Pilha vazia" << endl;
    }
    else
    {
        Piece* temp = ptrStack -> ptrTop;
        ptrStack -> ptrTop = temp -> ptrNext;
        free(temp);
    }
}

void movePiece(Hanoi* ptrHanoi, int iNum, int iStack)
{
    if (ptrHanoi -> ptrStack1 -> ptrTop != NULL && ptrHanoi -> ptrStack1 -> ptrTop -> iNum == iNum)
    {
        if (iStack == 1)
        {
            cout << "Movimento inutil, mas ok." << endl;
        }
        else if (iStack == 2 && (ptrHanoi -> ptrStack2 -> ptrTop == NULL || ptrHanoi -> ptrStack2 -> ptrTop -> iNum > iNum))
        {
            cout << "Teste" << endl;
            pop(ptrHanoi -> ptrStack1);
            push(ptrHanoi -> ptrStack2, iNum);
        }
        else if (iStack == 3 && (ptrHanoi -> ptrStack3 -> ptrTop == NULL || ptrHanoi -> ptrStack3 -> ptrTop -> iNum > iNum))
        {
            pop(ptrHanoi -> ptrStack1);
            push(ptrHanoi -> ptrStack3, iNum);
        }
        else
        {
            cout << "Jogada invalida" << endl;
        }
    }
    else if (ptrHanoi -> ptrStack2 -> ptrTop != NULL && ptrHanoi -> ptrStack2 -> ptrTop -> iNum == iNum)
    {
        if (iStack == 1 && (ptrHanoi -> ptrStack1 -> ptrTop == NULL || ptrHanoi -> ptrStack1 -> ptrTop -> iNum > iNum))
        {
            pop(ptrHanoi -> ptrStack2);
            push(ptrHanoi -> ptrStack1, iNum);
        }
        else if (iStack == 2)
        {
            cout << "Movimento inutil, mas ok." << endl;
        }
        else if (iStack == 3 && (ptrHanoi -> ptrStack3 -> ptrTop == NULL || ptrHanoi -> ptrStack3 -> ptrTop -> iNum > iNum))
        {
            pop(ptrHanoi -> ptrStack2);
            push(ptrHanoi -> ptrStack3, iNum);
        }
        else
        {
            cout << "Jogada invalida" << endl;
        }
    }
    else if (ptrHanoi -> ptrStack3 -> ptrTop != NULL && ptrHanoi -> ptrStack3 -> ptrTop -> iNum == iNum)
    {
        if (iStack == 1 && (ptrHanoi -> ptrStack1 -> ptrTop == NULL || ptrHanoi -> ptrStack1 -> ptrTop -> iNum > iNum))
        {
            pop(ptrHanoi -> ptrStack3);
            push(ptrHanoi -> ptrStack1, iNum);
        }
        else if (iStack == 2 && (ptrHanoi -> ptrStack2 -> ptrTop == NULL || ptrHanoi -> ptrStack2 -> ptrTop -> iNum > iNum))
        {
            pop(ptrHanoi -> ptrStack3);
            push(ptrHanoi -> ptrStack2, iNum);
        }
        else if (iStack == 3)
        {
            cout << "Movimento inutil, mas ok." << endl;
        }
        else
        {
            cout << "Jogada invalida" << endl;
        }
    }
    else
    {
        cout << "Jogada invalida" << endl;
    }
}

bool checkVictory(Stack* ptrStack)
{
    Piece* current = ptrStack -> ptrTop;
    int iNumPiece = 1;

    while (iNumPiece <= 5)
    {
        if (current == NULL || current -> iNum != iNumPiece)
        {
            return false;
        }
        current = current -> ptrNext;
        iNumPiece++;
    }

    return true;
}

void play(Hanoi* ptrHanoi)
{
    cout << "-> Jogo iniciado! Lembrando que o topo de cada pilha eh a esquerda!" << endl;
    cout << "-> Digite 0 para sair do jogo." << endl;
    cout << "=========================================================================" << endl;
    showHanoi(ptrHanoi);

    int iPieceMoved = 0;
    int iStackPut = 0;
    int iNumMoves = 1;

    while (true)
    {
        cout << "=========================================================================" << endl;
        cout << "-> JOGADA " << iNumMoves << endl;
        cout << "-> Escolha uma peca para mexer: ";
        cin >> iPieceMoved;
        if (iPieceMoved == 0){break;}
        cout << "-> Escolha uma pilha para colocar a peca: ";
        cin >> iStackPut;
        if (iStackPut == 0){break;}

        cout << "=========================================================================" << endl;
        movePiece(ptrHanoi, iPieceMoved, iStackPut);
        iNumMoves++;

        cout << "=========================================================================" << endl;
        showHanoi(ptrHanoi);

        if (iPieceMoved == 1)
        {
            if (iStackPut == 2 && checkVictory(ptrHanoi -> ptrStack2))
            {
                cout << "=========================================================================" << endl;
                cout << "-> Parabens! Voce venceu em " << iNumMoves << " movimentos!" << endl;
                cout << "=========================================================================" << endl;
                return;
            }
            else if (iStackPut == 3 && checkVictory(ptrHanoi -> ptrStack3))
            {
                cout << "=========================================================================" << endl;
                cout << "-> Parabens! Voce venceu em " << iNumMoves << " movimentos!" << endl;
                cout << "=========================================================================" << endl;
                return;
            }
        }
    }
}