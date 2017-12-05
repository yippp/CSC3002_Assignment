/*
 * File: p5.cpp
 * --------------------------
 * This is the answer to question 5 of assignmet 3 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 * It is used to test the the subclasses of class Employee
 */

#include <iostream>
#include "employee.h"
#include "vector.h"

using namespace std;

void p5() {
   HourlyEmployee cratchit("Bob Cratchit");
   cratchit.setHourlyRate(1.00);
   cratchit.setHoursWorked(90);

   CommissionedEmployee fezziwig("Mr Fezziwig");
   fezziwig.setBaseSalary(50);
   fezziwig.setCommissionRate(0.05);
   fezziwig.setSalesVolume(2000);

   SalariedEmployee scrooge("Ebenezer Scrooge");
   scrooge.setSalary(500);

   Vector<Employee *> payroll;
   payroll.add(&cratchit);
   payroll.add(&fezziwig);
   payroll.add(&scrooge);
   for (Employee *ep : payroll) {
      cout << ep->getName() << ": " << ep->getPay() << endl;
   }
}
