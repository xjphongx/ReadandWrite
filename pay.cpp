#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> //include this to be able to round values
#include <vector>

//do this to allow access to these file functions
#include "person.h"
#include "person.cpp"

using namespace std;

void readData(vector <Person>& employee);
void writeData(vector <Person>& employee);
int main()
{
    //I have to figure out how many employees are in the text file
    ifstream inputFile;
    inputFile.open("input.txt");

    /*
        This below counts every line in the text file
    
    int fileCount = 0;
    string line;
    while(getline(inputFile,line))
    {
        fileCount++;//this is used to get how many lines are in the txt file
    }
    */

    /*
        Calling the vector of employees from Person class
    */
    vector <Person> employees;
    
    //next call readData to get data and then writeData
    readData(employees);
    writeData(employees);
    cout<<"Calculation has been finished. Please check the 'output.txt' file."<<endl; 
    system("read -p 'Press Enter to continue...' var");
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
/*
    readData will read from the "input.txt" file by calling functions from the 
    Person class
*/
void readData(vector <Person> &employee){
    ifstream inputFile;
    inputFile.open("input.txt");
    
    int index =0;//increments for the next employee in the array
    while(!inputFile.eof())//is it at the end of the line?
    {
        string inputFirstName, inputLastName;
        float inputHours, inputPayRate;
        
        inputFile >> inputFirstName;
        inputFile >> inputLastName;
        inputFile >> inputHours;
        inputFile >> inputPayRate;

        employee.at(index).setFirstName(inputFirstName);
        employee.at(index).setLastName(inputLastName);
        employee.at(index).setHoursWorked(inputHours);
        employee.at(index).setPayRate(inputPayRate);

        inputFile.ignore();//I hope this ignores the new line at the end
        index++;
    }
    inputFile.close();
}
/*
    The writeData funtion will call functions to calculate the total pay of each employee
    I had to use iomanip library to be able to round values
*/
void writeData(vector <Person> &employee)
{
    ofstream outputFile;
    outputFile.open("output.txt");
    for(int b = 0; b < employee.size(); b++)
    {
        outputFile << employee.at(b).fullName()<< "\t"
        << fixed << setprecision(2) << employee.at(b).totalPay() << endl;
        //I had to use this to round the float values to 2 decimal places
        //These are functions NOT variables
    }

    outputFile.close();
}
//////////////////////////////////////////////////////////////////////////////////////////