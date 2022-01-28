#include <iostream>
#include "Lista.h"

using namespace std;

void inserisci(Lista &p,int f)
{
    struct Elemento *e=new Elemento;
    e->figurina=f;
    e->prossimo=p;
    p=e;
    return;
}

void visualizza(Lista p){
     Lista q=p;
     while (q!=NULL){
          cout<<q->figurina<<" ";
          q=q->prossimo;
     }
     cout<<endl;
    return;
}

bool scambia(Lista l1,int f1,Lista l2,int f2){
	Lista q1=l1;
	bool trovata1=false;
	while (q1!=NULL && !trovata1){
		if (q1->figurina==f1)
			trovata1=true;
		else
			q1=q1->prossimo;
	}
	if (!trovata1)
		cout<<"Il bambino 1 non ha la figurina "<<f1<<": lo scambio non e' possibile"<<endl;
	Lista q2=l2;
	bool trovata2=false;
	while (q2!=NULL && !trovata2){
		if (q2->figurina==f2)
			trovata2=true;
		else
			q2=q2->prossimo;
	}
	if (!trovata2)
		cout<<"Il bambino 2 non ha la figurina "<<f2<<": lo scambio non e' possibile"<<endl;
	if (trovata1 && trovata2){
		q1->figurina=f2;
		q2->figurina=f1;
		return true;
	}
	else
		return false;
	
}

bool terminato(Lista p){
	int album[6]={false,false,false,false,false,false};
	Lista q=p;
	while (q!=NULL){
		album[q->figurina-1]=true;
		q=q->prossimo;
	};
	for (int i=1;i<=6;i++)
		if (album[i-1]==false)
			return false;
	return true;
}
