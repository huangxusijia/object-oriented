#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Scan {
	public:
		bool Flag;//�����ж�ʽ���Ƿ���ȷ
		void ToStringQueue(string input);  //����ʽ��
		queue<string> getqueue();


	private:
		queue<string> inputqueue;
};

