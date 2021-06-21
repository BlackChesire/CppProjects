#ifndef _32_EX5_312391774_316373497_COUNTER_H
#define _32_EX5_312391774_316373497_COUNTER_H

#include <vector>
#include <iostream>
#include <exception>
#include <fstream>
#include <algorithm>

template <class T>
struct Pair{
    // will the added values by {value:number of instances}
    explicit Pair(T value) : value(value), instances(1) {}
    Pair(T value, int instances) : value(value), instances(instances){};
    T   value;
    int instances; // the times it appears.

};

// help to compare between the values and the instances of pairs
template <class K>
struct PairComparator{
    bool operator()(const Pair<K>& a, const Pair<K>& b)
    {
        if(a.value == b.value)
        {
            return (a.instances < b.instances);
        }
        return (a.value < b.value);
    }
};


template <class K>
class Counter{
private:
    int size; // counting the Pairs.
    std::string name; // the name of the array
    std::vector<Pair<K> > array; // will store the values

public:
    // default constructor
    Counter():size(0), name(" "){};
    // constructor
    explicit Counter(const std::string& name) : size(0),name(name){};
    // copy constructor
    Counter(const Counter<K>& other):size(other.size),name(other.name),array(other.array){};
    // destructor
    ~Counter(){};

    Counter& operator=(const Counter& rhs){
        clear();
        size = rhs.size;
        name = rhs.name;
        array = rhs.array; // will use operator = of std::vector
        return *this;
    }

    //clears the counter to 0
    void clear(){
        array.clear();
        size = 0;
    }

    // adds element to the array
    void add(K type){
        if (size == 0)
        {
            array.push_back(Pair<K>(type));
            size++;
        }
        else{
            for (int i = 0; i < size; ++i)
            {
                if (array[i].value == type)
                {
                    array[i].instances++;
                    return;
                }
            }
            array.push_back(Pair<K>(type));
            size++;
        }
    }

    // finds the amount of the type's instances
    int operator[] (const K type){
        for (int i=0; i < size; ++i)
        {
            if (array[i].value == type)
            {
                return array[i].instances;
            }
        }
        return 0;
    }

    // returns the most common Pair in the array
    Pair<K> most_common(){
        Pair<K> max(array[0].value);
        max.instances = 0;

        for (int i=0; i < size; i++)
        {
            if (array[i].instances > max.instances)
            {
                max = array[i];
            }
            else if (array[i].instances == max.instances)
            {
                max = (array[i].value < max.value) ? array[i] : max;
            } // if equals then max will be the lowest value between the two
        }
        return max;
    }

    // gets input from stream
    void add_from_stream(std::istream& in){
        K elem;
        while(in >> elem)
        {
            add(elem);
            if(in.fail()) { throw std::exception();}
        }
    }

    // prints to the ostream
    void print_to_stream(std::ostream& out){
       sort();
       if(size == 0)
       {
           out << "{ }";
       }
       else{
           out << "{ ";
           for (int i = 0; i < size; i++)
           {
               out << array[i];
               if (i != (size - 1))
               {
                   out << " ";
               }
           }
           out << " }";
       }
    }

    // prints the most common to the outStream, throws exception whether the array is empty
    void print_most_common(std::ostream& out){
        if (size == 0)
        {
            throw std::exception();
        }
        out << most_common();
    }

    //sorting by instances
    void sort() {
        std::sort(array.begin(),array.end(), PairComparator<K>());
    }

    // returns the size of the array.
    unsigned int getSize() const {
        return size;
    }

    // returns the name of the array.
    std::string getName() const{
        return name;
    }

};

// global function
template <class K>
std::ostream &operator<<(std::ostream &os, const Pair<K> &pair){
    os << pair.value << ":" <<pair.instances;
    return os;
}

#endif //_32_EX5_312391774_316373497_COUNTER_H