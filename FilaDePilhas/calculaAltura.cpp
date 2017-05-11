	int altura = 0;

	int getAltura() {
		return altura;
	}

	void calculaAltura() {
		No *aux;
		aux = topo->prox;
		while(aux != NULL)
		{
			altura++;
			aux = aux->prox;
		}
	}
