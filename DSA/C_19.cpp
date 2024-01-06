#include <iostream>
#include <string.h>
using namespace std;
//------------------------------------------------------------------------------------------
struct node{
    int prn;
    char name[20];
    node *next;
};
//------------------------------------------------------------------------------------------
class Pinnacle_Club
{
    int num, cnt;
    char namee[20];
    node *head;

public:
    Pinnacle_Club()
    {
        num = cnt = 0;
        head = NULL;
    }
    node *create();
    void display(node *);
    node *concat(node *, node *);
    node *insert_president(node *);
    void insert_sec(node *);
    void insert_member(node *);
    node *del_president(node *);
    node *del_secretary(node *);
    node *del_member(node *);
};
//------------------------------------------------------------------------------------------
node *Pinnacle_Club::create()
{
    node *temp, *n1;
    temp = n1 = NULL;
    cout << "\nHow many students data u want to insert in panclub database: ";
    cin >> cnt;
    do
    {
        n1 = new node;
        cout << "\nEnter the prn number of student:";
        cin >> num;
        n1->prn = num;
        cout << "\nEnter the name of student:";
        cin >> namee;
        strcpy(n1->name, namee);
        n1->next = NULL;
        if (head == NULL)
        {
            head = n1;
            temp = head;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n1;
        }
        cnt--;
    } while (cnt > 0);
    return head;
}
//------------------------------------------------------------------------------------------
void Pinnacle_Club::display(node *head)
{
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            cout << "[" << temp->prn << "|" << temp->name << "]->NULL";
        }
        else
        {
            cout << "[" << temp->prn << "|" << temp->name << "]->";
        }
        temp = temp->next;
    }
}
//------------------------------------------------------------------------------------------
/*
node *Pinnacle_Club::concat(node *head1, node *head2)
{
    node *head3, *temp, *temp1;
    head3 = temp = temp1 = NULL;
    temp = head1;
    head3 = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp1 = head2;
    temp->next = temp1;
    return head3;
}*/
//------------------------------------------------------------------------------------------
node *Pinnacle_Club::insert_president(node *head)
{
    node *temp, *n2;
    temp = n2 = NULL;
    temp = head;
    n2 = new node;
    cout << "\nEnter the PRN number of President: ";
    cin >> n2->prn;
    cout << "\nEnter the name of President: ";
    cin >> n2->name;
    n2->next = temp;
    head = n2;
    return head;
}
//------------------------------------------------------------------------------------------
void Pinnacle_Club::insert_member(node *head)
{
    node *temp, *n2;
    int pn;
    temp = head;
    n2 = new node;
    cout << "\nEnter the PRN number of Member: ";
    cin >> n2->prn;
    cout << "\nEnter the name of Member: ";
    cin >> n2->name;
    n2->next = NULL;
    cout << "\nEnter the PRN number after which u want to add this member: ";
    cin >> pn;
    while (temp != NULL)
    {
        if (temp->prn == pn)
        {
            n2->next = temp->next;
            temp->next = n2;
            break;
        }
        temp = temp->next;
    }
    cout << "\n\nMember added sucessfully . !!";
}
//------------------------------------------------------------------------------------------
void Pinnacle_Club::insert_sec(node *head)
{
    node *temp, *n2;
    temp = head;
    n2 = new node;
    cout << "\nEnter the PRN number of Secretary: ";
    cin >> n2->prn;
    cout << "\nEnter the Name of Secretary: ";
    cin >> n2->name;
    n2->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n2;
}
//------------------------------------------------------------------------------------------
node *Pinnacle_Club::del_president(node *head)
{
    node *temp;
    temp = head;
    head = temp->next;
    free(temp);
    return head;
}//------------------------------------------------------------------------------------------

