#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    int ans(1);
    string instruction, filepath;

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