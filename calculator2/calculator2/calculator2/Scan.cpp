#include "Scan.h"
#include<string>
#include<queue>
#include<iostream>
using namespace std;

queue<string> Scan::inputqueue(string input)
{
	queue<string> inputqueue;//��Ŷ���
	int i;
	int sum = 0; //�����ж�λ������֤������ʮλ��
	string symbol = ""; //��ŷ���
	string num =  "";
	bool flag=true; //���ڸ����ж����ֵĴ��
	for (i = 0;i < input.size();i++)
	{
		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')')//����Ƿ���λ��ֱ�����
		{
              inputqueue.push(symbol = input[i]);
		      symbol.clear();
		}         
		else if (input[i] >= '0' && input[i] <= '9'  || input[i] == '.')//���������
			{
				sum++;//�ж�λ��
				num = num+input[i];
				if (sum > 10)//λ������10ֱ�ӱ���
				{
					cout << "�������ֹ�������������" << endl;
					flag = false;
					break;
				}
                 if (i == input.size() - 1)//���������һλ,ֱ�����
					inputqueue.push(num);
                 if (input[i+1] == '+' || input[i+1] == '-' || input[i+1] == '*' || input[i+1] == '/' || input[i + 1] == '(' || input[i + 1] == ')')//������һλ�Ƿ��ţ����
				{
					inputqueue.push(num);
					num.clear();
					sum = 0;
				}
			}
			else
				flag = false;
	}
	if (!flag)//ִ�пն���
	{
		int size = inputqueue.size();
		for (i = 0;i < size;i++)
		{
			inputqueue.pop();
		}
		return inputqueue;
	}
	else
		return inputqueue;
}
