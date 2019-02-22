#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> //include this to be able to round values

//do this to allow access to these file functions
#include "person.h"
#include "person.cpp"

using namespace std;

void readData(Person employee[], int count);
void writeData(Person employee[],int count);
int main()
{
    //I have to figure out how many employees are in the text file
    ifstream inputFile;
    inputFile.open("input.txt");

    /*
        This below counts every line in the text file
    */
    int fileCount = 0;
    string line;
    while(getline(inputFile,line))
    {
        fileCount++;//this is used to get how many lines are in the txt file
    }
    
    /*
        Calling the Array of employees from Person class
    */
    const int maxCount = 20;
    Person employees[maxCount];
    
    //next call readData to get data and then writeData
    readData(employees,fileCount);
    writeData(employees,fileCount);
    cout<<"Calculation has been finished. Please check the 'output.txt' file."<<endl; 
    system("read -p 'Press Enter to continue...' var");
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
/*
    readData will read from the "input.txt" file by calling functions from the 
    Person class
*/
void readData( Person employee[], int fileCount){
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

        employee[index].setFirstName(inputFirstName);
        employee[index].setLastName(inputLastName);
        employee[index].setHoursWorked(inputHours);
        employee[index].setPayRate(inputPayRate);

        inputFile.ignore();//I hope this ignores the new line at the end
        index++;
    }
    inputFile.close();
}
/*
    The writeData funtion will call functions to calculate the total pay of each employee
    I had to use iomanip library to be able to round values
*/
void writeData(Person employee[], int fileCount)
{
    ofstream outputFile;
    outputFile.open("output.txt");
    for(int b = 0; b < fileCount; b++)
    {
        outputFile << employee[b].fullName()<< "\t"
        << fixed << setprecision(2) << employee[b].totalPay() << endl;
        //I had to use this to round the float values to 2 decimal places
        //These are functions NOT variables
    }

    outputFile.close();
}
//////////////////////////////////////////////////////////////////////////////////////////