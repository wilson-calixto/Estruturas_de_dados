#include<iostream>
#include "Fila.h"


using namespace std;



int main(){
	int tam=4;
	Item i1("s1 ","1");
	Item i2("s2 ","2");
	Item i3("s3 ","3");
	Item i4("s7 ","4");
	Item i5("s5 ","5");
	Fila f1(tam);
	f1.desenfileirar();
	f1.enfileira(i1);
	f1.enfileira(i2);
	f1.enfileira(i3);
	f1.enfileira(i4);
	f1.enfileira(i5);

	f1.desenfileirar();


	return 0;
}
