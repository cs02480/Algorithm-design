#include <iostream>
using namespace std;
#include <stack>
#define LEN 410
enum datatype{operond=0,oper,lp,rp};

datatype gettype(char  type)
{
	datatype tp;
	switch(type)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			tp =  oper;
			break;
		case '(':
			tp=lp;
			break;
		case ')':
			tp=rp;
			break;
	    default:
			tp=operond;

	}
	return tp;
}
void InfixToPostFix(char * orig)
{

	stack <char> st;
	char * temp=orig;
	char postfix[LEN];
	int postlen=0;
	datatype tp;
	while(*temp)
	{
		tp = gettype(*temp);
		if(operond == tp )
		{
			postfix[postlen++]=*temp;
		}
		else if(tp == oper)
		{
			st.push(*temp);
		}
		else if(tp == rp)
		{
			postfix[postlen++]=st.top();
			st.pop();
		}
		temp++;
	}
	postfix[postlen]='\0';
	cout<<postfix<<endl;
}
int readInfixdata(char * Exp)
{
	char ch;
	int len=0;
	//do
	//{
		//cin>>ch;
		int ret = scanf("%s",Exp);
	//	if(ch=='\0')
	//		break;
//		Exp[len++]=ch;
	//}while(ch!='\0');
return len;
}

void main_PostFix()
{
	int test_case=1;
	char data[LEN];//="((a+t)*((b+(a+c))^(c+d)))";
	cin>>test_case;
	for(int i=0;i<test_case;i++)
	{
		readInfixdata(data);
		InfixToPostFix(data);
	}
}