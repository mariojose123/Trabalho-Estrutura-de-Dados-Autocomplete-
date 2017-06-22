<<<<<<< HEAD

/*Estrutura da arvore ternaria*/
struct Tnodo{
=======
/*Estrutura da arvore ternaria*/
truct Tnodo{
>>>>>>> e62668d5187b6c096f61a1343abb6b77d1d80ddd
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
<<<<<<< HEAD
=======
void  Sugestions(TipoPilha **sugestions,pNodo *node,char* str);
>>>>>>> e62668d5187b6c096f61a1343abb6b77d1d80ddd
