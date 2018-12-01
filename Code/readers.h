#ifndef READERS_H
#define READERS_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <QMessageBox>

#include "dataset.h"
#include "stringlib.h"
#include "messagewindow.h"


// CSV files
Dataset* readCSV(std::string fileName);
Dataset* readR(std::string fileName);



#endif // READERS_H
