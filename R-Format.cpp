#include <iostream>
#include <vector>
#include "R-Format.hpp"
using namespace std;


void RFormat(string inst, string destination, string source1, string source2, vector<pair<string, int>> reg)
{
	// name inst 
	//substring 
	//
	int d = -1, s1 = -1, s2 = -1;
	for (size_t i = 0; i < reg.size(); ++i) {
		if (reg[i].first == destination) {
			d = i;
		}
		else if (reg[i].first == source1) {
			s1 = i;
		}
		else if (reg[i].first == source2) {
			s2 = i;
		}
	}
	if (d == -1 || s1 == -1 || s2 == -1) {
		cout << "Invalid entries." << endl;
	}
	else
	{
		if (inst == "add")
			reg[d].second = reg[s1].second + reg[s2].second;
		else if (inst == "sub")
			reg[d].second = reg[s1].second - reg[s2].second; // what if it is negative? needs consideration
		else if(inst =="sll")
			reg[d].second = reg[s1].second << reg[s2].second;
		else if(inst== "srl")
			reg[d].second = reg[s1].second >> reg[s2].second;
		else if (inst == "and")
			reg[d].second = reg[s1].second & reg[s2].second;
		else if (inst == "or")
			reg[d].second = reg[s1].second | reg[s2].second;
		else if (inst == "xor")
			reg[d].second = reg[s1].second ^ reg[s2].second;
		else if (inst == "sra")
			reg[d].second = reg[s1].second >> reg[s2].second;
		else if (inst == "slt")
		{
			if (reg[s1].second < reg[s2].second)
				reg[d].second = 0;
			else
				reg[d].second = 1;

		}
		else if (inst == "sltu")
		{
			if (reg[s1].second >= 0 && reg[s2].second>=0)
				if(reg[s1].second < reg[s2].second)
					reg[d].second = 1;
				else
					reg[d].second = 0;
			else if(reg[s1].second >= 0 && reg[s2].second < 0)
				reg[d].second = 1;
			else if (reg[s1].second < 0 && reg[s2].second < 0)
				if (reg[s1].second < reg[s2].second)
					reg[d].second = 1;
				else
					reg[d].second = 0;
			else if (reg[s1].second < 0 && reg[s2].second >= 0)
				reg[d].second = 0;
		}
	}
}