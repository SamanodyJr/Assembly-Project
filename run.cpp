#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    int ans(1);
    string instruction, filepath;
    vector<string<int>> reg =
    {
        {"Zero",0}, {"ra",0}, {"sp",0},{"qp",0},{"tp",0},{"t0",0},{"t1",0},{"t2",0},{"s0",0},{"s1",0},{"a0",0},{"a1",0},{"a2",0},{"a3",0}, {"a4",0},{"a5",0},{"a6",0},
        {"a7",0},{"s2",0},{"s3",0},{"s4",0},{"s5",0}, {"s6",0},{"s7",0},{"s8",0}, {"s9",0}, {"s10",0}, {"s11",0},{"t3",0}, {"t4",0},{"t5",0},{"t6",0},{"pc",0}

    }
    do 
    {

    cout << "~~~~~~~~~~~~~~~~~~Welcome to your RISC-V simulator~~~~~~~~~~~~~~~~ \n\n";
    cout << "\t\tHow would you like to input your data\n\n"
         << "\t\t  1. Instruction by Instruction\n\t\t  2. Read from an exisisting file\n\t\t  3. Exit\n" ;

    if( ans < 1 || ans > 3)
    {
        cout << "invalid number entered try again \n";
    }
    cout << "option:";
    cin >> ans;
    
    }while(ans > 3 || ans < 1);

    if (ans == 1)
    { 
        do{
            cout << "write your instructions and write 0 when you are done: \n";
            cin >> instruction;
            //substring
            //checkfoormat
            //display mem , reg , ect.

        }while(instruction != "0");
    }
    else if(ans ==2)
    {
        cout << "enter your file path\n";
        cin >> filepath;
       

    }
    else
        exit(1);

}