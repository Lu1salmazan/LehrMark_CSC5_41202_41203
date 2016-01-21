/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 21, 2016, 11:05 AM
    Purpose:  Inflation
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
    cout<<endl<<"Fun look at Inflation"<<endl<<endl;
    
    //Declare and initialize
    float price=0.25f;        //Initial Price $'s
    float inflate=0.07f;       //Inflation Rate / year
    float rule72=0.72f/inflate;//Rule of 72, Future Value = 2 * Present Value
    float infYear;             //Inflation per year
    //Output the Table Heading
    cout<<"The inflation rate = "<<inflate*100<<"%"<<endl;
    cout<<"At this inflation rate Price should double every ";
    cout<<rule72<<" Years"<<endl;
    cout<<"Year Year  Price Inflation"<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    
    //Calculate the savings
    for(int y=0,year=2016;y<=50;y++,year++){
        infYear=price*inflate;
        cout<<setw(4)<<y<<" "<<year<<setw(7)<<price
                <<setw(10)<<infYear<<endl;
        price*=(1+inflate);
    }
    
    //Exit stage right
    return 0;
}