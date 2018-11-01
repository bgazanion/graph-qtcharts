#include "readers.h"

// CSV files
Dataset readCSV(std::string fileName)
{
    // open the file
    std::ifstream input(fileName, std::ifstream::in);
    //input.clear();

    if (!input)
    {
        // error
        std::cerr << "readCSV: cannot open file " << fileName << std::endl;
        return Dataset();
    }


    // temporary container for strings
    std::string tmpStr = "";

    // read the file structure: comments, header and number of lines
    std::string headerStr = "";
    unsigned int nbLines = 0;

    while (getline(input, tmpStr))
    {
        // skip comments and empty lines
        if ( (tmpStr[0] != '#') && (!tmpStr.empty()) )
        {
            if (headerStr == "")
            {
                // header: supposed to be the first line after comments
                headerStr = tmpStr;
            }
            else
            {
                // new line of data
                nbLines += 1;
            }
        }
    }

    // the end of the file has been reached -> remove eof flag
    input.clear();

    // process header to get fields names
    std::vector<std::string> initHeaderFields = split(headerStr, ',');
    std::vector<std::string> headerFields = renameDuplicates(initHeaderFields);

    // create fields and dataset
    Dataset dataset;
    dataset.setSize(nbLines);

    for (std::string str : headerFields)
    {
        Field newField;
        newField.setSize(nbLines);
        newField.setName(str);

        dataset.addField(newField);
    }

    // go back to header and skip header
    input.clear();
    input.seekg(input.beg);
    input >> tmpStr;

    // read the data part line by line
    std::vector<std::string> splitStr;
    std::string fieldName;
    unsigned int lineNumber = 0;
    float value;
    Field tmpField;

    while (getline(input, tmpStr))
    {
        // skip comments and empty lines
        if ( (tmpStr[0] != '#') && (!tmpStr.empty()) )
        {
            // split the line and store pieces in the corresponding fields
            splitStr = split(tmpStr, ',');
            for (unsigned int i=0; i<splitStr.size(); ++i)
            {
                value = std::stof(splitStr[i]);
                dataset.setValue(headerFields[i], value, lineNumber);
            }

            // increment line number
            lineNumber ++;
        }
    }

    // dummy output
    return dataset;
}



// R files
Dataset readR(std::string fileName)
{
    // open the file
    std::ifstream input(fileName, std::ifstream::in);
    //input.clear();

    if (!input)
    {
        // error
        std::cerr << "readR: cannot open file " << fileName << std::endl;
        return Dataset();
    }


    // temporary container for strings
    std::string tmpStr = "";

    // read the file structure: comments, header and number of lines
    std::string headerStr = "";
    unsigned int nbLines = 0;

    while (getline(input, tmpStr))
    {
        // skip comments and empty lines
        if ( (tmpStr[0] != '#') && (!tmpStr.empty()) )
        {
            if (headerStr == "")
            {
                // header: supposed to be the first line after comments
                headerStr = tmpStr;
            }
            else
            {
                // new line of data
                nbLines += 1;
            }
        }
    }

    // the end of the file has been reached -> remove eof flag
    input.clear();


    // process header to get fields names
    std::vector<std::string> initHeaderFields = split(headerStr, ',');
    //   NB: if R index ("") is in the fields, remove it
    unsigned int indexStart = 0;
    unsigned int indexOffset = 0;
    if (initHeaderFields[0] == "\"\"")
    {
        initHeaderFields.erase(initHeaderFields.begin());
        indexStart = 1;
        indexOffset = 1;
    }
    std::vector<std::string> headerFields = renameDuplicates(initHeaderFields);
    for (unsigned int i=0; i<headerFields.size(); ++i)
    {
        headerFields[i] = strip(removeQuotes(headerFields[i]));
    }

    // create fields and dataset
    Dataset dataset;
    dataset.setSize(nbLines);

    for (std::string str : headerFields)
    {
        Field newField;
        newField.setSize(nbLines);
        newField.setName(str);

        dataset.addField(newField);
    }

    // go back to header and skip header
    input.clear();
    input.seekg(input.beg);
    input >> tmpStr;

    // read the data part line by line
    std::vector<std::string> splitStr;
    std::string fieldName;
    unsigned int lineNumber = 0;
    float value;
    Field tmpField;

    while (getline(input, tmpStr))
    {
        // skip comments and empty lines
        if ( (tmpStr[0] != '#') && (!tmpStr.empty()) )
        {
            // split the line and store pieces in the corresponding fields
            splitStr = split(tmpStr, ',');
            for (unsigned int i=indexStart; i<splitStr.size(); ++i)
            {
                value = std::stof(splitStr[i]);
                dataset.setValue(headerFields[i-indexOffset], value, lineNumber);
            }

            // increment line number
            lineNumber ++;
        }
    }

    // dummy output
    return dataset;
}
