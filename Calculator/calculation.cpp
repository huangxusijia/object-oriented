#include "calculation.h"
#include<stack>
#include<string>
#include<queue>
using namespace std;

stack<char> symbol;//存放符号
stack<int> cal;

void calculation::Calculationqueue(string caque) {
	string hz;//用于存放后缀运算符
	int len,i;
	int lenth=hz.size();
	hz.clear();
	for(i=0; i<lenth; i++) {
		if(caque[i]!='+' && caque[i]!='-' caque[i]!='*' caque[i]!='/' caque[i]!='(' caque[i]!=')')
			hz.push_back(caque[i]);
		else {
			if(symbol.size()==0 || caque[i]=='(')
				symbol.push(caque[i]);
			else {
				char tmp1 = symbol.top();
				if (caque[i] == ')') {
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
						if (caque[i] == '*' || caque[i] == '/')
							symbol.push(caque[i]);
						else {
							len = symbol.size();
							while (len) {
								char tmp = s.top();
								hz.push_back(tmp);
								symbol.pop();
								len--;
							}
							symbol.push(caque[i]);
						}
					}
					}
				}
			}
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
                   ss.pop(); 
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
    }
	  
queue<string> calculation::cagetqueue() {
	return cal.top();
}



