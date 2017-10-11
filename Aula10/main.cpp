#include <iostream>
#include "conio.h"
#include "string.h"

using namespace std;

struct DADOS_ALUNO{
	int CodAluno;
	char Nome[100];
	int Turma;
	struct DADOS_ALUNO * ptrLink;
};

DADOS_ALUNO* CriarLista(){
	DADOS_ALUNO *ptrCab;
	ptrCab = new DADOS_ALUNO;
	ptrCab->ptrLink = NULL;
	return ptrCab;
}

bool VerificarListaVazia(DADOS_ALUNO *ptrCab){ 
	if(ptrCab->ptrLink == NULL) 
		return true; 
	else 
		return false; 
} 

bool Inserir(DADOS_ALUNO *ptrCab, int PosInserir, int CodAluno, char Nome[], int Turma){ 
	DADOS_ALUNO *ptrNovo; 
	DADOS_ALUNO *ptrAux; 
	int Pos; 
	// Cria o novo nó e atribui os dados às variáveis membros 
	ptrNovo = new DADOS_ALUNO; 
	if (ptrNovo == NULL){ 
	cout << "Memoria insuficiente!"; 
	return false; 
	} 
	ptrNovo->CodAluno = CodAluno; 
	strcpy(ptrNovo->Nome, Nome); 
	ptrNovo->Turma = Turma; 
	ptrNovo->ptrLink = NULL; 
	// Se a lista estiver vazia, insere no início da lista 
	if( VerificarListaVazia(ptrCab) ){ 
		// Liga o primeiro nó ao nó cabeça 
		ptrCab->ptrLink = ptrNovo; 
		return true; 
	} 
	// Se não foi informada a posição, então insere no fim da lista 
	if (PosInserir == 0){ 
	// Localiza o último nó 
	ptrAux = ptrCab->ptrLink; 
	while(ptrAux->ptrLink != NULL) 
	ptrAux = ptrAux->ptrLink; 
	ptrAux->ptrLink = ptrNovo; 
	return true; 
	} 
	// Insere na posição informada 
	ptrAux = ptrCab; 
	Pos = 1; 
	// Localiza a posição a ser inserida 
	while((Pos < PosInserir) && (ptrAux != NULL)){ 
	ptrAux = ptrAux->ptrLink; 
	Pos++; 
	} 
	if(ptrAux == NULL){ 
	cout << "Posicao nao encontrada!"; 
	return false; 
	} 
	ptrNovo->ptrLink = ptrAux->ptrLink; 
	ptrAux->ptrLink = ptrNovo; 
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
		ptrAux = ptrAux->ptrLink; 
	} 
	if(ptrAux == NULL){ 
		cout << "Codigo do aluno não encontrado!"; 
		return -1; 
	} 
	return Posicao; 
} 

int ObterTamanho(DADOS_ALUNO *ptrCab){ 
	DADOS_ALUNO *ptrAux; 
	int Pos; 
	// Se a lista estiver vazia 
	if( VerificarListaVazia(ptrCab) ){ 
		cout << "Lista vazia!"; 
		return false; 
	} 
	Pos = 0; 
	ptrAux = ptrCab->ptrLink; 
	// Conta os nós 
	while(ptrAux != NULL){ 
		Pos++; 
		ptrAux = ptrAux->ptrLink; 
	} 
	return Pos; 
} 

void Exibir(DADOS_ALUNO *ptrCab){ 
	DADOS_ALUNO *ptrAux; 
	int Ind; 
	ptrAux = ptrCab->ptrLink; 
	Ind = 1; 
	while(ptrAux != NULL){ 
		cout << "No: " << Ind << endl; 
		cout << "Codigo do Aluno: " << ptrAux->CodAluno << endl; 
		cout << "Nome: " << ptrAux->Nome << endl; 
		cout << "Turma: " << ptrAux->Turma << endl; 
		cout << endl << endl; 
		Ind++; 
		ptrAux = ptrAux->ptrLink; 
	} 
} 

bool Remover(DADOS_ALUNO *ptrCab, int PosRemover){ 
	DADOS_ALUNO *ptrAux; 
	DADOS_ALUNO *ptrAnterior; 
	int Pos; 
	// Se a lista estiver vazia 
	if( VerificarListaVazia(ptrCab) ){ 
		cout << "Lista vazia!"; 
		return false; 
	} 
	if(PosRemover < 1){ 
		cout << "Codigo do aluno nao encontrado!"; 
		return false; 
	} 
	ptrAux = ptrCab; 
	ptrAnterior = ptrCab; 
	Pos = 0; 
	// Localiza a posição a ser removida 
	while((Pos < PosRemover) && (ptrAux != NULL)){ 
		ptrAnterior = ptrAux; 
		ptrAux = ptrAux->ptrLink; 
		Pos++; 
	} 
	if(ptrAux == NULL){ 
		cout << "Posicao invalida!"; 
		return false; 
	} 
	ptrAnterior->ptrLink = ptrAux->ptrLink; 
	delete ptrAux; 
} 

int main(int argc, char** argv){
	DADOS_ALUNO *ptrCabeca; 
	// Cria a lista 
	ptrCabeca = CriarLista();
	cout<<"Tamanho: "<<ObterTamanho(ptrCabeca)<<endl;
	cout<<"Inserindo 2 nos..."<<endl;
	Inserir(ptrCabeca, 1, 10, "Jose", 250);
	Inserir(ptrCabeca, 2, 20, "Maria", 250);
	cout<<"Tamanho: "<<ObterTamanho(ptrCabeca)<<endl;
 	cout<<"Exibindo a lista..."<<endl;
	Exibir(ptrCabeca);
	cout<<"Deletando o No 1..."<<endl;
	Remover(ptrCabeca,1);
	cout<<"Tamanho: "<<ObterTamanho(ptrCabeca)<<endl;
	cout<<"Exibindo a lista..."<<endl;
	Exibir(ptrCabeca);
	cout<<"Deletando o novo No 1..."<<endl;
	Remover(ptrCabeca,1);
	cout<<"Tamanho: "<<ObterTamanho(ptrCabeca)<<endl;
	cout<<"Exibindo a lista..."<<endl;
    	return 0;
}
