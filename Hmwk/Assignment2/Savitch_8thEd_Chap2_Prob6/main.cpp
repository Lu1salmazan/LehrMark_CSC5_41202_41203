/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 44, 2016, 9:05 PM
    Purpose:  ISP Bill
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    char package;      //A,B,C
    unsigned short hrs;//Hours utilized
    float bill;        //Your bill in $'s
    bool sentnl=true;  //End loop when sentnl is false
    
    //Loop until you end with a sentinels
    do{
        //Initialize the Bill
        bill=0;
        //Input data
        cout<<"Calculate your ISP Bill"<<endl;
        cout<<"What package are you under A, B, or C"<<endl;
        cin>>package;
        if(toupper(package)=='A'||toupper(package)=='B'){
            cout<<"How many hours have you utilized"<<endl;
            cin>>hrs;
        }

        //Calculate or map inputs to outputs, i.e. calculate the bill
        switch(package){
            case 'A':
            case 'a':{
                if(hrs<=10)bill=9.95f;
                else bill=9.95f+2*(hrs-10);
                break;
            }
            case 'B':
            case 'b':{
                if(hrs<=20)bill=14.95f;
                else bill=14.95f+(hrs-20);
                break;
            }
            case 'C':
            case 'c':{
                bill=19.95f;
                break;
            }
            default: cout<<"Bad package, no bill can be computed!"<<endl;
                     sentnl=false;
            };
        
        //Output the results
        cout<<fixed<<setprecision(2)<<showpoint;
        if(tolower(package)=='a'||tolower(package)=='b'){
            cout<<"For package "<<package<<" and hours = "
                <<hrs<<" the Bill = $"<<bill<<endl;
        }else{
            cout<<"For package "<<package
                <<" the Bill = $"<<bill<<endl;
        }
    }while(sentnl);
    
    //Exit stage right
    return 0;
}