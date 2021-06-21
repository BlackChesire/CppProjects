
#include "Parser.h"
#include <stdexcept>

Parser::Parser() {}

using namespace std;

void Parser::translateCommands() {
    string command;
    string counterName;
    string value;
    string fileName;
    while (getline(cin, value))
    {
        istringstream iStrStream(value);
        iStrStream >> command;
        checkCmdInput(command);

        iStrStream >> counterName;
        checkFailInputCounterName(iStrStream);
        if ((command == "string_counter") || (command == "int_counter"))
        {
            checkExistCounterName(counterName);
            if (command == "string_counter")
            {
                stringCounterCollection.push_back(Counter<string>(counterName));
            }
            else if (command == "int_counter")
            {
                intCounterCollection.push_back(Counter<int>(counterName));
            }
        }
        else if (command == "add_from_file")
        {
            checkExistCounter(counterName);
            iStrStream >> fileName;
            checkFailInputNameFile(fileName); // if didnt enter file name then print "Error: Missing file name" and exit
            addFromFile(counterName, fileName);
        }
        else if (command == "add_from_string")
        {
            checkExistCounter(counterName);
            string rest;
            getline(iStrStream, rest);
            addFromString(counterName, rest);
        }
        else if (command == "stats")
        {
            checkExistCounter(counterName);
            printStates(counterName);
        }
        else if (command == "most_common")
        {
            checkExistCounter(counterName);
            printMostCommon(counterName);
        }
    }
}

void Parser::checkCmdInput(const string& command) {
    if(!((command == "string_counter") || (command == "int_counter") || (command == "add_from_file") ||
    (command == "add_from_string") || (command == "stats") || (command == "most_common")))
    {
        cerr<< "Error: Unknown command "<<command<<endl;
        exit(-1);
    }
}

void Parser::checkFailInputNameFile(const string& file) {
    if (file.empty())
    {
        cerr << "Error: Missing file name" << endl;
        exit(-2);
    }
}

void Parser::fileOpenFailed(ifstream &file) {
    if(!file)
    {
        cerr << "Error: Failed to open file" << endl;
        exit(-3);
    }
}

void Parser::checkFailInputCounterName(istringstream &iss) {
    if (iss.fail())
    {
        cerr << "Error: Missing counter name" << endl;
        exit(-4);
    }
}

void Parser::checkExistCounterName(const string &counterName) const {
    for (unsigned int i = 0; i < intCounterCollection.size(); i++)
    {
        if (intCounterCollection[i].getName() == counterName)
        {
            cerr << "Error: Counter name already exists" << endl;
            exit(-4);
        }
    }
    for (unsigned int i = 0; i < stringCounterCollection.size(); i++)
    {
        if (stringCounterCollection[i].getName() == counterName)
        {
            cerr << "Counter name already exists" << endl;
            exit(-4);
        }
    }
}

void Parser::checkExistCounter(const string &counterName) const{
    for (unsigned  int i = 0; i < intCounterCollection.size(); i++)
    {
        if (intCounterCollection[i].getName() == counterName)
        {
            return;
        }
    }
    for (unsigned  int i = 0; i < stringCounterCollection.size(); i++)
    {
        if (stringCounterCollection[i].getName() == counterName)
        {
            return;
        }
    }
    // if the counter is not exist in one of the counters then print message error and exit program
    cerr << "Error: No counter named " << counterName << endl;
    exit(-5);
}

bool Parser::isItIntCounter(const string &counterName) const {
    for (unsigned int i = 0; i < intCounterCollection.size(); i++)
    {
        if (intCounterCollection[i].getName() == counterName)
        {
            return true;
        }
    }
    return false;
}

bool Parser::isItStringCounter(const string &counterName) const {
    for (unsigned int i = 0; i < stringCounterCollection.size(); i++)
    {
        if (stringCounterCollection[i].getName() == counterName)
        {
            return true;
        }
    }
    return false;
}

void Parser::addFromFile(const string &counterName, const string &fileName) {
    string val;
    string str;

    ifstream file(fileName.c_str(),ios::in);
    fileOpenFailed(file);

    while(getline(file, str))
    {
        istringstream iss(str);
        while(iss>>val)
        {
            if (isItIntCounter(counterName))
            {
                Counter<int>& c = findIntCounter(counterName);
                vector<int> values = parse_vector<int>(val);
                for (unsigned int i = 0; i < values.size(); i++)
                {
                    c.add(values[i]);
                }
            }
            else if (isItStringCounter(counterName))
            {
                Counter<string>& c = findStringCounter(counterName);
                vector<string> values = parse_vector<string>(val);
                for (unsigned int i = 0; i < values.size(); i++)
                {
                    c.add(values[i]);
                }
            }
        }
    }

    file.close();
}

void Parser::addFromString(const string &counterName, const string &str) {
    checkExistCounter(counterName);
    if (isItIntCounter(counterName))
    {
        Counter<int>& intCounter = findIntCounter(counterName);
        vector<int> values = parse_vector<int>(str);
        for (unsigned int i = 0; i < values.size(); i++)
        {
            intCounter.add(values[i]);
        }
    }
    else if(isItStringCounter(counterName)){
        Counter<string>& stringCounter = findStringCounter(counterName);
        vector<string> values = parse_vector<string>(str);
        for (unsigned int i = 0; i < values.size(); i++)
        {
            stringCounter.add(values[i]);
        }
    }
}

Counter<int> &Parser::findIntCounter(const string &counterName) {
    for (unsigned int i = 0; i < intCounterCollection.size(); i++) {
        if (intCounterCollection[i].getName() == counterName) {
            return intCounterCollection[i];
        }
    }
    throw exception();
}

Counter<string> &Parser::findStringCounter(const string &counterName) {
    for (unsigned int i = 0; i < stringCounterCollection.size(); i++) {
        if (stringCounterCollection[i].getName() == counterName) {
            return stringCounterCollection[i];
        }
    }
    throw exception();
}

void Parser::printStates(const string& counterName) {
    if (isItIntCounter(counterName))
    {
        Counter<int> counter = findIntCounter(counterName);
        cout << "counter " << counter.getName() << " = ";
        counter.print_to_stream(cout);
        cout << endl;
    }
    else if (isItStringCounter(counterName))
    {
        Counter<string> counter = findStringCounter(counterName);
        cout << "counter " << counter.getName() << " = ";
        counter.print_to_stream(cout);
        cout << endl;
    }
}

bool Parser::checkIfEmpty(const string &counterName){
    if(isItIntCounter(counterName))
    {
        if(findIntCounter(counterName).getSize() != 0)
        {
            return false;
        }
    }
    else if(isItStringCounter(counterName))
    {
        if (findStringCounter(counterName).getSize() != 0)
        {
            return false;
        }
    }
    return true;
}

void Parser::printMostCommon(const string& counterName) {
    if(checkIfEmpty(counterName))
    {
        cerr << "Error: Counter is empty" << endl;
        exit(-7);
    }
    else if(isItIntCounter(counterName)) {
        cout << "most common element for counter " << counterName <<" is "
        << findIntCounter(counterName).most_common() << endl;
    }
    else if(isItStringCounter(counterName))
    {
        cout << "most common element for counter " << counterName <<" is "
         << findStringCounter(counterName).most_common() << endl;
    }
}
