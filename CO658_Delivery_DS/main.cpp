#include <iostream>
#include <string>
#include "ItemOrder.h"
#include "StringHashTable.h"

using namespace std;

#define EXIT "EXIT"

//display menu to customer
int menu()
{
	int choice;
	cout << "\n\t\tDelivery Tracker\n" << endl;
	cout << "\n***************************************" << endl;
	cout << "1- Add Customer Name \n";
	cout << "2- Show all orders\n";
	cout << "3- Find customer order  \n";
	cout << "4- Update order \n";
	cout << "5- Remove order \n";
	cout << "6- Exit program\n";
	cout << "Please select an option (1 - 5) : ";
	cin >> choice;
	return choice;
}


//Function for Option 1 - Add Customer - insert record
void fInsert(StringHashTable* hashTable)
{
	string name, item;
	cout << "Enter name of customer: ";
	cin.ignore();
	getline(cin, name);

	cout << "Enter Item Name: ";
	cin >> item;
	// Asks the user to input delivery option / Standard, Express, Premiumn
	string d;
	cout << "Standard\n";
	cout << "Express\n";
	cout << "Premiumn\n";
	cout << "Enter Delivery option : ";
	cin >> d;
	// Asks the user to input delivery Status, Ordered, Dispatched & Delivered
	cout << "Enter Delivery status -> ";
	cout << "Ordered, Dispatched & Delivered : ";
	string status;
	cin >> status;

	hashTable->Insert(new ItemOrder(name, item, d, status));

}
// If the user selects option 2 Show all customers
void seeCustomer(StringHashTable* hashTable)
{

	cout << "\n***************************************" << endl;

	cout << "\n Delivery Menu:" << endl;
	// Displays HashTable Records
	hashTable->Display();
}


// If the user selects option 3 Find Customer
ItemOrder* FindCustomer(StringHashTable* hashTable)
{
	string searchQuery;
	ItemOrder* objToFind;


	// Search the name of customer
	cout << "Find customer order: ";
	cin.ignore();
	getline(cin, searchQuery);


	objToFind = hashTable->Find(searchQuery);
	if (objToFind && objToFind->name == searchQuery) {

		// If the customer name they entered was found, display the follwing success message
		cout << "\nFound name '" << searchQuery << "'!" << endl;
		cout << objToFind->Display() << endl;
		return objToFind;
	}
	else {
		// If the name they entered could not be found, display the follwing error message
		cout << "\nname '" << searchQuery << "' not found." << endl;
		return NULL;
	}
}

// If the user selects option 4 Update order
void UpdateOrder(StringHashTable* hashTable)
{
	string newStatus;

	ItemOrder* orderToUpdate = FindCustomer(hashTable);
	if (!orderToUpdate) {
		return;
	}

	cout << "\n\t\tDelivery Tracker\n" << endl;
	cout << "\n***************************************\n" << endl;
	// Updates Order status 
	cout << "Enter Updated Order Status: ";
	cin >> newStatus;



	// Currently it finds the Item and then updates from list 
	if (orderToUpdate) {
		orderToUpdate->status = newStatus;
		cout << "\n***************************************\n" << endl;
		//Display the updated order
		cout << orderToUpdate->Display() << endl;
		cout << "\n***************************************\n" << endl;
		hashTable->Display();
	}
	else
	{
		cout << "\n Customer not found." << endl;
	}
}
// If the user selects option 5 Remove order
void RemoveOrder(StringHashTable* hashTable)
{
	ItemOrder* orderToRemove = FindCustomer(hashTable);
	if (!orderToRemove) {
		return;
	}

	// Currently it finds the Item and then removes from list upon user confirmation
	if (orderToRemove) {
		cout << "\nAre you sure you want to delete this order ? Y/N : ";
		char answer;
		cin >> answer;
		if (answer == 'Y')
		{
			hashTable->Delete(orderToRemove->name);
			cout << "\n***************************************\n" << endl;
			hashTable->Display();
		}
		else {
			cout << "\n Record was not deleted" << endl;
		}


	}
	else
	{
		cout << "\n Customer not found." << endl;
	}
}


int main() {


	StringHashTable* deliveryTrack = new StringHashTable(17);

	while (true)
	{
		int choice = menu();
		if (choice == 1)
			// Insert customer details
			fInsert(deliveryTrack);
		// Display Customer Order  
		else if (choice == 2)
			seeCustomer(deliveryTrack);
		///serach or complete task
		else if (choice == 3)
			FindCustomer(deliveryTrack);
		else if (choice == 4)
			UpdateOrder(deliveryTrack);
		else if (choice == 5)
			RemoveOrder(deliveryTrack);
		// Exit Application
		else if (choice == 6)
			exit(0);
	}
	return 0;
}