#include "dataset.h"

Dataset::Dataset()
{
    m_nbFields = 0;
    m_size = 0;
    m_names = {};
    m_fields = {};
}


void Dataset::setSize(int size)
{
    m_size = static_cast<unsigned int>(size);
}


void Dataset::addField(Field field)
{
    // check that the new field has the same size as the dataset
    if (field.getSize() == m_size)
    {
        m_fields.push_back(field);
        m_nbFields += 1;
        m_names.push_back(field.getName());
    }
    else
    {
        std::cout << "addField: size mismatch" << std::endl;
    }
}


unsigned int Dataset::getSize()
{
    return m_size;
}


unsigned int Dataset::getNumberOfFields()
{
    return m_nbFields;
}


std::vector<std::string> Dataset::getNames()
{
    return m_names;
}


Field Dataset::getField(std::string name)
{
    for (Field field : m_fields)
    {
        if (field.getName() == name)
        {
            return field;
        }
    }

    // return empty field if the requested field is not found
    std::cout << "getField: requested field not found" << std::endl;
    return Field();
}


void Dataset::printInfo()
{
    std::cout << "---- info ----" << "\n";
    std::cout << "  size:             " << this->getSize() << "\n";
    std::cout << "  number of fields: " << this->getNumberOfFields() << "\n";
    std::cout << "---- fields ----" << "\n";
    for (std::string name : this->getNames())
    {
        std::array<float, 2> range = this->getField(name).getRange();
        std::cout << "  " << name << ": [" << range[0] << ", " << range[1] << "]" << "\n";
    }
    std::cout << std::endl;

}

