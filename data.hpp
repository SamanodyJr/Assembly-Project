#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
using namespace std;

void assembler();
void check_format(string inst, string inst_rest, vector<pair<string, int> > reg, int &pc, map <int , int> &memory, bool &pc_changed);
string removing_comments(string line);
string storing_label(string line);
int Intializing_Data(string filepath, int pc , map< int , string > &instructions, map< string, int > &labels);
#endif 
