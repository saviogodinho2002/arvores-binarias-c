#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ESQUERDA -1
#define DIREITA +1

typedef struct no
{
    char conteudo;
    struct no *esquerda, *direita, *pai;

} No; //estrutura da arvore binaria

void preFixado(No *raiz){
    if(raiz != NULL){
        printf("%c ",raiz->conteudo);
        preFixado(raiz->esquerda);
        preFixado(raiz->direita);
    }

}// Encaminhamento pre-ordem

void central(No *raiz){
    if(raiz != NULL){
        central(raiz->esquerda);
        printf("%c ", raiz->conteudo);
        central(raiz->direita);
    }
}// Encaminhamento em ordem

void posFixado(No *raiz){
    if(raiz != NULL){
        posFixado(raiz->esquerda);
        posFixado(raiz->direita);
        printf("%c ", raiz->conteudo);
    }
}// Encaminhamento pos-ordem

No* insere(char dado, No* pai){
    No *novoNo = (No*)malloc(sizeof(No)); //aloca a memoria e cria la
    novoNo->conteudo = dado;
    novoNo->pai = pai;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* montar(char string[], No* raiz){
    int tamanho = strlen(string);
    int lado = ESQUERDA;

    for(int i = 0; i < tamanho; i++){
        if(string[i] == '.'){
            if(lado == ESQUERDA){
                lado = DIREITA;
            
            } else {
                raiz = raiz->pai;
                if(raiz->direita != NULL && raiz->pai != NULL) i--;
            }
        } else {
            if(i == 0){
                raiz = insere(string[i], raiz);

            } else {
                if(lado == ESQUERDA){
                    raiz->esquerda = insere(string[i], raiz);
                    raiz = raiz->esquerda;
                } else {
                    raiz->direita = insere(string[i], raiz);
                    raiz = raiz->direita;
                }
            }
            lado = ESQUERDA;
        }
    }

    return raiz;
}

int main(){
    No *raiz = NULL;

    int opcao;
    char dado[50];

    printf("Insira a sequencia de caracteres:\n");
    scanf("%s", dado);
    
    raiz = montar(dado, raiz);

    printf("\n\n\n");
    printf("Pre-fixado: ");
    preFixado(raiz);
    printf("\nCentral: ");
    central(raiz);
    printf("\nPos-fixado: ");
    posFixado(raiz);
    
    return 0;
}
