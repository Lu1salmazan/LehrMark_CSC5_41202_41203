/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 21, 2016, 11:05 AM
    Purpose:  Savings
 */

//System Libraries
#include <iostream> //I/O
#include <iomanip>  //Format
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //The problem to solve
    cout<<endl<<"Fun look at Savings and rule of 72"<<endl;
    cout<<endl<<"http://california.municipalbonds.com/bonds/recent/"<<endl<<endl;
    
    //Declare and initialize
    float balance=100.0f;      //Initial Balance $'s
    float intRate=0.05f;       //Interest Rate / year
    float rule72=0.72f/intRate;//Rule of 72, Future Value = 2 * Present Value
    float intErnd;             //Interest Earned
    //Output the Table Heading
    cout<<"The interest rate = "<<intRate*100<<"%"<<endl;
    cout<<"At this interest Principle should double every ";
    cout<<rule72<<" Years"<<endl;
    cout<<"Year Year Balance Interest"<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    
    //Calculate the savings
    for(int y=0,year=2016;y<=50;y++,year++){
        intErnd=balance*intRate;
        cout<<setw(4)<<y<<" "<<year<<setw(8)<<balance
                <<setw(9)<<intErnd<<endl;
        balance*=(1+intRate);
    }
    
    //Exit stage right
    return 0;
}