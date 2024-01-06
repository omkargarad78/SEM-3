#include<iostream>
using namespace std;
#define MAX 50
//--------------------------------------------------------
class Stack {
    int top;
    int* a;
 
public:
    Stack(){
        top = -1;
        a = new int [MAX];
    }
    void push(int);
    int pop();
    int top_ch();
    int isEmpty();
    int isFull();  
};
//---------------------------------------------------------
int Stack::isEmpty(){
    if (top == -1){
        return 1;
    }
    else{
        return 0;
    }
} 
//---------------------------------------------------------
int Stack::isFull(){
    if(top == MAX - 1){
        return 1;
    }
    else{
        return 0;
    } 
} 
//---------------------------------------------------------
int Stack::top_ch(){ 
    return a[top]; 
} 
//---------------------------------------------------------
void Stack::push(int x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";   
    }
    else{
        top++;
        a[top] = x;
    }
}
//---------------------------------------------------------
int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow"; 
        return 1; 
    } 
    else { 
        int x = a[top]; 
        top--; 
        return x; 
    }
}
//---------------------------------------------------------
int priority (char c)
{
    if(c == '+' || c =='-')
        return 1;
    if(c == '*' || c =='/')
        return 2;
    if(c == '^')
        return 3;
    
    return 0;
}
//---------------------------------------------------------
string infix_to_postfix(string infix){

    int i = 0;
    Stack s;
    string postfix = " ";
    while(infix[i]!='\0'){
       if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z'){

           postfix += infix[i]; 
            i++; 
       } 
//**********************************************
       else if(infix[i]=='(') {
           s.push(infix[i]);
           i++; 
       } 
//**********************************************
		else if(infix[i]==')') { 
		    while(s.top_ch()!='(')
				postfix += s.pop(); 
			    s.pop(); 
			    i++;
			}
//*********************************************** 
		else{ 
			while (!s.isEmpty() && priority(infix[i]) <= priority(s.top_ch())){
				postfix += s.pop();
			} 
			s.push(infix[i]);
			i++;
    	}
    } 
//------------------------------------------------------------------------------------------
    while(!s.isEmpty()){
        postfix += s.pop();
        }
    return postfix;
} 
//------------------------------------------------------------------------------------------
int main() {

	char opt;
    string infix,postfix;
	cout<<"\n********** INFIX to POSTFIX CONVERTER **********\n";
	do{
		cout<<"\nEnter Infix Expression :- ";
		cin>>infix;

		cout<<"\nPostfix Expression :- "<<infix_to_postfix(infix);

		cout<<"\n\n\tDo you want to convert other expression ? (y/n) :- ";
		cin>>opt;
	}while(opt == 'y' || opt == 'Y');
    return 0;
}