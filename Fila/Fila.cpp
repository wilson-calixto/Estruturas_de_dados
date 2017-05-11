/*
 * Fila.cpp
 *
 *  Created on: 6 de abr de 2016
 *      Author: wilson
 */

#include "Fila.h"

Fila::Fila(int tam)
{
	// TODO Auto-generated constructor stub
	items=new Item[tam];
	primeiro=0;
	ultimo=0;
	this->tam=tam;
}

void Fila::enfileira(Item item)
{
	if((ultimo+1)%tam!=primeiro)
	{
		items[ultimo]=item;
		ultimo=ultimo+1%tam;
	}else{
		cout<<"fila cheia";

	}
}

void Fila::desenfileirar(){
		if(ultimo==primeiro)
		{

			cout<<"fila vazia\n";
		}else{
			primeiro=(primeiro+1)%tam;
		}
}




