#include "calculation.h"
#include<stack>
#include<string>
#include<queue>
using namespace std;
#include<iostream>
stack<char> symbol;//存放符号
stack<int> cal;

int calculation::Calculationqueue(queue<string> caque) {
	string hz;//用于存放后缀运算符
	int len,i;
	int lenth=caque.size();
	//hz.clear();
	for(i=0; i<caque.size(); i++) {
		if(caque.front() != '+' && caque.front() !='-' && caque.front() !='*' && caque.front() !='/' && caque.front() !='(' && caque.front() !=')')//读入数字 
			hz.push_back(caque.front());
		else {
			if(symbol.size()==0 || caque.front()=='(')
				symbol.push(caque.front());
			else {
				char tmp1 = symbol.top();
				if (caque.front() == ')') {
					len = symbol.size();
					while (len) {
						char tmp = symbol.top();
						symbol.pop();
						if (tmp == '(') 
							break;
						else
							hz.push_back(tmp);
						len--;
					}
				} else {
					if (tmp1 == '*' || tmp1 == '/') {
						if (caque.front() == '*' || caque.front() == '/')
							symbol.push(caque.front());
						else {
							len = symbol.size();
							while (len) {
								char tmp = symbol.top();
								hz.push_back(tmp);
								symbol.pop();
								len--;
							}
							symbol.push(caque.front());
						}
					}
					}
				}
			}
			caque.pop();
		}
		//用后缀运算符运算
		int temp1, temp2, temp3; 
        int len2 = hz.length();
          for (i = 0; i < len2; i++){
              if (hz[i]!='+' && hz[i]!='-' && hz[i]!='*' && hz[i]!='/' && hz[i]!='(' && hz[i]!=')')
			  { 
                  int t = hz[i]-48; 
                  cal.push(t); 
              } 
              else{
                   temp1 = cal.top();
                   cal.pop();
                   temp2 = cal.top();
                   cal.pop(); 
                   if (hz[i] == '+'){
                       temp3 = temp2 + temp1; 
                   }
                   else if (hz[i] == '-'){
                        temp3 = temp2 - temp1; 
                   }
                   else if (hz[i] == '*'){
                        temp3 = temp2 * temp1; 
                   }
                   else if (hz[i] == '/'){
                        temp3 = temp2 / temp1; 
                   }
                   cal.push(temp3); 
              }
          }
          return cal.pop();
    }
