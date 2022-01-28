#include <iostream>
#define DIM 3
#define NMINE 3

using namespace std;


void visualizza(char matrice[DIM][DIM]){
	for (int i=0;i<DIM;i++){
		cout<<i<<" - ";
		for (int j=0;j<DIM;j++)
			cout<<matrice[i][j]<<" ";
		cout<<endl;
		}
	cout<<"-----------"<<endl;
	cout<<"    ";
	for (int j=0;j<DIM;j++)
		cout<<j<<" ";
	cout<<endl;
	return;
}

void mina(char mine[DIM][DIM]){	
	bool ok;
	int riga,colonna;
	for (int i=1;i<=NMINE;i++){
		do{
			ok=true;
			cout<<"Mina numero "<<i<<" : "<<endl;
			cout<<"Inserisci la riga : ";
			cin>>riga;
			cout<<"Inserisci la colonna : ";
			cin>>colonna;
			if (riga<0 || riga>DIM || colonna <0 || colonna>DIM){
				cout<<"Coordinate non valide"<<endl;
				ok=false;
			} else if (mine[riga][colonna]=='*'){
				cout<<"Casella gia' minata"<<endl;
				ok=false;
			} else
			mine[riga][colonna]='*';		 
		} while (!ok);
	}
return;	
}

char adiacenti(char m[DIM][DIM],int r, int c){
	int ad=0;
	for (int i=-1;i<=1;i++)
		for (int j=-1;j<=1;j++)
			if (r+i>=0 && r+i<DIM && c+j>=0 && c+j<DIM)
				if (m[r+i][c+j]=='*')
					ad++;
	return '0'+ad;
}

bool finito (char campo[DIM][DIM]){ 
	int nmine=0;
	for (int i=0;i<DIM;i++)
		for (int j=0;j<DIM;j++)
			if (campo[i][j]=='?')	
				nmine++;
	return (nmine==NMINE);
}

void gioca(char m[DIM][DIM],char c[DIM][DIM]){
	bool ok;
	int riga,colonna;
	do{
		ok=true;
		cout<<"Inserisci la riga : ";
		cin>>riga;
		cout<<"Inserisci la colonna : ";
		cin>>colonna;
		if (riga<0 || riga>3 || colonna <0 || colonna>3){
			cout<<"Coordinate non valide"<<endl;
			ok=false;
		} else if (c[riga][colonna]!='?'){
			cout<<"Casella gia' scoperta"<<endl;
			ok=false;
		}
		else if (m[riga][colonna]=='*'){
			cout<<"Sei saltato in aria su di una mina!"<<endl;
		} else {
			c[riga][colonna]=adiacenti(m,riga,colonna);
			visualizza(c);
		};		
	} while (!finito(c)&& m[riga][colonna]!='*');
	if (finito(c)){
		cout<<"Hai vinto!"<<endl;
	}
	return;
}


int main()
{
	char mine[DIM][DIM];
	char campo[DIM][DIM];
	
	for (int i=0;i<DIM;i++)
		for (int j=0;j<DIM;j++){
			mine[i][j]='.';	
			campo[i][j]='?';
		}
	mina(mine);
	visualizza(mine);
	visualizza(campo);
	gioca(mine,campo);

	return 0;
}
