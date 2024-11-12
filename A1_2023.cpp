#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

// Estrutura da matrícula
typedef struct Reg
{
    int iNumReg;
    Reg* ptrNext;
    
} Reg;

// Estrutura da lista de matrículas
typedef struct RegsList
{
    Reg* ptrFirst;

} RegsList;

// Protótipos das funções
Reg* newReg(int);
RegsList* newRegsList();
bool isRegsListEmpty(RegsList*);
void showAllRegs(RegsList*);
void addReg(RegsList*, int);
void removeReg(RegsList*, int);
void swapFirstLast(RegsList*);
RegsList* intersection(RegsList*, RegsList*);
void cleanList(RegsList*);
int isThereLoop(RegsList*);


int main()
{
    // Criando uma lista de matrículas
    RegsList* list1 = newRegsList();
    cout << "-- Mostrando os elementos de uma lista vazia: " << endl;
    showAllRegs(list1);
    cout << "-- Removendo um elemento de uma lista vazia: " << endl;
    removeReg(list1, 2401);

    cout << "====================================================================" << endl;

    // Adicionando um registro com a lista vazia
    addReg(list1, 2401);
    cout << "-- Mostrando os elementos de uma lista com um elemento: " << endl;
    showAllRegs(list1);
    cout << "-- Removendo um elemento de uma lista com um elemento: " << endl;
    removeReg(list1, 2401);
    showAllRegs(list1);

    cout << "====================================================================" << endl;

    // Adicionando mais registros
    addReg(list1, 2402);
    addReg(list1, 2403);
    addReg(list1, 2404);
    addReg(list1, 2405);
    addReg(list1, 2406);
    addReg(list1, 2407);
    addReg(list1, 2408);
    addReg(list1, 2409);
    addReg(list1, 2410);
    addReg(list1, 2411);
    addReg(list1, 2412);
    addReg(list1, 2413);
    addReg(list1, 2414);
    addReg(list1, 2415);

    cout << "-- Mostrando os elementos de uma lista com mais de um elemento: " << endl;
    showAllRegs(list1);

    cout << "====================================================================" << endl;

    cout << "-- Removendo o primeiro elemento de uma lista: " << endl;
    removeReg(list1, 2402);
    showAllRegs(list1);

    cout << "-- Tentando remover um elemento que nao existe: " << endl;
    removeReg(list1, 314);

    cout << "-- Removendo um elemento qualquer: " << endl;
    removeReg(list1, 2410);
    showAllRegs(list1);

    cout << "====================================================================" << endl;

    // Nova lista
    RegsList* list2 = newRegsList();

    cout << "-- Trocando o primeiro e o ultimo de uma lista vazia: " << endl;
    swapFirstLast(list2);

    cout << "-- Trocando o primeiro e o ultimo de uma lista com um elemento: " << endl;
    addReg(list2, 3401);
    showAllRegs(list2);

    swapFirstLast(list2);
    showAllRegs(list2);

    cout << "-- Trocando o primeiro e o ultimo de uma lista com dois elementos: " << endl;
    addReg(list2, 3402);
    showAllRegs(list2);

    swapFirstLast(list2);
    showAllRegs(list2);

    cout << "-- Trocando o primeiro e o ultimo de uma lista com mais de dois elementos: " << endl;
    addReg(list2, 3403);
    addReg(list2, 3404);
    addReg(list2, 3405);
    addReg(list2, 3406);
    addReg(list2, 3407);

    showAllRegs(list2);
    swapFirstLast(list2);
    showAllRegs(list2);

    cout << "====================================================================" << endl;

    // Novas listas
    RegsList* list3 = newRegsList();
    addReg(list3, 4401);
    addReg(list3, 4402);
    addReg(list3, 4403);
    addReg(list3, 4404);
    addReg(list3, 4405);

    RegsList* list4 = newRegsList();
    addReg(list4, 4401);
    addReg(list4, 4403);
    addReg(list4, 4405);
    addReg(list4, 4407);
    addReg(list4, 4409);

    RegsList* list5 = newRegsList();

    cout << "-- Intersecao padrao: " << endl;
    RegsList* intersection34 = intersection(list3, list4);
    showAllRegs(intersection34);
    cout << "-- Intersecao com uma lista vazia: " << endl;
    RegsList* intersection45 = intersection(list4, list5);
    showAllRegs(intersection45);

    cout << "====================================================================" << endl;

    RegsList* list6 = newRegsList();

    addReg(list6, 5401);
    addReg(list6, 5402);
    addReg(list6, 5403);
    addReg(list6, 5404);
    addReg(list6, 5405);
    addReg(list6, 5403);

    showAllRegs(list6);
    cout << "Tamanho do loop: " << isThereLoop(list6) << endl;

    cout << "====================================================================" << endl;

    cleanList(list1);
    showAllRegs(list1);

    return 0;
}

