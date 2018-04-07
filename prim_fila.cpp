#include <bits/stdc++.h>
#define NULA 0
#define BRANCO 1
#define CINZA 2
#define MAXIMO 1000
using namespace std;

class Vertice{
private:
	float peso;
	int num;//	int indice;
	int d;//	int vizinho;
	float chave;

public:
	Vertice() {
		this->chave=0.0;
		this->d = 0;
		this->num = 0;
	
	}
	
	Vertice(float peso) {
		this->peso = peso;
	}

	int getPi() {
		return d;
	}
	
	void setPi(int n) {
		this->d = n;
	}
	
	int getIndice() {
		return num;
	}
	
	void setIndice(int num) {
		this->num = num;
	}
	
	float getPeso() {
		return peso;
	}
	
	void setPeso(float peso) {
		this->peso = peso;
	}
	float getKey() {
		return peso;
	}
	
	void setKey(float c) {
		this->chave = c;
	}
	
	
};

class Vertice2 {
public:
	float chave;
	int vizinho;
	int indice;
	float peso;
	
public:
	Vertice2(float chave){
		this->chave=chave;
	}
	Vertice2(){
		this->chave=800.0;
	}
	float getPeso() {
		return peso;
	}

	void setPeso(float peso) {
		this->peso = peso;
	}	

	float getKey() {
		return chave;
	}

	void setKey(float chave) {
		this->chave; 
	}	
	
	int getPi() {
		return vizinho;
	}
	
	void setPi(int vizinho) {
		this->vizinho = vizinho;
	}
	int getIndice() {
		return indice;
	}
	
	void setIndice(int indice) {
		this->indice = indice;
	}
};	

class Grafo
{
private:
	Vertice **mat;
	int ord, m, tempo; 

public:
	Grafo(int ord, int m){
		initialize(ord, m);
	}

	void initialize(int ord, int m) {
		this->tempo=0;
		this->ord = ord;
		mat = new Vertice*[ord+1];
 
    	for(int i = 0; i <ord; ++i)
        	mat[i] = new Vertice[ord+1];
	}

	void insertEdge(int u, int v, float peso) {
		Vertice v1;
		//v1.setKey(10000);
		//u=0 v=1 p=74

		v1.setPeso(peso);
		v1.setIndice(u);
		mat[u][v] = v1;

		v1.setIndice(v);
		mat[v][u] = v1;

	}
		
	void print() {	
		for(int i = 0; i <ord; ++i) {
			for(int j = 0; j < ord; ++j){
				cout << (int)mat[i][j].getIndice() << "   ";

			}
							cout << endl;
		}
	}
		Vertice minimo1(vector<Vertice> fila){
			Vertice atual,minimo=fila[0];
//			cout<<"DEBUG "<<fila.size()<<endl;
//			minimo.setPeso(-1);
				// pra todos os vertices na fila
			for(int c = 0; c < fila.size(); ++c){
				atual = fila[c];
			
				//olhar todos os adjs do atual
				for(int j = 0; j < ord; ++j){
				
					//cout<<"\n------------\natual indice \n"<<atual.getIndice();
					if(mat[atual.getIndice()][j].getKey() < minimo.getKey()){
							minimo = mat[atual.getIndice()][j];
							
					}
				}

			}			
			
			/*for(int j = 0; j < fila.size(); ++j){
				float peso=(float)fila[j].getPeso();
				if( peso < minimo.getPeso()){
						minimo = fila[j];
				}
			}*/	
			return minimo;
	}
	Vertice minimo11(vector<Vertice> fila){
			Vertice minimo;
//			cout<<"DEBUG "<<fila.size()<<endl;
			minimo = fila[0];
			
			for(int j = 0; j < fila.size(); ++j){
				float peso=(float)fila[j].getPeso();
				if( peso < minimo.getPeso()){
						minimo = fila[j];
				}
			}
			return minimo;
	}
	
