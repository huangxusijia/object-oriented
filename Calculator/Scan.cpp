#include "Scan.h"
using namespace std;

void Scan::ToStringQueue(string input) {
	Flag = true;
	string fuhao; //���ڴ������
	string num="";
	int count,i;  //count �����ж�λ��

	for (i=0; i<input.size(); i++) { //�������
		if (input[i] == '-' || input[i] == '(' || input[i] == ')' || input[i] == '+' || input[i] == '*' || input[i] == '/') {
			if (num!="") {
				inputqueue.push(num);
			}
			num="";
			count=0;
			inputqueue.push(fuhao=input[i]);
		}

		else if (input[i] >= '0' && input[i] <= '9' || input[i] == '.') { //(������48��57�ֱ��Ӧ0-9,string��Ҫ�õ����ж�,������'0''9'����Ǵ�ASCII)
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
	if(num!="" && Flag) {
		inputqueue.push(num);
	}
	if (!Flag) {
		int size = inputqueue.size();
		for (i=0; i<size; i++) {
			inputqueue.pop();
			cout<<"Error"<<endl; //ִ�пն���
		}
	}
}

queue<string> Scan::getqueue() {
	return inputqueue;
}

