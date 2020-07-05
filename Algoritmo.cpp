#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <locale.h>
#include <cstring>
#include <windows.h>

using namespace std;

//Estrutura do paciente
struct PAC
{
	char nomePACIENTE[100];
	int pacienteREGISTRO;
};


//Estrutura do medico
struct MED
{
	char nomeMEDICO[100];
	int medicoREGISTRO;
};

struct registro
{
	char nomePAC[100];
	char nomeMED[100];
	int numeroATENDIMENTO;
};


//Estrutura da Pilha
struct Pilha
{
	int topo; //guarda a posição do topo
	int capacidade; //guarda a capacidade da pilha
	MED *pElem; //ponteiro para int

} p;

//Estrutura da lista
struct lista
{
	PAC pac;
	struct lista *prox;
};
typedef struct lista Lista;

//Estrutura da arvore AVL
struct noh
{
	registro REGIS;
	struct noh *esq;
	struct noh *dir;
	int altura;

};
typedef struct noh arvore;

char nomePaciente[100];


//criado a pilha com capacidade = 15
void criarPilha(struct Pilha *p, int c)
{
	p->topo = -1; //pilha vazia
	p->capacidade = c; //capacidade da pilha
	p->pElem = (MED*) malloc (c * sizeof(MED)); //alocando tamanho
}

//verifica se a pilha de médicos está vazia
int estaVazia(struct Pilha *p)
{
	if(p->topo == -1)
		return 1; //pilha vazia
	else
	{
		return 0; //pilha nao vazia
	}
}

//verifica se a pilha de médico está cheia
int estaCheia(struct Pilha *p)
{
	if(p->topo == p->capacidade - 1)
		return 1;
	else
	{
		return 0;
	}
}

//Empilando (push) - insere médicos na pilha
void push(struct Pilha *p)
{
	system("cls");

	int tamanhoREGISTRO;
	int contREGISTRO = 0;

	MED *novoMed = (MED*) malloc(sizeof(MED));

	cout << "Nome do medico à ser inserido: ";
	cin.ignore();
	cin.getline(novoMed->nomeMEDICO, 100);
	cout << endl;

	do
	{
		if(contREGISTRO == 0)
		{
			cout << "Digite um registro para o medico(5-10): ";
			cin >> novoMed->medicoREGISTRO;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
			}
			cout << endl;

			//pega a quantidade de numeros da expressão
			tamanhoREGISTRO = floor(1 + log10(novoMed->medicoREGISTRO));
			contREGISTRO++;
		}

		else
		{
			cout << "Registro inválido! O Registro deve ter no mínimo 5 caracteres e no máximo 10 caracteres." << endl;
			cout << "Digite novamente: ";
			cin >> novoMed->medicoREGISTRO;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
			}
			cout << endl;

			//pega a quantidade de numeros da expressão
			tamanhoREGISTRO = floor(1 + log10(novoMed->medicoREGISTRO));
		}

	}
	while(tamanhoREGISTRO < 5 || tamanhoREGISTRO > 10);

	p->topo++;
	p->pElem[p->topo] = *novoMed;

	cout << "Médico inserido com sucesso!" << endl;
	cout << endl;

	system("pause");

}

//Desempilhar (pop) - remove médico da pilha após atender um paciente
MED pop(struct Pilha *p)
{
	system("cls");

	MED aux = p->pElem[p->topo];
	p->topo--;

	return aux;
}

//Retorna o médico que está no topo da pilha
void retornaTopo(struct Pilha *p)
{
	system("cls");

	int RECEBE;

	RECEBE = estaVazia(p);

	if(RECEBE == 1)
	{
		cout << "Não há médicos disponíveis!" << endl;
		cout << endl;
	}

	else
	{
		cout << "PRÓXIMO MÉDICO DISPONÍVEL: " << endl;
		cout << endl;
		cout << "Nome: " << p->pElem->nomeMEDICO << endl;
		cout << "Registro: " << p->pElem->medicoREGISTRO << endl;
		cout << endl;
	}

	system("pause");
}

