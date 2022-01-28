#include <iostream>

using namespace std;

//conversione da decimale a binario
void dec2bin(int d,char b[]){
	int cont=0; 
	while(d>0){
		b[cont]=d%2+'0';
		d/=2;
		cont++;
	}
	b[cont]=0;
	
	//per invertire
	for (int i=0;i<cont/2;i++){
		char temp=b[i];
		b[i]=b[cont-1-i];
		b[cont-1-i]=temp;
	}
	return;
}

int main()
{
     char bin[17];
     int dec;
   
     do{
         cout<<"Inserisci il numero decimale :";
         cin>>dec;
         if (dec<0 || dec>65535)
            cout<<"Deve essere un numero positivo compreso tra 0 e 65535"<<endl;
     } while (dec<0 || dec>65535);
    
	dec2bin(dec,bin);
	
	cout<<"La conversione di "<<dec<<" e'"<< bin<<endl;
     system("pause");
     return 0;
}

