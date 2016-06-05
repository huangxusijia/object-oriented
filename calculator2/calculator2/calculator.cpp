#include<iostream>
#include<stdlib.h>
#include<string>
#include"Scan.h"
#include"Print.h"
#include"cal.h"
using namespace std;

int main(int argc, char* argv[])
{
	string input,input1;
	cin >> input;
	Scan get;
	cal calc;
	if (input == "-a")
	{
		cin >> input1;
		cout << input1 << "= ";
		queue<string> f = get.inputqueue(input1);
		cout << calc.caluat(f) << endl;
	}
	else
	{
    queue<string> f = get.inputqueue(input);
	cout << calc.caluat(f) << endl;
	}
	//Print out;
	//out.printqueue(f);
	system("pause");
	return 0;
}