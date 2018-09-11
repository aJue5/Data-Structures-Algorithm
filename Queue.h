#include<iostream>
# define MAX 100 //declare the array size to the max(100)

using namespace std;
typedef struct subject
{
	string code;
	string name;
	int hour;
	string day;
	string time;
	string venue;

}subject;
class queue
{
		subject stu_Q[MAX];
		int rear,front; //This 2 variable for record and mention the slot inside the queue
    public:
        queue()
        {
             rear=-1;
             front=-1;
        }
        void insert(subject x) //function to insert subject by admin
        {
            if(rear >  MAX-1)
            {
                 cout <<"queue over flow"; //overflow occur if the rear larger than the array size
                 front=rear=-1;
                 return;
            }
            stu_Q[++rear]=x; //insert the array by increasing the place of rear
            //front=rear;
        }

         subject delet() //function to delete subject
        {
			subject x;
            if(front==rear)
              {
                  cout <<"queue under flow";
                  return x;
              }
              ++front;
              x=stu_Q[front];
              return x;
        }
        int length() //function to take the difference between the rear and the front
        {
			return rear-front;
		}
}; // end of class
