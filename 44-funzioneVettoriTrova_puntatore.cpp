#include <iostream>
#define MAXV 7

using namespace std;
//Trova un elemento in un vettore ordinato

bool trova(int a[],int riempimento,int el,int *posizione){
	*posizione=0;
	while (*posizione<riempimento){
		if (a[*posizione]==el){
			return true;
		}
		else
			(*posizione)++;
	}
	return false;
}


int main()
{
    int v[MAXV]={1,32,5,32,12,65,20};

    int riemp=MAXV; //MAXV E' LA MASSIMA DIMENSIONE DEL VETTORE, 
					//riemp LA SUA DIMENSIONE EFFETTIVA IN UN QUALSIASI MOMENTO DELL'ESECUZIONE
	for (int cont=0;cont<MAXV;cont++)
		cout<<v[cont]<<" ";
	cout<<endl;    
	    
	int el;
	
	cout<<"Elemento da trovare ";
	cin>>el;

	//puntatore int x, *y
	int i;
	
	bool trovato=trova(v,riemp,el,&i);
	
	if (!trovato)
		cout<<"Non c'e'"<<endl;
	else
		cout<<"Trovato in posizione "<<i<<endl;
   
	system("pause");
    return 0;
}     
