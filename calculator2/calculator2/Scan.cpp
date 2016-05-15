#include "Scan.h"
#include<string>
#include<queue>
#include<iostream>
using namespace std;

queue<string> Scan::inputqueue(string input)
{
	queue<string> inputqueue;//存放队列
	int i;
	int sum = 0; //用于判断位数，保证不超过十位数
	string symbol = ""; //存放符号
	string num =  "";
	bool flag=true; //用于辅助判断数字的存放
	for (i = 0;i < input.size();i++)
	{
		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')')//如果是符号位，直接入队
		{
              inputqueue.push(symbol = input[i]);
		      symbol.clear();
		}         
		else if (input[i] >= '0' && input[i] <= '9'  || input[i] == '.')//如果是数字
			{
				sum++;//判断位数
				num = num+input[i];
				if (sum > 10)//位数超过10直接报错
				{
					cout << "输入数字过大请重新输入" << endl;
					flag = false;
					break;
				}
                 if (i == input.size() - 1)//数字在最后一位,直接入队
					inputqueue.push(num);
                 if (input[i+1] == '+' || input[i+1] == '-' || input[i+1] == '*' || input[i+1] == '/' || input[i + 1] == '(' || input[i + 1] == ')')//数字下一位是符号，入队
				{
					inputqueue.push(num);
					num.clear();
					sum = 0;
				}
			}
			else
				flag = false;
	}
	if (!flag)//执行空队列
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
