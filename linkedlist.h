#include<stdio.h>
#include<stdlib.h>

/*Estrutura da lista encadeada com um int long long e um string*/
struct Nodo
{
    char *str;
    long long int data;
    struct Nodo* proximo;
};
typedef struct Nodo NodeLista;
/*
  Insere um nodo mais deixa a lista ordenada,ordem descrecente
*/
void sortedInsert(NodeLista** nodo,NodeLista* novonodo){
    /*Caso for nulo ou o novonodo ter um valor maior que o do que
    o nodo*/
   if(*nodo ==NULL||(*nodo)->data<=novonodo->data){
      novonodo->proximo=*nodo;
      *nodo=novonodo;
   }
   else
   {
       /*Localizar o nodo antes do ponto de inserção*/
       NodeLista* atual=*nodo;
       while(atual->proximo!=NULL && atual->proximo->data>novonodo->data)
        {
               atual=atual->proximo;
        }
       novonodo->proximo=atual->proximo;
       atual->proximo= novonodo;
   }
}

NodeLista* NovoNodo(long long int data, char* str){
   /*alocação de memoria*/
    NodeLista* novonodo=(NodeLista*)malloc(sizeof(NodeLista));
    /*coloca a data e a string*/
    novonodo->str=str;
    novonodo->data=data;
    novonodo->proximo=NULL;
    return novonodo;
}
/*Função :printList*/
/*Recebe a lista com as sugestoes nodo e escreve no FILE saida,no maximo a INT numero sugestoes */
void printList(NodeLista *nodo,FILE* saida,int numero){
    if(numero==0){
            return;
       }
    NodeLista *nnodo=nodo;
    if(nnodo==NULL){//caso não achou nenhuma sugestao na lista
        fprintf(saida,"nao achou nada \n");
    }
    while(nnodo!=NULL){
        fprintf(saida,"%llu %s \n",nnodo->data,nnodo->str);
        nnodo=nnodo->proximo;
        numero--;
        if(numero==0){
            return;
        }
    }
}


