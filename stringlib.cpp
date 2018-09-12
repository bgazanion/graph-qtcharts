#include "stringlib.h"

vector<size_t> findAll(string inputStr, char target)
{
    vector<size_t> result;

    for (size_t i=0; i<inputStr.length(); ++i)
    {
        if (inputStr[i]==target)
            result.push_back(i);
    }

    return result;
}


vector<string> split(string inputStr, char separator)
{
    // vector containing the positions of the separator in the string
    vector<size_t> pos = findAll(inputStr, separator);

    if (pos.empty())
    {
        // return the input string in a container
        return {inputStr};
    }

    else
    {
        // return a vector of sub-strings

        string tmpStr;

        // output vector
        vector<string> outputStr;

        // first position
        tmpStr = inputStr.substr(0, pos[0]);
        if (!tmpStr.empty())
            outputStr.push_back(tmpStr);

        // intermediate positions
        for (size_t i=0; i<pos.size()-1; ++i)
        {
            tmpStr = inputStr.substr(pos[i]+1, pos[i+1]-pos[i]-1);
            if (!tmpStr.empty())
                outputStr.push_back(tmpStr);
        }

        // last position
        tmpStr = inputStr.substr(pos.back()+1, inputStr.size()-1);
        if (!tmpStr.empty())
            outputStr.push_back(tmpStr);

        return outputStr;
    }

}


vector<string> renameDuplicates(vector<string> input)
{
    vector<string> output = input;
    int duplicates = 0;

    for (unsigned int index=0; index<input.size(); ++index)
    {
        // count number of duplicates in lower indices
        duplicates = 0;
        for (unsigned int i=0; i<index; ++i)
        {
            if ( (i!=index) && (input[i]==input[index]) )
            {
                duplicates ++;
            }
        }

        // rename if required
        if (duplicates > 0)
        {
            output[index] += "_";
            output[index] += to_string(duplicates);
        }
    }

    return output;
}
