#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include "I-Format.hpp"

using namespace std;

bool IFormat_Checker(string inst)
{
    if(inst == "jarl" || inst == "lb" || inst == "lh" || inst == "lw" || inst == "lbu" || inst == "lhu" || inst == "addi" || inst == "slti" || inst == "sltiu" || inst == "xori" || inst == "ori" || inst == "andi"|| inst == "slli" || inst == "srli" || inst == "srai" )
        return true;
    else
        return false;
}

void IFormat(string inst, string inst_rest, vector<pair<string, int> > reg, int pc, bool pc_changed , map< int , string > memory)
{
    int rd = -1, rs1 = -1, imm;
    bool imm_flag;
    stringstream instruction(inst_rest);
    string store;
    vector <string> temp;
        while (instruction >> store) {
                store.erase(remove(store.begin(), store.end(), ','), store.end());
                temp.push_back(store);
            }
	for (size_t i = 0; i < reg.size(); ++i) {
		if (reg[i].first == temp[0]) {
			rd = i;
		}
		else if (reg[i].first == temp[1]) {
			rs1 = i;
		}
        imm_flag = all_of(temp[2].begin(), temp[2].end(), ::isdigit);
		if(imm_flag)
		    imm =  stoi(temp[2]);
	}
	if (rd == -1 || rs1 == -1 || !imm_flag ) {
		cout << "Invalid entries." << endl;
	}
	else
	{
        if(inst == "jalr")
        {
            rd = pc + 4;
            pc_changed = true;

        }
        else if(inst == "lb")
        {

        }
        else if(inst == "lw")
        {
            
        }
        else if(inst == "lbu")
        {
            /* code */
        }
        else if(inst == "lhu")
        {
            /* code */
        }
        else if(inst == "addi")
        {
            /* code */
        }
        else if(inst == "slti")
        {
            /* code */
        }
        else if(inst == "sltiu")
        {
            /* code */
        }
        else if(inst == "xori")
        {
            /* code */
        }
        else if(inst == "ori")
        {
            /* code */
        }
        else if(inst == "andi")
        {
            /* code */
        }
        else if(inst == "slli")
        {
            /* code */
        }
        else if(inst == "srli")
        {
            /* code */
        }
        else if(inst == "srai")
        {
            /* code */
        }
    }

 
}