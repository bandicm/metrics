#ifndef _MTRC_
#define _MTRC_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <mutex>

using namespace std;

namespace marcelb {

/**
 * A class for measuring arbitrary statistics
*/
class Metrics {
    mutex io;
    map<string, uint> counters;

    public:

    /**
     * Constructor, without predefining the name of the counter
    */
    Metrics ();

    /**
     * Constructor, with predefined counters from the passed object
    */
    Metrics (map<string, uint> _counters);

    /**
     * Operator[] to access each measurement counter
    */
    uint& operator[](const string& key) {
        return counters[key];
    }

    /**
     * Operator++ to increment the measurement counter incrementally
    */
    Metrics& operator++ (int n) {
        lock_guard<mutex> _io(io);
        n++;
        return *this;
    }

    /**
     * Method to set the counter from the passed object
    */
    void set(map<string, uint> _counters) {
        counters = _counters;
    }

    /**
     * A method to reset the counter
    */
    void clear();

    /**
     * A method that returns a vector os strings of all counter names
    */
    vector<string> keys();

    /**
     * The method returns a map<string, uint> of all measurements
    */
    map<string, uint> get_data();

    /**
     * The method returns a map<string, uint> of all measurements and resets the counters
    */
    map<string, uint> get_data_and_clear();
    

};


}

#endif