#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <stdbool.h>

using namespace std;

#define ERRO -1
#define bool int
#define true 1
#define false 0

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO* A;       
    int nroElem;    
    int capacidade;   
} LISTA;

// Declaração das funções
void inicializarLista(LISTA* l);
void exibirLista(LISTA* l);
int tamanho(LISTA* l);
int tamanhoEmBytes(LISTA* l);
void reinicializarLista(LISTA* l);
int buscaSequencial(LISTA* l, TIPOCHAVE ch);
bool excluirElemLista(LISTA* l, TIPOCHAVE ch);
bool inserirElemListaOrd(LISTA* l, REGISTRO reg);
void resize(LISTA* l, int novaCapacidade);

void inicializarLista(LISTA* l) {
    l->capacidade = 50;
    l->A = (REGISTRO*)malloc(l->capacidade * sizeof(REGISTRO));
    if (l->A == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    l->nroElem = 0;
} 

void exibirLista(LISTA* l) {
    int i;
    printf("Lista: \" ");
    for (i = 0; i < l->nroElem; i++)
        printf("%i ", l->A[i].chave);
    printf("\"\n");
} 

int tamanho(LISTA* l) {
    return l->nroElem;
} 

int tamanhoEmBytes(LISTA* l) {
    return sizeof(LISTA) + l->capacidade * sizeof(REGISTRO); 
} 

int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
    int i = 0;
    while (i < l->nroElem) {
        if (ch == l->A[i].chave) return i; // achou
        i++;  // Incrementando corretamente
    }
    return ERRO; // Não encontrou
} 

void resize(LISTA* l, int novaCapacidade) {
    REGISTRO* temp = (REGISTRO*)realloc(l->A, novaCapacidade * sizeof(REGISTRO));
    if (temp == NULL) {
        printf("Erro ao redimensionar a lista!\n");
        exit(1);
    }
    l->A = temp;
    l->capacidade = novaCapacidade;
} 

bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
    if (l->nroElem >= l->capacidade) {
        resize(l, l->capacidade * 2); 
    }
    int pos = l->nroElem;
    while (pos > 0 && l->A[pos - 1].chave > reg.chave) {
        l->A[pos] = l->A[pos - 1];
        pos--;
    }
    l->A[pos] = reg;
    l->nroElem++;
    return true;
} 

bool excluirElemLista(LISTA* l, TIPOCHAVE ch) {
    int pos, j;
    pos = buscaSequencial(l, ch);
    if (pos == ERRO) return false; // Não encontrou o elemento
    for (j = pos; j < l->nroElem - 1; j++) l->A[j] = l->A[j + 1];
    l->nroElem--;
    
    if (l->nroElem <= l->capacidade / 4 && l->capacidade > 50) {
        int novaCapacidade = l->capacidade / 2;
        if (novaCapacidade < 50) novaCapacidade = 50;
        resize(l, novaCapacidade); 
    }
    return true;
} 

void reinicializarLista(LISTA* l) {
    l->nroElem = 0;
} 

int main() {
    int value_insert = 0, value_delete = 0;

    LISTA lista;
    REGISTRO reg;

    // Inicializar a lista
    inicializarLista(&lista);

    // Inserir elementos na lista
    while(value_insert != -1) {
        cout << "Digite um elemento para inserir na lista ou -1 para sair: ";
        cin >> value_insert;
        cout << endl;
        if (value_insert == -1) break;  
        reg.chave = value_insert;
        inserirElemListaOrd(&lista, reg);
        exibirLista(&lista);
        printf("Número de elementos na lista: %i.\n", tamanho(&lista));
        printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));
    }

    // Exibir lista após inserções
    exibirLista(&lista);
    printf("Número de elementos na lista: %i.\n", tamanho(&lista));
    printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

    // Excluir alguns elementos da lista
    while(value_delete != -1) {
        cout << "Digite um elemento para excluir da lista ou -1 para sair: ";
        cin >> value_delete;
        cout << endl;
        if (value_delete == -1) break;  
        reg.chave = value_delete;
        if (excluirElemLista(&lista, value_delete)) 
            cout << "Exclusão bem-sucedida: " << value_delete << endl;
        exibirLista(&lista);
        printf("Número de elementos na lista: %i.\n", tamanho(&lista));
        printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));
    }

    // Reinicializar a lista
    reinicializarLista(&lista);
    exibirLista(&lista);
    printf("Número de elementos na lista: %i.\n", tamanho(&lista));
    printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

    return 0;
}