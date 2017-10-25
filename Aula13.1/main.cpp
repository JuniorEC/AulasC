#include <iostream>
#include "conio.h"
#include "string.h"

using namespace std;

struct DADOS_ALUNO{
	int CodAluno;
	char Nome[100];
	int Turma;
	struct DADOS_ALUNO *ptrLinkProx; 
	struct DADOS_ALUNO *ptrLinkAnt; 
}; 

DADOS_ALUNO* CriarLista(){ 
	DADOS_ALUNO *ptrCab; 
	ptrCab = new DADOS_ALUNO; 
	ptrCab->ptrLinkProx = NULL; 
	ptrCab->ptrLinkAnt = NULL; 
	return ptrCab; 
} 

bool VerificarListaVazia(DADOS_ALUNO *ptrCab){ 
	if(ptrCab->ptrLinkProx == NULL) 
		return true; 
	else 
		return false; 
} 

bool Inserir(DADOS_ALUNO *ptrCab, int PosInserir, int CodAluno, char Nome[], int Turma){ 
	DADOS_ALUNO *ptrNovo; 
	DADOS_ALUNO *ptrAux; 
	DADOS_ALUNO *ptrAnterior; 
	int Pos; 
	//Cria o novo nó 
	ptrNovo = new DADOS_ALUNO; 
	if (ptrNovo == NULL){ 
		cout << "Memória insulficiente!"; 
		return false; 
	} 
	ptrNovo->CodAluno = CodAluno; 
	strcpy(ptrNovo->Nome, Nome); 
	ptrNovo->Turma = Turma; 
	ptrNovo->ptrLinkProx = NULL; 
	ptrNovo->ptrLinkAnt = NULL; 
	// Se a lista estiver vazia, insere no início da lista 
	if( VerificarListaVazia(ptrCab) ){ 
		// Liga o primeiro nó ao nó cabeça 
		ptrCab->ptrLinkProx = ptrNovo; 
		ptrNovo->ptrLinkAnt = ptrCab; 
		return true; 
	} 
	// Se não foi informada a posição, então insere no fim da lista 
	if (PosInserir == 0){ 
		// Localiza o último nó 
		ptrAux = ptrCab->ptrLinkProx; 
		while(ptrAux->ptrLinkProx != NULL) 
			ptrAux = ptrAux->ptrLinkProx; 
		ptrAux->ptrLinkProx = ptrNovo; 
		ptrNovo->ptrLinkAnt = ptrAux; 
		return true; 
	} 
	// Insere na posição informada 
	ptrAux = ptrCab; 
	ptrAnterior = ptrCab; 
	Pos = 0; 
	// Localiza a posição a ser inserida 
	while((Pos < PosInserir) && (ptrAux != NULL)){ 
		ptrAnterior = ptrAux; 
		ptrAux = ptrAux->ptrLinkProx; 
		Pos++; 
	} 
	if(ptrAux == NULL){ 
		cout << "Posição não encontrada!"; 
		return false; 
	} 
	ptrNovo->ptrLinkProx = ptrAux; 
	ptrNovo->ptrLinkAnt = ptrAnterior; 
	ptrAnterior->ptrLinkProx = ptrNovo; 
	ptrAux->ptrLinkAnt = ptrNovo; 
	return true; 
} 

int PosicaoNo(DADOS_ALUNO *ptrCab, int CodAluno){
	DADOS_ALUNO *ptrAux;
	int Posicao;
	// Se a lista estiver vazia
	if( VerificarListaVazia(ptrCab) ){
		cout << "Lista vazia!";
		return false;
	}
	ptrAux = ptrCab;
	Posicao = 0;
	// Localiza o nó
	while(ptrAux != NULL){
		if(ptrAux->CodAluno == CodAluno)
			break;
		Posicao++;
		ptrAux = ptrAux->ptrLinkProx;
	}
	if(ptrAux == NULL){
		cout << "Código do aluno não encontrado!";
		return -1;
	}
	return Posicao;
}

void Exibir(DADOS_ALUNO *ptrCab){ 
	DADOS_ALUNO *ptrAux; 
	int Ind; 
	ptrAux = ptrCab->ptrLinkProx; 
	Ind = 1; 
	while(ptrAux != NULL){ 
		cout << "No: " << Ind << endl; 
		cout << "Codigo do Aluno: " << ptrAux->CodAluno << endl; 
		cout << "Nome: " << ptrAux->Nome << endl; 
		cout << "Turma: " << ptrAux->Turma << endl; 
		cout << endl << endl; 
		Ind++; 
		ptrAux = ptrAux->ptrLinkProx; 
	} 
} 

bool Remover(DADOS_ALUNO *ptrCab, int PosRemover){ 
	DADOS_ALUNO *ptrAux; 
	DADOS_ALUNO *ptrAnterior; 
	DADOS_ALUNO *ptrProximo; 
	int Pos; 
	// Se a lista estiver vazia 
	if( VerificarListaVazia(ptrCab) ){ 
		cout << "Lista vazia!"; 
		return false; 
	} 
	if(PosRemover < 1){ 
		cout << "Código do aluno não encontrado!"; 
		return false; 
	} 
	ptrAux = ptrCab; 
	ptrAnterior = ptrCab; 
	Pos = 0; 
	// Localiza a posição a ser inserida 
	while((Pos < PosRemover) && (ptrAux != NULL)){ 
		ptrAnterior = ptrAux; 
		ptrAux = ptrAux->ptrLinkProx; 
		Pos++; 
	} 
	if(ptrAux == NULL){ 
		cout << "Código do aluno não encontrado!"; 
		return false; 
	} 
	else 
	{ 
		ptrProximo = ptrAux->ptrLinkProx; 
	} 
	ptrAnterior->ptrLinkProx = ptrProximo; 
	if(ptrProximo != NULL) 
		ptrProximo->ptrLinkAnt = ptrAnterior; 
	delete ptrAux; 
} 

int main(int argc, char** argv){
	DADOS_ALUNO *ptrCabeca; 
	// Cria a lista 
	ptrCabeca = CriarLista();
	cout<<"Inserindo 2 nos..."<<endl;
	Inserir(ptrCabeca,1, 10, "Jose", 250);
	Inserir(ptrCabeca,2, 20, "Maria", 250);
	//cout<<"Tamanho: "<<ObterTamanho(ptrCabeca)<<endl;
 	cout<<"Exibindo a lista..."<<endl;
	Exibir(ptrCabeca);
	cout<<"Deletando o No de cod 10..."<<endl;
	Remover(ptrCabeca,1);
	cout<<"Exibindo a lista..."<<endl;
	Exibir(ptrCabeca);
	cout<<"Deletando o No de Cod 20..."<<endl;
	Remover(ptrCabeca,2);
	cout<<"Exibindo a lista..."<<endl;
    	return 0;
}
