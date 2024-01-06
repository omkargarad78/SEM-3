#include<iostream>
using namespace std;
#define SIZE 50

//------------------------------------------------------------------------
class PizzaParlour{
	
	int a[10],front,rear;

	public:
		PizzaParlour(){
			front=rear=-1;
		}
		int addOrder(int);
		void serveOrder();
		void display();
};
//------------------------------------------------------------------------
int PizzaParlour::addOrder(int id){
 	if(front==-1){

 		front++;
		rear++;
 		a[rear]=id;
	 }
	 else{
	 	int pos=(rear+1)%SIZE;									//formula to remember
	 	if(pos==front){
	 		cout<<"\nCafe is Full.Please wait.\n";
		 }
		 else{
		 	rear=pos;
		 	a[rear]=id;
		 }
	 }
 }
 
 //------------------------------------------------------------------------
 void PizzaParlour::serveOrder(){
 	if(front==-1){
 		cout<<"\n No orders in Cafe.[Cafe is Empty)\n";
	 }
	 else{
	 	cout<<"\n Order No. "<<a[front]<<" is processed.\n";
	 	if(front==rear){ 											
	 		front=rear=-1;
		 }
		 else{
		 	front=(front+1)%SIZE;
		 }
	 }
 }
 
 //------------------------------------------------------------------------
 void PizzaParlour::display(){
 	int i=0;
	for(i=front;i!=rear;i=((i+1)%SIZE)){
	 	cout<<a[i]<<"  ";
		}
		//cout<<a[rear];
	 }
//------------------------------------------------------------------------
 int main(){
 	int ch,id=0;
	PizzaParlour q;

	do{
		cout<<"\n****Menu*****\n";
		cout<<"1. Accept order\n";
		cout<<"2. Serve order\n";
		cout<<"3. Display orders\n";
		cout<<"4. Exit";
		cout<<"\nChoice: ";
		cin>>ch;

		switch(ch){
		case 1: 
				id++;
				if(q.addOrder(id)){
					cout<<"Thank you for order.Order id is : "<<id;
				}
				else{
					id--;
				}
				break;

		case 2: q.serveOrder();
				break;

		case 3: q.display();
				break;
		}
	}while(ch!=4);
 }