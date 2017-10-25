#include <iostream>
#include "conio.h"
#include "string.h"

using namespace std;

struct DADOS_ALUNO{
	int CodAluno;
	char Nome[100];
	int Turma;
	struct DADOS_ALUNO *ptrLink; 
}; 

DADOS_ALUNO *CriarPilha(){
	DADOS_ALUNO *ptrCab;
	ptrCab = new DADOS_ALUNO;
	ptrCab->ptrLink = NULL;
	return ptrCab;
}

bool VerificarPilhaVazia(DADOS_ALUNO *ptrCab){ 
	if(ptrCab->ptrLink == NULL) 
		return true; 
	else 
		return false; 
} 

bool Empilhar(DADOS_ALUNO *ptrCab, int CodAluno, char Nome[], int Turma){ 
	DADOS_ALUNO *ptrNovo; 
	DADOS_ALUNO *ptrAux; 
	int Pos; 
	// Cria o novo nó 
	ptrNovo = new DADOS_ALUNO; 
	if (ptrNovo == NULL){ 
		cout << "Memória insuficiente!"; 
		return false; 
	} 
	ptrNovo->CodAluno = CodAluno; 
	strcpy(ptrNovo->Nome, Nome); 
	ptrNovo->Turma = Turma; 
	ptrNovo->ptrLink = NULL; 
	// Insere no topo da pilha 
	ptrAux = ptrCab; 
	while(ptrAux->ptrLink != NULL) 
		ptrAux = ptrAux->ptrLink; 
	ptrAux->ptrLink = ptrNovo; 
	return true; 
} 

void ExibirTopo(DADOS_ALUNO *ptrCab){ 
	DADOS_ALUNO *ptrAux; 
	ptrAux = ptrCab->ptrLink; 
	// Localiza a posição do topo 
	while(ptrAux->ptrLink != NULL){ 
		ptrAux = ptrAux->ptrLink; 
	} 
	cout << "Codigo do Aluno: " << ptrAux->CodAluno << endl; 
	cout << "Nome: " << ptrAux->Nome << endl; 
	cout << "Turma: " << ptrAux->Turma << endl; 
	cout << endl << endl; 
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
		ptrAux = ptrAux->ptrLink; 
		Ind++; 
	} 
} 

bool Desempilhar(DADOS_ALUNO *ptrCab){ 
	DADOS_ALUNO *ptrAux; 
	DADOS_ALUNO *ptrAnterior; 
	int Pos; 
	// Se a pilha estiver vazia 
	if( VerificarPilhaVazia(ptrCab) ){ 
		cout << "Pilha vazia!"; 
		return false; 
	} 
	ptrAux = ptrCab; 
	ptrAnterior = ptrCab; 
	// Localiza a posição do topo 
	while(ptrAux->ptrLink != NULL){ 
		ptrAnterior = ptrAux; 
		ptrAux = ptrAux->ptrLink; 
	} 
	ptrAnterior->ptrLink = NULL; 
	delete ptrAux;
} 

int main(int argc, char** argv){
	DADOS_ALUNO *ptrCabeca; 
	// Cria a lista 
	ptrCabeca = CriarPilha();
	cout<<"Empilhando..."<<endl;
	Empilhar(ptrCabeca, 10, "Jose", 250);
	Empilhar(ptrCabeca, 20, "Maria", 250);
	//cout<<"Tamanho: "<<ObterTamanho(ptrCabeca)<<endl;
 	cout<<"Exibindo a pilha..."<<endl;
	Exibir(ptrCabeca);
	cout<<"Desempilhando..."<<endl;
	Desempilhar(ptrCabeca);
	cout<<"Exibindo a pilha..."<<endl;
	Exibir(ptrCabeca);
	Desempilhar(ptrCabeca);
	cout<<"Exibindo a pilha..."<<endl;
	Exibir(ptrCabeca);
	return 0;
}
