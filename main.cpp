#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */  


#include <iostream>
#include"Scan.h"
#include"Print.h"
using namespace std;



int main() 
{
	string input;   
	cin>>input;
	Scan get;
    get.ToStringQueue(input) ;
    queue<string> g=get.getqueue();  
	Print out;
	out.printqueue(g);
	return 0;
}
