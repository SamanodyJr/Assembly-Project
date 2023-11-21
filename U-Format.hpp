#ifndef U_FORMAT_HPP
#define U_FORMAT_HPP

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>


using namespace std;
bool UFormatChecker(string inst);
void UFormat(string inst, string inst_rest, vector<pair<string, int> > reg, int pc,map< int , int >  &memory, bool &err );
#endif