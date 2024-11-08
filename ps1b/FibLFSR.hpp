// Copyright 2024 <Braden Maillet>
#pragma once
#include <stdio.h>
#include <bitset>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#define DEBUG 0
#define LOG_DEBUG if (DEBUG) printf ("DEBUG - "); if (DEBUG)printf

using std::bitset;
using std::string;
using std::endl;
using std::cout;
using std::ostream;
using std::vector;

namespace PhotoMagic {
class FibLFSR {
 public:
        explicit FibLFSR(string seed);
        FibLFSR() = delete;
        int step();
        int generate(int k);
        int getsize() { return _size; }
        int getbi() { return _Binary; }
        string& getseed() { return _seed; }
        string getstring() { return this->getbitostring(); }
        int getstringtobi(const FibLFSR& rhs);
        string getbitostring();

        friend ostream& operator<<(ostream& out, FibLFSR& Rhs);
 private:
        int _size;
        unsigned int _Binary;
        string _seed;
};
}  // namespace PhotoMagic
