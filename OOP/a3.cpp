#include<iostream>
using namespace std;

//---------------------------------------------------------------------------
class publication {
        private:
        string title;
        float price;
        public:
        publication(){
                title="";
                price=0.0;
        }

void get_data(){
        cout<<"\nEnter Title :";
        cin.ignore();                   //clear input buffer
        getline(cin,title);
        cout<<"\nEnter Price : ";
        cin>>price;
        }       

void put_data(){
        cout<<"\n Information : " <<endl;
        cout<<"\n Title :"<<title;
        cout<<"\n Price :"<<price;
        }
};
//******************************************************************************************************
class book:public publication{               
        private:                                //see::
        int pages;
        public:
                book(){
                pages=0;
                }
//----------------------------------------------------------------------------
        void get_data(){

                publication::get_data();
                cout<<"Enter Page Count : \n";
                cin>>pages;
        }
//----------------------------------------------------------------------------
        void put_data(){
                publication::put_data();
                /*try{
                        if(pages<0)
                        throw pages;
                }
                        catch(int f){
                        cout<<"\n error: pages not valid :"<<f;
                        pages=0;
                }*/
                cout<<"\n Pages Are :"<<pages;
        }
};
//*******************************************************************************************************
class tape: public publication{
        private:
        float playtime;
        public:
                tape(){
                playtime=0.0;
                }
//-------------------------------------------------------------------------------------

void get_data(){
        publication::get_data();
        cout<<"Enter Play Time Of Cassette \n";
        cin>>playtime;
        }
//-------------------------------------------------------------------------------------

void put_data(){
        publication::put_data();
        /*try{
                if(playtime<0.0)
                throw playtime;
                }
        catch(float r){
        cout<<"\n Error: Invalid Playtime : "<<playtime;
        playtime=0.0;
        }*/
        cout<<"\n Playtime is : "<<playtime;
        }
};
//*******************************************************************************************************

int main(){
        book b[10];                     // arrray of objects
        tape t[10];
        int ch=0,bookCount=0,tapeCount=0;
cout<<"-----------------------";
        do{
        cout<<"\n 1. Add book ";
        cout<<"\n 2. Add tape: ";
        cout<<"\n 3. Display book ";
        cout<<"\n 4. Display tape";
        cout<<"\n 5. Exit:"<<endl;
        cout<<"\n Enter Choice : ";
        cin>>ch;

        switch(ch){
        case 1:
                cout<<"\n--------------\n";
                b[bookCount].get_data();
                bookCount++;
                break;
 
        case 2:
                cout<<"\n--------------\n";
                t[tapeCount].get_data();
                tapeCount++;
                break;
        
        case 3:
                cout<<"\n (books)";
                for(int i=0;i<bookCount;i++){
                b[i].put_data();
                }
                break;
        
        case 4:
                cout<<"\n (tape)";
                for(int j=0;j<tapeCount;j++){
                t[j].put_data();
                }
                break;
        
        case 5:
                cout<<"**********"<<endl;
                cout<<"Program succesfully executed";
                exit(1);

        
        default:
                cout<<"\n Invalid";
        }
        
        }while(ch!=5);
        return 0;
}