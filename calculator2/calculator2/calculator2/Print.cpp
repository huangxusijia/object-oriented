#include "Print.h"
#include<iostream>
#include<string>
#include<queue>
using namespace std;

void Print::printqueue(queue<string> que)
{
	int i;
	if (!que.empty())
	{
		while (!que.empty())
		{ 
		    cout << que.front() << endl;
		    que.pop();
		}
	}
	else
		cout << "������������������" << endl;
}