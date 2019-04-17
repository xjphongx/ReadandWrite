///begin person.h
/*
    Class Declaration File
*/
#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;
class Person
{
    private:
        string lastName;
        string firstName;
        float payRate;
        float hoursWorked;
    public:
        Person();
        Person(string firstName, string lastName, float payRate, float hoursWorked);

        void setLastName(string lName);
        string getLastName();

        void setFirstName(string fName);
        string getFirstName();

        void setPayRate(float rate);
        float getPayRate();

        void setHoursWorked(float hour);
        float getHoursWorked();
        
        //these functions will write to the "input.txt"
        float totalPay();
        string fullName();

    

};
#endif
