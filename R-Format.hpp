#ifndef R_FORMAT_HPP
#define R_FORMAT_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool RFormatChecker(string inst);
void RFormat(string inst, string inst_rest, vector<pair<string, long long int> > &reg, bool err);


#endif 
