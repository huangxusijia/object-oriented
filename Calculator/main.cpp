#include<iostream>
#include"Scan.h"
#include"Print.h"
#include"calculation.h"
using namespace std;

int main() {
	string input;
	cin>>input;//����������ʽ��
	Scan get;
	get.ToStringQueue(input);
	queue<string> g=get.getqueue();
	calculation caget;
	caget.Calculationqueue(input);
	queue<string> f=caget.cagetqueue();
	Print out;
	//out.printqueue(g);
	out.caprintqueue(f);
	return 0;
}
