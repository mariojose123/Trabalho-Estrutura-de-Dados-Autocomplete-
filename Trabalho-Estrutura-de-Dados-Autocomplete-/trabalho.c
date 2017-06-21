#include "TernaryTree.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// newNode:char->pNodo
//Recebe um char word e devolve um Nodo com wordEnd false representado que não é o final da palavra
pNodo* newNode(char word)
{
    pNodo *Node=(pNodo*)malloc(sizeof(pNodo));
    Node->info=word;
    Node->wordEnd=0;
    Node->left=Node->center=Node->right=NULL;
    return Node;
}
//Insert: Insere uma string na arvore ternaria,usa recursão
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
void test(){


}

int main(){

}
/*DADO UM NODO COLOCA NA PILHA sugestions as palavras filhas
do nodo final da string (char*) str  da arvore terciaria*/
void NodeWords(TipoPilha **sugestions,pNodo *node,char *str){
    if(node==NULL){
        return;
    }
    if(node->wordEnd==1){
        sugestions=PushPilha(&(*sugestions),node->points,str);
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
