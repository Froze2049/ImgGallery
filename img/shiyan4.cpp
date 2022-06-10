#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stack>
#include <iostream>
using namespace std;
char words[100];
int i;
stack<char> line;
char E[2]={'T','G'};
char G[3]={'+','T','G'};
char T[2]={'F','H'};
char H[3]={'*','F','H'};
char F[3]={'(','E',')'};
char F1[1]={'i'};
void check()
{
	line.push('#');
	line.push('E');
	char num;
	while(!line.empty())
	{
		num=line.top();
		line.pop();
		if(num==words[i])
		{
			i++;
		}
		else if(num=='E'&&(words[i]=='i'||words[i]=='('))
		{
			line.push(E[1]);
			line.push(E[0]);
		}
		else if(num=='G'&&(words[i]=='+'||words[i]==')'||words[i]=='#'))
		{
			if(words[i]=='+')
			{
				line.push(G[2]);
				line.push(G[1]);
				line.push(G[0]);
			}
		}	
		else if(num=='T'&&(words[i]=='i'||words[i]=='('))
		{
			line.push(T[1]);
			line.push(T[0]);
		}
		else if(num=='H'&&(words[i]=='+'||words[i]=='*'||words[i]==')'||words[i]=='#'))
		{
			if(words[i]=='*')
			{
				line.push(H[2]);
				line.push(H[1]);
				line.push(H[0]);
			}
		}
		else if(num=='F'&&(words[i]=='i'||words[i]=='('))
		{
			if(words[i]=='i')
			{
				line.push(F1[0]);
			}
			else
			{
				line.push(F[2]);
				line.push(F[1]);
				line.push(F[0]);
			}
		}
		else
		{
			break;
		}
	}
	if(line.empty())
		{
			cout<<"输入正确"<<endl; 
		}
		else
		{
			cout<<"输入错误"<<endl; 
		}
}
int main()
{
	i=0;
	scanf("%s",&words);
	strcat(words,"#");
	check();
}
