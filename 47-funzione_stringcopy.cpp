#include <iostream>
#include <cstring>

using namespace std;

void stringcopy(char copia[],char originale[]){
	int l;
	for(l=0;originale[l]!=0;l++)
		copia[l]=originale[l];
	copia[l]=0;
	return ;
}

int main()
{
    char s[10]="parola1";

    char t[10]="jkljkljsd";

	stringcopy(t,s);
    
	cout<<t<<endl;
    
   system("pause");
    return 0;
}
