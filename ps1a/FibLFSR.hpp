// Copyright 2024 <Braden Maillet>
#pragma once
#include <stdio.h>
#include <bitset>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

#define DEBUG 1
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

        friend ostream& operator<<(ostream& out, FibLFSR Rhs);
 private:
        int _size;
        unsigned int _Binary;
        string _seed;
};
  FibLFSR::FibLFSR(string seed) {
    this->_seed = seed;
    this->_Binary = getstringtobi(*this);
    this->_size = seed.size();
  }

  int FibLFSR::step() {  // simulate one step
      int newbit = 0;
      int hold = 0;
      unsigned int largestbit = (static_cast<int>(pow(2, (this->_size - 1))));
      vector<unsigned int> taps = { 1024, 4096, 8192, largestbit};
      for (unsigned int i = 0; i < taps.size(); i++) {
          if ((taps.at(i) & this->_Binary) == taps.at(i))
              hold++;
      }
      if ((hold % 2) == 1)
          newbit = 1;
      // end of xor section
      if ((largestbit & this->_Binary) == largestbit) {
          this->_Binary = this->_Binary << 1;
          this->_Binary -= pow(2, this->_size);
          this->_Binary = this->_Binary | newbit;
      } else {
          this->_Binary = this->_Binary << 1;
          this->_Binary = this->_Binary | newbit;
      }
      cout << "DEBUG(string base10 newbit)" << " " <<
        this->getbitostring() << " " <<
        this->_Binary << " " << newbit << endl;

      return newbit;
  }
  int FibLFSR::generate(int k) {    // simulate k steps
     int hold;
     int result = 0;
     for (int i = 0; i < k; i++) {
         hold = this->step();
         LOG_DEBUG("hold: %d result: %d\n", hold, result);
         if ((result == 0) && (hold == 1)) {
             LOG_DEBUG("entering if statement in generate\n");
             result = 1;
             continue;
         }
         result = result << 1;
         result = result | hold;
     }
     LOG_DEBUG("final result: %d\n", result);
     return result;
  }
  int FibLFSR::getstringtobi(const FibLFSR& rhs) {
     int power = 1;
     int total = 0;
     for (int i = rhs._seed.size() - 1; i >= 0; i--) {
         if (rhs._seed[i] == '1') {
             total = total + power;
         }
         power *= 2;
     }
     return total;
  }
  string FibLFSR::getbitostring() {   // use mod approach
     string holder;
     int i, j, k;
     int temp = this->_Binary;
     if (temp == 0) {
         for (j = 0; j < this->_size; j++)
             holder.insert(0, "0");
         return holder;
     }
     for (i = 0; temp > 0; i++) {
         if ((temp % 2) == 0)
             holder.insert(0, "0");
         if ((temp % 2) == 1)
             holder.insert(0, "1");
         temp = temp / 2;
     }
     for (k = i; k < this->_size; k++) {
         holder.insert(0, "0");
     }
     return holder;
  }
  ostream& operator<<(ostream& out, FibLFSR rhs) {
    out << rhs.getbitostring();
    return out;
  }
}  // namespace PhotoMagic
