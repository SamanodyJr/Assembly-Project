#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
using namespace std;

void assembler();
void check_format(string inst, string inst_rest, vector<pair<string, long long int> > &reg, long long int& pc, map <long long int, long long int>& memory, bool& pc_changed, bool& err);
string removing_comments(string line);
void removeLeadingSpacesAndTabs(string& input);
void AddSpaces(string& input) ;
string storing_label(string line);
long long int Intializing_Data(string filepath, long long int pc, map< long long int, string >& instructions, map< string, long long int >& labels);
#endif