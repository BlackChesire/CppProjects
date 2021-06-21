

#ifndef _PARSER_H
#define _PARSER_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include "Counter.h"
#include <stdexcept>

using namespace  std;

class Parser{
private:
    vector<Counter<int> > intCounterCollection;
    vector<Counter<string> > stringCounterCollection;

public:
    // constructor
    Parser();
    // destructor
    ~Parser(){};
    // translate the commands input
    void translateCommands();

    // checking command input
    static void checkCmdInput(const string& command) ;
    // checking if the the name of the counter input correctly
    static void checkFailInputNameFile(const string& file);
    // printing error message and exit the program whether the file was not opened
    static void fileOpenFailed(ifstream& file);
    // checking if the the name of the file input correctly
    static void checkFailInputCounterName(istringstream& iss);
    // checking whether the name of counter already exist, if exist, it print error message and exit program
    void checkExistCounterName(const string& counterName) const;
    // using when read from file/standard input
    // checking if the require counter exist in the int or string counters, print message error if is not exist
    void checkExistCounter(const string& counterName) const;
    // return true whether the require counter is int counter, false otherwise
    bool isItIntCounter(const string& counterName) const;
    // return true whether the require counter is string counter, false otherwise
    bool isItStringCounter(const string& counterName) const;
    // return true whether the require counter is empty, false otherwise
    bool checkIfEmpty(const string& counterName);

    // adding int/string counter to the int/string counter collection from file
    void addFromFile(const string& counterName, const string& fileName);
    // adding int/string counter to the int/string counter collection from the standard input
    void addFromString(const string& counterName, const string& str);
    // printing the states of the require counter
    void printStates(const string& counterName);

    // return the require counter from the int counter collection, throw "not found" if not found
    Counter<int>& findIntCounter(const string& counterName);
    // return the require counter from the string counter collection, throw "not found" if not found
    Counter<string>& findStringCounter(const string& counterName);

    // print the most common in the require counter
    void printMostCommon(const string& counterName);
};

// checking if the type of the value matching to the type of the counter,
// inserted from files/standard input, printing error message whether.
template<class T>
vector<T> parse_vector(const string& str){
    vector<T> vec;
    istringstream ss(str);
    T temp;
    while(!ss.eof())
    {
        ss >> temp;
        if(!ss)
        {
           cerr << "Error: Read failed" << endl;
           exit(-6);
        }
        vec.push_back(temp);
    }
    return vec;
}


#endif _PARSER_H
