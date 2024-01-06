#include<iostream>
using namespace std;
#define SIZE 5

//-------------------------------------------------------------------------------------
struct make_queue{
    int a[SIZE];
    int front, rear;
};
//-------------------------------------------------------------------------------------
class Queue{
    struct make_queue q;
    public:
    Queue(){               
        q.front=q.rear=-1;    
    }
    int isempty();
    int isfull();
    int del_queue();
    void enqueue(int);
    void display();
};

//-------------------------------------------------------------------------------------

int Queue::isempty(){                         
    return(q.front==q.rear);
}

int Queue::isfull(){                           
    return(q.rear==SIZE-1);
}

void Queue::enqueue(int x){                    
    q.a[++q.rear]=x;                            //imp
}

int Queue::del_queue(){                        
    return q.a[++q.front];                      //imp
}

//-------------------------------------------------------------------------------------
void Queue::display(){                          
    cout<<"\n-> Queue Contains : ";
    for(int i=q.front+1; i<=q.rear; i++){
        cout<<q.a[i]<<" ";
    }
}
//------------------------------------------------------------------------------------
int main(){
    Queue obj;
    int ch, x;

    do{
        cout<<"\n1 = Insert Job\n2 = Delete Job\n3 = Display\n4 = Exit\nEnter your Choice : ";
        cin>>ch;
        switch(ch){
            case 1 :
                if(!obj.isfull()){
                    cout<<"\nEnter Job Data : ";
                    cin>>x;
                    obj.enqueue(x);
                }
                else{
                    cout<<"\n**** Queue is Full!****\n";
                }
                 break;

            case 2:
                if(!obj.isempty()){
                    cout<<"\n-> Deleted Job = "<<obj.del_queue();
                }
                else{
                    cout<<"\n-> No Jobs in Queue!";
                }
                break;

            case 3:
                if(!obj.isempty()){
                    obj.display();
                }
                else{
                    cout<<"\n-> No Jobs in Queue. Empty!\n";
                }
                break;

            case 4:
                cout<<"\nExiting...\n";
                break;

            default:
                cout<<"Enter valid choice";
        }
    }while(ch!=4);
    
    return 0;
}