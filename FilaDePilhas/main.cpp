/*
 * main.cpp
 *
 *  Created on: 4 de abr de 2016
 *      Author: wilson
 */
#include<iostream>
#include "Pilha.h"
//retirar os estados dos item e nos
using namespace std;
int main(){
	string entrada;//="6 2 1 -1 5 3 -1 4 -1 \0";
	Controle controleDePilhas(30);
	cin>>entrada;
	int k=0;
	//while(entrada[k]!='\0'){
		Pilha pilhaTemporaria;
		int cont=0;
		while(entrada[cont]!=-1){
			if(entrada[cont]!=' '){
				string aux(1,entrada[cont]);

				cout<<"deveria ser "<<entrada[cont]<<endl;
				cout<<"e isso"<<aux<<endl;

				Item itemTemporario(aux);
				itemTemporario.mostra();
				pilhaTemporaria.empilha(itemTemporario);
			}
			cont++;
		}
		controleDePilhas.aloca(pilhaTemporaria);
	//}

	controleDePilhas.mostra();
	/*
	Pilha p1;
	Pilha p2;
	Pilha p3;
	Pilha p4;
	Item i("0");
	Item i1("1");
	Item i2("2");
	Item i3("3");
	Item i4("4");
	Item i5("5");
	Item i6("6");
	Item i7("7");
	Item i8("8");
	Item i9("9");




	// PILHA 1
	p1.empilha(i);
	p1.empilha(i1);
	p1.empilha(i2);
	p1.empilha(i3);

	controleDePilhas.aloca(p1);
	//N PILHA 2
	p2.empilha(i4);
	p2.empilha(i5);
	p2.empilha(i6);

	controleDePilhas.aloca(p2);

	//N PILHA 3
	p3.empilha(i7);
	p3.empilha(i8);


	controleDePilhas.aloca(p3);

	// PILHA 4
	p4.empilha(i9);


	controleDePilhas.aloca(p4);

	//classifica as pilhas
	controleDePilhas.classifica(i4,0);


	cout<<"origem "<<controleDePilhas.origem<<endl;

	cout<<"destino "<<controleDePilhas.destino<<endl;
	cout<<"temporaria "<<endl;

	controleDePilhas.mostraT();

	controleDePilhas.mostra();

	controleDePilhas.organiza(i4);

//	controleDePilhas.classifica(i5,0);
	//controleDePilhas.organiza(i5);
	cout<<"\nlista final\n";
	controleDePilhas.mostra();
*/
cout<<"blz" << endl;
	return 0;
}
