/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on February 2nd, 2016, 8:20 AM
    Purpose:  How big of an X do you want to print
 */

//System Libraries
#include <iostream> //I/O
#include <iomanip>  //Formatting
#include <cstdlib>  //Random Functions
#include <ctime>    //Setting the seed with time
using namespace std;

//User Libraries

//Global Constants
const int COL=50;

//Function prototypes
int fillAry1(char [][COL],int);
int fillAry2(char [][COL],int);
void prntAry(char [][COL],int,int);
void allNOne();

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare variables
    const int ROW=50;
    char array[ROW][COL];
    
    //Fill the array with random 2 digit numbers
    int row_col=fillAry1(array,ROW);
    
    //Print the array
    prntAry(array,ROW,row_col);
    
    //Fill the array with random 2 digit numbers
    row_col=fillAry2(array,ROW);
    
    //Print the array
    prntAry(array,ROW,row_col);
    
    //Print the answer
    allNOne();
    
    //Exit stage right
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                     Print Array
//Inputs:
//  a->List
//  ROW->Number of rows in the array
//  COL->Number of columns in the array//Outputs:
//  rc->Number of rows and columns to print
//  a->Printed List
//******************************************************************************
void prntAry(char a[][COL],int ROW,int rc){
    //Loop and fill the array with random numbers
    cout<<endl;
    for(int row=0;row<rc;row++){
        for(int col=0;col<rc;col++){
            cout<<a[row][col];
        }
        cout<<endl;
    }
    cout<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                     Fill Array
//Inputs:
//  a->A 2 dimensional array
//  ROW->Number of rows in the array
//  COL->Number of columns in the array
//Outputs:
//  a->Big X
//******************************************************************************
void allNOne(){
    //Randomly choose how many rows and columns
    int row_col=rand()%51;//[0,50]
    //Fill the entire table with spaces
    for(int row=0;row<row_col;row++){
        for(int col=0;col<row_col;col++){
            if(row==col){cout<<row_col-row;
            }else if((row+col)==(row_col-1)){cout<<row+1;
            }else{ cout<<' ';}
        }
        cout<<endl;
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                     Fill Array
//Inputs:
//  a->A 2 dimensional array
//  ROW->Number of rows in the array
//  COL->Number of columns in the array
//Outputs:
//  a->Big X
//******************************************************************************
int fillAry2(char a[][COL],int ROW){
    //Randomly choose how many rows and columns
    int row_col=rand()%7+3;//[2,9]
    //Fill the entire table with spaces
    for(int row=0;row<row_col;row++){
        for(int col=0;col<row_col;col++){
            a[row][col]=' ';
             if(row==col)a[row][col]=(row_col-row)+48;
             if((row+col)==(row_col-1))a[row][col]=(row+1)+48;
        }
    }
    //Send back how many cells are occupied
    return row_col;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                     Fill Array
//Inputs:
//  a->A 2 dimensional array
//  ROW->Number of rows in the array
//  COL->Number of columns in the array
//Outputs:
//  a->Big X
//******************************************************************************
int fillAry1(char a[][COL],int ROW){
    //Randomly choose how many rows and columns
    int row_col=rand()%7+3;//[3,9]
    //Fill the entire table with spaces
    for(int row=0;row<row_col;row++){
        for(int col=0;col<row_col;col++){
            a[row][col]=' ';
        }
    }
    //Fill the back slash part of X
    for(int row=0;row<row_col;row++){
        for(int col=0;col<row_col;col++){
            if(row==col)a[row][col]=(row_col-row)+48;
        }
    }
    //Fill the forward slash part of X
    for(int row=0;row<row_col;row++){
        for(int col=0;col<row_col;col++){
            if((row+col)==(row_col-1))a[row][col]=(row+1)+48;
        }
    }
    //Send back how many cells are occupied
    return row_col;
}