/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 14, 2016, 11:00 AM
    Purpose:  Room Capacity
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    float qwntity=0.75f;//A value to add repeatedly
    float sum=0;//The result of a repetitive addition
    int   nLoops=10000000;//Number of times to loop
    float answer;//The computed answer
    
    //Input data
    for(int i=1;i<=nLoops;i++){
        sum+=qwntity;
    }
    
    //Calculate or map inputs to outputs
    answer=nLoops*qwntity;
    
    //Output the results
    cout<<"The product answer = "<<answer<<endl;
    cout<<"The sum answer     = "<<sum<<endl;
    cout<<"The percent error  = "<<(answer-sum)/answer*100<<"%"<<endl;

    //Exit stage right
    return 0;
}