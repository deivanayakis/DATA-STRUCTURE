#include<iostream>
using namespace std;
class CList;
class CAppliances
{
        string name,color,brand;
        float cost;
        int war;
        public:
                friend CList;
                void getdetails();
                void display();
};
class CList
{
        CAppliances *a;
        int capacity;
        int size;
        public:
                CList(int,int);
                int isFull();
                int isEmpty();
                int insertAtFront(string,string,string,float,int);
                int deleteAtFront();
                int insertAtEnd(string,string,string,float,int);
                int deleteAtEnd();
                int insertAtPos(int,string,string,string,float,int);
                int searchByElement(string);
                int deleteAfterElement(string);
                int searchByPosition(int);
                void display();
};
void CAppliances::getdetails()
{
        cout<<"ENTER APPLIANCES DETAILS:"<<endl;
        cout<<"Enter Name : ";
        cin>>name;
        cout<<"Enter Color : ";
        cin>>color;
        cout<<"Enter Brand : ";
        cin>>brand;
        cout<<"Enter Price : ";
        cin>>cost;
        cout<<"Enter years of warranty : ";
        cin>>war;
}
void CAppliances::display()
{
        cout<<"APPLIANCES DETAILS :"<<endl;
        cout<<"**************************************\n";
        cout<<"NAME              :"<<name<<endl;
        cout<<"COLOR             :"<<color<<endl;
        cout<<"BRAND             :"<<brand<<endl;
        cout<<"COST              :"<<cost<<endl;
        cout<<"YEARS OF WARRANTY :"<<war<<endl;
        cout<<"**************************************\n";
}
CList :: CList(int c,int s)
{
        capacity=c;
        size=s;
        a=new CAppliances[c];
        for(int i=0;i<size;i++)
                a[i].getdetails();
}
void CList :: display()
{
        for(int i=0;i<size;i++)
        {
                a[i].display();
        }
}
int CList :: isFull()
{
        if(size==capacity)
                return 1;
        else
                return -1;
}
int CList :: isEmpty()
{        if(size==0)
                return 1;
        else
                return -1;
}
int CList :: insertAtFront(string n,string c,string b,float co,int w)
{
        if(isFull()==1)
                return -1;
        else if(isEmpty()==1)
        {
                a[0].name=n;
                a[0].color=c;
                a[0].brand=b;
                a[0].cost=co;
                a[0].war=w;
                size++;
                return 1;
        }
        else
        {
                for(int i=size;i>0;i--)
                {
                        a[i].name=a[i-1].name;
                        a[i].color=a[i-1].color;
                        a[i].brand=a[i-1].brand;
                        a[i].cost=a[i-1].cost;
                        a[i].war=a[i-1].war;
                }
                a[0].name=n;
                a[0].color=c;
                a[0].brand=b;
                a[0].cost=co;
                a[0].war=w;
                size++;
                return 1;
        }
}
int CList :: deleteAtFront()
{
        if(isEmpty()==1)
                return -1;
        else if(size>1)
        {
                for(int i=0;i<size;i++)
                {
                        a[i].name=a[i+1].name;
                        a[i].color=a[i+1].color;
                        a[i].brand=a[i+1].brand;
                        a[i].cost=a[i+1].cost;
                       a[i].war=a[i+1].war;
                }
                a[size-1].name=-1;
                a[size-1].color=-1;
                a[size-1].brand=-1;
                a[size-1].cost=-1;
                a[size-1].war=-1;
                size--;
                return 1;
        }
        else
        {
                a[0].name=-1;
                a[0].color=-1;
                a[0].brand=-1;
                a[0].cost=-1;
                a[0].war=-1;
                size--;
                return 1;
        }
}
int CList :: insertAtEnd(string n,string c,string b,float p,int w)
{
        if (isFull()==1)
                return -1;
        else
        {
                a[size].name=n;
                a[size].color=c;
                a[size].brand=b;
                a[size].cost=p;
                a[size].war=w;
                size++;
                return 1;
        }
}
int CList :: deleteAtEnd()
{
        if (isEmpty()==1)
                return -1;
        else
        {
                a[size-1].name=-1;
                a[size-1].color=-1;
                a[size-1].brand=-1;
                a[size-1].cost=-1;
                a[size-1].war=-1;
                size--;
                return 1;
        }
}
int CList :: insertAtPos(int p,string n,string c,string b,float co,int w)
{
        p=p-1;
        if(isFull()==1)
                return -1;
        else if(size<p && p<0)
                return -2;
        else if(p+1==size)
        {
                a[p].name=n;
                a[p].color=c;
                a[p].brand=b;
                a[p].cost=co;
                a[p].war=w;
                size++;
                return 1;
        }
        else
        {
                for(int i=size-1;i>=p;i--)
                {
                        a[i+1].name=a[i].name;
                        a[i+1].color=a[i].color;
                        a[i+1].brand=a[i].brand;
                        a[i+1].cost=a[i].cost;
                        a[i+1].war=a[i].war;
                }
                a[p].name=n;
                a[p].color=c;
                a[p].brand=b;
                a[p].cost=co;
                a[p].war=w;
                size++;
                return 1;
        }
}
int CList :: searchByElement(string n)
{
        int flag=0,i;
        for(i=0;i<size;i++)
        {
                if(a[i].name==n)
                {
                        flag=1;
                        return i+1;
                }
        }
        if(flag==0)
                return -1;
}
int CList :: deleteAfterElement(string e)
{
        int s;
        s=searchByElement(e);
        int p,i;
        p=s-1;
        if(s==-1)
                return -3;
        else
        {
                if(isEmpty()==1)
                        return -1;
                else if(p<0 || p>=size)
                        return -2;
                else if(p==size-1)
                {
                        a[p].name=-1;
                        a[p].color=-1;
                        a[p].brand=-1;
                        a[p].cost=-1;
                        a[p].war=-1;
                        size--;
                        return 1;
                        }
                else
                {
                        for(i=p+1;i<=size-1;i++)
                        {
                                a[i].name=a[i+1].name;
                                a[i].color=a[i+1].color;
                                a[i].brand=a[i+1].brand;
                                a[i].cost=a[i+1].cost;
                                a[i].war=a[i+1].war;
                        }
                        size--;
                        a[size].name=-1;
                        a[size].color=-1;
                        a[size].brand=-1;
                        a[size].cost=-1;
                        a[size].war=-1;
                        return 1;
                }


        }
}
int CList::searchByPosition(int p)
{
        if (p<0 || p>size-1)
                return -1;
        else
        {
                p=p-1;
                a[p].display();
                return 1;
        }
 }
 int main()
{
        int cap,s,ch;
        cout<<"============================================"<<endl;
        cout<<"PERFORM LIST ADT FOR HOME APPLIANCES LIST"<<endl;
        cout<<"============================================"<<endl;
        cout<<"ENTER CAPACITY : ";
        cin>>cap;
        cout<<"ENTER SIZE :";
        cin>>s;
        CList l(cap,s);
    do
    {
         cout<<"1.INSERT\n2.DELETE\n3.SEARCH\n4.DISPLAY\n5.EXIT\n";
         cout<<"Enter your choice:";
         cin>> ch;
         switch(ch)
         {
                case 1:
                {
                        int w;
                        string n,c,b;
                        float co;
                        int ch;
                        cout<<"Enter details to be inserted:"<<endl;
                        cout<<"Name :";
                        cin>>n;
                        cout<<"Color :";
                        cin>>c;
                        cout<<"Brand :";
                        cin>>b;
                        cout<<"Price :";
                        cin>>co;
                        cout<<"Years of Warranty :";
                        cin>>w;
                        cout<<"1.At Front\n2.At End\n3.At Position\n";
                        cout<<"Enter your choice:";
                        cin>>ch;
                        switch(ch)
                        {
                                case 1:
                                        {
                                                int res;
                                                res=l.insertAtFront(n,c,b,co,w);
                                                if(res==1)
                                                        cout<<"INSERTED SUCCESSFULLY\n";
                                                else
                                                        cout<<"LIST IS FULL\n";
                                               break;
                                        }
                                case 2:
                                        {
                                                int res;
                                                res=l.insertAtEnd(n,c,b,co,w);
                                                if(res==1)
                                                        cout<<"INSERTED SUCCESSFULLY\n";
                                                else
                                                        cout<<"LIST IS FULL\n";
                                                break;
                                        }
                                 case 3:
                                        {
                                                int pos;
                                                int res;
                                                cout<<"Enter position to insert the appliances list :";
                                                cin>>pos;
                                                res=l.insertAtPos(pos,n,c,b,co,w);
                                                if(res==1)
                                                        cout<<"INSERTED SUCCESSFULLY\n";
                                                else if(res==-2)
                                                        cout<<"POSITION IS OVER A LIMIT\n";
                                                else
                                                        cout<<"LIST IS FULL\n";
                                                break;
                                        }
                        }
                        break;
                }
                case 2:
                {
                        int ch;
                        cout<<"1.At Front\n2.At End\n3.After Element\n";
                        cout<<"Enter your choice:";
                        cin>>ch;
                        switch(ch)
                        {
                                case 1:
                                        {
                                                int res;
                                                res=l.deleteAtFront();
                                                if(res==1)
                                                        cout<<"DELETED SUCCESSFULLY\n";
                                                else
                                                        cout<<"LIST IS EMPTY\n";
                                                break;
                                        }
                                case 2:
                                        {
                                                int res;
                                                res=l.deleteAtEnd();
                                                if(res==1)
                                                        cout<<"DELETED SUCCESSFULLY\n";
                                                else
                                                        cout<<"LIST IS EMPTY\n";
                                                break;
                                        }
                                case 3:
                                        {
                                                int res;
                                                string val;
                                                cout<<"Enter Appliaces name to delete after Appliances list:";
                                                cin>>val;
                                                res=l.deleteAfterElement(val);
                                                if(res==1)
                                                        cout<<"DELETED SUCCESSFULLY\n";
                                                else if(res==-1)
                                                        cout<<"LIST IS EMPTY\n";
                                                else if(res==-3)
                                                        cout<<"ELEMENT NOT FOUND\n";
                                                else
                                                        cout<<"NEXT ELEMENT IS EMPTY HENCE DELETION NOT POSSIBLE";
                                                break;
                                        }
                        }
                        break;
                }
                case 3:
                {
                        int ch;
                        cout<<"1.BY ELEMENT\n2.BY POSITION\n";
                        cout<<"Enter your choic:";
                        cin>>ch;
                        switch(ch)
                        {
                                  case 1:
                                  {
                                            int res;
                                            string val;
                                            cout<<"Enter Appliances name to search:";
                                            cin>>val;
                                            res=l.searchByElement(val);
                                            if(res!=-1)
                                                      cout<<"Appliances list found at "<<res<<endl;
                                            else
                                                      cout<<"Appliances list is not found"<<endl;
                                            break;
                                   }
                                   case 2:
                                   {
                                             int res;
                                             int pos;
                                             cout<<"Enter position to search :";
                                             cin>>pos;
                                             res=l.searchByPosition(pos);
                                             if(res==-1)
                                                      cout<<"Position not found";
                                             break;
                                    }

                          }
                }
                case 4:
                {
                           l.display();
                           break;
                }
        }
    }while(ch<5);
        return 0;
}
