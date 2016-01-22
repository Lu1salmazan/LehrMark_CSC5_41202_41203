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
    unsigned int savings=0;//Initial Savings pennies
    char invRate=5;       //Investment Rate % / year
    unsigned int intErnd; //Interest Earned pennies
    char depRate=10;      //Deposit Rate %/year
    unsigned int salary=10000000;//Salary pennies/year
    unsigned int deposit=salary*depRate/100;//Yearly deposit in pennies/year
    unsigned int savReq=salary/invRate*100;//Savings required to retire pennies
    
    //Output the Table Heading
    cout<<"Yearly Salary       = $"<<salary/100.0f<<endl;
    cout<<"The Investment Rate = "<<invRate*100.0f<<"%"<<endl;
    cout<<"The Deposit Rate    = "<<depRate*100.0f<<"%"<<endl;
    cout<<"Retirement Savings Required = $"<<savReq/100.0f<<endl<<endl;
 
    cout<<"Year Year    Savings  Interest  Deposit"<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    
    //Calculate the savings in pennies
    for(int y=0,year=2018;y<=50;y++,year++){
        intErnd=savings*invRate/100.0f;
        cout<<setw(4)<<y<<" "<<year<<setw(11)<<savings/100.0f
                <<setw(10)<<intErnd/100.0f<<setw(9)<<deposit/100.0f<<endl;
        savings*=(1+invRate/100.0f);
        savings+=deposit;
    }
    
    //Exit stage right
    return 0;
}