#include <fstream>
#include <iostream>

using namespace std;

void cercamax(int n[256],int &max,int &posmax){
        max=n[0];
        posmax=0;
        for (int i=1;i<256;i++)
            if (n[i]>max){
               max=n[i];
               posmax=i;
               }
    return;
}

int main(){
    int max,pmax;
    char nome[]="C11-filecontalettere.cpp";
    char l;
    int frequenza[256];
    ifstream input;
    ofstream output;
    for (int i=0;i<256;i++)
        frequenza[i]=0;
    // apertura file di input
   input.open(nome);
    if (input.fail()){
        cout<<"Errore nell'apertura del file";
        exit(1);
    }

    // lettura da file di input
    while (!input.eof()){
        input >> l;
        frequenza[l]++;
    }
    // chiusura file di input
    input.close();
    // apertura file di output
    output.open("C11-classifica.txt");
    // scrittura su file di output
    for (int i=0;i<10;i++){
        cercamax(frequenza,max,pmax);               
        cout << (char) pmax <<' '<<max<<" volte"<<endl;
		output << (char) pmax <<' '<<max<<" volte"<<endl;
        frequenza[pmax]=0;
    }
    // chiusura file di output
    output.close();

    system("pause");
    return 0;
}
