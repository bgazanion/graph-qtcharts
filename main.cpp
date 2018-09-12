#include <QApplication>

#include <iostream>
#include <vector>
#include <string>

#include "mainwindow.h"
#include "field.h"
#include "dataset.h"
#include "rng.h"
#include "stringlib.h"
#include "readers.h"


int main(int argc, char *argv[])
{
    //-- init RNG
    initRNG();

    //-- debug "field"
    /*
    Field f1;
    f1.print();

    Field f2;
    f2.setName("time");
    std::vector<float> v = {1, 5, 3, 8, 5, 7, 8, 54, 8, 5};
    f2.setSize(static_cast<unsigned int>(v.size()));
    f2.setData(v);
    f2.print();

    Field f3;
    f3.setSize(12);
    f3.randomize(0., 1.);
    f3.print();
    */

    //-- debug "dataset"
    /*
    Dataset dataset;
    int size = 20;
    dataset.setSize(size);
    for (int i=0; i<10; i++)
    {
        Field tmpField;
        tmpField.setSize( static_cast<unsigned int>(size) );
        tmpField.randomize(0., 1.);
        dataset.addField(tmpField);
    }
    dataset.printInfo();
    */

    //-- debug stringlib
    /*
    std::vector<std::string> testStr = { "zaekazjkjkl,adeaz,dazdazd,dzadz",
                                        "yoman",
                                        "",
                                        ",,,,,,,",
                                        "yrgre,",
                                        ",erzerez"
                                       };
    for (std::string t : testStr)
    {
        std::cout << "string tested: " << '"' << t << '"' << "\n";
        for (std::size_t index : findAll(t, ','))
        {
            std::cout << index << "\n";
        }
        for (std::string str : split(t, ','))
        {
            std::cout << "'" << str << "'" << "\n";
        }
        std::cout << std::endl;
    }
    */

    //-- debug CSV reader
    std::string fileName = "D:\\Prog\\datasets\\Rdatasets\\aids_cut_nice.csv";
    Dataset data = readCSV(fileName);
    data.printInfo();


    QApplication a(argc, argv);
    MainWindow w;
    // w.show();

    // return a.exec();

}
