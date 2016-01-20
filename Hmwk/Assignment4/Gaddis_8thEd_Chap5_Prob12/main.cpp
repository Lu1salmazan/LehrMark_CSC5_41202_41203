/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 20, 2016, 10:35 AM
    Purpose:  Table of Temperatures
 */

//System Libraries
#include <iostream> //I/O
#include <iomanip>  //Formatting
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //The problem to solve
    cout<<endl<<"Solution to Gaddis 8thEd Chap5 Prob12"<<endl;
    cout<<endl<<"Display a Temperature Table"<<endl<<endl;
    
    //Declare variables
    float slope=5.0f/9; //Slope of the line for temperature conversion c/f
    char  intrcpt=-32;  //Scaled 9/5 deg c
    unsigned char  c1=0,c2=100,f1=32,f2=212;//Data pts of freezing and boiling

    //Loop to generate the degree Celsius and output the table
    cout<<"Fahrenheit   Celsius   Celsius"<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    for(int f=f1;f<=f2;f++){
        float ceq=slope*(f+intrcpt);
        float cintrp=c1+static_cast<float>(f-f1)/(f2-f1)*(c2-c1);
        cout<<setw(10)<<f<<setw(10)<<ceq<<setw(10)<<cintrp<<endl;
    }
    
    //Exit stage right
    return 0;
}