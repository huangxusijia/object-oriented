#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
char a[2001];
string symbol="";//´¢´æ×ÖÄ¸ 
char f;
int main()
{
	int n,i;
	cin >> n;
	getchar();
	for(i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	if(n%2==0)
	{
		for(i=1;i<=n/2;i++)
		{
			if(a[i]>a[n-i+1])
			{
				symbol+=a[n-i+1];
				symbol+=a[i]; 
				continue;
			}
			else if(a[i]<a[n-i+1])
			{
				symbol+=a[i];
				symbol+=a[n-i+1];
				continue;
			}
			else if(a[i]==a[n-i+1])
			{
				if(i==n/2)
				{
					symbol+=a[i];
				    symbol+=a[n-i+1];
				    continue;
				}
				else
				{
					if(a[i+1]<a[n-i])
					{
						symbol+=a[i];
					    symbol+=a[i+1];
					    symbol+=a[n-i+1];
					    symbol+=a[n-i];
					    continue;
					}
					else if(a[i+1]>a[n-i])
					{
					    symbol+=a[n-i+1];
					    symbol+=a[n-i];
					    symbol+=a[i];
					    symbol+=a[i+1];
					    continue;
					}
				}
			}
		}
		cout << symbol << endl;
	}
	else
	{
	for(i=1;i<=n/2;i++)
		{
			if(a[i]>a[n-i+1])
			{
				symbol+=a[n-i+1];
				symbol+=a[i]; 
			}
			else if(a[i]<a[n-i+1])
			{
				symbol+=a[i];
				symbol+=a[n-i+1];
			}
			else if(a[i]==a[n-i+1])
			{
				if(i==n/2)
				{
					symbol+=a[i];
				symbol+=a[n-i+1];
				}
				else
				{
					if(a[i+1]<a[n-i])
					{
						symbol+=a[i];
					    symbol+=a[i+1];
					    symbol+=a[n-i+1];
					    symbol+=a[n-i];
					}
					else if(a[i+1]>a[n-i])
					{
					    symbol+=a[n-i+1];
					    symbol+=a[n-i];
					    symbol+=a[i];
					    symbol+=a[i+1];
					}
				}
			}
		}
		symbol+=a[n/2+1];
		cout << symbol << endl;	
	}
	
	return 0;
 } 