//Criando uma lista de pacientes vazia
Lista *list_cria(void)
{
	return NULL;
}

//Inserindo um paciente na lista
Lista *list_insere(Lista *list)
{
	system("cls");

	int contREGISTRO = 0;
	int tamanhoREGISTRO;

	Lista *novo = (Lista*) malloc(sizeof(Lista));

	cout << "Nome do paciente à ser inserido: ";
	cin.ignore();
	cin.getline(novo->pac.nomePACIENTE, 100);
	cout << endl;

	do
	{
		if(contREGISTRO == 0)
		{
			cout << "Digite um registro para o paciente(5-10): ";
			cin >> novo->pac.pacienteREGISTRO;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
			}
			cout << endl;
			tamanhoREGISTRO = floor(1 + log10(novo->pac.pacienteREGISTRO));
			contREGISTRO++;
		}

		else
		{
			cout << "Registro inválido! O Registro deve ter no mínimo 5 caracteres e no máximo 10 caracteres." << endl;
			cout << "Digite novamente: ";
			cin >> novo->pac.pacienteREGISTRO;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
			}
			cout << endl;

			//pega a quantidade de numeros da expressão
			tamanhoREGISTRO = floor(1 + log10(novo->pac.pacienteREGISTRO));
		}

	}
	while(tamanhoREGISTRO < 5 || tamanhoREGISTRO > 10);

	novo->prox = list;
	return novo;

}

//verifica se a lista de pacientes esta vazia
int list_vazia(Lista *list)
{
	return(list == NULL);
}

//remove um paciente da lista após ser atendido
Lista *list_retira(Lista *list)
{
	lista *A = NULL;
	Lista *p = list;

	while(p->prox != NULL)
	{
		A = p;
		p = p->prox;
	}
	strcpy(nomePaciente, p->pac.nomePACIENTE);

	if(A == NULL)
	{
		cout << "Um paciente foi atendido!" << endl;
		cout << endl;
		list = p->prox;

	}

	else
	{
		A->prox = p->prox;
		cout << "Um paciente atendido!" << endl;
		cout << endl;
	}

	system("pause");

	free(p);
	return list;

}

//mostra os pacientes em espera
void list_imprime(Lista *list)
{
	system("cls");

	Lista *p;
	int RECEBE;

	RECEBE = list_vazia(list);

	if(RECEBE == NULL)
	{
		cout << "LISTA DE PACIENTES EM ESPERA: " << endl;
		for(p = list; p != NULL; p = p->prox)
		{
			cout << endl;
			cout << "Nome: " << p->pac.nomePACIENTE << endl;
			cout << "Registro: " << p->pac.pacienteREGISTRO << endl;
			cout << endl;
		}
	}

	else
	{
		cout << "Não há pacientes em espera! " << endl;
		cout << endl;
	}

	system("pause");
}


//cria uma arvore vazia
arvore *arv_criavazia(void)
{
	return NULL;
}

//Cria arvore com um no
arvore *novoNo(registro *rg)
{
	arvore *p = (arvore*)malloc(sizeof(arvore));
	p->REGIS = *rg;
	p->esq = NULL;
	p->dir = NULL;
	p->altura = 1;
	return p;
}

//Pega a altura de uma arvore
int altura(arvore *a)
{
	if(a == NULL)
		return 0;
	return a->altura;
}

//Retorna o valor min da arvore
arvore *min(arvore *a)
{
	arvore *atual = a;

	while(atual->esq != NULL)
		atual = atual->esq;

	return atual;
}

//Rotacao a esquerda
arvore *rotacaoEsquerda(arvore *x)
{
	arvore *y = x->dir;
	arvore *T2 = y->esq;

	//Realiza a rotacao
	y->esq = x;
	x->dir = T2;

	//Atualiza as alturas
	x->altura = max(altura(x->esq), altura(x->dir)) + 1;
	y->altura = max(altura(y->esq), altura(y->dir)) + 1;

	//Retora nova raiz
	return y;
}