// Função para criar uma nova matrícula
Reg* newReg(int iReg)
{
    Reg* temp = (Reg*) malloc(sizeof(Reg));
    temp -> iNumReg = iReg;
    temp -> ptrNext = NULL;

    return temp;
}

// Função para criar uma nova lista de matrículas
RegsList* newRegsList()
{
    RegsList* temp = (RegsList*) malloc(sizeof(RegsList));
    temp -> ptrFirst = NULL;

    return temp;
}

// Função para conferir se a lista está vazia
bool isRegsListEmpty(RegsList* regslist)
{
    return regslist -> ptrFirst == NULL;
}

// Função para mostrar todas as matrículas de uma lista
void showAllRegs(RegsList* regslist)
{
    // Se a lista está vazia...
    if (isRegsListEmpty(regslist))
    {
        cout << "Lista de matriculas vazia" << endl;
    }
    else
    {
        // Caminha pelas matrículas da lista exibindo cada uma
        Reg* current = regslist -> ptrFirst;
        cout << "Matriculas: ";

        while (current != NULL)
        {
            cout << current -> iNumReg << "; ";
            current = current -> ptrNext;
        }

        cout << endl;
    }
}

// Função para adicionar uma matrícula a uma lista
void addReg(RegsList* regslist, int iNumReg)
{
    // Criando a matrícula
    Reg* temp = newReg(iNumReg);
    
    // Se a lista está vazia...
    if (isRegsListEmpty(regslist))
    {
        // A nova matrícula se torna a primeira da lista
        regslist -> ptrFirst = temp;
    }
    else
    {
        // Encontra a última matrícula da lista
        Reg* lastReg = regslist -> ptrFirst;

        while (lastReg -> ptrNext != NULL)
        {
            lastReg = lastReg -> ptrNext;
        }

        // Conecta a nova matrícula ao final da lista
        lastReg -> ptrNext = temp;
    }
}

// Função para remover uma matrícula específica de uma lista
void removeReg(RegsList* regslist, int iNumReg)
{
    // Se a lista está vazia...
    if (isRegsListEmpty(regslist))
    {
        cout << "Lista de matriculas vazia" << endl;
    }
    // Se o elemento a ser removido é o primeiro da lista...
    else if (regslist -> ptrFirst -> iNumReg == iNumReg)
    {
        // Ponteiro auxiliar para a matrícula que será removida
        Reg* temp = regslist -> ptrFirst;
        // O primeiro elemento passa a ser o seguinte ao que será removido
        regslist -> ptrFirst = temp -> ptrNext;
        free(temp);
    }
    else
    {
        // Ponteiros do elemento atual e anterior para a iteração
        Reg* current = regslist -> ptrFirst;
        Reg* previous = NULL;

        // Enquanto não encontrar a matrícula a ser removida...
        while (current -> iNumReg != iNumReg)
        {
            // Avançam para o próximo
            previous = current;
            current = current -> ptrNext;
            // Se chegar no final da fila, o elemento não existe
            if (current == NULL)
            {
                cout << "Matricula nao encontrada" << endl;
                return;
            }
        }

        // "Costura" a lista e remove o elemento
        previous -> ptrNext = current -> ptrNext;
        free(current);
    }
}

