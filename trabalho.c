#include "TernaryTree.h"
#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*Função :learquivo*/
//função que dado um file com os pesos e string lê e coloca na arvore ternaria*;
/*            */
void learquivo(pNodo **node,FILE *fp){
    char string1[100];
    char string2[100];
    long long int numero;
    while(fgetc(fp)!='\n'){}
    while(fscanf(fp,"%s %s",string1,string2)!=EOF){
        numero=atoll(string1);
        Insert(string2,&(*node),numero);
    }
}
/*Função :NodeWork*/
//DADO UM NODO COLOCA NA LISTA ORDENADA DESCRESCENTE sugestions as palavras filhas
/*do nodo final da string (char*) str  da arvore terciaria*/
/*Procura todos as palavras filhas dado o nodo que para a string da sugestão*/
void NodeWords(NodeLista **sugestions,pNodo *node,char *str){
    if(node==NULL){//se nulo retorna nulo
        return;
    }
    if(node->wordEnd==1){//caso nulo
        char *_str =(char *)malloc(strlen(str)+2);
        sprintf(_str,"%s%c",str,node->info);
        NodeLista* novonodo=NovoNodo(node->points,_str);
        sortedInsert(&(*sugestions),novonodo);
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
        NodeWords(&(*sugestions),node->center,_str);
    }
}
/*Função :Sugestions*/
/*Coloca as sugestões para a palavra str na LISTA DECRESCENT sugestions , dado a arvore ternaria e
a string (char*) str que é a word na primeira execução da função */
void  Sugestions( NodeLista **sugestions,pNodo *node,char *str,char *word){
    if(!node){//caso 1:não achou,nodo atual vazio acaba função,não achou nenhuma sugestao
        return;
    }
    //caso char for maior recursão no nodo esquerdo
    //caso menor recursão nodo direito
    if(*str<node->info)
        return Sugestions(&(*sugestions),node->left,str,word);
    else if(*str>node->info)
        return Sugestions(&(*sugestions),node->right,str,word);
    //se o char for igual ao do nodo atual executa o else
    else
    {
        if(*(str+1)=='\0'){//fim da palavra que estamos pŕocurando sugestoes
          if(node->wordEnd){
          //caso essa palavra estiver registrada na arvore executa o if acima
          //insere uma das sugestões na lista sugestions
          NodeLista* novonodo=NovoNodo(node->points,word);
          sortedInsert(&(*sugestions),novonodo);
          }
          //Acha todas as palavras filhas da palavra que se procura a sugestão registrada
          //na variavel word para se manter na recursão da função
          NodeWords(&(*sugestions),node->center,word);
          return;
        }
     return Sugestions(&(*sugestions),node->center,str+1,word);
    }
    }

//                MAIN                    //
int  main(int argc,char *argv[]){
  if(argc!=5){
    printf ("Numero incorreto de parametros.\nExemplo de chamada: autocompletar wiktionary.txt consulta.txt saida.txt 5");
    return 0;
  }
  //abre os arquivos de entrada,processamento e saida
  FILE* wiktionary=fopen(argv[1],"r");
  if(!wiktionary)
  {
      printf("Nao se deu possivel abrir o arquivo %s",argv[1]);
      return 0;
  }
  FILE* consulta=fopen(argv[2],"r");
  if(!consulta)
  {
      printf("Nao foi possivel abrir o arquivo %s", argv[2]);
      return 0;
  }
  fseek(consulta,0,SEEK_END);
  unsigned long len=(unsigned long)ftell(consulta);
  if(len<1)
  {
      printf("Arquivo vazio");
      return 0;
  }
  rewind(consulta);
  FILE *saida= fopen(argv[3],"w+");
  if(!saida)
  {
      printf("Nao foi possivel abrir o arquivo %s de saida",argv[3]);
      return 0;
  }
  int max=atoi(argv[4]);
  clock_t start,end;
  double execucaotimer;//variavel para o tempo de execucação
  // arvoreterc=(pNodo*)malloc(sizeof(pNodo));
  pNodo*  arvoreterc=NULL;/*arvore terciaria*/
  //NodeLista* lista=(NodeLista*)malloc(sizeof(NodeLista));/*lista que vai ficar em ordem crescente que se vai colocar os pontos*/
  NodeLista* lista=NULL;
  start=clock();
  learquivo(&arvoreterc,wiktionary);
  fclose(wiktionary);
  char string[100];//string onde sera colocado cada palavra para fazer consulta
  //das sugestoes na arvore e depois escrevelas no FILE saida
  char *saidastr;//texto final que vai ser escrito no FILE saida junto com o tempo
  //da um while enquanto lê cada string do FILE cosulta
  //dentro do while acha as sugestoes e printa na saida as sugestões
  while(fscanf(consulta,"%s",string)==1){
  fprintf(saida,"%s\n",string);
  Sugestions(&lista,arvoreterc,string,string);//acha as sugestoes e coloca na lista encadeada lista
  printList(lista,saida,max);//coloca as sugestões no FILE saida
  lista=NULL;
  }
  fclose(consulta);
  end=clock();
  execucaotimer=(double)1000*(end-start)/CLOCKS_PER_SEC;
  fprintf(saida,"Tempo:%lfms\n",execucaotimer);
  fclose(saida);
  return 0;
  }
