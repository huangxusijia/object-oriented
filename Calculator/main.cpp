#include<iostream>
#include<string>
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
	Print out;
	calculation cal;
	int l=cal.Calculationqueue(g); 
	cout << l;
	return 0;
}
