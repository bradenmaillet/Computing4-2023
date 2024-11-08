// Copyright 2024 <Braden Maillet>
#include "FibLFSR.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;

PhotoMagic::FibLFSR::FibLFSR(string seed) {
    this->_seed = seed;
    this->_Binary = getstringtobi(*this);
    this->_size = seed.size();
}

int PhotoMagic::FibLFSR::step() {  // simulate one step
    int newbit = 0;
    int hold = 0;
    unsigned int largestbit = (static_cast<int>(pow(2, (this->_size - 1))));
    vector<unsigned int> taps = { 1024, 4096, 8192, largestbit };
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
    return newbit;
}
int PhotoMagic::FibLFSR::generate(int k) {    // simulate k steps
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
int PhotoMagic::FibLFSR::getstringtobi(const PhotoMagic::FibLFSR& rhs) {
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
string PhotoMagic::FibLFSR::getbitostring() {   // use mod approach
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
namespace PhotoMagic {
  ostream& operator<<(ostream& out, FibLFSR& Rhs) {
    out << Rhs.getbitostring();
    return out;
  }
}  //  end of PhotoMagic

