	#include <iostream>
	#include <cstring>
	
	using namespace std;
	
	struct Giorno{
		int giorno;
		int mese;
		int anno;
	};
	
	int main()
	{
	  struct Giorno g;
	  bool ok;
	  
	  char str[100];

	do{
		ok=true;
	
		cout<<"Inserisci la data nel formato gg-mm-aaaa : ";
		cin>>str;
		if (strlen(str)!=10)
			{cout<<"Stringa della dimensione sbagliata"<<endl;return false;}
		for (int i=0;i<10;i++){
			if (i==2 || i==5){
			 	if (str[i]!='-')
					{cout<<"La stringa non e' nel formato gg-dd-aaaa"<<endl;ok=false;}
				}
			else if (str[i]<'0' || str[i]>'9')
					{cout<<"La stringa non e' nel formato gg-dd-aaaa"<<endl;ok=false;}
			}
			

			g.giorno=10*(str[0]-'0')+str[1]-'0';
			g.mese=10*(str[3]-'0')+str[4]-'0';
			g.anno=1000*(str[6]-'0')+100*(str[7]-'0')+10*(str[8]-'0')+str[9]-'0';
			
			if (g.giorno<1 || g.giorno>31)
				{cout<<"Il giorno non e' compreso tra 1 e 31"<<endl;ok=false;}
			if (g.mese<1 || g.mese>12)
				{cout<<"Il mese non e' compreso tra 1 e 12"<<endl;ok=false;}
			if ((g.mese==4 || g.mese==6 || g.mese==9 || g.mese==11) && (g.giorno==31))
				{cout<<"Questo mese ha solo 30 giorni"<<endl;ok=false;}
			if (g.mese==2 && g.giorno>28)
				{cout<<"Questo mese ha solo 28 giorni"<<endl;ok=false;}	
	} while (!ok);
	
	if (g.anno>2019 || (g.anno==2019 && g.mese>12) || 
		(g.anno==2019 && g.mese==12 && g.giorno>17))
		cout<<g.giorno<<"-"<<g.mese<<"-"<<g.anno<<" cade dopo 17-12-2019"<<endl;
	else if (g.anno==2019 && g.mese==12 && g.giorno==17)
		cout<<"Le due date coincidono"<<endl;
	else
		cout<<g.giorno<<"-"<<g.mese<<"-"<<g.anno<<" cade prima di 17-12-2019"<<endl;	
 
  
  return 0;
}
