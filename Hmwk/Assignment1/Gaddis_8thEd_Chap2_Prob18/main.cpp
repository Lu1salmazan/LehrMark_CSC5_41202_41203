/* 
 * Author: Dr. Mark E. Lehr
 * Created on January 6, 2016, 9:35 PM
 * Purpose:  Energy Drink Survey
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constant
const char cnvPerc=100;//Conversion to percentage

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    unsigned short cstSrvy=16500; //Customers surveyed
    unsigned char  peDrnk=15;     //Percentage surveyed energy drinkers
    unsigned char  pcDrnk=58;     //Percentage surveyed energy citrus drinkers
    unsigned short neDrnk,ncDrnk; //Number of energy and citrus energy drinkers
    
    //Calculate the number of drinkers
    neDrnk=cstSrvy*peDrnk/cnvPerc;
    ncDrnk=neDrnk*pcDrnk/cnvPerc;
    
    //Output the results
    cout<<"Number of Customer Surveyed = "<<cstSrvy<<endl;
    cout<<"Percentage of Energy Drinkes = "<<static_cast<int>(peDrnk)<<"%"<<endl;
    cout<<"Percentage of Energy Drinkes = "<<static_cast<int>(pcDrnk)<<"%"<<endl;
    cout<<"Number of Energy Drinkers = "<<neDrnk<<endl;
    cout<<"Number of Energy Citrus Drinkers = "<<ncDrnk<<endl;
    
    //Exit stage right
    return 0;
}