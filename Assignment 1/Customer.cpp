#include <iostream> 
#include <string>
#include "Customer.h" 

void Customer::setId(int no)
{
 	id = no; 
} 

void Customer::setFName(std::string first)
{
 	fName = first; 
}

void Customer::setLName(std::string last)
{
	lName = last; 
}

void Customer::setFullName()
{
	fullName = fName + "  " + lName; 
} 
		
void Customer::setBalance(double bal)
{
	balance = bal; 
}
		
void Customer::order (double amt)
{
	balance+=amt; 
} 

void Customer::payment (double amt)
{
	balance-=amt; 
}