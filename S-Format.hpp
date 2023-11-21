#ifndef S_FORMAT_HPP
#define S_FORMAT_HPP

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

bool SFormatChecker(string inst, bool& offset);
void SFormat(string inst, string inst_rest, vector<pair<string, long long int> > &reg, long long int &pc, bool &pc_changed , map< long long int , long long int >  &memory, bool &err , bool&offset);
void SextractStrings(string input, string& beforeParentheses, string& withinParentheses);

#endif 