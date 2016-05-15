#include<iostream>
#include<stdlib.h>
#include<string>
#include"Scan.h"
#include"Print.h"
using namespace std;

int main()
{
	string input;
	cin >> input;
	Scan get;
	queue<string> f = get.inputqueue(input);
	Print out;
	out.printqueue(f);
	system("pause");
	return 0;
}