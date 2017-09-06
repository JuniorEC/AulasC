#include <iostream>
using namespace std;

int vet[10];				//<-- vetor de inteiros como variável global;

void inverte(int vet[10]);	//<-- protótipo da função;


int main(int argc, char** argv) {
	
	for(int i = 0; i<10; i++) {							//<-- Recebe os valores inteiros.
		
		if(i==0) {
			cout<<"digite o primeiro numero: "<<endl;	
			cin>>vet[i];
		}
		
		else {
			cout<<"digite o proximo numero: "<<endl;	
			cin>>vet[i];
		}
		
	}
	
	cout<<"Seu vetor inicial eh: "<<endl;
	
	for(int j = 0; j < 10 ; j++) {
		cout<< vet[j] <<" " ;
	}
	
	inverte(vet);										//<-- Chamada da função para inverter vetor
	
	cout<<"Seu vetor final eh: "<<endl;
	
	for(int j = 0; j < 10 ; j++) {
		cout<< vet[j] <<" " ;
	}
	
	
	return 0;
}

void inverte(int vet[]) {
	int j;
	for(int i = 0; i <= 4; i++) {
		j = vet[9-i];
		vet[9-i] = vet[i];
		vet[i] = j;
	}
}