	bool in(Vertice v, vector<Vertice> fila){
		
			for(int j = 0; j < fila.size(); ++j){
				if(fila[j].getIndice() ==  v.getIndice()){
						return true;
				//cout<<"tes"<<fila[j].getIndice();
				}
			}

		//	cout<<v.getIndice() <<" nao est na fila\n";
		//	mostraFila(fila);
			cout<<endl;

			return false;
	}
	void remove(Vertice v, vector<Vertice> &fila){
			int count=0;
			for(int j = 0; j < fila.size(); ++j){
				if(fila[j].getIndice() ==  v.getIndice()){
						j=fila.size()+1;
						count--;
				}
				count++;
			}
			fila.erase (fila.begin()+count);
	}
	void mostraFila(vector<Vertice> &fila){
			cout<<"\nfila\n";
			for(int j = 0; j < fila.size(); ++j){
				cout<<"\nindice ;"<<fila[j].getIndice()<<endl;
				cout<<"\npeso ;"<<fila[j].getPeso()<<endl;
	
			}
	}
	float PRIM(Vertice r){	
//		r=mat[r.getIndice()][0];
		float minimo = 0.0;
		for(int i = 0; i <ord; ++i) {
			for(int j = 0; j < ord; ++j){
				float max=2000.0;
				
				if((mat[i][j].getIndice()==r.getIndice())){
							mat[i][j].setKey(0.0);
							cout<<"\n2222estou valendo \n"<<mat[i][j].getKey();
							cout<<"\nindice \n"<<mat[i][j].getIndice();
				}else{
				
					mat[i][j].setKey(max); 
				}

	//			cout<<"\n-------\nkey "<<mat[i][j].getKey()<<endl;
				//defalut anterior é sempre o -1
				mat[i][j].setPi(-1);
//				cout<<"\n\nDEBUG setando o pos: "<<mat[i][j].getIndice()<<"pos : ij "<<i<<j<<endl;
				}
		}
//	cout<<"\n\nDEBUG 0 1: "<<mat[0][1].getIndice()<<"pos : ij "<<i<<j<<endl;

		
		
		
		vector<Vertice> fila;
//		fila.push_back(r);
		// preenchimento da fila
	//	cout<<"DEBUG ord: "<<ord<<endl;
		for(int i = 0; i <ord; ++i) {
				for(int j = 0; j < ord; ++j){
				/*if(i==6)
				{
				cout<<"DEBUG indice : "<<mat[i][j].getIndice()<<" ij "<<i<<" "<<j<<endl;
				cout<<"PESO : "<<mat[i][j].getPeso()<<endl;
				}*/

					if(!in(mat[i][j], fila)){
							fila.push_back(mat[i][j]);//indice
							cout<<"entrando na fila indice : "<<mat[i][j].getIndice()<<endl;
					}
					if(mat[j][i].getPeso()>0 && !in(mat[j][i], fila)){
						fila.push_back(mat[j][i]);//indice
						cout<<"entrando na fila indice : "<<mat[j][i].getIndice()<<endl;
					}
				}
		}		
		while(!fila.empty()) {
				//mostraFila(fila);
				Vertice	u = minimo1(fila);
				cout<<"\n\nDEBUG indice do no: "<<u.getIndice()<<endl;
				cout<<"\n\nDEBUG peso: "<<u.getPeso()<<endl;
				minimo += u.getPeso();
			//	cout<<"DEBUG size antes  : "<<fila.size()<<endl;
				remove(u,fila);
			//	cout<<"DEBUG size depois  : "<<fila.size()<<endl;
				for(int j = 0; j < ord; ++j){
							// se a=é adjacente a u cria o vertice v
							if(mat[u.getIndice()][j].getPeso() >0){
								Vertice	v=mat[u.getIndice()][j];

								if((in(v,fila))){								
							   		    if (mat[u.getIndice()][j].getKey() < v.getKey()){
												v.setPi(u.getIndice());			
												v.setKey(mat[u.getIndice()][j].getKey());			
												cout<<"\n++++++++++++++++++++\n";
											
										}else{
												cout<<"\nIN else mat i: "<<u.getIndice()<<" j: "<<j<<endl;
												cout<<"\nIN else mat key: "<<mat[u.getIndice()][j].getKey();
		 									    cout<<"\nIN else mat indice: "<<mat[u.getIndice()][j].getIndice();
												cout<<"\nIN else v key: "<< v.getKey();
												cout<<"\nIN else v in: "<< v.getIndice();										
												/*cout<<"\nIN else: "<<v.getIndice()<<endl;
												cout<<"\nPES else: "<<v.getPeso()<<endl;
												cout<<"\nKE else: "<<v.getKey()<<endl;*/
										}
							}else{
							
							//			cout<<"\n v nao este na fila\n";							
							}
						}
				}		
		}
		return minimo;
	
	}
	
	


	void destroy(){
		for(int i = 0; i < ord; ++i)
        	delete []mat[i];
 
    	delete []mat;   
	}
};

Grafo entrada() {
	int a, b, ordem, m, origem;
	float peso;
	
	//cout << "Ordem e tamanho: ";
	cin >> ordem >> m;
	
	Grafo g(ordem, m);
	for(int i = 0; i < m; i++) {
		//cout << "\nvertices: ";
		cin >> a >> b >> peso;
		g.insertEdge(a, b, peso);
	}
	
	cin >> origem;
	Vertice v(74.29);//peso

	
	v.setIndice(origem);
	cout<<"origem"<<origem<<endl;
	cout<<"ENTRADApimri	o indice : "<<v.getIndice()<<endl;
	cout << g.PRIM(v) << endl;
	return g;	
}

int main(int argc, const char * argv[])
{	
	Grafo g = entrada();
g.print();
	g.destroy();
	return 0;
}
