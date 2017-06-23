/*Estrutura da arvore ternaria*/
struct Tnodo{
    char info;
    struct Tnodo *left;
    struct Tnodo *right;
    struct Tnodo *center;
    int wordEnd;
    int points;
};
typedef struct Tnodo pNodo;
void Insert(char *word,pNodo **node,int pontos);
pNodo* newNode(char word);
