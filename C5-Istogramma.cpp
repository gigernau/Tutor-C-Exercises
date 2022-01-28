
#include <iostream>

using namespace std;




	
int main()
{
	int v[5];
	
	cout<<"Inserisci il vettore : "<<endl;
		for (int i=0;i<5;i++)
		{
			do{
				cout<<"Inserisci il valore in posizione "<<i<<" :";
				cin>>v[i];
				if (v[i]<0 || v[i]>9)
					cout<<"Il valore deve essere compreso tra 0 e 9"<<endl;
			} while (v[i]<0 || v[i]>9);
		}

	cout<<"Istogramma : "<<endl; 
	for (int i=9;i>0;i--){
		cout<<i<<" ";
		for (int j=0;j<5;j++){
			if (v[j]>=i)
				cout<<"*";
			else cout<<" ";
			cout<<" ";
		}
		cout<<endl;
	}
	cout<<endl;	
	
	return 0;		
}
