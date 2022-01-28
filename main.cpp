#include <iostream>
using namespace std;

#define MAX 100 
/* Scrivere un programma che riceve come input un vettori v1 di interi. 
Si costruisca la struttura Info che contiene:
Il numero di elementi del vettore
Il suo massimo
Il suo minimo
Il programma stampa infine la struttura creata.
 */
typedef struct {
	int riemp;
	int max;
	int min;

} Info;

int main(int argc, char** argv) {
	Info info;
	int N, max, p_max, p_min, min;
	int a[MAX];
	
	do{
  	   cout<<"Inserisci N: ";
  	   cin>>N;
      }while(N<=0 || N>MAX)  ;
      
    for (int i=0; i<N; i++) {
  	   cout<<"Inserisci un numero: ";
	   cin>>a[i];
       }
	
	//troviamo il massimo
	
	max=a[0]; //poniamo il massimo uguale al primo elemento
	p_max=0; //poniamo l'indice uguale a 0

  	for (int i=0; i<N; i++) {
  		if(a[i]>max){
  			max=a[i];
  			p_max=i;
		  }

	}

	
	min = a[0];
	p_min = 0;
	
	for (int i=0; i<N; i++) {
  		if(a[i]<min){
  			min=a[i];
  			p_min=i;
		  }

	}
	
	info.riemp = N;
	info.min = min;
	info.max = max;
	
	cout<<"Info: "<<endl;
	cout<<"MIN: "<<info.min<<endl;
	cout<<"MAX: "<<info.max<<endl;
	cout<<"Numero elementi "<<info.riemp<<endl;
	
	return 0;
}
