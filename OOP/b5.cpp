#include<iostream>
#define size 10
using namespace std;

//---------------------------------------------------------------------------
int n;
template<class T>
void sel(T A[size]){

    int i,j,min;                                                     //.
    T temp;                                                          //.
    for(i=0;i<n-1;i++){                                              //.
        min=i;                                                       //.
                                                                     //.
        for(j=i+1;j<n;j++){                                          //.
            if(A[j]<A[min])                                          //.
            min=j;                                                   //.
        }                                                            //.
        temp=A[i];                                                   //.
        A[i]=A[min];                                                 //.
        A[min]=temp;                                                 //.
    }
    cout<<"\nSorted array:";
    for(i=0;i<n;i++)
    {
        cout<<" "<<A[i];
    }
}

//----------------------------------------------------------------------------
int main(){

    int A[size];
    float B[size];
    int i,ch;

    cout<<"Enter what you want to do:-";
    cout<<"\n1)Int elements:-\n2)float elements:-\n3)Exit\n";
    cin>>ch;

    switch(ch){
        case 1:
            cout<<"\nEnter total no of int elements:";
            cin>>n;
            cout<<"\nEnter int elements:";
            for(i=0;i<n;i++){
               cin>>A[i];
            }
            sel(A);
            break;                                  //if you want to continuosly exicute program then remove break 

        case 2:
            cout<<"\nEnter total no of float elements:";
            cin>>n;
            cout<<"\nEnter float elements:";
            for(i=0;i<n;i++){
                 cin>>B[i];
            }
            sel(B);
            break;

        case 3:
            cout<<"\n-----------code exited successfully--------------";

        default:
            cout<<"\nInvalid choice";
    }
}
//----------------------------------------------------------------------------