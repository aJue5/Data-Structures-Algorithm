#include<iostream>

using namespace std;
class link_list       //defining class called link_list.
{
private:         //only accessed by the functions in this classl.
struct node      //creating a node.
{
subject data;     //store data in the node(data part).
node*next;        //node points another node.
}*head;         //head node pointer.

public:        //this is where the function go.
link_list()         //constructor function to set default value.
{
head=NULL;       //set head to null.
}

void insert(subject x);     //add a node and place a subject value.
void deletenode(subject x);    //delete a node.
node* gethead(){            //return the first element in the list.
	return head;
}

void sethead(node* p)       //set the head node with the value what pointer p is pointing to.
{
	 head=p;                //head is pointing to the same thing what p is pointing to.
}
}; // end of class

void link_list::insert(subject x)      // constructor function.
{
	node *temp;           //create a node pointer.
	temp=new node;       //that node pointer '*temp' points new node.
	temp->data=x;        //temp is pointing to the data node and set its value as x.
	temp->next=head;      //to find the node, temp is pointing to,access its next element,and make the element point to the first element(head).
	head=temp;
}

void link_list::deletenode(subject x)           //constructor function.
{
int n,p=0;
node *list,*temp;        //clear 2 node pointers.
list=head;                // pointer list is pointing the same thing what pointer head is pointing to .
if(list == NULL)
return;
while(list->next != NULL)     //next element of the list is not null.
{
	if(list->next->data.code == x.code)
	{
		temp=list->next;       //temporary pointer is pointing to the next node of the list.
		list->next=list->next->next;    //list pointer is pointing the last node of the list.
		delete(temp);                   //delete the current node.
		return;
	}
} //end of while
cout<<"Subject is not present";
} //end of void link_list
