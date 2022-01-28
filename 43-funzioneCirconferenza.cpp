#include <iostream>
#define PI 3.1415

using namespace std;

float calcolacirc(float raggio){
	float circonferenza=2*PI*raggio;
	return circonferenza;
}

void calcolacirc2(float raggio,float* circonferenza){
	*circonferenza=2*PI*raggio;
	return;
}


int main()
{
    float raggio=0.0;
    cout<<"Il raggio e' ";
    cin>>raggio; 
    float circ=0;
    if (raggio>0) {
        //no puntatore
        circ=calcolacirc(raggio);
        cout<<"La circonferenza vale "<<circ<<endl;

        calcolacirc2(raggio,&circ);
        cout<<"La circonferenza vale "<<circ<<endl;    }
    else {
        cout<<"Il raggio "<<raggio<<" deve essere positivo"<<endl;
        }
    system("pause");
    return 0;
}
