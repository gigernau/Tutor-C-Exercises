#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[200]; //parola da indovinare
    bool ok;
    do
    {      
      cout<<"Inserisci la stringa :"<<endl;
      cin>>str;      
      if (strlen(str)>20)
         cout<<"Troppo lunga"<<endl;
      else
      {
          ok=true;
          //se almeno un simbolo non è una lettera minuscola, allora la stringa non va bene
		  for (int i=0;i<strlen(str) && ok;i++)
              if ((str[i]<'a') || (str[i]>'z')){
                 ok=false;
                 cout<<"Contiene simboli non ammessi"<<endl;
      		  }
      }
    } while ((strlen(str)>20)||(!ok));
       
    char ind[strlen(str)+1]; //parola finora indovinata: all'inizio solo trattini
    for (int i=0;i<strlen(str);i++)
        ind[i]='-';
    ind[strlen(str)]='\0';
    
    cout<<"Inizia il gioco : "<<endl;
    int tentativi=0;
	//mentre la parola da indovinare e quella indovinata non coincidono, gioca
	while (strcmp(ind,str)!=0)
    {
		  char l;
          cout<<"Che lettera devo cercare? ";
          cin>>l;
          if (l<'a' || l>'z')
          	cout<<"Non e' una lettera valida"<<endl;
          else {
          	tentativi++;
          	//cerca in tutta la parola da indovinare la lettera richiesta: se la trovi mettila nella stessa posizione trovata nell'altra stringa ind
		  	for (int i=0;str[i]!=0;i++)
              if (str[i]==l)
                 ind[i]=str[i];
          	cout<<ind<<endl;
          }
    }
    cout<<"Bravo: hai indovinato in "<<tentativi<<" tentativi!"<<endl;
    
    return 0;
}
