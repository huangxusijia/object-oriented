//#ifndef SCAN_H
//#define SCAN_H
#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Scan {
	public:
		bool Flag = true;//用于判断式子是否正确
		void ToStringQueue(string input);  //接受式子
		queue<string> getqueue();


	private:
		queue<string> inputqueue;
};
//#endif
