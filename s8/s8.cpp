// s8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int num;
	int dolar = 100;
	int quarter = 25;
	int dime = 10;
	int nickel = 5;
	int penny = 1 ;
	int dolars = 0;
	int quarters = 0;
	int dimes = 0;
	int nickels = 0;
	int pennys = 0;
		cout << "enter num of cents "<<endl;
		cin >> num;
		while (num != 0)
		{
			if (num >= dolar)
			{
				num -= dolar;
				dolars ++;
			}
			else if (num >= quarter)
			{
				num -= quarter;
				quarters++;
			}
			else if (num >= dime)
			{
				num -= dime;
				dimes ++;
			}
			else if (num >= nickel)
			{
				num -= nickel;
				nickels++;
			}
			else if (num >= penny)
			{
				num -= penny;
				pennys++;
			}
		}
		cout << "dolars = " << dolars << endl;
		cout << "quarters = " << quarters << endl;
		cout <<  "dimes = " << dimes << endl;
		cout <<  "nickels = " << nickels << endl;
		cout <<  "pennys = " << pennys << endl;
		
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
