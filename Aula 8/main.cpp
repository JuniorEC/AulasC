#include <iostream>
using namespace std;



int main(int argc, char** argv) {
	int A = 2, B = 3, *ptrA, *ptrB;
	
	ptrA = &A;
	
	ptrB = &B;
	
	cout<<A<<" "<<&A<<" "<<ptrA<<" "<< *ptrA<<" "<<&ptrA<<endl;
	
	*ptrA = *ptrA + *ptrB;
	
	cout<<endl;
	cout<<A<<" "<<&A<<" "<<ptrA<<" "<< *ptrA<<" "<<&ptrA<<endl;
	
	ptrA = ptrA+1;
	
	cout<<endl;
	cout<<A<<" "<<&A<<" "<<ptrA<<" "<< *ptrA<<" "<<&ptrA<<endl;
	
	return 0;
}
