#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include "I-Format.hpp"

using namespace std;

bool IFormatChecker(string inst, bool &offset)
{
    if( inst == "addi" || inst == "slti" || inst == "sltiu" || inst == "xori" || inst == "ori" || inst == "andi"|| inst == "slli" || inst == "srli" || inst == "srai" )
    {
        offset = false;
        return true;
    }
    else if (inst == "jalr" || inst == "lb" || inst == "lh" || inst == "lw" || inst == "lbu" || inst == "lhu" )
    {
        offset = true
        return false;
    }
        
}

void IFormat(string inst, string inst_rest, vector<pair<string, int> > reg, int &pc, bool &pc_changed , map< int , int > &memory, bool &err)
{
    int rd = -1, rs1 = -1, imm;
    bool imm_flag;
    stringstream instruction(inst_rest);
    
    string store;
    vector <string> temp;
        while (instruction >> store) {
                store.erase(remove(store.begin(), store.end(), ','), store.end());
                store.erase(remove(store.begin(), store.end(), ' '), store.end());
                temp.push_back(store);
                cout << store << endl;
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
            pc = rs1 + imm;
            pc_changed = true;

        }
        else if(inst == "lb")
        {
            if(memory.find(rs1+imm) != memory.end())
                rd = memory[rs1+imm];
            else
            {
                "memory location not found please make sure it is initialized \n";
            }
        }
        else if(inst == "lw")
        {
            rd = memory[rs1+imm];
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
            rd = rs1 + imm;
        }
        else if(inst == "slti")
        {
            if( rs1 < imm)
                rd = 1;
            else
                rd = 0;

        }
        else if(inst == "sltiu")
        {
            if ( rs1 >= 0 && imm>=0)
				if(rs1 < imm)
					rd = 1;
				else
					rd = 0;
			else if(rs1 >= 0 && imm < 0)
				rd = 1;
			else if (rs1 < 0 && imm < 0)
				if (rs1 < imm)
					rd = 1;
				else
					rd = 0;
			else if (rs1 < 0 && imm >= 0)
				rd = 0;
        }
        else if(inst == "xori")
        {
            rd = rs1 ^ imm ;
        }
        else if(inst == "ori")
        {
            rd = rs1 | imm ;
        }
        else if(inst == "andi")
        {
            rd = rs1 & imm ;
        }
        else if(inst == "slli")
        {
            rd = rs1 << imm ;
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

    return;
}