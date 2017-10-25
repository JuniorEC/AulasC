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

DADOS_ALUNO* CriarFila(){
	DADOS_ALUNO *ptrCab;
	ptrCab = new DADOS_ALUNO;
	ptrCab->ptrLink = NULL;
	return ptrCab;
}

bool VerificarFilaVazia(DADOS_ALUNO *ptrCab){ 
	if(ptrCab->ptrLink == NULL) 
		return true; 
	else 
		return false; 
} 

bool Enfileirar(DADOS_ALUNO *ptrCab, int CodAluno, char Nome[], int Turma){
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
	// Insere no fim da fila 
	ptrAux = ptrCab; 
	while(ptrAux->ptrLink != NULL) 
		ptrAux = ptrAux->ptrLink; 
	ptrAux->ptrLink = ptrNovo; 
	return true; 
} 

void ExibirPrimeiro(DADOS_ALUNO *ptrCab){ 
	DADOS_ALUNO *ptrAux; 
	ptrAux = ptrCab->ptrLink; 
	cout << "Código do Aluno: " << ptrAux->CodAluno << endl; 
	cout << "Nome: " << ptrAux->Nome << endl; 
	cout << "Turma: " << ptrAux->Turma << endl; 
	cout << endl << endl; 
} 

bool Desenfileirar(DADOS_ALUNO *ptrCab){ 
	DADOS_ALUNO *ptrAux; 
	DADOS_ALUNO *ptrAnterior; 
	int Pos; 
	// Se a fila estiver vazia 
	if( VerificarFilaVazia(ptrCab) ){ 
		cout << "Fila vazia!"; 
		return false; 
	} 
	ptrAnterior = ptrCab; 
	ptrAux = ptrCab->ptrLink; 
	ptrAnterior->ptrLink = ptrAux->ptrLink; 
	delete ptrAux; 
} 


int main(int argc, char** argv){
	DADOS_ALUNO *ptrCabeca; 
	// Cria a lista 
	ptrCabeca = CriarFila();
	cout<<"Enfileirando..."<<endl;
	Enfileirar(ptrCabeca, 10, "Jose", 250);
	Enfileirar(ptrCabeca, 20, "Maria", 250);
	//cout<<"Tamanho: "<<ObterTamanho(ptrCabeca)<<endl;
 	cout<<"Exibindo o 1o ..."<<endl;
	ExibirPrimeiro(ptrCabeca);
	cout<<"Desenfileirando..."<<endl;
	Desenfileirar(ptrCabeca);
	cout<<"Exibindo o 1o ..."<<endl;
	ExibirPrimeiro(ptrCabeca);
	Desenfileirar(ptrCabeca);
	return 0;
}
