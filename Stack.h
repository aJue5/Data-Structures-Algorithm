#include<iostream>
# define MAX 10 // Maximum size of stack
# define NULL 0
using namespace std;

 typedef struct student
{
	string uname;
	string pwd;
	string year;
}student; // student username && student password

class stack
{
student s[MAX]; // student with object s declared in array of MAX = 10
int top; // index to top of the stack

public:
stack()
{
	top=-1; // remove the items from top
}

void push(student);
student pop();
int getTop();
}; //end of class

void stack::push(student z) //Push Operation
{
if(top<MAX)
 {
  top=top+1; //add items to top
  s[top]=z; // added items pushed/placed on top
 }
else
cout<<"stack overflows..."<<endl;
}

student stack::pop() //Pop Operation
{
int item;
if(top>=0) // if stack is not empty
 {
  return s[top--]; //removes item from top of stack
 }
 else
 cout<<endl<<"stack underflows"<<endl;
}
int stack::getTop() //To find the top of the stack
{
	return top;
}
