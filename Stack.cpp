#include<iostream>
using namespace std;
class CStack;
class CAppliances
{
        private:
                string name;
                string color;
                string brand;
                float cost;
                int warranty;
        public:
                friend CStack;
                void display();
};
class CStack
{
        private:
                CAppliances *a;
                int capacity,top;
        public:
                CStack(int);
                int displayStack();
                int isEmpty();
                int isFull();
                int push(string,string,string,float,int);
                int pop();
                int peek();
                int searchByElement(string);
                int searchByPosition(int);
};
void CAppliances :: display()
{
        cout<<"*************************************************\n";
        cout<<"APPLIANCES DETAILS  : "<<endl;
        cout<<"*************************************************\n";
        cout<<"NAME                :"<<name<<endl;
        cout<<"COLOR               :"<<color<<endl;
        cout<<"BRAND               :"<<brand<<endl;
        cout<<"PRICE               :"<<cost<<endl;
        cout<<"WARRANTY            :"<<warranty<<endl;
        cout<<"*************************************************\n";
}
CStack :: CStack(int cap)
{
        capacity=cap;
        top=-1;
        a=new CAppliances[capacity];
        for(int i=0;i<capacity;i++)
        {
                a[i].name=-1;
                a[i].color=-1;
                a[i].brand=-1;
                a[i].cost=-1;
                a[i].warranty=-1;
        }
}
int CStack :: isFull()
{
        if(top==capacity-1)
                return 1;
        else
                return -1;
}
int CStack :: isEmpty()
{
        if(top==-1)
                return 1;
        else
                return -1;
}
int CStack :: displayStack()
{
        if(isEmpty()==1)
                return -1;
        else
        {
                for(int i=0;i<=top;i++)
                        a[i].display();
                return 1;
        }
}
int CStack :: push(string n, string c,string b,float p,int w)
{
        if(isFull()==1)
                return -1;
        else
        {
                top++;
                a[top].name=n;
                a[top].color=c;
                a[top].brand=b;
                a[top].cost=p;
                a[top].warranty=w;
                return 1;
        }
}
int CStack :: pop()
{
        if(isEmpty()==1)
                return -1;
        else
        {
                a[top].name=-1;
                a[top].color=-1;
                a[top].brand=-1;
                a[top].cost=-1;
                a[top].warranty=-1;
                top--;
                return 1;
        }
}
int CStack :: peek()
{
        if(isEmpty()==1)
                return -1;
        else
        {
                cout<<"PEEK APPLIANCES DETAILS ARE \n";
                a[top].display();
                return 1;
        }
}
int CStack :: searchByElement(string n)
{
        if(isEmpty()==1)
                return -1;
        else
        {
                int flag=0;
                for(int i=0;i<=top;i++)
                {
                        if(a[i].name==n)
                        {
                                flag=1;
                                return i+1;
                        }
                }
                if(flag==0)
                        return -2;
        }
}
int CStack :: searchByPosition(int p)
{
        p=p-1;
        if(isEmpty()==1)
                return -1;
        else if(top+1<capacity)
        {
                return -2;
        }
        else
                a[p].display();
}
#include"hahead.h"
int main()
{
        int cap,ch;
        cout<<"****************************************************************************************\n";
        cout<<"PROGRAM TO PERFORM STACK ADT FOR HOME APPLIANCES DETAILS\n";
        cout<<"****************************************************************************************\n";
        cout<<"ENTER CAPACITY : "<<endl;
        cin>>cap;
        CStack s(cap);
        do
        {
                cout<<"--------------------\n1.PUSH\n2.POP\n3.SEARCH\n4.PEEK\n5.DISPLAY\n6.EXIT\n--------------------\n";
                cout<<"ENTER YOUR CHOICE : ";
                cin>>ch;
                switch(ch)
                {
                        case 1:
                        {
                                int res,w;
                                string n,c,b;
                                float p;
                                cout<<"ENTER APPLIANCES DETAILS TO BE INSERTED : \n";
                                cout<<"ENTER NAME     : "<<endl;
                                cin>>n;
                                cout<<"ENTER COLOR    : "<<endl;
                                cin>>c;
                                cout<<"ENTER BRAND    : "<<endl;
                                cin>>b;
                                cout<<"ENTER PRICE    : "<<endl;
                                cin>>p;
                                cout<<"ENTER WARRANTY : "<<endl;
                                cin>>w;
                                res=s.push(n,c,b,p,w);
                                if(res==-1)
                                        cout<<"STACK OVERFLOW!!\n";
                                else
                                        cout<<"PUSH OPERATION IS DONE SUCCESSFULLY!!\n";
                                break;
                        }
                        case 2:
                        {
                                int res;
                                res=s.pop();
                                if(res==-1)
                                        cout<<"STACK UNDERFLOW!!\n";
                                else
                                        cout<<"POP OPERATION IS DONE SUCCESSFULLY!!\n";
                                break;
                        }
                        case 3:
                        {
                                int ch,res;
                                string n;
                                cout<<"1.BY ELEMENT\n2.BY POSITION\n";
                                cout<<"ENTER YOUR CHOICE : ";
                                cin>>ch;
                                switch(ch)
                                {
                                        case 1:
                                        {
                                                cout<<"ENTER APPLIANCES NAME TO SEARCH :\n";
                                                cin>>n;
                                                res=s.searchByElement(n);
                                                if(res==-1)
                                                        cout<<"STACK UNDERFLOW!!\n";
                                                else if(res==-2)
                                                        cout<<"DETAILS NOT FOUND!!\n";
                                                else
                                                {
                                                        cout<<"APPLIANCES DETAILS IS FOUND AT "<<res<<endl;
                                                        s.displayStack();
                                                }
                                                break;
                                        }
                                        case 2:
                                        {
                                                int p;
                                                cout<<"ENTER POSITION TO DISPLAY THE DETAILS : \n";
                                                cin>>p;
                                                res=s.searchByPosition(p);
                                                if(res==-1)
                                                        cout<<"STACK UNDERFLOW!!\n";
                                                else if(res==-2)
                                                        cout<<"OUT OF BOUND!!\n";
                                                break;
                                        }
                                }
                                break;
                        }
                        case 4:
                        {
                                int res;
                                res=s.peek();
                                if(res==-1)
                                        cout<<"STACK UNDERFLOW!!\n";
                                break;
                        }
                        case 5:
                        {
                                int res;
                                res=s.displayStack();
                                if(res==-1)
                                        cout<<"STACK UNDERFLOW!!\n";
                                break;
                        }
                }
        }while(ch<6);
        cout<<"YOU ARE EXITED!!\n";
        return 0;
}
