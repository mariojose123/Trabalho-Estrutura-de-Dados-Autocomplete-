struct TPtFila{
TipoInfo dado;
struct TPtFila *elo;
};
typedef struct TPtFila TipoFila;
struct s_TipoDFila{
struct TPtFila *prim;
struct TPtFila *ult;
};
typedef int TipoInfo;
typedef struct s_TipoDFila TipoDFila;

