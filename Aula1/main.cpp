#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Dados_Aluno{
	
	int matricula;
	char nome[100];
	int turma;
	float media;
	
};

void MostraDados(struct Dados_Aluno aluno) {
			
	cout<<"Matricula:"<<aluno.matricula<<endl;
	cout<<"Aluno:"<<aluno.nome<<endl;
	cout<<"Turma:"<<aluno.turma<<endl;
	cout<<"Media:"<<aluno.media<<endl;
}

int main(int argc, char** argv) {
	
	struct Dados_Aluno aluno[100];
	int i,n;
	cout<<"Numero de cadastros"<<endl;
	cin>>n;
	for(i=0; i<=n-1;i++) {
	
		cout<<"Qual o codigo do aluno?"<<endl;
		cin>>aluno[i].matricula;
		
		cout<<"Qual o nome do aluno?"<<endl;
		cin>>aluno[i].nome;
		
		cout<<"Qual a turma do aluno?"<<endl;
		cin>>aluno[i].turma;
		
		cout<<"Qual a media do aluno?"<<endl;
		cin>>aluno[i].media;
		
	}
	
	for(i=0; i<=n-1;i++) {
		
		MostraDados(aluno[i]);
		
	}
	
	return 0;
}
