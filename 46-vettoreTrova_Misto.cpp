#include <iostream>
#define MAXV 7

using namespace std;

void ricerca (int v[],int riempimento,int el,int& dove, bool *trovato){
	*trovato=false;
	while(dove<riempimento){
		if (v[dove]==el){
			*trovato=true;
			return;
		}
		else
			(dove)++;
		}
	return;	
}
//Trova un elemento in un vettore ordinato

int main()
{
    int v[MAXV]={1,32,5,32,12,65,20};
    int riemp=MAXV; //MAXV E' LA MASSIMA DIMENSIONE DEL VETTORE, 
					//riemp LA SUA DIMENSIONE EFFETTIVA IN UN QUALSIASI MOMENTO DELL'ESECUZIONE
	for (int cont=0;cont<riemp;cont++)
		cout<<v[cont]<<" ";
	cout<<endl;    
	//RICERCA LINEARE
	int elemento;
	cout<<"Valore dell'elemento da cercare :";
	cin>>elemento;	
	int i=0;
	bool trovato;
	ricerca(v,riemp,elemento,i,&trovato);
		
	if (!trovato)
		cout<<"Non l'ho trovato"<<endl;
    else
    	cout<<"Trovato in posizione "<<i<<"!"<<endl;
	
	return 0;
}     
