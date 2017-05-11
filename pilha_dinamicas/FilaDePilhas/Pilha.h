/*
 * Pilha.h
 *
 *  Created on: 14 de abr de 2016
 *      Author: wilson
 */

#ifndef PILHA_H_
#define PILHA_H_
#include<iostream>

using namespace std;

class Item{
public:
	string codigo;
	//string nome;
	Item() {}
	Item (string codigo){
		this->codigo = codigo;
		//this->nome = nome;
	}
	void mostra(){
		cout<<codigo<<"  ";
		//cout<<"\nnome:"<<nome<<endl;
	}
};

class No{
public:
	Item item;
	No *prox;
	int indicePilha;
	No(){};
	No(Item item){
		this->item=item;
		prox=NULL;
	};
	void setIndice(int indicePilha) {
		this->indicePilha = indicePilha;
	}
	int getIndice() {
			return indicePilha;
	}
};


class Pilha {
public:
	No *fundo;
	No *topo;
	int indice;
	string estado;

	Pilha();
	void empilha(Item item);
	void desempilha(Item &item);
	void mostra();
	bool busca(Item item);
	void setIndice(int indice) {
		this->indice = indice;
	}

	void setEstado(string estado) {
			this->estado = estado;
	}

	string getEstado() {
			return estado;
	}

};

class Controle {
public:

	int primeiro,origem,destino,*temporario;
	int ultimo,tam;
	Pilha *pilhas;
	Controle(int tam);
	void aloca(Pilha pilha);
	void desenfileirar();
	void mostra();
	int busca(Item item);

	void setDestino(int destino) {
			this->destino = destino;
	}

	int getDestino(){
		return destino;
	}

	void setOrigem(int origem) {
				this->origem = origem;
	}

	int getOrigem(){
		return origem;
	}


	void classifica(Item item,int destino){


		int indiceDaPilha=primeiro;
		bool achou;

		while(indiceDaPilha!=ultimo){
			achou=pilhas[indiceDaPilha].busca(item);
			if(achou)//se achou
			{

				// classifica as origens e destinos
				pilhas[destino].setEstado("d");
				this->destino=destino;
				if(destino==indiceDaPilha)
				{
					pilhas[indiceDaPilha].setEstado("od");
					this->origem=destino;
				}else{
					pilhas[indiceDaPilha].setEstado("o");
					this->origem=indiceDaPilha;
				}
				// classifica os temprarios
				string aux;
				int j=0;
				for(int i=0;i<this->tam;i++)
				{
					aux=pilhas[i].getEstado();
					if(aux!="o" && aux!="d" && aux!="od")
					{
							this->temporario[j]=i;
							j++;
					}
				}
			}
			indiceDaPilha++;
		}
		if(!achou){
			cout<<"nao encontrado\n";
		}
	}

	void moveTemporario(int origem,int destino,Item item){
				cout<<"\n aqui desempilha \n";
				pilhas[origem].desempilha(item);
				cout<<"\n aqui empilha \n";
				pilhas[destino].empilha(item);


	}


	void organiza(Item &item){

		//limpa a pilha origem ate achar o item
			No *aux;
			aux=pilhas[this->origem].topo->prox;
			int i=0;
			while(aux!=NULL && aux->item.codigo != item.codigo)
			{
				moveTemporario(this->origem,this->temporario[i],item);
				//i++;
				aux=aux->prox;
			}
			//limpa a pilha destino inteira

			aux=pilhas[this->destino].topo->prox;
			i=0;
			while(aux!=NULL)
			{
				moveTemporario(this->destino,this->temporario[i],item);
				//i++;
				aux=aux->prox;
			}


			moveTemporario(this->origem,this->destino,item);


/*
		for(int i=0;i<4;i++)
		{
				if(pilhas[i].getEstado()=="od"||pilhas[i].getEstado()=="d")
				{
					cout<<"\n aqui empilha \n";
						pilhas[i].empilha(item);
				}
		}*/

	}

};



#endif /* PILHA_H_ */
