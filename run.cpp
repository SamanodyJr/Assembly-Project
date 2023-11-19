#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include "R-Format.hpp"
#include "I-Format.hpp"

using namespace std;
void check_format(string inst, string inst_rest, vector<pair<string, int> > reg, int &pc, map <int , string> memory, bool &pc_changed) // name , string
{
<<<<<<< HEAD

//     if (IFormat_Checker(inst)) //if( rformt =)
//     {
// //         IFormat( inst, inst_rest, reg, pc, pc_changed , memory);
//     }
 
}
=======
    int x;
    if (inst == "add" || inst == "sub" || inst == "srl" || inst == "sll" || inst == "xor" || inst == "and" || inst == "or") //if( rformt =)
        //d,s,s
         RFormat(inst, destintation, source1, source2, reg);
    //if(iformat)
    // d,s,im
    //x=
    //cout << " ans is " << x << endl;
};
>>>>>>> refs/remotes/origin/main
int main()
{   
    int pc;
    int ans(1);
    string filepath,inst;
    vector<pair<string, int> > reg ;
    reg.push_back(make_pair("Zero",0)); reg.push_back(make_pair("ra",0)); reg.push_back(make_pair("sp",34359672828)); 
    reg.push_back(make_pair("gp",268468224)); reg.push_back(make_pair("tp",0)); reg.push_back(make_pair("t0",0)); 
    reg.push_back(make_pair("t1",0)); reg.push_back(make_pair("t2",0)); reg.push_back(make_pair("s0",0)); 
    reg.push_back(make_pair("s1",0)); reg.push_back(make_pair("a0",0)); reg.push_back(make_pair("a1",0)); 
    reg.push_back(make_pair("a2",0)); reg.push_back(make_pair("a3",0)); reg.push_back(make_pair("a4",0)); 
    reg.push_back(make_pair("a5",0)); reg.push_back(make_pair("a6",0)); reg.push_back(make_pair("a7",0)); 
    reg.push_back(make_pair("s2",0)); reg.push_back(make_pair("s3",0)); reg.push_back(make_pair("s4",0)); 
    reg.push_back(make_pair("s5",0)); reg.push_back(make_pair("s6",0)); reg.push_back(make_pair("s7",0)); 
    reg.push_back(make_pair("s8",0)); reg.push_back(make_pair("s9",0)); reg.push_back(make_pair("s10",0)); 
    reg.push_back(make_pair("s11",0)); reg.push_back(make_pair("t3",0)); reg.push_back(make_pair("t4",0)); 
    reg.push_back(make_pair("t5",0)); reg.push_back(make_pair("t6",0));
    do 
    {

    cout << "~~~~~~~~~~~~~~~~~~Welcome to your RISC-V simulator~~~~~~~~~~~~~~~~ \n\n";
    cout << "\t\tWhat would you like to do?\n\n"
         << "\t\t  1. Read from an exisisting file\n\t\t  2. Exit\n" ;

    if( ans < 1 || ans > 2)
    {
        cout << "invalid number entered try again \n";
    }
    cout << "option:";
    cin >> ans;
    
    }while(ans > 2 || ans < 1);

    if (ans == 1)
    { 
        map < int , int > memory;
        int END(824);
        int tempPC, memadd, memvalue; 
        string mem;
        
        cout << "enter your file path\n";
        cin >> filepath;

        cout << "enter your starting PC\n";
        cin >> pc;

        cout << "Do you want to initialize your memory ? yes/Yes \n";
        cin >> mem ;

        while (mem == "yes" || mem == "Yes")
        {
            cout << "enter the memory address: ";
            cin >> memadd;
            cout << "enter the corresponding memory value: ";
            cin >> memvalue;

            memory[memadd] = memvalue ;

            cout << "Do you want to initialize another thing in your memory? yes/Yes \n";
            cin >> mem;
        }
        // map< int, string > inst;

        // //call the function 
        // tempPC = pc;
        // stringstream instruction(inst[tempPC]);
        // string store;

        // vector <string> temp;
        // store.erase(remove(store.begin(), store.end(), ' '), store.end());
        // while (instruction >> store) {
        //     store.erase(remove(store.begin(), store.end(), ','), store.end());
        //     temp.push_back(store);
        //     break;
        // }
        // string concat;
        // concat = inst[tempPC];
        // int i = concat.find(temp[0]);
        // concat.erase(i,temp[0].length());
        // check_format(temp[0], concat, reg);
        // tempPC += 4;

    }
    else
        exit(1);

}