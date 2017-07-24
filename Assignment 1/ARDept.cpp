#include <iostream> 
#include <fstream> 
#include <string>
#include <cctype> 
#include "Customer.h" 

int main ()  { 
	std::ifstream inFile1("MasterFile.txt"); 
	if (inFile1.fail() )  {
	std::cout << "Error opening the file\n" << std::endl; 
	std::cout << "Program Terminating\n" << std::endl; 
	return 1; 
	} 
	
	std::ifstream inFile2("TransactionFile.txt"); 
	if (inFile2.fail())	{ 
		std::cout << "Error opening the file\n" << std::endl; 
		std::cout << "Program Terminating\n" << std::endl; 
		return 1;
	} 
	
	std::ofstream outFile("Invoice.txt");
	// std::ofstream outFile("/dev/stdout"); 
	outFile << "Kenneth Dorji \nCISC 3130 - 1FG \nProf Moshe Lowenthal \nAssignment 1" 
				<< "\nJune 12 2017" << std::endl << std::endl; 
	
	int num = 0; 
	std::cout << "Input the no of customers account to process." << std::endl; 
	std::cin >> num; 
	const int SIZE = 15; 
	Customer client[SIZE]; 
	
	int id = 0; double balance = 0; std::string firstName, lastName; 
	for(int i = 0; i<num; i++)	  { 
		inFile1 >> id; 
		client[i].setId(id);
		inFile1 >> firstName; 
		client[i].setFName(firstName); 
		inFile1 >> lastName; 
		client[i].setLName(lastName); 
		client[i].setFullName(); 
		inFile1 >> balance; 
		client[i].setBalance(balance); 
	} 
	
	// All the variable declarations 
	char status; int transactionNo = 0, amtDue = 0, paymentAmt = 0, buffer = 0, length = 0;
	std::string itemOrdered, itemOrdered1, itemOrdered2, credit; char fileTest; 
	
	inFile2 >> id; 
	for(int j = 0; j<num; j++) 		{ 
		length = client[j].getFullName().length(); 
		if (length > 20) 
			outFile << client[j].getFName()	<< '\t' << client[j].getId() << std::endl; 
		else 
			outFile << client[j].getFullName()	<< '\t' << client[j].getId() << std::endl; 

		outFile.width(39);
		outFile << "Previous Balance $" << client[j].getBalance() << std::endl; 
		
		while ( id == client[j].getId() ) 		{
			inFile2 >> status >> transactionNo; 
			outFile << transactionNo << '\t'; 
			
			if (status == 'O' || status == 'o') 	{ 
				inFile2 >> itemOrdered1 >> itemOrdered2 >> buffer >> amtDue; 
				itemOrdered = itemOrdered1 + ' ' + itemOrdered2; 
				length = itemOrdered.length(); 
				if (length > 20) 	
					outFile << itemOrdered2 << "\t\t" << '$' << amtDue << std::endl; 
				else 
					outFile << itemOrdered1 << ' ' << itemOrdered2 << "\t\t" << '$' << 
								amtDue << std::endl; 
				client[j].order(amtDue); 
			}
			
			else 	{
				inFile2 >> credit >> paymentAmt; 
				outFile << "Payment" << "\t\t\t" << '$' << paymentAmt << std::endl; 
				client[j].payment(paymentAmt);
			}
			inFile2 >> id; 
		}
		
		outFile.width(34); 
		outFile << "Balance Due $" << client[j].getBalance() << std::endl << std::endl; 
	} 
	inFile1.close(); 
	inFile2.close(); 
	outFile.close(); 
	return 0; 
} 
		
