#include"Print.h"
using namespace std;

void Print::printqueue(queue<string> que)
{
	int size = que.size(),i;   
	if (!que.empty())
	{
		for (i=0;i<size;i++)
		{
			cout << que.front() << endl;
			que.pop();
		}
	}
}
