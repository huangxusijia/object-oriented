#include<iostream>
#include<string.h>
using namespace std;

struct node
{
     int num;
	 node *next;	
};

int main()
{
	int n=0;
	int count = 0;
	//创建链表 
	node *p1,*p2,*head;
	p1=p2=new node;//申请空间 
	cin >> p1->num;//输入第一个数 
	head=NULL;//头指针最开始为空 
	while(p1->num!=0)
	{
		if(n==0)
		{
			head=p1;
		}
		else
		p2->next=p1;
		p2=p1;
		p1=new node;
		cin >> p1->num;
		n++;
	 } 
	 p2->next=NULL;
	 
	 node *p=head;//输出链表 
	 while(p)
	 {
	 	cout << p->num << " ";
		p=p->next;
		count++; //计数 
	 }
	 cout << endl;
	 cout << count << endl; 
	 //查找链表 
	 int valua;
	 cin >> valua; 
	 p=head;
	 while(p)
	 {
	 	if(p->num == valua)
	 	{
	 		cout << p->num << endl;
	 		break;
		 }
		 else
		 p=p->next;//指向下一个 
	  } 
	  
	  
	return 0;
} 
