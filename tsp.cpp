#include <bits/stdc++.h>

#define NULA 0

#define BRANCO 1

#define CINZA 2

#define PRETO 3


using namespace std;



class filaPrioridade {
private:
	
	int indice;
	float peso;
public:


int getIndice() {
		
	return indice;
	
}	
	
	

void setIndice(int indice) {
		
	this->indice = indice;
	
}
	
			
	

float getPeso() {
		
	return peso;
	
}


void setPeso(float peso) {
		
	this->peso = peso;
	
}
	
	
};

class Item {

private:
	
	float peso;
	
	int num;
	
	int cor;
	
	int d,f;
	
	int inimigo;
	
	Item *anterior;
	
	vector<filaPrioridade> fila;	
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
	
	

filaPrioridade deletemin()
{
    filaPrioridade min = fila.front();
    fila[0] = fila.at(fila.size() - 1);
    fila.pop_back();
    heapifydown(0);
    return min;
}

void heapifyup(int v)
{   
	if(v == 1) return;

	int p =pai(v);

	if(fila[v].getPeso() < fila[p].getPeso()) { 
 		filaPrioridade tmp = fila[v];
		fila[v] = fila[p];
		fila[p] = tmp;
		heapifyup(p);
	}
}

void heapifydown(int v)
{     
    int d = direita(v);
    int e = esquerda(v);

	int maior = v;

    if(d <= fila.size() && fila[d].getPeso() < fila[v].getPeso()) maior = d;

    if(e <= fila.size() && fila[e].getPeso() < fila[maior].getPeso()) maior = e;

    

    if(maior != v) { 
        filaPrioridade tmp = fila[v];	
	fila[v] = fila[maior];
	fila[maior] = tmp;
        heapifydown(maior);
    }
}

int esquerda(int i)
{
    return 2*i;
}

int direita(int i)
{
    return 2*i+1;
}

int pai(int i)
{   
    return i/2;
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
		
	return fila[k].getIndice();
	
}

filaPrioridade getMin() {
		
	return fila[0];
	
}	
	
	

void setAdj(filaPrioridade n) {
		
	fila.push_back(n);

	heapifyup(fila.size()-1);	
}
	
	

void setAnterior(Item *item) {
		
	this->anterior = item;
	
}
	
	

int sizeAdj() {
		
	return fila.size();
	
}

	

void setInimigo() {
		
	this->inimigo = true;
	
}
	
	

float getPeso(int i) {
	return fila[i].getPeso();
}

void printAdj() {
	for(int i = 0; i < fila.size(); i++) cout << fila[i].getIndice() << "-" << fila[i].getPeso() << " ";
	cout << endl;
}
};



class Grafo 
{

private:
	
	vector<Item> vertices;
		
	int ord, m, indice, cor, origem; 
	
	float distancia;
	
	bool inimigo;
	
	Grafo *anterior;


public:
	
Grafo() {}

	

void insertEdge(int u, int v, float peso) {

	filaPrioridade itemFila;
	itemFila.setIndice(v);
	itemFila.setPeso(peso);				
	vertices[u].setNum(u);
		
	vertices[u].setAdj(itemFila);

	itemFila.setIndice(u);
	vertices[v].setAdj(itemFila);

	vertices[v].setNum(v);
	
}
	
	

void setAnterior(Grafo *anterior) {
		
	this->anterior = anterior;
	
}
	
	

Grafo* getAnterior() {
		
	return anterior;
	
}
	
	

void setOrigem(int origem) {
		
	this->origem = origem;
	
}

void setCor(int cor) {
		
	this->cor = cor;
	
}
	
	

int getCor() {
		
	return cor;
	
}
	
	
	

void setIndice(int indice) {
		
	this->indice = indice;
	
}
	
	

int getIndice() {
		
	return indice;
	
}
	
	

float tsp(int origem) {
		
	for (int k = 1; k <= ord; k++) {
			
		vertices[k].setCor(BRANCO);		
		
	}
		
	distancia = 0.0;	
		
	tsp_aux(vertices[origem], 1);
		
	return distancia;
	
}

	

void tsp_aux(Item &item, int count) {

		item.setCor(CINZA);
		
		filaPrioridade min = item.deletemin();
		int k = min.getIndice();
		if(count == ord && vertices[k].getNum() == origem) {
			distancia += min.getPeso();
		}
		if(vertices[k].getCor() == CINZA) {
			min = item.deletemin();
			k = min.getIndice();
		}

		if(vertices[k].getCor() == CINZA) {
			min = item.deletemin();
			k = min.getIndice();
		}

		 
			
		if(vertices[k].getCor() == BRANCO) {

							
			distancia += min.getPeso();
				
			tsp_aux(vertices[k], ++count);
			
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
	
	

void printl() {	
	for (int k = 1; k < vertices.size(); k++) {
		cout << k << ": ";
		vertices[k].printAdj();				
		cout << "\n";		
	}
}


};

int main(int argc, const char * argv[])
{
	
	int ordem, tamanho, origem;
	
	cin >> ordem >> tamanho;
	
	Grafo g;
	
	g.entrada(ordem, tamanho);
	cin >> origem;
	g.setOrigem(origem);
	cout << g.tsp(origem)<< endl;
}	
	