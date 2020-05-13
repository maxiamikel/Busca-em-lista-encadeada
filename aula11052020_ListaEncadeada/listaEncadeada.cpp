//Faça a fusão de duas listas encadeadas, de números inteiros, em uma única lista.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct tipoElemento
{
	int valor;
	struct tipoElemento *proximo;
}TElemento;

typedef struct tipoLista
{
	TElemento *inicio;
	TElemento *fim;
}TLista;

void inicializar (TLista *p)
{
	p->inicio = NULL;
	p->fim = NULL;
}

void inserir (TLista *p)
{
	TElemento *novoElemento;
	novoElemento = (TElemento *) malloc (sizeof(TElemento)); // OU novoElemento = new TElemento;
	
	printf("\n Informe valor: ");
	scanf("%d", &novoElemento->valor);
	novoElemento->proximo = NULL;
	
	if (p->inicio == NULL)
	{
		p->inicio = novoElemento;
		p->fim = novoElemento;
	}
	else
	{
		p->fim->proximo = novoElemento;
		p->fim = novoElemento; // OU p->fim = p->fim->proximo;
	}
}

void apresentar (TLista *p)
{
	TElemento *aux;
	aux = p->inicio;
	
	while (aux != NULL)
	{
		printf("\n Valor: %d", aux->valor);
		aux = aux->proximo;
	}
}

void fusaoL1L2 (TLista *pL1, TLista *pL2)
{
	pL1->fim->proximo = pL2->inicio;
	pL1->fim = pL2->fim;
	inicializar(pL2);
}


int verificaListasIguais(TLista *l1, TLista *l2)
{
	TElemento *aux1,*aux2;
	aux1 = l1->inicio;
	aux2 = l2->inicio;
	while(aux1 != NULL && aux2 != NULL)
	{
		if(aux1->valor != aux2->valor)
		{
			return 0;
		}
		else
		{
			aux1 = aux1->proximo;
		    aux2 = aux2->proximo;
		}	
		
	}
	if(aux1 == aux2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
TElemento* buscaRecursiva(TElemento *p, int valor)
{
	if(p == NULL)
	{
		return NULL;
	}
	else
	{
		if(p->valor == valor)
		{
			return p;
		}
		else
		{
			return buscaRecursiva(p->proximo, valor);
		}
	}
}

void verificacaoL1L2(TLista *pL1, TLista *pL2)
{
	if (verificaListasIguais(pL1, pL2) == 1)
	{
		printf("\n Listas iguais!");
	}
	else
	{
		printf("\n Listas diferentes!");
	}
}
 TElemento* buscarValor(TLista *p, int valorConsulta)
 {
 	TElemento *aux;
 	aux = p->inicio;
 	while(aux != NULL)
 	{
 		if(aux->valor == valorConsulta)
		 {
		 	return aux;
		 }	
		 else
		 {
		 	aux = aux->proximo;
		// return aux = buscarValor(p, aux->proximo);
		 }
	}
	return aux;
 }

void consultarValor(TLista *p)
{
	int valorBusca;
	printf("\n Informe o valor para buscar: ");
	fflush(stdin);
	scanf("%d", &valorBusca);
	 if(buscarValor(p,valorBusca) != NULL)
	 {
	 	printf("\n Valor encontrado\n");
	 }
	 else
	 {
	 	printf("\n Valor nao encontrado\n");
	 }
}

int main()
{
	int opcao;
	
	TLista L1, L2;
	
	inicializar (&L1);
	inicializar (&L2);

	
	do
	{
		printf("\n 1 - Informe valor para L1");
		printf("\n 2 - Informe valor para L2");
		printf("\n 3 - Apresentar lista L1");
		printf("\n 4 - Apresentar lista L2");
		printf("\n 5 - Fusao de L1 com L2");
		printf("\n 6 - Verificar L1 = L2");
		printf("\n 7 - Consultar");
		printf("\n 0 - Sair");
		printf("\n Escolha uma opcao: ");
		scanf("%d", &opcao);
		switch(opcao)
		{
			 case 1: inserir (&L1); break;
			 case 2: inserir (&L2); break;
			 case 3: apresentar (&L1); break;
			 case 4: apresentar (&L2); break;
			 case 5: fusaoL1L2 (&L1, &L2); break;
			 case 6: verificacaoL1L2(&L1,&L2); break;
			 case 7: consultarValor(&L1); break;
		}
	}while (opcao != 0);
}



