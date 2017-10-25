#include <iostream>
#include "conio.h"
#include "string.h"

using namespace std;

struct DADOS_ALUNO{
	int CodAluno;
	char Nome[100];
	int Turma;
	bool NoCabeca;
	struct DADOS_ALUNO *ptrLink;
};

DADOS_ALUNO* CriarLista(){ 
	DADOS_ALUNO *ptrCab; 
	ptrCab = new DADOS_ALUNO; 
	ptrCab->NoCabeca = true; 
	ptrCab->ptrLink = ptrCab; 
	return ptrCab; 
} 

bool VerificarListaVazia(DADOS_ALUNO *ptrCab){ 
	if(ptrCab->ptrLink == ptrCab) 
		return true; 
	else 
		return false; 
} 

bool Inserir(DADOS_ALUNO *ptrCab, int CodAluno, char Nome[], int Turma){ 
	DADOS_ALUNO *ptrNovo; 
	DADOS_ALUNO *ptrAux; 
	DADOS_ALUNO *ptrAnterior; 
	int Pos; 
	// Cria o novo nó 
	ptrNovo = new DADOS_ALUNO; 
	if (ptrNovo == NULL){ 
		cout << "Memoria insuficiente!"; 
		return false; 
	} 
	ptrNovo->CodAluno = CodAluno; 
	strcpy(ptrNovo->Nome, Nome); 
	ptrNovo->Turma = Turma; 
	ptrNovo->NoCabeca = false; 
	// Insere no fim da lista 
	ptrAnterior = ptrCab; 
	ptrAux = ptrCab->ptrLink; 
	while(ptrAux->NoCabeca != true){ 
		ptrAnterior = ptrAux; 
		ptrAux = ptrAux->ptrLink; 
	} 
	ptrAnterior->ptrLink = ptrNovo; 
	ptrNovo->ptrLink = ptrAux; 
	return true; 
}

void Exibir(DADOS_ALUNO *ptrCab){ 
	DADOS_ALUNO *ptrAux; 
	ptrAux = ptrCab->ptrLink; 
	// Conta os nós 
	while(ptrAux->NoCabeca != true){ 
		cout << "Codigo do Aluno: " << ptrAux->CodAluno << endl; 
		cout << "Nome: " << ptrAux->Nome << endl; 
		cout << "Turma: " << ptrAux->Turma << endl; 
		cout << endl << endl; 
		ptrAux = ptrAux->ptrLink; 
	} 
} 

bool Remover(DADOS_ALUNO *ptrCab, int CodAluno){ 
	DADOS_ALUNO *ptrAux; 
	DADOS_ALUNO *ptrAnterior; 
	bool Encontrado; 
	// Se a lista estiver vazia 
	if( VerificarListaVazia(ptrCab) ){ 
		cout << "Lista vazia!"; 
		return false; 
	} 
	ptrAnterior = ptrCab; 
	ptrAux = ptrCab->ptrLink; 
	Encontrado = false; 
	// Percorre a lista 
	while(ptrAux->NoCabeca != true){ 
		// Se encontrou o código do aluno 
		if(ptrAux->CodAluno == CodAluno){ 
			Encontrado = true; 
			break; 
		}	 
		ptrAnterior = ptrAux; 
		ptrAux = ptrAux->ptrLink; 
	} 
	if(Encontrado == false){ 
		cout << "Código do aluno não encontrado!"; 
		return false; 
	} 
	ptrAnterior->ptrLink = ptrAux->ptrLink; 
	delete ptrAux; 
}


int main(int argc, char** argv){
	DADOS_ALUNO *ptrCabeca; 
	// Cria a lista 
	ptrCabeca = CriarLista();
	cout<<"Inserindo 2 nos..."<<endl;
	Inserir(ptrCabeca, 10, "Jose", 250);
	Inserir(ptrCabeca, 20, "Maria", 250);
	//cout<<"Tamanho: "<<ObterTamanho(ptrCabeca)<<endl;
 	cout<<"Exibindo a lista..."<<endl;
	Exibir(ptrCabeca);
	cout<<"Deletando o No de cod 10..."<<endl;
	Remover(ptrCabeca,10);
	cout<<"Exibindo a lista..."<<endl;
	Exibir(ptrCabeca);
	cout<<"Deletando o No de Cod 20..."<<endl;
	Remover(ptrCabeca,20);
	cout<<"Exibindo a lista..."<<endl;
    	return 0;
}
