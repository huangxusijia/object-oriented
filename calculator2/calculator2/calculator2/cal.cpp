#include "cal.h"
#include<iostream>
#include<stack>
#include<sstream>


double  cal::caluat(queue<string> inputqueue)
{
	stack<string>operat;                                             //������������� 
	stack<string>number;                                             //���������ֵ� 
	stack<double>num;                                                //����������� 
	double i, j, k;                                                   //�����ڼ���ʱ��ȡstack�ڵ����֣����ڼ��� 
	string temp = "", material = "";                                     //���������������������
	while (!inputqueue.empty())                                             //�ȰѴ���Ķ��д���׺�ĳɺ�׺ 
	{
		temp = inputqueue.front();
		if (temp == "(")
		{
			operat.push(temp);
			inputqueue.pop();
			if (inputqueue.front() == "-")                                   //�����ж��Ƿ��Ǹ����ĸ��ţ������Ǽ��� ,��Ϊ����������ź��и��ž�һ���Ǹ����ĸ��� 
			{
				number.push("0");                                   /* ����Ǹ��ŵĸ����Ļ��Ϳ���������֮ǰ����һ��0��
																	�����ѷ��ŵ������ţ�0��ȥһ�������൱�����෴ֵ */
				temp = inputqueue.front();                                   //����Ѹ��ŵ������� 
				operat.push(temp);
				inputqueue.pop();                                         //ȥ����������� 
			}
		}
		else if (temp == ")")                                         /*����������Ҫȥ����stack��ȥ�Ӻ���ǰ�ң�ֱ���ҵ������ţ�
																	  ����֮��ķ��ž�push������stack�� */
		{
			for (;;)
			{
				if (operat.top() == "(")
				{
					operat.pop();                                  //��ȻҪ�ǵð�������ȥ�� 
					inputqueue.pop();
					break;
				}
				else
				{
					material = operat.top();                        //����������֮���������洢��numberstack�� 
					number.push(material);
					operat.pop();
				}
			}
		}
		else if (temp == "+" || temp == "-")
		{
			for (;;)
			{
				if (operat.empty() || operat.top() == "(")           //�Ӻźͼ���ֻ���������stackΪ��ʱ������ջ��Ϊ������ʱ������� 
				{
					operat.push(temp);
					inputqueue.pop();
					break;
				}
				else
				{
					material = operat.top();
					number.push(material);
					operat.pop();
				}
			}
		}
		else if (temp == "*" || temp == "/")
		{
			for (;;)
			{
				if (operat.empty() || operat.top() == "(" || operat.top() == "-" || operat.top() == "+")

					/*ֻ�е��Ѷ��ǳ��Ż��߳˺ŵ�ʱ�����Ҫ�������stack��ջ
					��ת��numberstack�У�ֱ�������Ѷ����ǳ˺Ż��߳��� */

				{
					operat.push(temp);
					inputqueue.pop();
					break;
				}
				else
				{
					material = operat.top();
					number.push(material);
					operat.pop();
				}
			}
		}
		else                                                                   //������Ƿ��������������ˣ���ʱ��Ҫ��mark��ӣ���Ϊ�п����Ǹ��� 
		{
			number.push(temp);
			inputqueue.pop();
		}
	}


	while (!operat.empty())                                                    //������һЩ�����������number�� 
	{
		temp = operat.top();
		number.push(temp);
		operat.pop();
	}



	while (!number.empty())                                                    //��number���еĶ����������浽operat�У����ڼ��� 
	{
		operat.push(number.top());
		number.pop();
	}

	double d = 0;                                                                /*�������-(100+9)��������ĳ��� �������Ҫ��
																				 �����һ������-���������͵Ļ���Ҳ��Ӱ�� */
	num.push(d);

	while (!operat.empty())                                                     //���м��� 
	{
		temp = operat.top();
		if (temp == "-")
		{
			j = num.top();
			num.pop();
			k = num.top();
			num.pop();
			i = k - j;
			num.push(i);
			operat.pop();
		}
		else if (temp == "+")
		{
			j = num.top();
			num.pop();
			k = num.top();
			num.pop();
			i = j + k;
			num.push(i);
			operat.pop();
		}
		else if (temp == "*")
		{
			j = num.top();
			num.pop();
			k = num.top();
			num.pop();
			i = j*k;
			num.push(i);
			operat.pop();
		}
		else if (temp == "/")
		{
			j = num.top();
			num.pop();
			k = num.top();
			num.pop();
			i = k / j;
			num.push(i);
			operat.pop();
		}
		else
		{
			stringstream stream;
			stream << temp;
			stream >> i;
			num.push(i);
			operat.pop();
		}
	}

	double result = 0;                                                          //ʹresult���ڼ�����Ľ������return��ȥ 
	result = num.top();
	num.pop();
	return result;
}