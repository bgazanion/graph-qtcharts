#include "readers.h"

// CSV files
Dataset* readCSV(std::string fileName)
{
    // create dataset
    Dataset *dataset = new Dataset();

    // message window
    MessageWindow *messageWindow = new MessageWindow();

    // open the file
    std::ifstream input(fileName, std::ifstream::in);
    //input.clear();

    if (!input)
    {
        // error
        messageWindow->printError("CSV Reader",
                                  "Cannot open file",
                                  fileName);
        return nullptr;
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
    std::cout << "'" << headerStr << "'" << std::endl;
    for (unsigned int i=0; i<headerFields.size(); ++i)
    {
        std::cout << headerFields[i] << "   " << i << std::endl;
        headerFields[i] = strip(removeQuotes(headerFields[i]));
    }

    // create fields and dataset
    unsigned int nbFields = 0;
    dataset->setSize(nbLines);

    for (std::string str : headerFields)
    {
        Field newField;
        newField.setSize(nbLines);
        newField.setName(str);

        dataset->addField(newField);
        nbFields ++;
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

            if (splitStr.size() != nbFields)
            {
                messageWindow->printError("CSV Reader",
                                          "Wrong number of columns");
                return nullptr;
            }

            for (unsigned int i=0; i<splitStr.size(); ++i)
            {
                try
                {
                    value = std::stof(splitStr[i]);
                }
                catch (invalid_argument)
                {
                    messageWindow->printError("CSV Reader",
                                              "Cannot convert line data",
                                              splitStr[i]);
                    return nullptr;
                }
                dataset->setValue(headerFields[i], value, lineNumber);
            }

            // increment line number
            lineNumber ++;
        }
    }

    // set title
    std::string title;
    title = getBaseName(fileName);
    dataset->setTitle(title);

    // output
    return dataset;
}



// R files
Dataset* readR(std::string fileName)
{
    // create dataset
    Dataset *dataset = new Dataset();

    // message window
    MessageWindow *messageWindow = new MessageWindow();

    // open the file
    std::ifstream input(fileName, std::ifstream::in);
    //input.clear();

    if (!input)
    {
        // error
        messageWindow->printError("R Reader",
                                  "Cannot open file",
                                  fileName);
        return nullptr;
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
    unsigned int nbFields = 0;
    dataset->setSize(nbLines);

    for (std::string str : headerFields)
    {
        Field newField;
        newField.setSize(nbLines);
        newField.setName(str);

        dataset->addField(newField);
        nbFields ++;
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

            if (splitStr.size() != nbFields+1)
            {
                messageWindow->printError("R Reader",
                                          "Wrong number of columns");
                return nullptr;
            }

            for (unsigned int i=indexStart; i<splitStr.size(); ++i)
            {
                try
                {
                    value = std::stof(splitStr[i]);
                }
                catch (invalid_argument)
                {
                    messageWindow->printError("R Reader",
                                              "Cannot convert line data",
                                              splitStr[i]);
                    return nullptr;
                }
                dataset->setValue(headerFields[i-indexOffset], value, lineNumber);
            }

            // increment line number
            lineNumber ++;
        }
    }

    // set title
    std::string title;
    title = getBaseName(fileName);
    dataset->setTitle(title);

    // dummy output
    return dataset;
}
