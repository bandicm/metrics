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
     * Klasa za mjerenje proizvoljne statistike
    */

class Metrics {
    mutex io;
    map<string, uint> counters;

    public:

    Metrics ();
    Metrics (map<string, uint> _counters);

    /**
     * Operator[] za pristup svakoj brojaču mjerenja
    */
    uint& operator[](const string& key) {
        return counters[key];
    }

    /**
     * Operator++ za inkrementalno povećanje brojača mjerenja
    */
    Metrics& operator++ (int n) {
        lock_guard<mutex> _io(io);
        n++;
        return *this;
    }

    void set(map<string, uint> _counters) {
        counters = _counters;
    }

    /**
     * Metoda za resetiranje brojača
    */
    void clear();

    /**
     * Metoda koja vraća vektor stringova svih naziva brojača
    */
    vector<string> keys();

    /**
     * Metoda vraća map<string, uint> svih mjerenja
    */
    map<string, uint> get_data();

    /**
     * Metoda vraća map<string, uint> svih mjerenja i resetira brojače
    */
    map<string, uint> get_data_and_clear();
    

};


}

#endif