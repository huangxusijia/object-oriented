//#ifndef SCAN_H
//#define SCAN_H
#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Scan {
	public:
		bool Flag = true;//�����ж�ʽ���Ƿ���ȷ
		void ToStringQueue(string input);  //����ʽ��
		queue<string> getqueue();


	private:
		queue<string> inputqueue;
};
//#endif
