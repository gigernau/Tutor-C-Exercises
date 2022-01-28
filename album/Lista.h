struct Elemento{
    int figurina;
    struct Elemento *prossimo;
};
    
    typedef struct Elemento* Lista;

void inserisci(Lista &p,int f);

void visualizza(Lista p);

bool scambia(Lista l1,int f1,Lista l2,int f2);

bool terminato(Lista l1);
