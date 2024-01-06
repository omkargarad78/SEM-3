#include<iostream>
using namespace std;
#define SIZE 5

//----------------------------------------------------------------------
class dequeue{
	int a[10],front,rear,count;

public:
	dequeue(){
		front=rear=-1;
		count=0;
	}
	void add_at_beg(int);
	void add_at_end(int);
	void delete_fr_front();
	void delete_fr_rear();
	void display();
};
//------------------------------------------------------------------------
void dequeue::add_at_beg(int x){
	int  i;
	if(front==-1){

		front++;
		rear++;
		a[rear]=x;
		count++;
	}
	else if(rear>=SIZE-1){
		cout<<"\nInsertion is not possible,overflow!!!!";
	}
	else{
		for(i=count;i>=0;i--){
			
			a[i]=a[i-1];
		}
		a[i]=x;
		count++;
		rear++;
	}
}

//------------------------------------------------------------------------
void dequeue::add_at_end(int x){

	if(front==-1){
		front++;
		rear++;
		a[rear]=x;
		count++;
	}
	else if(rear>=SIZE-1){
		cout<<"\nInsertion is not possible,overflow!!!";
	}
	else{
		a[++rear]=x;
	}
}

//------------------------------------------------------------------------
void dequeue::display(){
	for(int i=front;i<=rear;i++)
	{
		cout<<a[i]<<" ";	
	}
}

//------------------------------------------------------------------------
void dequeue::delete_fr_front(){
	if(front==-1){
		cout<<"Deletion is not possible:: Dequeue is empty";
	}
	else{
		if(front==rear)
		{
			front=rear=-1;
		}
		cout<<"The deleted element is "<<a[front];
		front=front+1;
	}
}

//------------------------------------------------------------------------
void dequeue::delete_fr_rear(){
	if(front==-1){
		cout<<"Deletion is not possible:Dequeue is empty";
	}
	else{
		if(front==rear)
		{
			front=rear=-1;
		}
		cout<<"The deleted element is "<< a[rear];
		rear=rear-1;
	}
}
//------------------------------------------------------------------------

int main(){
	int ch,x;
	dequeue d;

	do
	{
		cout<<"\n\n****DEQUEUE OPERATION****\n";
		cout<<"\n1-Insert at beginning";
		cout<<"\n2-Insert at end";
		cout<<"\n3_Display";
		cout<<"\n4_Deletion from front";
		cout<<"\n5-Deletion from rear";
		cout<<"\nEnter your choice<1-4>:";
		cin>>ch;

		switch(ch){
		case 1:
			cout<<"Enter the element to be inserted:";
			cin>>x;
			d.add_at_beg(x);
			break;

		case 2:
			cout<<"Enter the element to be inserted:";
			cin>>x;
			d.add_at_end(x);
			break;

		case 3:
			d.display();
			break;

		case 4:
			d.delete_fr_front();
			break;
		case 5:
			d.delete_fr_rear();
			break;

		default:
			cout<<"Invalid choice";
			break;
		}
	}while(ch!=7);
	return 0;
}
//-----------------------------------------------------------------------------------