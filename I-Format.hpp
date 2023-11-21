#ifndef I_FORMAT_HPP
#define I_FORMAT_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IFormatChecker(string inst, bool& offset);
void IFormat(string inst, string inst_rest, vector<pair<string, long long int> > &reg, long long int &pc, bool &pc_changed , map< long long int , long long int >  &memory, bool &err , bool&offset);
void extractStrings(string input, string& beforeParentheses, string& withinParentheses);

#endif 