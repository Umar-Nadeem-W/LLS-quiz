#include <iostream>
#include <windows.h>
#include <unistd.h>

using namespace std;

int siz1;
int siz2;
int totalsiz;

int current1 =0;
int current2;
void menu()
{
cout<<"Press 1: Push value on the LEFT side"<<endl;
cout<<"Press 2: Push value on the RIGHT side"<<endl;
cout<<"Press 3: Pop value from the LEFT side"<<endl;
cout<<"Press 4: Pop value from the RIGHT side."<<endl;
cout<<"Press 5: Top value of the LEFT side"<<endl;
cout<<"Press 6: Top value of the RIGHT side."<<endl;
cout<<"Press 7: Exit"<<endl<<endl;
}

class stck
{

private:
    int val;
    int* myarr = new int [totalsiz];

public:

    void push1(int a)
    {
    if (isfull1() == false)
    {
    myarr[current1] = a;
    current1++;
    }
    else cout<<"Stack 1 is full."<<endl;
    };

    int pop1()
    {
        if (isempty1() == false)
            {
            current1--;
            return myarr[current1];
            }
        else {cout<<"Stack 1 is empty.";}
    };

    int top1()
     {
        if (isempty1() == false)
            {
              return myarr[current1 - 1];
            }
        else {cout<<"Stack 1 is empty.";}
    };

    bool isempty1()
    {
        if (current1 <= 0){return true;}
        else {return false;}
    };
    bool isfull1()
   {

    if (current1 >= siz1){return true;}
        else {return false;}

   }


   bool isempty2()
   {
       if (current2 >= totalsiz)
        {
            return true;
        }
       else {return false;}
   }

   bool isfull2()
   {
    if (current2 < siz1)
        {return true;}
    else {return false;}
   }

int pop2()
{
    if(!isempty2())
        {
            current2++;
            return myarr[current2];
        }

else {cout<<"Stack 2 is empty.";}
}

void push2(int b)
{
    if(!isfull2())
        {
        myarr[current2] = b;
        current2--;
        }
    else{cout<<"Stack2 is full."<<endl;}
}

int top2()
{
if(!isempty2())
    {return myarr[current2 + 1];}

    else{cout<<"Stack2 is empty."<<endl;}
}


};




int main(){

cout <<"Please enter the size of the first stack."<<endl;
cin>>siz1;
cout<<"Please enter the size of the second stack."<<endl;
cin>>siz2;
totalsiz = siz1 + siz2;
current2 = totalsiz - 1;

stck s1;

int selection;
int check;

while (check != 99){
menu();
cin>>selection;
if (selection == 1){
        int j;
        cout<<"Please enter the value you wish to push."<<endl;
        cin>>j;
        s1.push1(j);
}

else if (selection == 2){
        int k;
        cout<<"Please enter the value you wish to push."<<endl;
        cin>>k;
        s1.push2(k);}
else if (selection == 3){cout<<s1.pop1()<<endl;}
else if (selection == 4){cout<<s1.pop2()<<endl;}
else if (selection == 5){cout<<s1.top1()<<endl;}
else if (selection == 6){cout<<s1.top2()<<endl;}
else if (selection == 7){check = 99;}
else {cout<<"Invalid selection"<<endl;}
sleep(1);
system("CLS");
}




return 0;
}

