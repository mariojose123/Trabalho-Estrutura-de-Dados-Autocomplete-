#include <stddef.h>
#include <stdlib.h>
//ESTRUTURA DE PILHA COM STRING (CHAR* ) E INT
struct TPtPilha{
int pontos;
char *palavra;
struct TPtPilha *elo;
};
typedef struct TPtPilha TipoPilha;

TipoPilha* inicializaPilha(){
return NULL;
}
TipoPilha* PushPilha (TipoPilha *Topo, int Dado,char *str)
{
TipoPilha *novo; //novo elemento
/*aloca um novo nodo */
novo = (TipoPilha*) malloc(sizeof(TipoPilha));
/*insere os pontos  do novo nodo*/
novo->pontos = Dado;
/*insere a string do  nodo*/
novo->palavra=str;
/*encadeia o elemento */
novo->elo = Topo;
/*retorna novo topo */
return novo;
}
int PopPilha (TipoPilha **Topo, int *Dado,char **str) //retorna 1 se
//exclui e zero se não exclui
{
TipoPilha* ptaux;
if (*Topo==NULL)
return 0; // a pilha está vazia
else
{
*Dado = (*Topo)->pontos; // devolve o valor do topo
*str =(*Topo)->palavra;//devolve a string para o topo
ptaux = *Topo; //guarda o endereço do topo
*Topo = (*Topo)->elo; //o próximo passa a ser o topo
free(ptaux); //libera o que estava no topo
ptaux=NULL;
return 1;
}
}

