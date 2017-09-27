#include <iostream>
#include <math.h>
using namespace std;

struct Ponto {
	float x;
	float y;
};

struct Circulo {
	float x;
	float y;
	float r;
};

Ponto *pto_cria (float x, float y) {
	Ponto *p = new Ponto;
	if (p == NULL) {
		cout<<"Memória insuficiente!\n";
		exit(1);
	   }
	p->x = x;
	p->y = y;
	return p;
}

Circulo *circ_cria (float x, float y, float r) {
	Circulo *c = new Circulo;
	if (c == NULL) {
		cout<<"Memória insuficiente!\n";
		exit(1);
	   }
	c->x = x;
	c->y = y;
	c->r = r;
	return c;
}

void pto_libera (Ponto *p)
{
	delete p;
}

void circ_libera (Circulo *c)
{
	delete c;
}

void pto_acessa (Ponto *p, float *x, float *y)
{
	*x = p->x;
	*y = p->y;
}

void pto_atribui (Ponto *p, float x, float y)
{
	p->x = x;
	p->y = y;
}

float pto_distancia (Ponto *p1, Ponto *p2)
{
	float dx = p2->x - p1->x;
	float dy = p2->y - p1->y;
	return sqrt(dx*dx + dy*dy);
}

void verifica_pto_circ (Ponto *p, Circulo *c) {
	
	float dx = p->x - c->x;
	float dy = p->y - c->y;
	float d = sqrt(dx*dx + dy*dy);
	if (d > c->r) {
		cout<<"Circulo externo" <<endl;
	} else {
		cout<<"Circulo interno" <<endl;
	}
	
}

int main(int argc, char** argv) {
	//float x, y;
	Ponto *p = pto_cria(2.0,1.0);
	Circulo *q = circ_cria(4,2,3);
	verifica_pto_circ(p,q);
	
	//cout<<"Distancia entre pontos: "<<d<<endl;
	circ_libera(q);
	pto_libera(p);
	
	return 0;
}
