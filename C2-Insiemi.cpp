#include <iostream>

using namespace std;

int main()
{
  const int DIM=10;
  int a[DIM];
  int b[DIM];
  int unione[DIM*2]; //al più 10 + 10 se numeri tutti diversi
  int inters[DIM];
  int diff[DIM];
  int riempa;
  int riempb;
  int riempunione;
  int riempinters;
  int riempdiff;
  bool trovato=false;
  

  //input da tastiera insieme 1 e 2 max 10 dim
  cout<<"Primo insieme"<<endl;
   do //chiedi lunghezza primo insieme
  {
    cout << "Inserisci il numero di elementi dell'insieme" << endl;
    cin >> riempa;
  } while (riempa<=0 || riempa>DIM);
  
  // inserisci elemento primo insieme
  for (int i=0; i<riempa; i++) 
  {    
    do { //ripeti fino a che non trovi un elemento diverso
        cout << "Inserisci il valore dell'elemento in posizione " << i << " : ";
        cin >> a[i];
        trovato=false;
		for (int j=0; j<i && !trovato; j++) //confronta con tutti gli elementi già inseriti
          if (a[j]==a[i])
            trovato=true;
        if (trovato)
           cout<<"L'elemento gia' esiste: non va bene"<<endl;

    } while (trovato);
       
  }

  cout<<"Secondo insieme"<<endl;
  do
  {
    cout << "Inserisci il numero di elementi dell'insieme" << endl;
    cin >> riempb;
  } while (riempb<=0 || riempb>DIM);
  
  for (int i=0; i<riempb; i++)
  {
    do {
        cout << "Inserisci il valore dell'elemento in posizione " << i << " : ";
        cin >> b[i];
        trovato=false;
		for (int j=0;j<i;j++)
          if (b[j]==b[i])
            trovato=true;
        if (trovato)
           cout<<"L'elemento gia' esiste: non va bene"<<endl;
    } while (trovato);
       
  }
  

  //in array unione metto tutto ins 1  
  cout<<"Unione : ";
    riempunione=0;
    //aggiungo all'insieme unione tutti gli elementi del primo insieme
    for (int i=0;i<riempa;i++){
       unione[riempunione]=a[i];
       riempunione++;
     }
    // aggiungo all'unione gli elementi del secondo insieme che non sono nel primo
    for (int i=0;i<riempb;i++){
    	trovato=false;
 	    // controllo se c'è già nell'altro insieme
		for (int j=0;j<riempa && !trovato;j++)
          if (a[j]==b[i])
            trovato=true;
        //come sopra
        if (!trovato){
           //aggiungo all'unione e aggiorno il valore del riempimento	
           unione[riempunione]=b[i];
           riempunione++;
         }             
	}

    for (int i=0;i<riempunione;i++)
        cout<<unione[i]<<", ";
    cout<<endl;


    //controllo primo controllo il secondo se uguale per ogni eleme del primo se lo trovo lo aggiungo
  cout<<"Intersezione : ";
    riempinters=0;
    for (int i=0;i<riempa;i++){
    	trovato=false;
 	    for (int j=0;j<riempb && !trovato;j++)
          if (a[i]==b[j])
            trovato=true;
        if (trovato){
        	//aggiungo all'intersezione solo se è un elemento del primo insieme presente anche nel secondo
           inters[riempinters]=a[i];
           riempinters++;
           }
	}
    for (int i=0;i<riempinters;i++)
        cout<<inters[i]<<", ";
    cout<<endl;


    //giro primno giro secondo se non uguale elem lo aggiungo al risultatyo
  cout<<"Differenza primo insieme - secondo insieme : ";
    riempdiff=0;
    for (int i=0;i<riempa;i++){
    	trovato=false;
 	    for (int j=0;j<riempb;j++)
          if (a[i]==b[j])
            trovato=true;
        if (!trovato){
           //aggiungo alla differenza solo se è un elemento del primo insieme che non è presente nel secondo	
           diff[riempdiff]=a[i];
           riempdiff++;
           }
	}
    for (int i=0;i<riempdiff;i++)
        cout<<diff[i]<<", ";
    cout<<endl;

  system("pause");   
}
