#include<iostream>			
#include<string>						
#define max 100;
using namespace std;
//-------------------------------------------------------------------------------------------------
class info{

    string lic, dob, bgrp;    
    public:
    info();                 
    info(info &);       
    ~info(){
          cout<<"\nDESTRUCTOR IS CALLED!!!!!"<<endl;
    }
    friend class student;                     //FRIEND FUNCTION DECLARATION
};
//-------------------------------------------------------------------------------------------------
class student{

    string name, address, year;
    char div;
    int roll_no;
    long mob;
    static int cnt; 	            //imp

    public:
    void create(info &);			
    void display(info &);			
 
    inline static void inccnt(){
      cnt++;
    }
    inline static void showcnt(){
      cout<<"\nTOTAL NO OF RECORDS ARE : "<<cnt;
    }
    student();                           
    student(student &);                  //COPY CONSTRUCTOR OF STUDENT CLASS//
    ~student(){
       cout<<"\nDESTRUCTOR IS CALLED!!!"<<endl;
    }
};
//************************************************************************************************
int student::cnt;                               //DEFINITION OF STATIC MEMBER//

student::student(){

        name="ANAGHA NIRGUDE";
        address="SR NO.81 BABBAR SOLANKI \nDIGHI, PUNE";
        year="SE COMPUTER";
        div='A';
        roll_no=21042;
        mob=942329999;
}
//-------------------------------------------------------------------------------------------------
info::info(){             //CONSTRUCTOR DEFINITION//

       lic="ABD45656";
       dob="02/11/1997";
       bgrp="A-";
}
//************************************************************************************************
student::student(student &obj){

      this->name=obj.name;			//this is a pointer points to the object which invokes it
      this->address=obj.address;	
      this->year=obj.year;
      this->div=obj.div;
      this->roll_no=obj.roll_no;
      this->mob=obj.mob;
}
//-------------------------------------------------------------------------------------------------
info::info(info &obj){		//DEFINITION OF COPY CONTRUCTOR OF PERSONAL CLASS

     lic=obj.lic;
     dob=obj.dob;
     bgrp=obj.bgrp;
}
//-------------------------------------------------------------------------------------------------
void student::create(info &obj){

cout<<"\nNAME : "<<endl;
cin>>name;
cout<<"\nADDRESS : "<<endl;
cin>>address;
cout<<"\nDATE OF BIRTH : "<<endl;
cin>>obj.dob;
cout<<"\nYEAR : "<<endl;
cin>>year;
cout<<"\nDIVISION: "<<endl;
cin>>div;
cout<<"\nROLL NUMBER : "<<endl;
cin>>roll_no;
cout<<"\nBLOOD GROUP : "<<endl;
cin>>obj.bgrp;
cout<<"\nLICEINCE NUMBER : "<<endl;
cin>>obj.lic;
cout<<"\nPHONE NUMBER : "<<endl;
cin>>mob;
}
//-------------------------------------------------------------------------------------------------
void student::display(info &obj){

cout<<"\nNAME OF STUDENT : "<<name<<endl;
cout<<"\nADDRESS OF STUDENT : "<<address<<endl;
cout<<"\nDATE OF BIRTH : "<<obj.dob<<endl;
cout<<"\nYEAR : "<<year<<endl;
cout<<"\nDIVISION : "<<div<<endl;
cout<<"\nROLL NO : "<<roll_no<<endl;
cout<<"\nBLOOD GROUP : "<<obj.bgrp<<endl;
cout<<"\nLICEINCE NUMBER : "<<obj.lic<<endl;
cout<<"\nPHONE NUMBER : "<<mob<<endl;
cout<<"\n***********************"<<endl;
}
//-------------------------------------------------------------------------------------------------
int main(){

 int n,ch;				
 char ans;
 
 cout<<"\nENTER NO OF STUDENTS :"<<endl;
 cin>>n;

 student *sobj=new student[n];		//sobj,pobj IS POINTER OF TYPE STUDENT AND IT IS A ARRAY OF OBJECT OF SIZE n
 info *pobj=new info[n];		
 
 do{
	 cout<<"\n Menu \n 1. Create Database \n 2. Display Databse \n 3. Copy Constructor\n 4. Default Constructor \n 5. Delete (Destructor)";
	 cout<<"\n Enter your Choice: ";
	 cin>>ch;

	 switch(ch){
	 case 1: 
		 for(int i=0;i<n;i++){
		       sobj[i].create(pobj[i]);
		       sobj[i].inccnt();
		 }
		break;
 	 case 2:
			sobj[0].showcnt(); 	//to display the total count of students
			 for(int i=0;i<n;i++){
				 sobj[i].display(pobj[i]);
			 }
    	            break;
	  /*case 3:{
		 student obj1;
		 info obj2;
		 obj1.create(obj2);
		 student obj3(obj1);		//invoking copy constructor of student info to copy contents from object 1 to 3
		 info obj4(obj2);		 
		 cout<<"\n Copy Constructor is called ";
		 obj3.display(obj4);
 		}
            break;*/
	 case 4:{
		 student obj1;	//obj1 is invoking default constructor of class student
		 info obj2;	
		 cout<<"\n Default Constructor is called ";
		 obj1.display(obj2);
 		}
 		break;
	 /*case 5: 
			 delete [] sobj;			//invoking destructor and delete sobj dynamically
 		     delete [] pobj;	*/	
 	}				
 	cout<<"\n Want to continue:(y/n)"	     ;
 	cin>>ans;
  }while(ans=='y');
 return 0;
}