#include <bits/stdc++.h>
#define NULA 0
#define BRANCO 1
#define CINZA 2
#define PRETO 3

using namespace std;

class Item {
private:
	float peso;
	int num;
	int cor;
	int d,f;
	int inimigo;
	Item *anterior;
	vector<int> adj;
	int sInicial, sFinal;
public:
	Item() {
		this->d = 0;
		this->f = 0;
		this->num = 0;
		this->cor = NULA;
		this->anterior=NULL;
		this->inimigo = false;	
		peso = 0.0;
	}
	
	int getNum() {
		return num;
	}
	
	void setNum(int num) {
		this->num = num;
	}
	void setCor(int cor) {
		this->cor = cor;
	}
	int getCor() {
		return this->cor;
	}
	void setDescoberta(int d) {
		this->d = d;
	}
	void incrementa() {
		++this->d;
	}
	void setFinal(int f) {
		this->f = f;
	}
	
	int getIndice(int k) {
		return adj[k];
	}	
	
	void setAdj(int n) {
		adj.push_back(n);
	}
	
	void setAnterior(Item *item) {
		this->anterior = item;
	}
	
	int size() {
		return adj.size();
	}

	void setInimigo() {
		this->inimigo = true;
	}
	
	float getPeso() {
		return peso;
	}
	
	void setPeso(float peso) {
		this->peso = peso;
	}
};

class SubGrafo
{
private:
	vector<Item> vertices;
	vector<int> adj;
	int ord, m, indice, cor; 
	float distancia;
	bool inimigo;
	SubGrafo *anterior;
public:
	SubGrafo() {}

	void insertEdge(int u, int v, float peso) {
		vertices[u].setAdj(v);
		vertices[u].setNum(u);
		vertices[u].setPeso(peso);
		vertices[v].setAdj(u);
		vertices[v].setNum(v);
	}
	
	void setAnterior(SubGrafo *anterior) {
		this->anterior = anterior;
	}
	
	SubGrafo* getAnterior() {
		return anterior;
	}
	
	void setCor(int cor) {
		this->cor = cor;
	}
	
	int getCor() {
		return cor;
	}
	
	void setAdj(int v) {
		adj.push_back(v);
	}
	
	int getAdj(int v) {
		return adj[v];
	}
	
	void setIndice(int indice) {
		this->indice = indice;
	}
	
	int getIndice() {
		return indice;
	}
	
	float anda() {
		for (int k = 1; k <= ord; k++) {
			vertices[k].setCor(BRANCO);		
		}
		distancia = vertices[1].getPeso();		
		anda_aux(vertices[1]);
		return distancia;
	}

	void anda_aux(Item &item) {
		item.setCor(CINZA);
		for(int i = 0; i < item.size(); ++i) {			 
			if(vertices[item.getIndice(i)].getCor() == BRANCO) {
				distancia += vertices[item.getIndice(i)].getPeso();
				anda_aux(vertices[item.getIndice(i)]);
			}
		}
		item.setCor(PRETO);
	}
	
	void entrada(int ord, int m) {
		this->ord = ord;
		this->m = m;
		int a, b;
		float c;
	
		vector<Item> x(ord+1);
		vertices = x;
		for(int i = 1; i <= m; i++) {
			cin >> a >> b >> c;
			insertEdge(a, b, c);
		}
	}
	
	void setInimigo(bool valor) {
		inimigo = valor;
	}
	
	bool getInimigo() {
			return 	inimigo;
	}
	
	int size() {
		return adj.size();
	}
};

class Grafo
{
private:
	int ord, m;
	int sInicial, sFinal;
	vector<SubGrafo> vertices;
	
public:
	Grafo(int ord, int m) { 
		this->ord = ord;
		this->m = m;
		vector<SubGrafo> x(ord+1);
		vertices = x;
		
		for(int i = 1; i <= ord; i++) vertices[i].setInimigo(false);
	}

	float menorCaminho() {
		return menorCaminho(sInicial, sFinal);
	}
	
	float menorCaminho(int origem, int destino) {

		float distancia = 0.0;
		BFS(origem);
	
		SubGrafo *aux;
		aux = &vertices[destino];
		
		while(aux != NULL) {
			distancia += aux->anda();
			aux = aux->getAnterior();
		}
		return distancia;			
	}
	
	int getTamanho() {
		return m;
	}
	
	void setIncial(int sInicial){
		this->sInicial=sInicial;
	}
	void setFinal(int sFinal){
		this->sFinal=sFinal;
	}
	
	void setOrdem(int ordem){
		this->ord=ordem;
	}
	
	void setTamanho(int tamanho) {
		this->m=tamanho;	
	}
	
	SubGrafo getVertice(int num) {
		return vertices[num];
	}

	void insertEdge(int u, int v) {
		vertices[u].setAdj(v);
		vertices[u].setIndice(u);
		vertices[v].setAdj(u);
		vertices[v].setIndice(v);
	}
	
	void entradaSubGrafo() {
		int ordem, tamanho;
		for(int i = 1; i <= ord; i++) {
			//cout << "Ordem tamanho\n";
			cin >> ordem >> tamanho;
			vertices[i].entrada(ordem, tamanho);
		}
	}
		
	
	void BFS(int origem) {
		BFS(vertices[origem]);
	}

	void BFS(SubGrafo &s) {

		for (int k = 1; k <= ord; k++) {			
		
			if(s.getIndice() == k) vertices[k].setCor(CINZA);
			else vertices[k].setCor(BRANCO);

			vertices[k].setAnterior(NULL);				
		}

		list<SubGrafo> fila;
		fila.push_back(s);

		while(!fila.empty()) {
		
			SubGrafo u = fila.front();
			fila.pop_front();
			
			
			for(int i = 0; i < u.size(); ++i) {
				if(vertices[u.getAdj(i)].getCor() == BRANCO && (!getInimigo(u.getAdj(i)))) {
				
					vertices[u.getAdj(i)].setCor(CINZA);
					vertices[u.getAdj(i)].setAnterior(&vertices[u.getIndice()]);
					fila.push_back(vertices[u.getAdj(i)]);
				}
			}
			vertices[u.getIndice()].setCor(PRETO);
		}
	}
	void setInimigo(int indice) {
		vertices[indice].setInimigo(true);
	}
	
	bool getInimigo(int indice) {
			return 	vertices[indice].getInimigo();
	}

};

void entradaSuperGrafo(Grafo &supergrafo) {
	
		int a, b;
				
		for(int i = 1; i <= supergrafo.getTamanho(); i++) {
			cin >> a >> b;
			supergrafo.insertEdge(a, b);
		}
		
		int inimigos, sInicial, sFinal, num;
		cin >> inimigos;

		for(int i = 0; i < inimigos; i++) {
			cin >> num;
			supergrafo.setInimigo(num);
		}
		
		cin >> sInicial >> sFinal;			
		supergrafo.setIncial(sInicial);
		supergrafo.setFinal(sFinal);
		supergrafo.entradaSubGrafo();	
		cout << "Menor caminho: " << supergrafo.menorCaminho() << endl;	
}

int main(int argc, const char * argv[])
{
	int ordem, tamanho;
	cin >> ordem >> tamanho;
	Grafo supergrafo(ordem, tamanho);
	entradaSuperGrafo(supergrafo);//fazer fora do grafo
	//supergrafo.printl();
//cout"------------------------------------\n";	
	//supergrafo.printSB();
	//supergrafo.BFS(1);
	//supergrafo.destroy();
	////cout << supergrafo.menorCaminho() << endl;
	return 0;
}