//Rotacao a direita
arvore *rotacaoDireita(arvore *y)
{
	arvore *x = y->esq;
	arvore *T2 = x->dir;

	//Realiza a rotacao
	x->dir = y;
	y->esq = T2;

	//Atualiza as alturas
	y->altura = max(altura(y->esq), altura(y->dir)) + 1;
	x->altura = max(altura(x->esq), altura(x->dir)) + 1;

	//Retorna nova raiz
	return x;
}

//Calcula o fator de balanceamento
int pegaBalanceamento(arvore *a)
{
	if(a == NULL)
		return 0;
	return altura(a->esq) - altura(a->dir);

}

//Pega o maximo entre 2 intiros
int max(int a, int b)
{
	return (a > b) ? a : b;
}

//Insere na arvore
arvore *insere(arvore *a, registro *rg)
{
	//1.Inserindo normalmente
	if(a == NULL)
	{
		return(novoNo(rg));
	}

	if(rg->numeroATENDIMENTO < a->REGIS.numeroATENDIMENTO)
		a->esq = insere(a->esq, rg);

	else if(rg->numeroATENDIMENTO > a->REGIS.numeroATENDIMENTO)
		a->dir = insere(a->dir, rg);
	else//chaves iguais nao sao permitidas
		return a;

	//2.Atualiza a altura do no pai
	a->altura = 1 + max(altura(a->esq), altura(a->dir));

	//3.Pega o fator de balanceamento do pai para verificar se esta desbalanceado
	int fb = pegaBalanceamento(a);
	//Se houver desbalanceamento, entao pode cair nos 4 casos de rotacao

	//3.1.Rotacao a Direita
	if(fb > 1 && rg->numeroATENDIMENTO < a->esq->REGIS.numeroATENDIMENTO)
		return rotacaoDireita(a);

	//3.2.Rotacao a Esquerda
	if(fb < -1 && rg->numeroATENDIMENTO > a->dir->REGIS.numeroATENDIMENTO)
		return rotacaoEsquerda(a);

	//3.3.Rotacao Esquerda Direita
	if(fb > 1 && rg->numeroATENDIMENTO > a->esq->REGIS.numeroATENDIMENTO)
	{
		a->esq = rotacaoEsquerda(a->esq);
		return rotacaoDireita(a);
	}

	//3.4.Rotacao Direita Esquerda
	if(fb < -1 && rg->numeroATENDIMENTO < a->dir->REGIS.numeroATENDIMENTO)
	{
		a->dir = rotacaoDireita(a->dir);
		return rotacaoEsquerda(a);
	}

	return a;
}

//Verifica se a arvore e vazia
int arv_vazia(arvore *a)
{
	return a == NULL;
}

//Busca pelos atendimentos utilizando a arvore
void arv_busca(arvore* a, int PESQ)
{
	if(!arv_vazia(a))
	{
		if(PESQ == a->REGIS.numeroATENDIMENTO)
		{
			cout << "Numero de atendimento: " << a->REGIS.numeroATENDIMENTO << endl;
			cout << "Paciente: " << a->REGIS.nomePAC << endl;
			cout << "Médico: " << a->REGIS.nomeMED << endl;
			cout << endl;
		}
		
		else
		{
			cout << "Esse número de atendimento não está registrado no sistema." << endl;
			cout << endl;
		}
		arv_busca(a->esq, PESQ);
		arv_busca(a->dir, PESQ);
	}
}

