#include <iostream>
#include <Math.h>
using namespace std;

struct ponto {											//<- Cria a Struct ponto com 2 valores.
	float x;
	float y;
};

														// Protótipos.

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
	pto_libera(q);										//<- a função "liberar" serve para limpar o espaço de memória usada,
	pto_libera(p);										//   caso contrário, continuará ocupando após o término da execução.
	return 0;

}

ponto *pto_cria (float x, float y) {					//<- Método para criação de um ponteiro do tipo ponto e retorna o endereço do ponteiro. 
	ponto *p = new ponto;
	
	if (p == NULL) {									//<- Verificação do espaço de memório.
	cout<<"Memória insuficiente!\n"<<endl;
	exit(1);											//<- Serve para sair do programa.
	}
	
	p->x = x;											// O simbolo (->) é a forma de acesso ao Struct quando o objeto é um ponteiro, ao invés de p.x ou p.y.
	p->y = y;
	return p;
}

void pto_libera (ponto *p) {							//<- Método serve para eliminar o espaco ocupado pelo ponteiro.
	delete p;
}

void pto_acessa (ponto *p, float *x, float *y) {		//<- Método acessa os valores dos endereços de x e y.
	*x = p->x;
	*y = p->y;
}

void pto_atribui (ponto *p, float x, float y) {			//<- Método mudaria os valores das coordenadas, passando dessa vez como parâmetro os novos pontos.
	p->x = x;
	p->y = y;
}

float pto_distancia (ponto *p1, ponto *p2) {			//<- Método calcula a distância utilizando os conteudos dos ponteiros.
	float dx = p2->x - p1->x;
	float dy = p2->y - p1->y;
	
	return sqrt(dx*dx + dy*dy);							//<- sqrt é a função para calcular raiz quadrada.
}

