#include <iostream>
#include <Math.h>
using namespace std;

struct ponto {											//<- Cria a Struct ponto com 2 valores.
	float x;
	float y;
};

														// Prot�tipos.

ponto *pto_cria(float x, float y);
void pto_libera(ponto *p);
void pto_acessa(ponto *p, float *x, float *y);
void pto_atribui(ponto *p, float x, float y);
float pto_distancia(ponto *p1, ponto *p2);


int main(int argc, char** argv) {
	float x, y;
	cout<<"Entre com as coordenadas do primeiro ponto (x,y)"<<endl;
	cin>>x>>y;
	ponto *p = pto_cria(x,y);
	cout<<"Entre com as coordenadas do primeiro ponto (x,y)"<<endl;
	cin>>x>>y;
	ponto *q = pto_cria(x,y);
	float d = pto_distancia(p,q);
	pto_acessa(p, &x, &y);
	cout<<"Coordenadas (x,y) = ("<<x<<","<<y<<")"<<endl;
	cout<<"Distancia entre pontos: "<<d<<endl;
	pto_libera(q);										//<- a fun��o "liberar" serve para limpar o espa�o de mem�ria usada,
	pto_libera(p);										//   caso contr�rio, continuar� ocupando ap�s o t�rmino da execu��o.
	return 0;

}

ponto *pto_cria (float x, float y) {					//<- M�todo para cria��o de um ponteiro do tipo ponto e retorna o endere�o do ponteiro. 
	ponto *p = new ponto;
	
	if (p == NULL) {									//<- Verifica��o do espa�o de mem�rio.
	cout<<"Mem�ria insuficiente!\n"<<endl;
	exit(1);											//<- Serve para sair do programa.
	}
	
	p->x = x;											// O simbolo (->) � a forma de acesso ao Struct quando o objeto � um ponteiro, ao inv�s de p.x ou p.y.
	p->y = y;
	return p;
}

void pto_libera (ponto *p) {							//<- M�todo serve para eliminar o espaco ocupado pelo ponteiro.
	delete p;
}

void pto_acessa (ponto *p, float *x, float *y) {		//<- M�todo 
	*x = p->x;
	*y = p->y;
}

void pto_atribui (ponto *p, float x, float y) {			//<- M�todo 
	p->x = x;
	p->y = y;
}

float pto_distancia (ponto *p1, ponto *p2) {			//<- M�todo calcula a dist�ncia utilizando os conteudos dos ponteiros.
	float dx = p2->x - p1->x;
	float dy = p2->y - p1->y;
	
	return sqrt(dx*dx + dy*dy);							//<- sqrt � a fun��o para calcular raiz quadrada.
}

