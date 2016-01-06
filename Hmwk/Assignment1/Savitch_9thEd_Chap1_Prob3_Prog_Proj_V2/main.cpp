/* 
 * Author: Dr. Mark E. Lehr
 * Created on January 6, 2016, 10:45 AM
 * Purpose:  Quarters,Nickels,Dimes
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constant
const char cnvQrtr=25;//Cents per quarter
const char cnvDime=10;//Cents per dime
const char cnvNikl=5 ;//Cents per nickel
const char cnvPnDl=100;//Conversion from pennies to dollars

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    unsigned short nQrtrs,nNikls,nDimes;//Declare inputs, number of Q,D,N
    unsigned short total;//total 
    
    //Input the number of coins
    cout<<"How many quarters do you have"<<endl;
    cin>>nQrtrs;
    cout<<"How many dimes do you have"<<endl;
    cin>>nDimes;
    cout<<"How many nickels do you have"<<endl;
    cin>>nNikls;
    
    //Calculate the total
    total=nQrtrs*cnvQrtr+nDimes*cnvDime+nNikls*cnvNikl;
    
    //Output the results
    cout<<"Number of Quarters input = "<<nQrtrs<<endl;
    cout<<"Number of Dimes    input = "<<nDimes<<endl;
    cout<<"Number of Nickels  input = "<<nNikls<<endl;
    cout<<"The dollar amount = $"<<1.0f*total/cnvPnDl<<endl;
    
    //Exit stage right
    return 0;
}