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
	int tam;
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
	void calculaTam(){
		int tamanho=0;
		No *aux;
		aux=topo->prox;
		while(aux!=NULL)
		{
			tamanho++;
			aux=aux->prox;
		}
		this->tam=tamanho;
	}

	int getTam() {
		calculaTam();
		return tam;
	}


};

class Controle {
public:

	int primeiro,origem,destino,*temporario;
	int ultimo,tam,ultimaPosicaoValida;
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


		int indiceDaPilha;
		bool achou;

		for(indiceDaPilha=0;indiceDaPilha<=ultimaPosicaoValida;indiceDaPilha++){
			achou=pilhas[indiceDaPilha].busca(item);
			if(achou)//se achou
			{

				// classifica a origen e o destino
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

			}
		}
		// classifica os temporarios
		string aux="o";
		int j=0;
		for(int i=0;i<ultimaPosicaoValida;i++)
		{

			aux=pilhas[i].getEstado();
			if(aux!="o" && aux!="d" && aux!="od")
			{
					cout<<aux<<endl;
					cout<<i<<endl;
					this->temporario[j]=i;
					j++;
			}
		}
		//delimitador fim do vetor temporario
		temporario[j]=-1;



		if(!achou){
			cout<<"nao encontrado\n";
		}
	}

	void TrocaDePilha(int origem,int destino,Item item){

				pilhas[origem].desempilha(item);
				cout<<"\nmovendo o item ";
				item.mostra();
				pilhas[destino].empilha(item);
	}
	void mostraT(){

		int i=0;
				while(temporario[i]!=-1){
					cout<<"\n valor do temporario "<<temporario[i]<<endl;
						i++;
				}
	}

	int melhorTemporario(){
		int i=0,tamDaMenorPilha=1000,tamAtual=0,melhorIndice;//vou guardar o menor contador possivel

		while(temporario[i]!=-1){
			tamAtual=pilhas[temporario[i]].getTam();
				  if(tamDaMenorPilha>tamAtual){
					  tamDaMenorPilha=tamAtual;
					  melhorIndice=temporario[i];
				  }
				i++;
		}
		return melhorIndice;
	}

	void move(Item item, int origem,int destino,int temp){
		if(pilhas[this->destino].topo->item.codigo==item.codigo)
		{//se topo do destino tiver o item
			cout<<"fim da ordenacao"<<endl;//pilha de origem for == a item
		}else{
			//calcula o melhor temporario posivel
			temp=melhorTemporario();

			//limpa a pilha destino ele esta limpando tudo e isso nao e certo
			if(pilhas[this->destino].topo->prox!=NULL ){

				TrocaDePilha(destino,temp,item);
				cout<<"da pilha "<<destino<<" para a pilha "<<temp<<endl;
				move(item,origem,destino,temp);

			}else{

				if(pilhas[this->origem].topo->prox->item.codigo==item.codigo){
					TrocaDePilha(origem,destino,item);
				}else{

					TrocaDePilha(origem,temp,item);
					cout<<"da pilha "<<origem<<" para a pilha "<<temp<<endl;
					move(item,origem,destino,temp);
				}

			}
		}
	}





	void organiza(Item &item){

		move(item,this->origem,this->destino,this->temporario[0]);

	}

};



#endif /* PILHA_H_ */
