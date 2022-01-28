#include <iostream>
#include "Lista.h"

using namespace std;

int main()
{
    Lista b1=NULL;
    Lista b2=NULL;
    inserisci(b1,1);inserisci(b1,2);inserisci(b1,2);inserisci(b1,5);inserisci(b1,5);inserisci(b1,6);
    inserisci(b2,3);inserisci(b2,3);inserisci(b2,4);inserisci(b2,4);inserisci(b2,5);inserisci(b2,6);
    bool fine=false;
	do{
		cout<<"Figurine del bambino 1 : ";
		visualizza(b1);
		cout<<"Figurine del bambino 2 : ";
		visualizza(b2);    	
		int f1;
		do{
    		cout<<"Inserisci il numero della figurina del bambino 1 da scambiare : ";
			cin>>f1;
			if (f1<1 || f1>6)
				cout<<"Numero di figurina non valido: deve essere compreso tra 1 e 6"<<endl;
		} while (f1<1 || f1>6);
		int f2;
		do{
    		cout<<"Inserisci il numero della figurina del bambino 2 da scambiare : ";
			cin>>f2;
			if (f2<1 || f2>6)
				cout<<"Numero di figurina non valido: deve essere compreso tra 1 e 6"<<endl;
		} while (f2<1 || f2>6);
		bool ok=scambia (b1,f1,b2,f2);
		if (ok){
			if (terminato(b1)){
				cout<<"Il bambino 1 ha terminato l'album"<<endl;
				fine=true;
			}
			if (terminato(b2)){
				cout<<"Il bambino 2 ha terminato l'album"<<endl;
				fine=true;
			}
		}
	}while (!fine);
        
   return 0;
}

