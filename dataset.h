#ifndef DATASET_H
#define DATASET_H

#include <vector>
#include <array>
#include <string>
#include <iostream>

#include "field.h"


class Dataset
{
private:
    // number of fields
    unsigned int m_nbFields;
    // number of elements per field
    unsigned int m_size;
    // names of the fields
    std::vector<std::string> m_names;
    // fields
    std::vector<Field> m_fields;

public:
    // constructor
    Dataset();

    // set private members
    void setSize(unsigned int size);
    void addField(Field &field);
    void setValue(std::string name, float value, unsigned int index);

    // get private members & infos
    unsigned int getSize();
    unsigned int getNumberOfFields();
    std::vector<std::string> getNames();
    Field getField(std::string name);
    void printInfo();

};

#endif // DATASET_H
