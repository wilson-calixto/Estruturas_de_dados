/*
 * Pilha.cpp
 *
 *  Created on: 14 de abr de 2016
 *      Author: wilson
 */
#include <iostream>
#include "Pilha.h"
using namespace std;
Pilha::Pilha(){
	// TODO Auto-generated constructor stub
	//cria o No sentinela
	Item sentinela("nulo");
	fundo=new No(sentinela);
	fundo->prox=NULL;
	topo=fundo;
	estado="t";
}


void Pilha::empilha(Item item){

	No *aux=new No();
	aux->setIndice(indice);//coloca o indice no no
	topo->item=item;
	aux->prox=topo;
	topo=aux;
}

void Pilha::desempilha(Item &item){
	No *aux;
	aux=topo;
	topo=topo->prox;
	item=topo->item;
	delete(aux);



}

void Pilha::mostra(){
	No *aux;
	aux=topo->prox;
	while(aux!=NULL)
	{
		aux->item.mostra();
		aux=aux->prox;
	}
}

bool Pilha::busca(Item item){
	No *aux;
	aux=topo->prox;
	while(aux!=NULL)
	{
		if(aux->item.codigo==item.codigo)
		{
			return true;
		}
		aux=aux->prox;
	}
	return false;
}



		/*     Comeco da Controle*/
Controle::Controle(int tam)
{
	// TODO Auto-generated constructor stub
	this->tam=tam;
	temporario=new int[tam];
	pilhas=new Pilha[tam];
	primeiro=0;
	ultimo=0;
	ultimaPosicaoValida=0;

}

void Controle::aloca(Pilha pilha)
{
		pilha.setIndice(ultimaPosicaoValida);//coloca o indice na pilha
		pilhas[ultimaPosicaoValida]=pilha;
		ultimaPosicaoValida++;
}

void Controle::desenfileirar(){
		if(ultimo==primeiro)
		{

			cout<<"Controle vazia\n";
		}else{
			primeiro=(primeiro+1)%tam;
		}
}


void Controle::mostra(){
		int i;
		for(i=0;i<=ultimaPosicaoValida;i++)
		{
				pilhas[i].mostra();
				cout<<"\n";

		}

}
int Controle::busca(Item item){

		bool achou=false;
		for(int i=0;i<=ultimaPosicaoValida;i++)
		{
				achou=pilhas[i].busca(item);
				if(achou)
				{
						return i;
				}
		}
		return -1;
}




