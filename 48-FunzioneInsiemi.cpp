#include <iostream>

using namespace std;

int chiedilunghezza(int DIM){
   int r;
   do //chiedi lunghezza primo insieme
  {
    cout << "Inserisci il numero di elementi dell'insieme" << endl;
    cin >> r;
  } while (r<=0 || r>DIM);
  return r;
}

void chiediinsieme(int a[],int riemp){
  bool trovato;
  // inserisci elemento primo insieme
  for (int i=0; i<riemp; i++) 
  {    
    do { //ripeti fino a che non trovi un elemento diverso
        cout << "Inserisci il valore dell'elemento in posizione " << i << " : ";
        cin >> a[i];
        trovato=false;
		for (int j=0;j<i && !trovato;j++) //confronta con tutti gli elementi già inseriti
          if (a[j]==a[i])
            trovato=true;
        if (trovato)
           cout<<"L'elemento gia' esiste: non va bene"<<endl;

    } while (trovato);
       
  }
  return;
}


void unione(int unione[],int &riempunione,int a[],int riempa,int b[],int riempb){
	riempunione=0;
    //aggiungo all'insieme unione tutti gli elementi del primo insieme
    for (int i=0;i<riempa;i++){
       unione[riempunione]=a[i];
       riempunione++;
     }
    // aggiungo all'unione gli elementi del secondo insieme che non sono nel primo
    bool trovato;
	for (int i=0;i<riempb;i++){
    	trovato=false;
 	    // controllo se c'è già nell'altro insieme
		for (int j=0;j<riempa && !trovato;j++)
          if (a[j]==b[i])
            trovato=true;
        if (!trovato){
           //aggiungo all'unione e aggiorno il valore del riempimento	
           unione[riempunione]=b[i];
           riempunione++;
           }             
	}
	return;
}

void visualizza(int v[],int riemp){
	for (int i=0;i<riemp;i++)
        cout<<v[i]<<", ";
    cout<<endl;
    return;
}

void intersezione(int inters[],int &riempinters,int a[],int riempa,int b[],int riempb){
    bool trovato;
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
	return;
}
void diff(int diff[],int &riempdiff,int a[],int riempa,int b[],int riempb){
	bool trovato;
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
	return;
}

int main()
{
  const int DIM=10;
  int a[DIM];
  int b[DIM];
  int insunione[DIM*2];
  int inters[DIM];
  int insdiff[DIM];
  int riempa;
  int riempb;
  int riempunione;
  int riempinters;
  int riempdiff;
  bool trovato=false;
  
  cout<<"Primo insieme"<<endl;
  riempa=chiedilunghezza(DIM);
  chiediinsieme(a,riempa);

  riempb=chiedilunghezza(DIM);
  chiediinsieme(b,riempb); 
  
  cout<<"Unione : ";
  unione(insunione,riempunione,a,riempa,b,riempb);
  visualizza(insunione,riempunione);

  cout<<"Intersezione : ";
  intersezione(inters,riempinters,a,riempa,b,riempb);
  visualizza(inters,riempinters);

  cout<<"Differenza primo insieme - secondo insieme : ";
  diff(insdiff,riempdiff,a,riempa,b,riempb);
  visualizza(insdiff,riempdiff);	 

  cout<<"Differenza secondo insieme - primo insieme : ";
  diff(insdiff,riempdiff,b,riempb,a,riempa);
  visualizza(insdiff,riempdiff);	 

  system("pause");   
}
