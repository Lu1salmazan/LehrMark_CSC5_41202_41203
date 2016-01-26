/* 
    Author: Dr. Mark E. Lehr
    Created on January 26, 2016, 08:45 AM
    Purpose:  Variations on a Savings Theme
 */

//System Libraries
#include <iostream>//I/O
#include <iomanip> //Formatting
#include <cmath>   //Power/Exponential/Log functions
#include <cstdlib> //Rand and Srand functions
#include <ctime>   //Time function
using namespace std;

//User Libraries

//Global Constants
const char PERCENT=100;//Convert (Decimal to Percentage)

//Function prototypes
float save1(float,float,int);//Power
float save2(float,float,int);//Exponential and Log
float save3(float,float,int);//For-Loops
float save4(float,float,int);//For-Loops Banking with Pennies
float save5(float,float,int);//Recursion, function calling itself
float save6(float,int,float=0.05f);//Defaulted save function
float save7(float,float,int);//For-Loops and static variable

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare and initialize variables
    float pv=rand()%9001+1000;//[1000,10000] $'s
    float intRate=rand()%11+5;//[5,15]       %
    char  nComp=rand()%16;//[0,15]           Years
    
    //Output the random inputs
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"The Present Value   = $"<<pv<<endl;
    cout<<"The interest rate   =  "<<intRate<<"%"<<endl;
    cout<<"The number of years =  "<<static_cast<int>(nComp)<<endl;
    
    //Output the results
    cout<<"The Savings using Power Function               = $"
            <<save1(pv,intRate/PERCENT,nComp)<<endl;
    cout<<"The Savings using Exponential and Log Function = $"
            <<save2(pv,intRate/PERCENT,nComp)<<endl;
    cout<<"The Savings using For-Loops                    = $"
            <<save3(pv,intRate/PERCENT,nComp)<<endl;
    cout<<"The Savings using For-Loops  Banking Version   = $"
            <<save4(pv,intRate/PERCENT,nComp)<<endl;
    cout<<"The Savings using Recursion                    = $"
            <<save5(pv,intRate/PERCENT,nComp)<<endl;
    cout<<"The Savings Exponential Defaulting Interest    = $"
            <<save6(pv,nComp,intRate/PERCENT)<<endl;
    cout<<"The Savings Exponential Defaulting Interest 5% = $"
            <<save6(pv,nComp)<<endl;
    cout<<"The Savings using For-Loops and static counter = $"
            <<save7(pv,intRate/PERCENT,nComp)<<endl;
    cout<<"The Savings using For-Loops and static counter = $"
            <<save7(pv,intRate/PERCENT,nComp)<<endl;

    //Exit stage right
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/***************************************SAVE1**********************************/
//Inputs
// p->Present Value $'s
// i->Interest Rate %
// n->Number of compounding periods
//Output
// fv->Future Value $'s
//Note:  Using the for loop function static Variable
float save7(float p,float i,int n){
    static int nCalls=0;
    for(int years=1;years<=n;years++){
        p*=(1+i);
    }
    nCalls++;
    cout<<"This function save7 contains a static counter = "
            <<nCalls<<endl;
    return p;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/***************************************SAVE1**********************************/
//Inputs
// p->Present Value $'s
// i->Interest Rate %
// n->Number of compounding periods
//Output
// fv->Future Value $'s
//Note:  Using the power function and defaulting the interest
float save6(float p,int n,float i){
    return p*pow((1+i),n);
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/***************************************SAVE1**********************************/
//Inputs
// p->Present Value $'s
// i->Interest Rate %
// n->Number of compounding periods
//Output
// fv->Future Value $'s
//Note:  Recursion
float save5(float p,float i,int n){
    if(n<=0)return p;//Base Condition
    return save5(p,i,n-1)*(1+i);
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/***************************************SAVE1**********************************/
//Inputs
// p->Present Value $'s
// i->Interest Rate %
// n->Number of compounding periods
//Output
// fv->Future Value $'s
//Note:  Using the for loop function Banking Implementation
float save4(float p,float i,int n){
    int ip=p*PERCENT;//Place the value in pennies
    for(int years=1;years<=n;years++){
        ip*=(1+i);
    }
    p=static_cast<float>(ip)/PERCENT;//Returning to $'s
    return p;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/***************************************SAVE1**********************************/
//Inputs
// p->Present Value $'s
// i->Interest Rate %
// n->Number of compounding periods
//Output
// fv->Future Value $'s
//Note:  Using the for loop function
float save3(float p,float i,int n){
    for(int years=1;years<=n;years++){
        p*=(1+i);
    }
    return p;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/***************************************SAVE1**********************************/
//Inputs
// p->Present Value $'s
// i->Interest Rate %
// n->Number of compounding periods
//Output
// fv->Future Value $'s
//Note:  Using the exponential and log function
float save2(float p,float i,int n){
    return p*exp(n*log(1+i));
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/***************************************SAVE1**********************************/
//Inputs
// p->Present Value $'s
// i->Interest Rate %
// n->Number of compounding periods
//Output
// fv->Future Value $'s
//Note:  Using the power function
float save1(float p,float i,int n){
    return p*pow((1+i),n);
}