#include "cal.h"
#include<iostream>
#include<stack>
#include<sstream>


double  cal::caluat(queue<string> inputqueue)
{
	stack<string>operat;                                             //用来存运算符的 
	stack<string>number;                                             //用来存数字的 
	stack<double>num;                                                //用来最后计算的 
	double i, j, k;                                                   //用来在计算时提取stack内的数字，用于计算 
	string temp = "", material = "";                                     //单纯的用来用来做替代的
	while (!inputqueue.empty())                                             //先把传入的队列从中缀改成后缀 
	{
		temp = inputqueue.front();
		if (temp == "(")
		{
			operat.push(temp);
			inputqueue.pop();
			if (inputqueue.front() == "-")                                   //用来判断是否是负数的负号，而不是减号 ,因为如果在左括号后有负号就一定是负数的负号 
			{
				number.push("0");                                   /* 如果是负号的负数的话就可以再数字之前传入一个0，
																	这样把符号当做减号，0减去一个数就相当于其相反值 */
				temp = inputqueue.front();                                   //这里把负号当做减号 
				operat.push(temp);
				inputqueue.pop();                                         //去除掉这个负号 
			}
		}
		else if (temp == ")")                                         /*碰到右括号要去符号stack中去从后往前找，直到找到左括号，
																	  而这之间的符号就push到数字stack中 */
		{
			for (;;)
			{
				if (operat.top() == "(")
				{
					operat.pop();                                  //当然要记得把左括号去掉 
					inputqueue.pop();
					break;
				}
				else
				{
					material = operat.top();                        //用来把括号之间的运算符存储入numberstack中 
					number.push(material);
					operat.pop();
				}
			}
		}
		else if (temp == "+" || temp == "-")
		{
			for (;;)
			{
				if (operat.empty() || operat.top() == "(")           //加号和减号只能在运算符stack为空时或者在栈顶为左括号时候导入堆中 
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

					/*只有当堆顶是除号或者乘号的时候才需要将运算符stack的栈
					顶转入numberstack中，直到碰到堆顶不是乘号或者除号 */

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
		else                                                                   //如果不是符号数就是数字了，此时还要和mark相加，因为有可能是负数 
		{
			number.push(temp);
			inputqueue.pop();
		}
	}


	while (!operat.empty())                                                    //把最后的一些运算符都存入number中 
	{
		temp = operat.top();
		number.push(temp);
		operat.pop();
	}



	while (!number.empty())                                                    //把number堆中的东西反过来存到operat中，用于计算 
	{
		operat.push(number.top());
		number.pop();
	}

	double d = 0;                                                                /*以免出现-(100+9)这种情况的出现 这个很重要，
																				 如果第一个不是-（这种类型的话，也无影响 */
	num.push(d);

	while (!operat.empty())                                                     //进行计算 
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

	double result = 0;                                                          //使result等于计算出的结果并且return出去 
	result = num.top();
	num.pop();
	return result;
}