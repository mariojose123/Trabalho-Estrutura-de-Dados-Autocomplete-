#include "TernaryTree.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//TAREFA FELIPE:PEGAR AS INFORMAÇÕES DO ARQUIVO E INSERIR A PONTUAÇÃO JUNTO COM A STRING COMO UM NODO EM UMA PILHA ,USANDO A ESTRUTURA DO stack.h//





// newNode:char->pNodo
//Recebe um char word e devolve um Nodo com wordEnd false representado que não é o final da palavra//
pNodo* newNode(char word)
{
    pNodo *Node=(pNodo*)malloc(sizeof(pNodo));
    Node->info=word;
    Node->wordEnd=0;
    Node->left=Node->center=Node->right=NULL;
    return Node;
}
//Insert: Insere uma string na arvore ternaria,usa recursão//
void Insert(char *word,pNodo **node,int points){
    if((*node)==NULL){  //caso nodo seja nulo
     *node=newNode(*word);
    }
    if((*word)<(*node)->info){
        Insert(word,&((*node)->left),points);
    }
    else if((*word)>(*node)->info){
            Insert(word,&((*node)->right),points);
        }
    else
    {
      if(*(word+1)){
          Insert(word+1,&((*node)->center),points);
      }
      else{
          (*node)->wordEnd=1;
          (*node)->points=points;
      }
    }
}
void print(char *t) {
   if (*t == '\0')
      return;
   printf("%c", *t);
   print(++t);
}
void test(){
 TipoPilha *pilhateste=(TipoPilha*) malloc(sizeof(TipoPilha));
 pilhateste=inicializaPilha();
 pilhateste=PushPilha(pilhateste,10,"bola");
 pilhateste=PushPilha(pilhateste,20,"show");
 char *string1,*string2;
 int ponto[2];
 PopPilha(&pilhateste,&ponto[0],&(string1));
 PopPilha(&pilhateste,&ponto[1],&(string2));
 printf("%i ",ponto[0]);
 print(string1);
 printf("/n%i ",ponto[1]);
 print(string2);
}
int main(){
    test();
    return 0;
}
/*DADO UM NODO COLOCA NA PILHA sugestions as palavras filhas
do nodo final da string (char*) str  da arvore terciaria*/
void NodeWords(TipoPilha **sugestions,pNodo *node,char *str){
    if(node==NULL){
        return;
    }
    if(node->wordEnd==1){
        *sugestions=PushPilha(*sugestions,node->points,str);
    }
    if(node->left!=NULL){
        NodeWords(&(*sugestions),node->left,str);
    }
    if(node->right!=NULL){
        NodeWords(&(*sugestions),node->right,str);
    }
    if(node->center!=NULL){
        char *_str =(char *)malloc(strlen(str)+2);
        sprintf(_str,"%s%c",str,node->info);
        *sugestions=PushPilha((*sugestions),node->points,_str);
        NodeWords(&(*sugestions),node->center,_str);
    }
}
/*Coloca as sugestões para a palavra na pilha dado a arvore ternaria e
a string (char*) str */
void  Sugestions( TipoPilha **sugestions,pNodo *node,char *str){
    pNodo *nodeaux=node;
    int pos;
    while(nodeaux!=NULL)
    {
       int cmp=(int)*(str+pos)-node->info;
       if(*(str+pos)!=node->info){
        if(cmp<0)
        nodeaux=nodeaux->left;
        else
        nodeaux=nodeaux->right;
       }
       else{
        pos++;
        if(*(str+pos))
        {
          NodeWords(&(*sugestions),node->center,str);
          return;
          }
        nodeaux=nodeaux->center;
       }
    }
        return;
    }
