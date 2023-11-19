#ifndef I_FORMAT_HPP
#define I_FORMAT_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IFormat_Checker(string inst);
void IFormat(string inst, string inst_rest, vector<pair<string, int> > reg, int pc, bool pc_changed , map< int , string >  memory);

#endif 