/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 19, 2016, 8:35 AM
    Purpose:  Fibonacci Crud Problem with a limit
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const char LIMIT=47;//Limit of an unsigned int for Fibonacci Sequence

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //The problem to solve
    cout<<endl<<"Solution to Savitch 8thEd Chap3 Prob10"<<endl;
    cout<<endl<<"The Fibonacci Sequence"<<endl<<endl;
    //Declare variables
    unsigned int fi,fim1,fim2;//Designations in the sequence
    unsigned short nTerms;    //Number of terms in the sequence
    unsigned short counter;   //Current position in the sequence
    const char DREPRO=5;      //Days to reproduce
    float crudWt;             //Weight of Crud
    unsigned int nDays;       //Number of days to grow Crud
    //Initialize the sequence
    fim2=fim1=1;              //Start the sequence
    counter=2;                //Initialize the counter
    //Input the number of terms in the sequence
    cout<<"Input the the initial weight of the crud in lbs"<<endl;
    cin>>crudWt;
    cout<<"How many days will the crud be allowed to grow"<<endl;
    cin>>nDays;
    //Calculate the number of terms
    nTerms=nDays/DREPRO+1;
    //Output or calculate the output required
    if(nTerms==1){
         cout<<"After "<<nDays<<" days the crud weighs "<<fim2*crudWt
                 <<"(lbs)"<<endl<<endl;
    }else if(nTerms==2){
         cout<<"After "<<nDays<<" days the crud weighs "<<fim1*crudWt
                 <<"(lbs)"<<endl<<endl;
    }else{
        do{
            fi=fim1+fim2;
            counter++;
            fim2=fim1;
            fim1=fi;
        }while(counter<nTerms&&counter<=LIMIT);
        if(nTerms<=LIMIT)
         cout<<"After "<<nDays<<" days the crud weighs "<<fi*crudWt
                 <<"(lbs)"<<endl<<endl;
        else
            cout<<"After "<<nDays<<" days the crud weighs too much"<<endl<<endl;
    }
    //Exit stage right
    return 0;
}