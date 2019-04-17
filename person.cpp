/*
    Class Definition File
*/

#include <iostream>
#include <string>

using namespace std;

#include "person.h"

/*
    Default Constructor
*/
Person::Person()
{
    firstName = "Jimmy";
    lastName = "Phong";
    payRate = 12;
    hoursWorked = 10;
}

Person::Person(string fName, string lName, float rate, float hour)
{
    firstName = fName;
    lastName = lName;
    payRate = rate;
    hoursWorked = hour;
}
//last name stuff
void Person::setLastName(string lName){
    lastName = lName;
}
string Person::getLastName(){
    return lastName;
}
//first name stuff
void Person::setFirstName(string fName){
    firstName = fName;//this variable is in the header file 
}
string Person::getFirstName() {
	return firstName;
}
//payrate stuff
void Person::setPayRate(float rate){
    payRate = rate;
}
float Person::getPayRate(){
    return payRate;
}
//hour stuff
void Person::setHoursWorked(float hour){
    hoursWorked = hour;
}
float Person::getHoursWorked(){
    return hoursWorked;
}
//output stuff 
float Person::totalPay(){
    float pay = hoursWorked*payRate;
    return pay;
}
string Person::fullName(){
    string fullName = firstName + " " + lastName;
    return fullName;
}




