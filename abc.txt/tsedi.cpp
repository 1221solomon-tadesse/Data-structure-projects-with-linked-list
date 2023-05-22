/*****->>"Title ASTU CSE department and software program student registration"**********.
*Section 10*********Group:20
    *Group Members********ID number  
     1.Tsdenia Sisay *******UGR/26316/14
     2.Mihret  Lealem *******UGR/25335/14
     3.Mihret  Habitamu ******UGR/25499/14
     4.Mistre  Seyoum ******UGR/25559/14
     5.Tekle_mariam  Girma ***UGR/25641/14
   ---------------------------------------------------
   */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
struct node{ //used to create doubly linked list of nodes
    //data
    string Name;
    string Email;
    string Id_number;
    string Department;
    //node pointer/
    node *prev, *next;
};
//external pointer //head is the same with start node

node *start_node = NULL;
void savefile(),openfile();

node *head, *temp1, *temp2, *npt1, *currentNode;
void logo(){
cout<< "\t ******************************************************* " <<endl;
cout<< "\t *      ADAMA SCIENCE AND TECHNOLOGY UNIVERSITY        * " <<endl;
cout<< "\t *          SCHOOL OF ELECTRICAL ENGINEERING           * " <<endl;
cout<< "\t *                   AND COMPUTING                     * " <<endl;
cout<< "\t ******************************************************* " <<endl;
cout<< "\t ******************************************************* " <<endl;
cout<< "\t *    Project on Data Structure and Algorithm          * " <<endl;
cout<< "\t *                                                     * " <<endl;
cout<< "\t ******************************************************* " <<endl;
cout<<"\t\t      _   _   _   _   _   _   _  "<<endl;
cout<<"\t\t     / \\ / \\ / \\ / \\ / \\ / \\ / \\ "<<endl;
cout<<"\t\t    (  S | t | u | d | e | n | t )"<<endl;
cout<<"\t\t     \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ "<<endl;
cout<<"\t\t  _   _   _   _   _   _   _   _   _  _    _    _     "<<endl;
cout<<"\t\t / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\"<<endl;
cout<<"\t\t( r | e | g | i | s | t | r | a | t| i  | o | n   )"<<endl;
cout<<"\t\t \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/" <<endl;
cout<<"\t              _   _   _   _   _   _  "<<endl;
cout<<"\t\t     / \\ / \\ / \\ / \\ / \\ / \\  "<<endl;
cout<<"\t\t    ( S | y | s | t | e | m )"<<endl;
cout<<"\t\t     \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ "<<endl;
}
void RegisterAtFirst(){
    temp1 = new node;
    cout<<"\t\tEnter name: ";
    cin>>temp1->Name;
    cout<<"\t\t:Enter Id number ";
    cin>>temp1->Id_number;
    cout<<"\t\t Enter Email Address: ";
    cin>>temp1->Email;
    cout<<"\t\tEnter Department : ";
    cin>>temp1->Department;
    cout<<"\t\tRegistered successfully :)\n";


    if(start_node == NULL){
        temp1->next=NULL;
        start_node = temp1;
    }
    else{
        temp1->next=start_node;
        start_node = temp1;
    }
    system("cls");
}
void RegisterAtEnd(){
    temp2 = new node;
    cout<<"\tEnter name: ";
    cin>>temp2->Name;
    //getline(cin, temp2->Name);
    cout<<"\tEnter Id_number: ";
    cin>>temp2->Id_number;
    cout<<"\tEnter Email address ";
    cin>>temp2->Email;
    cout<<"\tEnter Department: ";
    cin>>temp2->Department;
    cout<<"\tRegistered successfully :)\n";

    temp2->next=NULL;

    if(start_node==NULL){
        start_node = temp2;
        return;
    }node *last = start_node;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=temp2;

}
void registration(){
    int regOption;
    cout<<"\t-------------------------------------------"<<endl;
    cout<<"\t-----------Registration form--------------"<<endl;
    cout<<"\t\t1. Register at first ""for SE student""."<<endl;
    cout<<"\t\t2. Register at end ""for cse student""."<<endl;
    cout<<"\t\t   Enter your option: ";
    cin>>regOption;
    cout<<"\t-------------------------------------------"<<endl;
    cout<<"\t-------------------------------------------"<<endl;


    if(regOption==1){
        RegisterAtFirst();
    }
	else if(regOption==2){
        RegisterAtEnd();
    }
    else{
        cout<<"\t\tWrong Input! \n\t\tPlease Try Again!\n";
    }
    
    system("cls");
	}
