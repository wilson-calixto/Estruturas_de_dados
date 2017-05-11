/*
 * main.cpp
 *
 *  Created on: 4 de abr de 2016
 *      Author: wilson
 */
#include<iostream>
#include "Pilha.h"

using namespace std;
int main(){
	string aMover="1";
	Controle controleDePilhas(4);
	Pilha p1;
	Pilha p2;
	Pilha p3;
	Item i("0");
	Item i1("1");
	Item i2("2");
	Item i3("3");
	Item i4("4");
	Item i5("5");
	Item i6("6");
	Item i7("7");
	Item i8("8");
	controleDePilhas.aloca(p1);
	controleDePilhas.aloca(p2);
	controleDePilhas.aloca(p3);

	// PILHA 1
	controleDePilhas.pilhas[0].empilha(i);
	controleDePilhas.pilhas[0].empilha(i1);
	controleDePilhas.pilhas[0].empilha(i2);
	controleDePilhas.pilhas[0].empilha(i3);
	//N PILHA 2
	controleDePilhas.pilhas[1].empilha(i4);
	controleDePilhas.pilhas[1].empilha(i5);
	controleDePilhas.pilhas[1].empilha(i6);
	//N PILHA 3
	controleDePilhas.pilhas[2].empilha(i7);
	controleDePilhas.pilhas[2].empilha(i8);
	//classifica as pilhas
	controleDePilhas.classifica(i4,0);


	cout<<controleDePilhas.origem<<endl;
	cout<<controleDePilhas.temporario[0]<<endl;
	cout<<controleDePilhas.destino<<endl;


	controleDePilhas.mostra();
	controleDePilhas.organiza(i4);
		cout<<"\nlista final\n";
	controleDePilhas.mostra();
	cout<<"blz" << endl;
	//int resposta=controleDePilhas.busca(i8);

	//cout<<resposta << endl;
	//cout << p1.indice << endl;

	//controleDePilhas.classifica(i1,0);
	return 0;
}
