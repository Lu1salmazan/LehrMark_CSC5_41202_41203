/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 21, 2016, 08:45 PM
    Purpose:  Retirement
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
    cout<<endl<<"Retirement = Salary/InvRate + Deposits"<<endl;
    cout<<endl<<"http://california.municipalbonds.com/bonds/recent/"<<endl<<endl;
    
    //Declare and initialize
    double savings=0.0;        //Initial Savings $'s
    double invRate=0.05;       //Investment Rate % / year
    double intErnd;            //Interest Earned
    double depRate=0.10;       //Deposit Rate %/year
    double salary=1e5;        //Salary $/year
    double deposit=salary*depRate;//Yearly deposit in $'s/year
    double savReq=salary/invRate;//Savings required to retire $'s
    
    //Output the Table Heading
    cout<<"Yearly Salary       = $"<<salary<<endl;
    cout<<"The Investment Rate = "<<invRate*100<<"%"<<endl;
    cout<<"The Deposit Rate    = "<<depRate*100<<"%"<<endl;
    cout<<"Retirement Savings Required = $"<<savReq<<endl<<endl;
 
    cout<<"Year Year    Savings  Interest  Deposit"<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    
    //Calculate the savings
    for(int y=0,year=2018;y<=50;y++,year++){
        intErnd=savings*invRate;
        cout<<setw(4)<<y<<" "<<year<<setw(11)<<savings
                <<setw(10)<<intErnd<<setw(9)<<deposit<<endl;
        savings*=(1+invRate);
        savings+=deposit;
    }
    
    //Exit stage right
    return 0;
}