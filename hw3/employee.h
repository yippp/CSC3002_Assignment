/*
 * File: employee.h
 * ----------------
 * This file include the the classes need in problem 5
 */

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <string>
using namespace std;

/*
 * Class: Employee
 * ---------------
 * This parent class of HourlyEmployee, CommissionedEmployee
 * and SalariedEmployee.
 */

class Employee {
public:
    string getName();
    virtual double getPay() = 0;
    void setName(string name);
private:
    string name;
};

/*
 * Classes: HourlyEmployee, CommissionedEmployee, SalariedEmployee
 * ------------------------------------------------------------------
 * Subclasses belongs to class Emplyee will different getPay() function.
 */

class HourlyEmployee : public Employee {
public:
    virtual double getPay();
    void setHourlyRate(double rate);
    void setHoursWorked(double hours);
    HourlyEmployee(string name);
private:
    double hourlyRate;
    double hoursWorked;
};

class CommissionedEmployee : public Employee {
public:
    virtual double getPay();
    void setBaseSalary(double dollars);
    void setCommissionRate(double rate);
    void setSalesVolume(double dollars);
    CommissionedEmployee(string name);
private:
    double baseSalary;
    double commissionRate;
    double salesVolume;
};

class SalariedEmployee : public Employee {
public:
    virtual double getPay();
    void setSalary(double salary);
    SalariedEmployee(string name);
private:
    double salary;
};

#endif _EMPLOYEE_H
