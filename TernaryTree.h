#include <stdlib.h>
/*Estrutura da arvore ternaria*/
struct Tnodo{
    char info;
    struct Tnodo *left;
    struct Tnodo *right;
    struct Tnodo *center;
    int wordEnd;
    long long int points;
};
typedef struct Tnodo pNodo;
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
/*Função :Insert*/
//Insert: Insere uma string na arvore ternaria,usa recursão
void Insert(char *word,pNodo **node,long long int points){
    if((*node)==NULL){  //caso nodo seja nulo
     *node=newNode(*word); //inicia novo nodo na arvore terciaria
    }
    if(*word<(*node)->info){
    //caso a primeira letra da palavra
    //inserida seja menor que o nodo atual,insere a letra
    //no nodo esquerdo
        Insert(word,&((*node)->left),points);
    }
    else if(*word>(*node)->info){
        //caso a primeira letra da palavra
        //inserida seja maior que o nodo atual,insere
        //na direita
            Insert(word,&((*node)->right),points);
        }
    //else passara para o caso que a letra da palavra e igual
    //a letra do nodo,o que faz a proxima letra da palavra serhttps://www.facebook.com/groups/1226333167449583/?multi_permalinks=1405240656225499&ref=notif&notif_t=group_activity&notif_id=1500258613871670
    //ser inserida no nodo central,caso não tenha terminado caso contrario acaba a função
    //colocando o nodo atual como um final e os pontos dele
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
