//Title Contact directory system with address
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
/*  Group Members			ID number
    1.Mohammed Jafar   		    UGR/22624/13
    2.Mulatu Shiferaw			UGR/23486/13
    3.Degife Fura				UGR/22944/13
    4.Habtamu Tadesse			UGR/22737/13
    5.Fuad umer        		    UGR/23250/13
                Section 5;
                group 10;
    */
using namespace std;
struct node{ //used to create doubly linked list of nodes
    //data
    string Name;
    string Email;
    string Gender;
    string phoneNumber;
    //node pointer/
    node *prev, *next;
};
//external pointer //head is the same with start node

node *start_node = NULL;
void savefile(),openfile();

node *temp1, *temp2, *npt1, *currentNode;
void logo(){
cout<<"\t\t      _   _   _   _   _   _   _  "<<endl;
cout<<"\t\t     / \\ / \\ / \\ / \\ / \\ / \\ / \\ "<<endl;
cout<<"\t\t    ( C | o | n | t | a | c | t )"<<endl;
cout<<"\t\t     \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ "<<endl;
cout<<"\t\t  _   _   _   _   _   _   _   _   _     "<<endl;
cout<<"\t\t / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\"<<endl;
cout<<"\t\t( D | i | r | e | c | t | o | r | y )"<<endl;
cout<<"\t\t \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/"<<endl;
cout<<"\t              _   _   _   _   _   _  "<<endl;
cout<<"\t\t     / \\ / \\ / \\ / \\ / \\ / \\  "<<endl;
cout<<"\t\t    ( S | y | s | t | e | m )"<<endl;
cout<<"\t\t     \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ "<<endl;
}
void SaveAtFirst(){
    temp1 = new node;
    cout<<"\t\tEnter name: ";
    cin>>temp1->Name;
    cout<<"\t\tEnter Email Address: ";
    cin>>temp1->Email;
    cout<<"\t\tEnter Gender: ";
    cin>>temp1->Gender;
    cout<<"\t\tEnter phone number: ";
    cin>>temp1->phoneNumber;
    cout<<"\t\tBooked successfully :)\n";


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
void SaveAtEnd(){
    temp2 = new node;
    cout<<"\tEnter name: ";
    cin>>temp2->Name;
    //getline(cin, temp2->Name);
    cout<<"\tEnter Email Address: ";
    cin>>temp2->Email;
    cout<<"\tEnter Gender: ";
    cin>>temp2->Gender;
    cout<<"\tEnter phone number: ";
    cin>>temp2->phoneNumber;
    cout<<"\tBooked successfully :)\n";

    temp2->next=NULL;

    if(start_node==NULL){
        start_node = temp2;
        return;
    }
    node *last = start_node;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=temp2;

}
void registration(){
    int regOption;
    cout<<"\t-------------------------------------------"<<endl;
    cout<<"\t-----------Save Menu--------------"<<endl;
    cout<<"\t\t1. Save at first."<<endl;
    cout<<"\t\t2. Save at end."<<endl;
    cout<<"\t\t   Enter your option: ";
    cin>>regOption;
    cout<<"\t-------------------------------------------"<<endl;
    cout<<"\t-------------------------------------------"<<endl;


    if(regOption==1){
        SaveAtFirst();
    }
    else if(regOption==2){
        SaveAtEnd();
    }
    else{
        cout<<"\t\tWrong Input! \n\t\tPlease Try Again!\n";
    }
    system("cls");

}
void searchByName(){
    //search by name
    string targetName;
    cout<<"\t\tEnter contact Name: ";
	cin>>targetName;
	if (start_node != NULL) {
		// list is not empty
		currentNode = start_node;
		if (start_node->Id_number == targetName)  {
			cout<<"\t---------------------------------------------\n";
			cout<<"\t\tName : "<<currentNode->Name<<endl;
			cout<<"\t\tGender: "<<currentNode->Gender<<endl;
            cout<<"\t\tEmail : "<<currentNode->Email<<endl;
            cout<<"\t\tPhone Number : "<<currentNode->phoneNumber<<endl;
		}
		else {
			node *prev = NULL;
			while (currentNode != NULL && currentNode -> Name != targetName) {
				prev = currentNode;
				currentNode = currentNode->next;
			}
			if (currentNode != NULL) {
				cout<<"\t---------------------------------------------\n";
				cout<<"\t\tName : "<<currentNode->Name<<endl; //data
				cout<<"\t\tGender: "<<currentNode->Gender<<endl; //data
                cout<<"\t\tEmail : "<<currentNode->Email<<endl; //data
                cout<<"\t\tPhone Number : "<<currentNode->phoneNumber<<endl; //data
			}
			else{
	            cout<<"\t\t"<<targetName<<" Not Found!"<<endl;
	        }
		}
	}
	else{
	    cout<<"\t\t"<<targetName<<" Not Found!"<<endl;
	}
}
void removeByName() {
	// check case 1
	string targetName;
	cout<<"\t\tEnter contact's Name: ";
	cin>>targetName;
	if (start_node != NULL) {
		// list is not empty
		// need to traverse list, stopping at the last node
		currentNode = start_node;
		// check case 2... the node to delete is the first node
		if (start_node->Name == targetName)  {
			start_node = start_node->next;
			delete currentNode;
		}
		else { // case 3... the node to delete is not the first node, but might not even be in the list
			node *prev = NULL;
			while (currentNode != NULL && currentNode -> Name != targetName) {
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
	}
}
void groupMembers(){
    cout<<"\t----------------------------------------------------"<<endl;
    cout<<"\t----------------------------------------------------"<<endl;
    cout<<"\t\t *Section 5*  "<<setw(20)<<"Group:10"<<endl;
    cout<<"\t\t *Group Members*  "<<setw(20)<<"ID number"<<endl;
    cout<<"\t\t1. Mohammed Jafar "<<setw(20)<<"UGR/22624/13"<<endl;
    cout<<"\t\t2. Mulatu Shiferaw"<<setw(20)<<"UGR/23486/13"<<endl;
    cout<<"\t\t3. Degife Fura	  "<<setw(20)<<"UGR/22944/13"<<endl;
    cout<<"\t\t4. Habtamu Tadesse"<<setw(20)<<"UGR/22737/13"<<endl;
    cout<<"\t\t5. Fuad umer      "<<setw(20)<<"UGR/23250/13"<<endl;
    cout<<"\t----------------------------------------------------"<<endl;
    cout<<"\t----------------------------------------------------"<<endl;
}
void display(){
    //print all  information
    if(start_node == NULL)
        cout<<"\t\t***There is no registration found!***\n";//list is empty
    else {
        npt1 = start_node;
        while(npt1 != NULL){
            cout<<"\t--------------------------------------------\n";
            cout<<"\t\tName : "<<npt1->Name<<endl; //data
            cout<<"\t\tGender: "<<npt1->Gender<<endl; //data
            cout<<"\t\tEmail : "<<npt1->Email<<endl; //data
            cout<<"\t\tPhone Number : "<<npt1->phoneNumber<<endl; //data
            npt1 = npt1->next; //node
        }
    }
}
void exitProgram(){
    savefile();
    system("exit");
}
void menu(){
    int menuOption;
    cout<<"\t----------------------------------------------------"<<endl;
    cout<<"\t------------------------MENU------------------------"<<endl;
    cout<<"\t----------------------------------------------------"<<endl;
    cout<<"\t\t1. Save Contact"<<endl;//done
    cout<<"\t\t2. Search Contact[by name]"<<endl;
    cout<<"\t\t3. Remove Contact[by name]"<<endl;
    cout<<"\t\t4. Show Contacts Directory"<<endl;//done
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
            searchByName();
            menu();
            break;

        case 3:
            removeByName();
            menu();
            break;

        case 4:
            openfile();
            display();
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
    my.open("Saved_Contacts.txt",ios::app);
    node *start=start_node;
  while(start != NULL){
    my<<start->Name<<endl<<start->Gender<<endl<<start->Email<<endl<<start->phoneNumber<<endl<<"----------------------------------------------------"<<endl;
  start= start->next;
  }
}
void openfile(){
string line;
ifstream my("Saved_Contacts.txt");
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
       else if(4*(i+1)-2==l){temp1->Gender=line;}
       else if(4*(i+1)-1==l){temp1->Email=line;}
       else if(4*(i+1)==l){temp1->phoneNumber=line;}}

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
    system("color a");
    openfile();
    logo();
    menu();

    return 0;
}












