/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on February 4th, 2016, 8:45 PM
    Purpose:  Game of Life
 */

//System Libraries
#include <iostream> //I/O
#include <fstream> //I/O
#include <iomanip>  //Formatting
#include <cstdlib>  //Random Functions
#include <ctime>    //Setting the seed with time
using namespace std;

//User Libraries

//Global Constants
const int COL=60;
const int ROW=30;

//Function prototypes
void readAry(char [][ROW][COL]);
void prntAry(char [][ROW][COL],int,bool);
void gner8(char [][ROW][COL],int,bool);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    const int TABLES=2;
    char array[TABLES][ROW][COL];
    
    //Read from a file the array
    readAry(array);
    prntAry(array,TABLES,0);
    
    //Generate and evolve the Game of Life
    int nGen=100;
    for(int gen=1;gen<=nGen;gen++){
        gner8(array,TABLES,gen%2);
        prntAry(array,TABLES,gen%2);
    }
    
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
//  tab->Number of tables
//  a->Printed Table
//******************************************************************************
void prntAry(char a[][ROW][COL],int tab,bool which){
    //Loop and fill the array with random numbers
    cout<<endl;
    for(int row=0;row<ROW;row++){
        for(int col=0;col<COL;col++){
            cout<<a[which][row][col];
        }
        cout<<endl;
    }
    cout<<endl;
}


//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                     Read Array
//Inputs:
//  a->A 3 dimensional array
//  ROW->Number of rows in the array
//  COL->Number of columns in the array
//  tab->Number of tables
//******************************************************************************
void readAry(char a[][ROW][COL]){
    //Declare the file object
    ifstream in;
    //Open the input
    in.open("gameOfLife.dat");
    //Fill the entire table with spaces
    for(int tab=0;tab<=1;tab++){
        for(int row=0;row<ROW;row++){
            for(int col=0;col<COL;col++){
                in>>a[tab][row][col];
            }
        }
    }
    //Send back how many cells are occupied
    in.close();
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
void gner8(char a[][ROW][COL],int tables,bool tab){
    //Perform the 4 rules
    for(int row=1;row<ROW-1;row++){
        for(int col=1;col<COL-1;col++){
            int neighbor=((a[!tab][row-1][col-1]=='X'?1:0)+
                         (a[!tab][row-1][col]=='X'?1:0)+
                         (a[!tab][row-1][col+1]=='X'?1:0)+
                         (a[!tab][row][col-1]=='X'?1:0)+
                         (a[!tab][row][col+1]=='X'?1:0)+
                         (a[!tab][row+1][col-1]=='X'?1:0)+
                         (a[!tab][row+1][col]=='X'?1:0)+
                         (a[!tab][row+1][col+1]=='X'?1:0));
            if(neighbor<=1)a[tab][row][col]='-';
            if(neighbor>=4)a[tab][row][col]='-';
            if(neighbor==2||neighbor==3&&a[!tab][row][col]=='X')a[tab][row][col]='X';
            if(neighbor==3&&a[!tab][row][col]=='-')a[tab][row][col]='X';
        }
    }
}