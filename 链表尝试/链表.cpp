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
	//�������� 
	node *p1,*p2,*head;
	p1=p2=new node;//����ռ� 
	cin >> p1->num;//�����һ���� 
	head=NULL;//ͷָ���ʼΪ�� 
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
	 
	 node *p=head;//������� 
	 while(p)
	 {
	 	cout << p->num << " ";
		p=p->next;
		count++; //���� 
	 }
	 cout << endl;
	 cout << count << endl; 
	 //�������� 
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
		 p=p->next;//ָ����һ�� 
	  } 
	  
	  
	return 0;
} 
