#include <bits/stdc++.h>
using namespace std;

template<class T>
class Grafo
{
private:
	T **matriz, soma;
	int ordem, tamanho, raiz; 

public:
	Grafo(int ordem, int tamanho) {
		initialize(ordem, tamanho);
	}

	void setRaiz(int raiz) {
		this->raiz = raiz;
	}
	
	void initialize(int ordem, int tamanho) {
		this->ordem = ordem;
		matriz = new T*[ordem];
 
    	for(int i = 0; i < ordem; ++i)
        	matriz[i] = new T[ordem];
	}

	void insertEdge(int u, int v, float peso) {
		matriz[u][v] = peso;
		matriz[v][u] = peso;
	}
			
	int chaveMinima(vector<float> chave, vector<bool> mstVertices) {
    	float minimo = FLT_MAX; 
    	int indice;
 
    	for (int v = 0; v < ordem; v++) {
  			if (mstVertices[v] == false && chave[v] < minimo) {
     			minimo = chave[v];
     			indice = v;
     		}
     	}
		return indice;
	}
  
	T MST_PRIM()
	{
		vector<int> adjacente(ordem); 
	 	vector<float> chave(ordem);   
 		vector<bool> mstVertices(ordem);
	 	soma = 0.0; 
	 
	 	for (int i = 0; i < ordem; i++)
	    	chave[i] = FLT_MAX, mstVertices[i] = false;
	 
	 	chave[0] = 0.0;     
 		adjacente[0] = -1; 
	 
 		for (int i = 0; i < ordem-1; i++) {
	    	int u = chaveMinima(chave, mstVertices);

	    	mstVertices[u] = true;
	 
    		for (int j = 0; j < ordem; j++) {		    
				if (matriz[u][j] && mstVertices[j] == false && matriz[u][j] <  chave[j]) {
					adjacente[j] = u;
					chave[j] = matriz[u][j];
				}
	  		}		    
		}

		for (int i = 1; i < ordem; i++) soma += matriz[i][adjacente[i]];
		return soma;
	}
	
	void destroy() {
		for(int i = 0; i < ordem; ++i)
        	delete []matriz[i];
 
    	delete []matriz;   
	}
};

Grafo<float> entrada() {
	int verticeA, verticeB, ordem, tamanho, raiz;
	float peso;
	
	cin >> ordem >> tamanho;
	
	Grafo<float> grafo(ordem, tamanho);
	for(int i = 0; i < tamanho; i++) {
		cin >> verticeA >> verticeB >> peso;
		grafo.insertEdge(verticeA, verticeB, peso);
	}
	
	cin >> raiz;
	grafo.setRaiz(raiz);
	return grafo;	
}

int main(int argc, const char * argv[])
{	
	Grafo<float> grafo = entrada();
	cout.precision(2);
	cout << fixed << grafo.MST_PRIM() << endl;
	grafo.destroy();
	return 0;
}


