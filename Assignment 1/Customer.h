#ifndef CUSTOMER_H 
#define CUSTOMER_H

#include <iostream> 
#include <string>

class Customer 
{
	private: 
		int id; 
		std::string fName; 
		std::string lName; 
		std::string fullName; 
		double balance; 
	public:
		void setId(int);
		void setFName(std::string);
		void setLName(std::string); 
		void setFullName(); 
		void setBalance(double); 
		int getId() { return id; }
		std::string getFName() { return fName; } 
		std::string getLName() { return lName; } 
		std::string getFullName() { return fullName; } 
		double getBalance () { return balance; } 
		void order (double); 
		void payment (double); 
}; 

#endif 