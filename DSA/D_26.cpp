#include <iostream>
using namespace std;
#define MAX 50

//-------------------------------------------------------------
class stack{
    char stck[MAX];
    int top;
	
    public:
        stack(){
			top = -1;
		}
        void push(char);
        char pop();
        int isFULL();
        int isEMPTY();
};
//-------------------------------------------------------------
int stack::isEMPTY(){
    if (top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
//-------------------------------------------------------------
int stack::isFULL(){
    if(top == MAX - 1){
        return 1;
    }
    else{
        return 0;
    }
}
//-------------------------------------------------------------
void stack::push(char ch)
{
	if(!isFULL()){													//**
		top++;														//**
		stck[top]=ch;												//**
	}
}
//-------------------------------------------------------------
char stack::pop()
{
	if(!isEMPTY()){														//**
		char ch=stck[top];												//**
		top--;															//**
		return ch;														//**
	}
}
//-------------------------------------------------------------
int main(){
	char opt;
	cout<<"\n######  Expression Paranthesis Checker  ######\n";

	do{
		stack s;
		char exp[20],ch,lch;
		int i = 0,flag;
		cout<<"\nEnter the Expression to Check :- ";
		cin>>exp;
		
		while(exp[i] != '\0'){
			ch = exp[i];
			switch(ch){
				case '(':s.push(ch);break;
				case '{':s.push(ch);break;
				case '[':s.push(ch);break;
				case ')':
					flag = 0;
					lch = s.pop();
					if (ch == ')' && lch == '('){
						flag = 1;
					}
					break;

				case '}':
					flag = 0;
					lch = s.pop();
					if (ch == '}' && lch == '{'){
						flag = 1;
					}
					break;

				case ']':
					flag = 0;
					lch = s.pop();
					if (ch == ']' && lch == '['){
						flag = 1;
					}
					break;
			}
			i = i+1;
		}
		
		if (s.isEMPTY() && flag == 1){
			cout<<"\tExpression is parenthesised or in balanced form.\n";
		}
		else{
			cout<<"\tExpression is not well parenthesised.  \n";
		}

		cout<<"\nDo you want to check other expression? (y/n) :- ";
		cin>>opt;

	}while(opt == 'y' || opt == 'Y');
	
	return 0;
}
//-------------------------------------------------------------

