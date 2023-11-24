#include<iostream>
#include<string.h>
using namespace std;
struct emp
{
    int id;
    string name;
    int key;
};
class hashtable
{
    emp e[10];
    public:
    hashtable()
    {
        for(int i=0;i<10;i++)
        {
            e[i].id=-1;
            e[i].name=" ";
            e[i].key=-1;
        }
    }
    void insert(int id,string n)
    {
        int index=id%10;
        int c=index;
        while(e[index].id!=-1)
        {
            index=(index+1)%10;
            if(c==index)
            {
                cout<<"Overflow";
            }
        }
        e[index].id=id;
            e[index].name=n;
            e[index].key=index;
    }
    void display()
    {
        cout<<"Index\tId\tName\n";
        for(int i=0;i<10;i++)
        {
            cout<<e[i].key<<"\t"<<e[i].id<<"\t"<<e[i].name<<"\n";
        }
    }
};
int main()
{
    hashtable h;
    int ch;
    do
    {
        cout<<"1.Add Record\n2.Display\n3.exit\nEnter Choice:";
        cin>>ch;
        string n1;
        int i;
        switch(ch)
        {
            case 1:
            cout<<"Enter ID:";
            cin>>i;
            cout<<"Enter name:";
            cin>>n1;
            h.insert(i,n1);
            break;
            case 2:
            h.display();
            break;
            case 3:
            break;
            default:
            cout<<"Invalid Choice";
            break;
        }
    }
    while(ch!=3);
    return 0;
}