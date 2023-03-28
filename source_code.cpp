#include<iostream>
using namespace std;

// Node Class
class Node {
public:
	int srno;
	string Name;
	string company;
	float condition;
	int price;
	int model;
	string reg;
	Node* next;
};
// Stores the head of the Linked List
Node* head = new Node();
// Check Function to check that if
// Record Already Exist or Not
bool check(int x)
{
	// Base Case
	if (head == NULL)
		return false;
	Node* t = new Node;
	t = head;
	// Traverse the Linked List
	while (t != NULL) {
		if (t->srno == x)
			return true;
		t = t->next;
	}
	return false;
}
// Function to insert the record
void Insert_Record(int srno, string Name,
				string company, float condition, int price, int model, string reg)
{

	// Create new Node to Insert Record
	Node* t = new Node();
	t->srno = srno;
	t->Name = Name;
	t->model = model;
	t->reg = reg;
	t->company = company;
	t->condition = condition;
	t->price = price;
	t->next = NULL;

	// Insert at Begin if head is empty
	{
	if(head==NULL)
	{
	head=t;
	t->next=NULL;
	}
	else //Insert at tail if head is occupied
	{
	t -> next = NULL;
	Node * tail = head;
	while(tail->next!=NULL)
	{
	tail=tail->next;
	}
	tail -> next = t;
	}}

	cout << "Record Inserted Successfully!"<<endl;
}

// Function to search record for any
// vehicles Record with srno number
void Search_Record(int srno)
{
	// if head is NULL
	if (!head) {
		cout << "No such Record Available!"<<endl;
		return;
	}

	// Otherwise
	else {
		Node* p = head;
		while (p) {
			if (p->srno == srno) {
				cout << endl;
				cout << "-------------------------------------------"<<endl;
				cout << "Serial Number: "<< p->srno <<endl;
				cout << "-------------------------------------------"<<endl;
				cout << "Name: "<< p->Name << endl;
				cout << "Company: "<< p->company << endl;
				cout << "Model Year: "<< p->model << endl;
				cout << "Registration Number: "<< p->reg << endl;
				cout << "-------------------------------------------"<<endl;
				cout << "Condition: "<< p->condition << endl;
				cout << "Price: "<< p->price << endl;
		    	cout << "-------------------------------------------"<<endl;
				return;
			}
			p = p->next;
		}

		if (p == NULL)
			cout << "No such Record Available!"<<endl;
	}
}

// Function to delete record vehicles
// record with given srno number
// if it exist
int Delete_Record(int srno)
{
	Node* t = head;
	Node* p = NULL;

	 // Deletion at Begin
	 if (t != NULL && t->srno == srno) {
	 	head = t->next;
	 	delete t;
	 	cout << "Record Deleted Successfully!"<<endl;
	 	return 0;
	 	}
	 		else if (t == NULL) {
		cout << "Record does not Exist!"<<endl;
		return -1;
		p->next = t->next;
}
}
// Function to display the vehicle's
// Record
void Show_Record()
{
	Node* p = head;
	if (p == NULL) {
		cout << "No Record Available!"<<endl;
	}
	else {

		// Until p is not NULL
		while (p != NULL) {
				cout << endl;
				cout << "-------------------------------------------"<<endl;
				cout << "             Serial Number: "<< p->srno <<endl;
				cout << "-------------------------------------------"<<endl;
				cout << "\tVehicle: "<< p->company<<" "<< p->Name << endl;
				cout << "Model Year: "<< p->model <<"Registration Number: "<< p->reg << endl;
				cout << "\tCondition: "<< p->condition << " / 10"<< endl;
				cout << "-------------------------------------------"<<endl;
				cout << "\tPrice: "<< p->price <<"/-"<< endl;
		    	cout << "-------------------------------------------"<<endl;
			p = p->next;
		}
	}
}

// Driver code
int main()
{
	head = NULL;
	string Name, company;
	int srno;
	int price;
	float condition;
	int model;
	string reg;
	
	// Menu-driven program
	cout<<"\n\t\tWelcome to Vehicle Showroom Database Management System\n\n"<<endl;
	cout<<"\tProject prepared by Sheharyar Abid (2012187) and Sharjeel Ali Khan (2012332)"<<endl<<endl;
	while (true) {
		
		cout << "\tWelcome to Main Menu"<<endl;
		cout << "\n\tSelect Option:-"<<endl;
		cout << "\t1 - Add a new vehcile"<<endl;
		cout << "\t2 - Delete a vehicle"<<endl;
		cout << "\t3 - Search a vehicle"<<endl;
		cout << "\t4 - View the stock"<<endl;
		cout << "\t5 - Exit the program"<<endl;
		cout << "\nEnter your Choice"<<endl;
		 
		int Choice;
		
		// Enter Choice
		cin >> Choice;
		system("cls");
		if (Choice == 1) {
			
			cout << "Enter Unique serial Number of Vehcile (Format = 0000)"<<endl;;
			cin >> srno;
			if (check(srno)) { //check if srno already exits.
			cout << "Vehicle with this record already Exists!"<<endl;
			cout << "Note: Try again with different serial number."<<endl<<endl<<endl;
			system("cls");
			}
			else{
			cout << "Enter Name of vehicle"<<endl;
			cin >> Name;
			cout << "Enter Manufacturer of vehicle"<<endl;
			cin >> company;
			cout << "Enter model year of vehicle"<<endl;
			cin >> model;
			cout << "Enter registration number of vehicle (Format = ABC123)"<<endl;
			cin >> reg;
			cout << "Enter Condition of vehicle out of 10 (Format = 0.0)"<<endl;
			cin >> condition;
			cout << "Enter Price of the vehicle" << endl;
			cin >> price;
			system("cls");
			Insert_Record(srno, Name, company, condition,price,model,reg);
			}
			cout<<endl;
		
		}
			
		else if (Choice == 2) {
			cout << "Enter the user-defined serial Number of first vehicle for deletion."<<endl;
			cout << "Note: The vehcile inserted first is deleted first."<<endl;
			cin >> srno;
			
			Delete_Record(srno);
		}
		else if (Choice == 3) {
			cout << "Enter serial Number of vehicle for search"<<endl;
			cin >> srno;
			cout<<"Showing search results for "<<srno<<endl;
			Search_Record(srno);
		}
		else if (Choice == 4) {
			Show_Record();
		}
		else if (Choice == 5) {
			exit(0);
		}
		else {
			cout << "Invalid Choice! Try Again"<<endl;
		}
	}
	return 0;
}
