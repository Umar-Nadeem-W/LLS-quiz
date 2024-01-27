#include <iostream>
using namespace std;


int number = 31;

class node{

private:

    int val;
    node* next_node;
    node* previous_node;

public:
void setval(int v){val = v;}
void set_next_node(node* nn){next_node = nn;}
void set_previous_node(node* pn){previous_node = pn;}

int getval (){return val;}
node* get_next_node(){return next_node;}
node* get_previous_node(){return previous_node;}

};


class linked_list{


public:

        node* header;
        node* last_current_node;
        node* current_node;
        node* tail_node;
        int list_size;


linked_list(){
header->set_next_node(NULL);
header->setval(-1);
current_node = NULL;
last_current_node = NULL;
tail_node = NULL;
list_size = 0;
}


void create_list(int x){

current_node = header;
int i = x;
while ((number > 30) && (i < number) )
    {
    node* newnode = new node();
    newnode->setval(i);
    newnode->set_next_node(NULL);
    tail_node = newnode;
    if ( (i ==1) || (i==2) ){newnode->set_previous_node(NULL);}
    else{newnode->set_previous_node(current_node);}
    current_node->set_next_node(newnode);
   current_node = current_node->get_next_node();
    i = i + 2;
    list_size++;
    }
if (number <= 30) {cout <<"USER ERROR:  Number must be greater than 30";}

}


void display_list(){

cout<<"The list is displayed below."<<endl;
current_node = header;

for (int i = 1; i<=list_size; i++)
    {
        current_node = current_node->get_next_node();
        cout <<current_node->getval()<<", ";
    }

}

void addresval(int x)
{
node* newnod = new node();
newnod->setval(x);
newnod->set_next_node(NULL);
current_node->set_next_node(newnod);
current_node = current_node->get_next_node();
list_size++;
}


friend int addinglists (linked_list l1, linked_list l2);

};

linked_list resultlist;

int addinglists(linked_list la, linked_list lb)
{
    int ret;
     int ls1 = la.list_size;
     int ls2 = lb.list_size ;
    


la.current_node =la.header->get_next_node();
lb.current_node = lb.tail_node;


ret = la.current_node->getval() + lb.current_node->getval();
la.current_node = la.current_node ->get_next_node();
lb.current_node = lb.current_node ->get_previous_node();
return ret;
}






int main(){

cout<<"Please enter the number"<<endl;
cin>>number;

linked_list oddlist;
oddlist.create_list(1);
linked_list evenlist;
evenlist.create_list(2);

oddlist.display_list();
evenlist.display_list();



return 0;
}


