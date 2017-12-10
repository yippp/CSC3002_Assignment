/*
 * File: employee.cpp
 * ------------------
 * Impliment the function in employee.h
 */

#include <string>
#include "employee.h"
using namespace std;

/*
* Function: Employee::getName
* Usage: Employee::getName();
* ------------------------
* Get name of the employee.
*/

string Employee::getName() {
    return name;
}

/*
* Function: Employee::setName
* Usage: Employee::setName(name);
* ------------------------
* Set name of the employee.
*/

void Employee::setName(string name) {
    this->name = name;
}

/*
* Function: HourlyEmployee::HourlyEmployee
* Usage: HourlyEmployee::HourlyEmployee(name);
* ------------------------
* Initial the class HourlyEmployee.
*/

HourlyEmployee::HourlyEmployee(string name) {
    setName(name);
}

/*
* Function: HourlyEmployee::getPay
* Usage: HourlyEmployee::getPay();
* ------------------------
* Get salary pay of the hourly employee.
*/

double HourlyEmployee::getPay() {
    return hoursWorked * hourlyRate;
}

/*
* Function: HourlyEmployee::setHourlyRate
* Usage: HourlyEmployee::setHourlyRate(name);
* ------------------------
* Set the hourly rate of the hourly employee.
*/

void HourlyEmployee::setHourlyRate(double rate) {
    hourlyRate = rate;
}

/*
* Function: HourlyEmployee::setHoursWorked
* Usage: HourlyEmployee::setHoursWorked(name);
* ------------------------
* Set the worked hours of the hourly employee.
*/

void HourlyEmployee::setHoursWorked(double hours) {
    hoursWorked = hours;
}

/*
* Function: CommissionedEmployee::CommissionedEmployee
* Usage: CommissionedEmployee::CommissionedEmployee(name);
* ------------------------
* Initial the class CommissionedEmployee.
*/

CommissionedEmployee::CommissionedEmployee(string name) {
    setName(name);
}

/*
* Function: CommissionedEmployee::getPay
* Usage: CommissionedEmployee::getPay();
* ------------------------
* Get salary pay of the commissioned employee.
*/

double CommissionedEmployee::getPay() {
    return baseSalary + commissionRate * salesVolume;
}

/*
* Function: CommissionedEmployee::setBaseSalary
* Usage: CommissionedEmployee::setBaseSalary(dollars);
* ------------------------
* Set the base salary of the commissioned employee.
*/

void CommissionedEmployee::setBaseSalary(double dollars) {
    baseSalary = dollars;
}

/*
* Function: CommissionedEmployee::setCommissionRate
* Usage: CommissionedEmployee::setCommissionRate(rate);
* ------------------------
* Set the commission rate of the commissioned employee.
*/

void CommissionedEmployee::setCommissionRate(double rate) {
    commissionRate = rate;
}

/*
* Function: CommissionedEmployee::setSalesVolume
* Usage: CommissionedEmployee::setSalesVolume(dollars);
* ------------------------
* Set the sales volume of the commissioned employee.
*/

void CommissionedEmployee::setSalesVolume(double dollars) {
    salesVolume = dollars;
}

/*
* Function: SalariedEmployee::SalariedEmployee
* Usage: SalariedEmployee::SalariedEmployee(name);
* ------------------------
* Initial the class SalariedEmployee.
*/

SalariedEmployee::SalariedEmployee(string name) {
    setName(name);
}

/*
* Function: SalariedEmployee::getPay
* Usage: SalariedEmployee::getPay();
* ------------------------
* Get salary pay of the salaried employee.
*/

double SalariedEmployee::getPay() {
    return salary;
}

/*
* Function: SalariedEmployee::setSalary
* Usage: SalariedEmployee::setSalary(salary);
* ------------------------
* Set the salary of the salaried employee.
*/

void SalariedEmployee::setSalary(double salary) {
    this->salary = salary;
}