// Função para trocar o primeiro e o último elemento
void swapFirstLast(RegsList* regslist)
{
    // Se a lista é vazia, não faz sentido
    if (isRegsListEmpty(regslist))
    {
        cout << "Lista de matriculas vazia" << endl;
    }
    // Se a lista tem só um elemento, não precisa fazer nada
    else if (regslist -> ptrFirst -> ptrNext == NULL)
    {
        return;
    }
    // Se a lista tem só 2 elementos...
    else if (regslist -> ptrFirst -> ptrNext -> ptrNext == NULL)
    {
        // Ponteiro do segundo elemento
        Reg* secondReg = regslist -> ptrFirst -> ptrNext;
        // O segundo aponta pro primeiro
        secondReg -> ptrNext = regslist -> ptrFirst;
        // O primeiro aponta pro nada
        regslist -> ptrFirst -> ptrNext = NULL;
        // O segundo vira o primeiro
        regslist -> ptrFirst = secondReg;
    }
    else
    {
        // Ponteiros do primeiro, do segundo, do penúltimo e do último elementos
        Reg* firstReg = regslist -> ptrFirst;
        Reg* secondReg = regslist -> ptrFirst -> ptrNext;
        Reg* penultimateReg = NULL;
        Reg* lastReg = regslist -> ptrFirst;

        // Encontrando os dois últimos elementos
        while (lastReg -> ptrNext != NULL)
        {
            penultimateReg = lastReg;
            lastReg = lastReg -> ptrNext;
        }

        // O penúltimo aponta pro primeiro
        penultimateReg -> ptrNext = firstReg;
        // O primeiro aponta pro nada
        firstReg -> ptrNext = NULL;
        // O último vira o primeiro
        regslist -> ptrFirst = lastReg;
        // O último aponta pro segundo
        lastReg -> ptrNext = secondReg;
    }
}

// Função para encontrar a interseção entre duas listas
RegsList* intersection(RegsList* list1, RegsList* list2)
{
    // Lista com a interseção
    RegsList* intersection = newRegsList();

    // Se alguma delas está vazia, a interseção também é vazia
    if (isRegsListEmpty(list1) || isRegsListEmpty(list2))
    {
        return intersection;
    }
    else
    {
        // Ponteiro para iterar sobre a lista 1
        Reg* current1 = list1 -> ptrFirst;
        // Para cada elemento da lista 1...
        while (current1 != NULL)
        {
            // Cria um ponteiro para iterar sobre a lista 2
            Reg* current2 = list2 -> ptrFirst;
            // Itera sobre todos os elementos da lista 2
            while (current2 != NULL)
            {  
                // Se os valores forem iguais, adiciona à lista de interseção
                if (current1 -> iNumReg == current2 -> iNumReg)
                {
                    addReg(intersection, current1 -> iNumReg);
                }
                // Avança para o próximo
                current2 = current2 -> ptrNext;
            }
            // Avança para o próximo
            current1 = current1 -> ptrNext;
        }

        return intersection;
    }
}

// Função para apagar uma lista
void cleanList(RegsList* const regslist)
{
    // Se a lista é vazia, não faz nada
    if (isRegsListEmpty(regslist))
    {
        cout << "Lista vazia" << endl;
    }
    else
    {
        // Ponteiros atual e anterior para caminhar pela lista
        Reg* current = regslist -> ptrFirst;
        Reg* previous = NULL;

        // Iterando sobre toda a lista
        while (current != NULL)
        {
            // Avança os ponteiros e libera o anterior
            previous = current;
            current = current -> ptrNext;
            free(previous);
        }

        regslist -> ptrFirst = NULL;
    }
}

// Função para descobrir se há um loop na lista
int isThereLoop(RegsList* regslist)
{
    // Se a lista for vazia, não faz sentido
    if (isRegsListEmpty(regslist))
    {
        return -1;
    }
    else
    {
        // Lista com os elementos anteriores ao atual
        RegsList* previousRegs = newRegsList();
        // Elemento atual
        Reg* current = regslist -> ptrFirst;
        // Variável para ativar a contagem com o loopSize
        bool isThereLoop = false;
        int loopSize = 0;

        // Iterando sobre todos os elementos da lista até que um loop seja encontrado
        while (current != NULL && !isThereLoop)
        {
            // Ponteiro para caminhar pelos anteriores
            Reg* somePreviousReg = previousRegs -> ptrFirst;

            // Iterando sobre todos os anteriores
            while (somePreviousReg != NULL)
            {
                // Se o dado do atual for igual ao do anterior...
                if (somePreviousReg -> iNumReg == current -> iNumReg)
                {
                    // Há um loop
                    isThereLoop = true;
                }
                // A partir do momento que a variável foi ativada...
                if (isThereLoop)
                {
                    // Começa a contar o número de elementos até o final da lista de anteriores
                    loopSize++;
                }
                // Avança na lista de anteriores
                somePreviousReg = somePreviousReg -> ptrNext;
            }

            // Adiciona o atual à lista de anteriores
            addReg(previousRegs, current -> iNumReg);
            // Avança na lista original
            current = current -> ptrNext;
        }

        cleanList(previousRegs);
        return loopSize;
    }
}