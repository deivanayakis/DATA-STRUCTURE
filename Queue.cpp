#include<iostream>
using namespace std;
class CQueue;
class CAppliances
{
        private:
                string name;
                string color;
                string brand;
                float cost;
                int warranty;
        public:
                friend CQueue;
                void display();
};
class CQueue
{
        private:
                CAppliances *a;
                int capacity;
                int front;
                int rear;
        public:
                CQueue(int);
                int isEmpty();
                int isFull();
                int displayQueue();
                int enqueue(string,string,string,float,int);
                int dequeue();
                int Front();
                int Rear();
                int makeEmpty();
                int searchByElement(string);
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
CQueue :: CQueue(int c)
{
        front=0;
        rear=-1;
        capacity=c;
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
int CQueue :: isFull()
{
        if(rear>=capacity-1)
                return 1;
        else
                return -1;
}
int CQueue :: isEmpty()
{
        if(rear==-1)
                return 1;
        else
                return -1;
}
int CQueue :: displayQueue()
{
        if(isEmpty()==1)
                return -1;
        else
        {
                for(int i=front;i<=rear;i++)
                        a[i].display();
                return 1;
        }
}
int CQueue :: enqueue(string n,string c,string b,float p,int w)
{
        if(isFull()==1)
                return -1;
        else
        {
                rear++;
                a[rear].name=n;
                a[rear].color=c;
                a[rear].brand=b;
                a[rear].cost=p;
                a[rear].warranty=w;
                return 1;
        }
}
int CQueue :: dequeue()
{
        if(isEmpty()==1)
                return -1;
        else
        {
                a[front].name=-1;
                a[front].color=-1;
                a[front].brand=-1;
                a[front].cost=-1;
                a[front].warranty=-1;
                front++;
                return 1;
        }
}
int CQueue :: Front()
{
        if(isEmpty()==1)
                return -1;
        else
                a[front].display();
}
int CQueue :: Rear()
{
        if(isEmpty()==1)
                return -1;
        else
                a[rear].display();
}
int CQueue :: makeEmpty()
{
        for(int i=front;i<=rear;i++)
        {
                a[i].name=-1;
                a[i].color=-1;
                a[i].brand=-1;
                a[i].cost=-1;
                a[i].warranty=-1;
        }
        front=0;
        rear=-1;
}
int CQueue :: searchByElement(string n)
{
        if(isEmpty()==1)
                return -1;
        else
        {
                int flag=0;
                for(int i=front;i<=rear;i++)
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
int main()
{
        int cap,ch;
        cout<<"*****************************************************************************************\n";
        cout<<"PROGRAM TO PERFORM THE QUEUE ADT FOR HOME APPLIANCES DETAILS\n";
        cout<<"*****************************************************************************************\n";
        cout<<"ENTER CAPACITY : "<<endl;
        cin>>cap;
        CQueue q(cap);
        do
        {
                cout<<"--------------------\n1.ENQUEUE\n2.DEQUEUE\n3.SEARCH\n4.FRONT\n5.REAR\n6.MAKE EMPTY\n7.DISPLAY\n8.EXIT\n--------------------\n";
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
                                res=q.enqueue(n,c,b,p,w);
                                if(res==-1)
                                        cout<<"QUEUE OVERFLOW!!\n";
                                else
                                        cout<<"ENQUEUE OPERATION IS DONE SUCCESSFULLY!!\n";
                                break;
                        }
                        case 2:
                        {
                                int res;
                                res=q.dequeue();
                                if(res==-1)
                                        cout<<"QUEUE UNDERFLOW!!\n";
                                else
                                        cout<<"DEQUEUE OPERATION IS DONE SUCCESSFULLY!!\n";
                                break;
                        }
                        case 3:
                        {
                                        int res;
                                        string n;
                                        cout<<"ENTER APPLIANCES NAME TO SEARCH :\n";
                                        cin>>n;
                                        res=q.searchByElement(n);
                                        if(res==-1)
                                                cout<<"QUEUE UNDERFLOW!!\n";
                                        else if(res==-2)
                                                cout<<"DETAILS NOT FOUND!!\n";
                                        else
                                        {
                                                cout<<"APPLIANCES DETAILS IS FOUND AT "<<res<<endl;
                                                q.displayQueue();
                                        }
                                        break;
                        }
                        case 4:
                        {
                                int res;
                                res=q.Front();
                                if(res==-1)
                                        cout<<"QUEUE UNDERFLOW!!\n";
                                break;
                        }
                        case 5:
                        {
                                int res;
                                res=q.Rear();
                                if(res==-1)
                                        cout<<"QUEUE UNDERFLOW!!\n";
                                break;
                        }
                        case 6:
                        {
                                q.makeEmpty();
                                cout<<"QUEUE IS MADE AS EMPTY !!\n";
                                break;
                        }
                        case 7:
                        {
                                int res;
                                res=q.displayQueue();
                                if(res==-1)
                                        cout<<"QUEUE UNDERFLOW!!\n";
                                break;
                        }
                }
        }while(ch<8);
        cout<<"YOU ARE EXITED!!\n";
        return 0;
}