int main()
{
	//Varivaveis
	int OP;
	int RECEBE1;
	int RECEBE2;
	int foiATENDIDO = 0;
	int atendimentoBUSCA;
	MED med;
	arvore *ARV;

	Lista *LISTA;
	LISTA = list_cria();

	criarPilha(&p, 15);

	//Criar árvore vazia.
	ARV = arv_criavazia();

	setlocale(LC_ALL, "Portuguese");

	while(1)
	{
		system("cls");

		cout << "Bem-vindo ao ProntoMED" << endl;
		cout << endl;
		cout << "1 - Inserir novos pacientes;" << endl;
		cout << "2 - Inserir novos médicos;" << endl;
		cout << "3 - Médicos disponíveis;" << endl;
		cout << "4 - Lista de Paciêntes em espera;" << endl;
		cout << "5 - Realizar atendimento;" << endl;
		cout << "6 - Acessar registro de atendimento; " << endl;
		cout << "7 - Buscar informações no site oficial; " << endl;
		cout << "8 - Sair do programa." << endl;
		cout << "Opção: ";
		cin >> OP;
		cout << endl;

		switch(OP)
		{
			//Chama a função insere para inserir um paciente na lista
		case 1:
			LISTA = list_insere(LISTA);
			cout << "Paciente inserido com sucesso!" << endl;
			cout << endl;

			system("pause");
			break;

			//Chama a função pop para inserir um médico na pilha
		case 2:
			push(&p);

			break;

			//Mostra um médico disponível que está no topo da pilha
		case 3:
			retornaTopo(&p);
			break;

			//Mostra todos os pacientes que estão em espera
		case 4:
			list_imprime(LISTA);
			break;

			//Faz o atendimento, excluindo um paciente e um médico quando há pelo menos 1 médico na pilha e 1 paciente na lista
		case 5:

			system("cls");

			RECEBE1 = estaVazia(&p);
			RECEBE2 = list_vazia(LISTA);

			if(RECEBE1 == 0 && RECEBE2 == NULL)
			{


				registro *REGIS = (registro*) malloc(sizeof(registro));
				foiATENDIDO++;
				LISTA =	list_retira(LISTA);
				med = pop(&p);
				strcpy(REGIS->nomeMED, med.nomeMEDICO);
				strcpy(REGIS->nomePAC, nomePaciente);
				REGIS->numeroATENDIMENTO = foiATENDIDO;
				ARV = insere(ARV, REGIS);
			}

			else if(RECEBE1 == 0 && RECEBE2 != NULL)
			{
				cout << "Não há pacientes em espera!" << endl;
				cout << endl;
			}

			else if(RECEBE1 != 0 && RECEBE2 == NULL)
			{
				cout << "Não há médicos disponíveis!" << endl;
				cout << endl;
			}

			else
			{
				cout << "Não há médicos disponíveis nem pacientes em espera! " << endl;
				cout << endl;
			}

			system("pause");
			break;

		case 6:
			if(arv_vazia(ARV) == 1)
			{
				system("cls");

				cout << "Não há atendimento registrado no sistema." << endl;
				cout << endl;
			}
			else
			{
				system("cls");

				cout << "Número do atendimento: ";
				cin >> atendimentoBUSCA;
				cout << endl;
				arv_busca(ARV, atendimentoBUSCA);
			}

			system("pause");
			break;
			//Sai do programa

        case 7:
        	system("cls");
        	
        	cout << "Escolha uma opção de navegador: " << endl;
        	cout << endl;
        	cout << "1 - Google Chrome" << endl;
        	cout << "2 - Internet Explorer" << endl;
        	cout << "Opção: ";
        	cin >> OP;
        	cout << endl;
        	switch(OP)
        	{
				case 1:
					system("start chrome.exe http://www.prontomedmg.com.br/br/index.php");
					break;
				case 2:
					system("start iexplore.exe http://www.prontomedmg.com.br/br/index.php");
					break;
				
			default:
			cout << "Entrada incorreta! " << endl;
			cout << endl;
			break;
					
			}
        	
        	break;
		case 8:
			cout << "Obrigado por ter se aventurado em nosso novo programa! " << endl;
			return 0;
			break;

		default:
			cout << "Entrada incorreta! " << endl;
			cout << endl;
			break;

		}
	}

}
