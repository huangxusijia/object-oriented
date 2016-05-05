#include<iostream>
#include<stdlib.h>
#include"area.h"
using namespace std;

int main()
{
	double sem;
	while(cin >> sem)
	{
        area get;
	    get.calculator(sem);
	    double result = get.calculator(sem);
	    cout << result << endl;
	}
	system("pause");
	return 0;
}