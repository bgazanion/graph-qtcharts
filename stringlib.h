#ifndef STRINGLIB_H
#define STRINGLIB_H

#include <string>
#include <vector>

using namespace std;

// functions to manipulate strings
vector<size_t> findAll(string inputStr, char target);
vector<string> split(string inputStr, char separator);
vector<string> renameDuplicates(vector<string> input);
string removeQuotes(string inputStr);
string strip(string inputStr);

#endif // STRINGLIB_H
