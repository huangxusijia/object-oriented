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
			
			else if (input[i] >= 48 && input[i] <= 57 || input[i] == '.')//(������48��57�ֱ��Ӧ0-9,string��Ҫ�õ����ж�)
			{
				count++;//�ж�λ�� 
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
		 		cout<<"Error"<<endl; //ִ�пն��� 
			}
		} 
    }

	queue<string> Scan::getqueue()
	{
		return inputqueue;
	}
