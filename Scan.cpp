#include "Scan.h"
using namespace std;

	void Scan::ToStringQueue(string input)
	{
		string fuhao;  
		string num="";  
		int count,i;  
		
		for (i=0;i<input.size();i++)
		{ 
			if (input[i] == '-' || input[i] == '(' || input[i] == ')' || input[i] == '+' || input[i] == '*' || input[i] == '/')
			{
				if (num!="") 
				{
					inputqueue.push(num);
				}
				num="";
				count=0;
				inputqueue.push(fuhao=input[i]);
			}
			
			else if (input[i] >= '0' && input[i] <= '9' || input[i] == '.')//(附表中48到57分别对应0-9,string需要用到此判断,可以用'0''9'以免记错ASCII)
			{
				count++;//判断位数 
				if (count>10)
				{
					cout << "Error" << endl;
					Flag = false;
					break; 
				}
				num=num+input[i];
			}
	 	} 
        if(num!="" && Flag)
		{
			inputqueue.push(num);
		}
		if (!Flag)
		{
			int size = inputqueue.size();
		 	for (i=0;i<size;i++)
		 	{
		 		inputqueue.pop();
		 		cout<<"Error"<<endl; //执行空队列 
			}
		} 
    }

	queue<string> Scan::getqueue()
	{
		return inputqueue;
	}
