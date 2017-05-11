/*
 * Fila.h
 *
 *  Created on: 6 de abr de 2016
 *      Author: wilson
 */

#ifndef FILA_H_
#define FILA_H_
#include<iostream>
using namespace std;


class Item{
public:
	string codigo;
	string nome;
	Item() {}
	Item (string codigo, string nome){
		this->codigo = codigo;
		this->nome = nome;
	}

	void mostra()
	{
		cout<<"\n codigo\n"<<codigo;
		cout<<"\nnome:"<<nome<<endl;
	}
};
// cria no passando um item pra ele


class Fila {
public:
	int primeiro;
	int ultimo,tam;
	Item *items;
	Fila(int tam);
	void enfileira(Item item);
	void desenfileirar();

};

#endif /* FILA_H_ */
