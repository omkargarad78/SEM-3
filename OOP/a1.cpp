#include<iostream>
using namespace std;

class complex{
    float x,y;
    public:
    complex(){
        x=0;
        y=0;
    }
//----------------------------------------------------------
    complex operator+(complex);
    complex operator*(complex);
    friend istream &operator>>(istream &input,complex &t){
        cout<<"Enter the real part:-";
        cin>>t.x;
        cout<<"Enter imaginery part:-";
        cin>>t.y;
    }
    friend ostream &operator<<(ostream &output,complex &t){
        cout<<t.x<<"+"<<t.y<<"i\n";
    }
};
//-------------------------------------------------------------

complex complex::operator+(complex c){
    complex temp;
    temp.x=x+c.x;
    temp.y=y+c.y;
    return(temp);
}
complex complex::operator*(complex c){
    complex temp2;
    temp2.x=(x*c.x)-(y*c.y);
    temp2.y=(y*c.x)+(x*c.y);
    return(temp2);
}
//----------------------------------------------------------------

int main(){
    complex c1,c2,c3,c4;
    
    cout<<"Default constructor value:-\n";
    cin>>c1;
    cout<<"Enter Second complex number below\n";
    cin>>c2;

    c3=c1+c2;
    c4=c1*c2;

    cout<<"first number:-"<<c1<<endl;
    cout<<"Second number:-"<<c2<<endl;
    cout<<"Addition:-"<<c3<<endl;
    cout<<"Multiplication:-"<<c4<<endl;
    return 0;
}