node *Pinnacle_Club::del_secretary(node *head)
{
    node *temp, *t1;
    temp = head;
    while (temp->next != NULL)
    {
        t1 = temp;
        temp = temp->next;
    }
    t1->next = NULL;
    free(temp);
    return head;
}
//------------------------------------------------------------------------------------------
node *Pinnacle_Club::del_member(node *head)
{
    node *temp, *t1;
    int pn;
    temp = head;
    cout << "\nEnter the PRN number after which you want to delete member: ";
    cin >> pn;
    while (temp != NULL)
    {
        if (temp->prn == pn)
        {
            t1 = temp->next;
            temp->next = t1->next;
            free(t1);
            break;
        }
        temp = temp->next;
    }
    cout << "\n\nMember removed sucessfully . !!";
    return head;
}
//------------------------------------------------------------------------------------------
int main()
{
    Pinnacle_Club p1, p2, p3;
    node *h1, *h2, *h3;
    h1 = h2 = h3 = NULL;
    int ch;
    do
    {
        cout << "\n\n1.Enter data of SE A Division:";
        cout << "\n2.Enter data of SE B Division:";
        cout << "\n3.Concatination of List..";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\n\nPlease enter the student info who is register memeber..";
            cout << "\n\nEnter the Panclub Data of SE A Division:\n";
            h1 = p1.create();
            cout << "\nSE Comp Division A List are as follows..\n\n";
            p1.display(h1);
            p1.insert_sec(h1);
            cout << "\nAfter insertion of Secretary: \n";
            p1.display(h1);
            h1 = p1.insert_president(h1);
            cout << "\nAfter insertion of President: \n";
            p1.display(h1);
            p1.insert_member(h1);
            cout << "\n After insertion of member...\n";
            p1.display(h1);
            h1 = p1.del_president(h1);
            cout << "\n\nAfter deletion of president...\n";
            p1.display(h1);
            h1 = p1.del_secretary(h1);
            cout << "\n\nAfter deletion of secretary...\n";
            p1.display(h1);
            h1 = p1.del_member(h1);
            cout << "\n\nAfter deletion of member...\n";
            p1.display(h1);
            break;
        case 2:
            cout << "\n\nEnter the Panclub Data of SE B Division:\n";
            h2 = p2.create();
            cout << "\nSE Comp Division B List are as follows..\n\n";
            p2.display(h2);
            p2.insert_sec(h2);
            cout << "\nAfter insertion of Secretary: \n";
            p2.display(h2);
            h2 = p2.insert_president(h2);
            cout << "\nAfter insertion of President: \n";
            p2.display(h2);
            p2.insert_member(h2);
            cout << "\n After insertion of member...\n";
            p2.display(h2);
            h2 = p2.del_president(h2);
            cout << "\n\nAfter deletion of president...\n";
            p1.display(h2);
            h2 = p2.del_secretary(h2);
            cout << "\n\nAfter deletion of secretary...\n";
            p1.display(h2);
            h2 = p2.del_member(h2);
            cout << "\n\nAfter deletion of member...\n";
            p2.display(h2);
            break;
        case 3:
            h3 = p3.concat(h1, h2);
            cout << "\n\nThe concatenation of Div : A and Div : B of SE Comp Class are as follows.\n\n";
            p3.display(h3);
            break;
        }
    } while (ch != 4);
    return 0;
}
//------------------------------------------------------------------------------------------
/* ~~~~~~~~~ Output ~~~~~~~~~~ 

1.Enter data of SE A Division:
2.Enter data of SE B Division:
3.Concatination of List..     
Enter your choice: 1


Please enter the student info who is register memeber..

Enter the Panclub Data of SE A Division:

How many students data u want to insert in panclub database: 2

Enter the prn number of student:1001

Enter the name of student:A 

Enter the prn number of student:1002

Enter the name of student:B

SE Comp Division A List are as follows..

[1001|A]->[1002|B]->NULL
Enter the PRN number of Secretary: 101

Enter the Name of Secretary: C

After insertion of Secretary:
[1001|A]->[1002|B]->[101|C]->NULL
Enter the PRN number of President: 10

Enter the name of President: PR

After insertion of President:
[10|PR]->[1001|A]->[1002|B]->[101|C]->NULL
Enter the PRN number of Member: 31

Enter the name of Member: M1

Enter the PRN number after which u want to add this member: 10


Member added sucessfully . !!
 After insertion of member...
[10|PR]->[31|M1]->[1001|A]->[1002|B]->[101|C]->NULL

After deletion of president...
[31|M1]->[1001|A]->[1002|B]->[101|C]->NULL

After deletion of secretary...
[31|M1]->[1001|A]->[1002|B]->NULL
Enter the PRN number after which you want to delete member: 101


Member removed sucessfully . !!

After deletion of member...
[31|M1]->[1001|A]->[1002|B]->NULL

1.Enter data of SE A Division:
2.Enter data of SE B Division:
3.Concatination of List..
Enter your choice:
4

~~~~~~~~~~~~~~~~~~~~ */