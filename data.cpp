#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "data.hpp"
#include "R-Format.cpp"
#include "I-Format.cpp"

using namespace std;
// C:\Users\noury\OneDrive\Documents\Assembly\Project1\Assembly-Project\input.asm
void assembler()
{
	int pc;
	int ans(1);
	string filepath;
	vector<pair<string, int> > reg;
	reg.push_back(make_pair("Zero", 0)); reg.push_back(make_pair("ra", 0)); reg.push_back(make_pair("sp", 34359672828));
	reg.push_back(make_pair("gp", 268468224)); reg.push_back(make_pair("tp", 0)); reg.push_back(make_pair("t0", 0));
	reg.push_back(make_pair("t1", 0)); reg.push_back(make_pair("t2", 0)); reg.push_back(make_pair("s0", 0));
	reg.push_back(make_pair("s1", 0)); reg.push_back(make_pair("a0", 0)); reg.push_back(make_pair("a1", 0));
	reg.push_back(make_pair("a2", 0)); reg.push_back(make_pair("a3", 0)); reg.push_back(make_pair("a4", 0));
	reg.push_back(make_pair("a5", 0)); reg.push_back(make_pair("a6", 0)); reg.push_back(make_pair("a7", 0));
	reg.push_back(make_pair("s2", 0)); reg.push_back(make_pair("s3", 0)); reg.push_back(make_pair("s4", 0));
	reg.push_back(make_pair("s5", 0)); reg.push_back(make_pair("s6", 0)); reg.push_back(make_pair("s7", 0));
	reg.push_back(make_pair("s8", 0)); reg.push_back(make_pair("s9", 0)); reg.push_back(make_pair("s10", 0));
	reg.push_back(make_pair("s11", 0)); reg.push_back(make_pair("t3", 0)); reg.push_back(make_pair("t4", 0));
	reg.push_back(make_pair("t5", 0)); reg.push_back(make_pair("t6", 0));
	do
	{

		cout << "~~~~~~~~~~~~~~~~~~Welcome to your RISC-V simulator~~~~~~~~~~~~~~~~ \n\n";
		cout << "\t\tWhat would you like to do?\n\n"
			<< "\t\t  1. Read from an exisisting file\n\t\t  2. Exit\n";

		if (ans < 1 || ans > 2)
		{
			cout << "invalid number entered try again \n";
		}
		cout << "option:";
		cin >> ans;

	} while (ans > 2 || ans < 1);

	if (ans == 1)
	{
		map < int, int > memory;
		map < int, string> instructions;
		map < string, int> labels;
		int end;
		int memadd, memvalue; //initializing data memory if user wants
		string mem;//flag to know if they want to initialize their data memory

		cout << "enter your file path\n";
		cin >> filepath;

		cout << "enter your starting PC\n";
		cin >> pc;

		end = Intializing_Data(filepath, pc, instructions, labels);

		cout << "Do you want to initialize your memory ? yes/Yes \n";
		cin >> mem;

		while (mem == "yes" || mem == "Yes")
		{
			cout << "enter the memory address: ";
			cin >> memadd;
			cout << "enter the corresponding memory value: ";
			cin >> memvalue;

			memory[memadd] = memvalue;

			cout << "Do you want to initialize another thing in your memory? yes/Yes \n";
			cin >> mem;
		}

		cout <<  " memory\n";
		
		for (const auto& pair : memory) 
		{
			cout << "Address: " << pair.first << ", Value: " << pair.second << endl;
		}

		int startpc(pc);
		bool pc_changed(false);

		
		do{
			stringstream instruction(instructions[pc]);
        	string store;
			string temp;

        	
        	if (instruction >> store) {
				store.erase(remove(store.begin(), store.end(), ' '), store.end());
				temp = store;
			}

			string concat;
        	concat = instructions[pc];
        	int i = concat.find(temp);
        	concat.erase(i,temp.length());
			
        	check_format(temp, concat, reg, pc, memory, pc_changed);

			if(!pc_changed )
        		pc += 4;
			
		}while(pc != end+4);
	}
	else
		exit(1);
}

void removeLeadingSpacesAndTabs(string& input) {
    int start = input.find_first_not_of(" \t"); // Find the first character that is not a space or tab
    if (start != string::npos) {
        input = input.substr(start); // Modify the input string to start from the first non-space/tab character
    } else {
        input = ""; // If the input is all spaces and tabs, set the input string to an empty string
    }
}

void check_format(string inst, string inst_rest, vector<pair<string, int> > reg, int &pc, map <int , int> &memory, bool &pc_changed) // name , string
{
	pc_changed = false;
	// if(RFormatChecker(inst))
	// {
	// 	//RFormat(inst, inst_rest, reg);
	// }
	// else 
	if(IFormatChecker(inst))
	{
		IFormat(inst, inst_rest, reg, pc, pc_changed,  memory);
	}
	else
		cout << "not defined yet bas hi\n";
   
};

string removing_comments(string line)
{
	string new_line;
	size_t found = line.find('#');
	if (found != string::npos)
	{
		int i = 0;
		while (line[i] != '#')
		{
			new_line += line[i];
			i++;
		}

		return new_line;
	}
	else
		return line;
}
string storing_label(string line)
{
	string new_line;
	size_t found = line.find(':');
	if (found != string::npos)
	{
		int i = 0;
		while (line[i] != ':')
		{
			new_line += line[i];
			i++;
		}

		return new_line;
	}
	else
		return line;
}
int Intializing_Data(string filepath, int pc, map< int, string> &instructions, map<string, int> &labels)
{
	//C:\Users\noury\OneDrive\Documents\Assembly\Project1\Assembly-Project\input.asm

	ifstream input(filepath);
	

	string line;
	string label="";
	if (input.is_open())
	{
		getline(input, line);
		if (line[0] == '#' || line == "")
		{
			getline(input, line);
			line = removing_comments(line);
		}
		size_t found = line.find(':');
		if (found != string::npos)
		{
			int i = 0;
			while (line[i] != ':')
			{
				label += line[i];
				i++;
			}
			labels[label] = pc;
			getline(input, line);
			line = removing_comments(line);
			removeLeadingSpacesAndTabs(line);
			instructions[pc] = line;
			while (!input.eof())
			{
				label = "";
				getline(input, line);
				line = removing_comments(line);
				label = storing_label(line);
				if (label != line)
				{
					labels[label] = pc + 4;
				}
				else
				{
					removeLeadingSpacesAndTabs(line);
					pc += 4;
					instructions[pc] = line;
				}

			}
		}
		
	}
	input.close();
	int end = pc;

	cout << " label\n";
	for (const auto& pair : labels) {
		cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
	}
	cout <<  " instructions\n";
	for (const auto& pair : instructions) {
		cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
	}

	return end;
}