void searchById(){
    //search by Id
    string targetId;
    cout<<"\t\tEnter ID_number: ";
	cin>>targetId;
	if (start_node != NULL) {
		// list is not empty
		currentNode = start_node;
		if (start_node->Id_number == targetId)  {
			cout<<"\t---------------------------------------------\n";
			cout<<"\t\tName : "<<currentNode->Name<<endl;
			cout<<"\t\tId_number: "<<currentNode->Id_number<<endl;
            cout<<"\t\tEmail : "<<currentNode->Email<<endl;
            cout<<"\t\tDepartment : "<<currentNode->Department<<endl;
		}
	else {
			node *prev = NULL;
			while (currentNode != NULL && currentNode -> Id_number != targetId) {
				prev = currentNode;
				currentNode = currentNode->next;
			}
			if (currentNode != NULL) {
				cout<<"\t---------------------------------------------\n";
				cout<<"\t\tName : "<<currentNode->Name<<endl; //data
				cout<<"\t\tId_number: "<<currentNode->Id_number<<endl; //data
                cout<<"\t\tEmail : "<<currentNode->Email<<endl; //data
                cout<<"\t\tDepartment : "<<currentNode->Department<<endl; //data
			}
				else{
	            cout<<"\t\t"<<targetId<<" Not Found!"<<endl;
	        }
		}
	}
		else{
	    cout<<"\t\t"<<targetId<<" Not Found!"<<endl;
	}
}
void groupMembers(){
    cout<<"\t----------------------------------------------------"<<endl;
    cout<<"\t----------------------------------------------------"<<endl;
    cout<<"\t\t *Section 10*         "<<setw(20)<<"Group:20"<<endl;
    cout<<"\t\t *Group Members*      "<<setw(20)<<"ID number"<<endl;
    cout<<"\t\t1. Tsdenia Sisay       "<<setw(20)<<"UGR/26316/14"<<endl;
    cout<<"\t\t2. Mihret  Lealem      "<<setw(20)<<"UGR/25335/14"<<endl;
    cout<<"\t\t3. Mihret  Habitamu    "<<setw(20)<<"UGR/25499/14"<<endl;
    cout<<"\t\t4. Mistre  Seyoum       "<<setw(20)<<"UGR/25559/14"<<endl;
    cout<<"\t\t5. Tekle_mariam  Girma"<<setw(20)<<"UGR/25641/14"<<endl;
    cout<<"\t----------------------------------------------------"<<endl;
    cout<<"\t----------------------------------------------------"<<endl;
}
void display_data(){
    //print all  information
    if(start_node == NULL){
    	cout<<"\t\t***There is no registration found!***\n";//list is empty
	}    
    else {
        npt1 = start_node;
        while(npt1 != NULL){
            cout<<"\t--------------------------------------------\n";
            cout<<"\t\tName : "<<npt1->Name<<endl; //data
            cout<<"\t\tId_number: "<<npt1->Id_number<<endl; //data
            cout<<"\t\tEmail : "<<npt1->Email<<endl; //data
            cout<<"\t\tDepartment : "<<npt1->Department<<endl; //data
            npt1 = npt1->next; //node
        }
    }
}
	void exitProgram(){
    savefile();
    system("exit");
}
void removeById() {
	// check case 1
	string targetId;
	cout<<"\t\tEnter Id_number to remove from file: ";
	cin>>targetId;
	if (start_node != NULL) {
		// list is not empty
		// need to traverse list, stopping at the last node
		currentNode = start_node;
		// check case 2... the node to delete is the first node
		if (start_node->Name == targetId)  {
			start_node = start_node->next;
			delete currentNode;
		}
		else { // case 3... the node to delete is not the first node, but might not even be in the list
			node *prev = NULL;
			while (currentNode != NULL && currentNode -> Id_number!= targetId) {
				prev = currentNode;
				currentNode = currentNode->next;
			}
			// check if we found targetValue
			if (currentNode != NULL) {
				// did find it
				prev->next = currentNode->next;
				delete currentNode;
			}
		}
	}}
void menu(){
    int menuOption;
    cout<<"\t----------------------------------------------------"<<endl;
    cout<<"\t------------------------Student regisstration application------------------------"<<endl;
    cout<<"\t----------------------------------------------------"<<endl;
    cout<<"\t\t1.Register student "<<endl;//done
    cout<<"\t\t2. Search student by Id"<<endl;
    cout<<"\t\t3. Delete student by Id"<<endl;
    cout<<"\t\t4. display all data"<<endl;//done
    cout<<"\t\t5. About"<<endl;//done
    cout<<"\t\t6. save and Exit"<<endl;//done
    cout<<"\t\tEnter your option: ";
    cin>>menuOption;
    system("cls");

    switch(menuOption){
        case 1:
            registration();
            menu();
            break;

        case 2:
            searchById();
            menu();
            break;

        case 3:
            removeById();
            menu();
            break;
            case 4:
            openfile();
            display_data();
            menu();
            break;

        case 5:
            groupMembers();
            menu();
            break;

        case 6:
            exitProgram();
            break;

        default:
            cout<<"\tWrong Input\n";
            cout<<"\tTry Again...\n";
            menu();
            break;
    }
}
void savefile(){
    ofstream my;
    my.open("Registration_data.txt",ios::app);
    node *start=start_node;
  while(start != NULL){
    my<<start->Name<<endl<<start->Id_number<<endl<<start->Email<<endl<<start->Department<<endl<<"----------------------------------------------------"<<endl;
  start= start->next;
  }
}
void openfile(){
string line;
ifstream my("Registration_data.txt");
if(my.is_open()){
    temp1=new node;
    int i=0,l=0;
    while(getline(my,line)){
         ++l;
         if(4*(i+1)+1==l){++i;
              temp1->next=NULL;
    if(start_node==NULL){
        start_node = temp1;
        return;
    }
    node *last = start_node;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=temp1;
          temp1=new node;}
        if(4*(i+1)-3==l){temp1->Name=line;}
       else if(4*(i+1)-2==l){temp1->Id_number=line;}
       else if(4*(i+1)-1==l){temp1->Email=line;}
       else if(4*(i+1)==l){temp1->Department=line;}}

           temp1->next=NULL;
    if(start_node==NULL){
        start_node = temp1;
        return;
    }
    node *last = start_node;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=temp1;
       }}

int main(){
    system("color b");
    openfile();
    logo();
    menu();

    return 0;
}
