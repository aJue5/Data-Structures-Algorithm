#include<iostream>
#include<cstdlib>  // to declare system
#include"Queue.h"
#include"Stack.h"
#include"LinkedList.h"

using namespace std;


void welcome_scr(); // void function for the welcome screen
queue showSortedSubjects(queue qu); // to view sorted subjects in queue

int main()
{
    welcome_scr(); // calling the welcome screen

	struct subject s; // subject with the object s
	struct student st,temp_st; //student with object st and temp_st used for username and password.
	stack stk1,stk2; // stack with object stk1, stk2
	queue q,u; //queue with the object q and u
	link_list link; // linkedList with the object link

	int sum=0; // sum initialized to 0
    int position=0,choice=0; //position of admin and student initialized to 0 and the choice for admin page initialized to 0

	string uname,pwd; // string is the data type of username and password
	char ch; // character data type for ch

	while(1) // while true
	{
		cout<<"\n 1. Admin\n 2. Student\n 3. Exit\n\n Key in your choice : ";
		cin>>position;


                try{
                    if(position <1 || position >3 ) // if the choice is <1 or >3 the program will gently show error message and terminate

                            throw position;

                    }
                    catch(int r)
                    {
                        system("cls");
                        cout<<"\n\n\nInvalid Input! Program will now end.\n\n";
                        return 0;

                    }


		if(position == 3)
		{
			return 0; // exits the system
		}
		if(position == 1 || position == 2) // if position is chosen either 1 or 2 system prompts user to input username & password
		{   system("cls");
			cout<<"\nKey in username : ";
			cin>>uname;
			cout<<"\nKey in password : ";
			cin>>pwd;

system("cls"); //clears screen

			if(position == 1) // admin
			{
				if(uname == "admin" && pwd == "admin")
				{ 	cout<<  "\n\n Login successful .\n\n";
                    system("pause");
					system("cls");

					while(1) // while true
					{
						cout<<"\n\n1. Add Student\n2. Add Subject\n3. Previous Menu\n\n Key in your choice : ";
						cin>>choice;
						if(choice == 3) // moves to position choosing page

							break;

						switch(choice)
						{
							case 1:
                                system("cls");
								cout<<"\nKey in username for new student  : ";
								cin>>st.uname;
								cout<<"\nKey in password for new student  : ";
								cin>>st.pwd;
								stk1.push(st); // add student password into the stack
								cout<<"\nKey in study year : ";
								cin>>st.year;
								cout<<"\n Login credentials successfully added.\n\n";
								system("pause");
								system("cls");
								break;
							case 2:
							    system("cls");
								cout<<"\nKey in subject code : ";
								cin>>s.code;
								cout<<"\nKey in subject name : ";
								cin>>s.name;
								cout<<"\nKey in subject hour : ";
								cin>>s.hour;
								if(!(s.hour)){ // ignores invalid input for credit hour by terminating the system
								cout<<"\n\n Invalid input,only digits are allowed!\n\n ";
								return 0;}
                                cout<<"\nKey in subject day : ";
								cin>>s.day;
								cout<<"\nKey in subject time : ";
								cin>>s.time;
								cout<<"\nKey in subject venue : ";
								cin>>s.venue;
								q.insert(s); // adding subject details into queue (function void insert(subject x))
								cout<< "\nSubject details successfully added.\n\n";
								system("pause");
								system("cls");
								break;
                            case 3:
                                break;
                            default:
                                system("cls");
                                cout<< "\n\n\nInvalid Input! Program will now end.\n\n"; // for choice other than 1,2 and 3
                                return 0;

						} // end of switch
					} // end of while (while true)
				} // end of if (admin details)
				else
				{  // system("pause");


					cout<<"\n Invalid login\n\n"; // invalid login message for wrong details of admin and student login
					system("pause");
                   system("cls");
				}
			}// end of if (position 1)


			if(position==2)
		{
                //validate student by popping from stack using sequential search
				int flag=0; // to signalize true or false initialized to 0
				stk2=stk1; //stk1 is assigned to stk2
				int len=stk2.getTop(); // top of the stk2 is assigned to len
				for(int i=0;i<=len;i++)
				{
					temp_st=stk2.pop(); // uname & pwd given by admin for student assigned to temp.st
					if(temp_st.uname == uname && temp_st.pwd == pwd) // student entered uname and pwd same with admin given uname and pwd
					{
						flag=1; //valid login
						break;
					}
				}
				if(flag==0) // not true
				{
					cout<<"\n Invalid login\n\n";
					system("pause");
                    system("cls");

				}
				else
				{
					//shows all subjects here sorted by credit hour
					cout<<"\n Study year : "<<st.year<<"\n\n";
					while(1) //while true
					{
						q=showSortedSubjects(q);
						u=q;          // the sorted result store to u
						sum=0;          // set sum to 0
						int len=u.length();
						subject array[MAX];   //create array to MAX
						for(int i=0;i<len;i++)
						{

                            array[i]=u.delet();     //to get the front value
						}
						cout<<"\n\n(If no subject added, press any digits to view main page)\n\n";
						cout<<"\n\nSelect a subject : ";
						cin>>choice;
						if(choice<1 || choice>len)
						{

						    //system("pause");
						    cout<<"\n\n Invalid digit input, Program will now end. \n\n ";
							return 0;

						}
						else if (!(choice))
						{
                            cout<< "\n\n\nInvalid Input! \n\n"; // for choice other than 1
                            return 0;
                        }

						{
							int chc;
							cout<<"\n1. Add Subject\n2. Delete Subject\n3. Confirm\n4. Log Out\n\n Enter your choice: ";
							cin>>chc;
							if(chc == 3) // choice = 3
							{
								sum=0; // sum initialized to 0
								system("pause");
                                system ("cls");
								cout<<"\n Registered Subject List: "<< st.year<<" year\n";;
                                cout<<"-------------------------------------------------------------------------------";
                                cout<<"\n\nCODE \tNAME \t C.HOUR\tDAY \tTIME \tVENUE\n";
                                cout<<"-------------------------------------------------------------------------------";

								while(link.gethead()!=NULL) // while head is not null
								{
									sum=sum+(link.gethead()->data.hour);//receives data of hour
									cout<<"\n"<<link.gethead()->data.code<<"\t"<<link.gethead()->data.name<<"\t"<<link.gethead()->data.hour<<"\t"<< link.gethead()->data.day<<"\t"<<link.gethead()->data.time<<"\t"<<link.gethead()->data.venue<<"\t";
									link.sethead(link.gethead()->next);
								}
								if(sum<10 || sum>20 )
								{
											cout<<"\n\n\n Credit Hours should be between 10 to 20.\n\n";
											cout<<"\n Your Total Credit Hour(s) = "<<sum<<". Changes are needed.\n\n";

								}
								else
								{
									cout<<"\n\nYour Total Credit Hours = "<<sum<<"\n\n Subject Registered. \n\n";
                                        system("pause") ;
									     system ("cls");
									break;
								}
							} //end of if
							if(chc == 4) // logout
							{
                                    main(); // moves to main page
                                    return 0;
							}
							switch(chc)
							{
								case 1:
									link.insert(array[choice-1]);
									cout<< "\nSuccessfully added.\n";
									break;


								case 2:
									link.deletenode(array[choice-1]);
									cout<< "\nSuccessfully deleted.\n";
									break;

							} //end of switch
							if(chc<1 || chc>4) // logout
							{     system("cls");
                                  cout<< "\n\n\nInvalid Input! Program will now end.\n\n"; // for choice other than 1,2,3 and 4
                                  return 0;
							}

                      } //end of else

					} //end of while

				} //end of else

		} // end of if (position 2)

	} // end of if (position 1 or position 2 choice)

    else{
              if(!(cin>>position)) {

        return 0;
   }

        cout<<"\n\nInvalid position number, please enter again.\n\n";
        system("pause"); // system pauses until a key is pressed
        main(); // moves to main page

    }



} //end of while (main page)

	return 0;
} // end of main
queue showSortedSubjects(queue qu)
{
	int len=qu.length();
    subject tmp,min;    //create subject with object tmp, min
	queue e;   //create object e with queue

	for(int i=1;i<=len;i++)
	{
		min=qu.delet();     //to ensure the lowest number
		for(int j=1;j<=(len-i);j++)
		{

			tmp=qu.delet();  //to ensure the number to swap
			if(min.hour > tmp.hour)
			{
				qu.insert(min); //min insert to queue qu
				min=tmp;   //tmp assign to min
			}
			else
			{
				qu.insert(tmp); //if false tmp no changes
			}
		}
		e.insert(min); //insert min to e
	} //end of for loop
	qu=e;   // e assign to qu
                    system ("pause");
                    system ("cls");
					cout<<"\n Subject List:\n";
					cout<<"-------------------------------------------------------------------------------";
					cout<<"\n\nS.No\tCODE \tNAME \tC.HOUR \t DAY \tTIME \tVENUE\n";
					cout<<"-------------------------------------------------------------------------------";
					for(int i=1;i<=len;i++)
					{
						tmp=qu.delet();
						cout<<"\n"<<i<<"\t"<<tmp.code<<"\t"<<tmp.name<<"\t"<<tmp.hour<<"\t"<<tmp.day<<"\t"<<tmp.time<<"\t"<<tmp.venue;
					}
	return e;
}
void welcome_scr() // design of welcome screen
{   system("cls");
    cout << "\n\n\n\n                 **************************************************" << endl;
	cout << "                 *************  Subject               *************" << endl;
	cout << "                 *************       Registration     *************" << endl;
	cout << "                 *************                System  *************" << endl;
	cout << "                 **************************************************" << endl;
	cout << "                           Multimedia University (Malacca) \n\n\n";

}










