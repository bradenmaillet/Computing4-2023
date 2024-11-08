//  Copyright Braden Maillet 2024
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
#include <exception>
#include <random>
#include <unordered_set>
#include "RandWriter.hpp"


using std::string;

//  might be a special case if 0
RandWriter::RandWriter(const string& text, size_t k) {
  //  current kgram;
  string temp;
  this->_K = k;
  if (text.size() < k) {
    throw std::logic_error("invalid k is larger than text size");
  }

  for (int i = 0; i < static_cast<int>(text.size()); ++i) {
    if (i + k < text.size()) {
        for (int j = 0; j < static_cast<int>(k); ++j) {
          temp.push_back(text.at(i + j));
        }
      //  search map if kgram already exists
      //  if it does exist, add one to its count
      //  if it doesn't push it onto the map with count 0
      //  look at next character aswell for kgram + 1
      if (_Kgrams.find(temp) == _Kgrams.end()) {
        kgram g(temp, 1);
        _Kgrams.insert(std::pair<string, kgram>(temp, g));
      } else {
        _Kgrams.at(temp).increment();
      }
      //  increment g + 1
      if (i + k < static_cast<size_t>(text.size())) {
        _Kgrams.at(temp).pushkplus1(text.at(i + k));
      } else {
        //  shouldn't need this but just incase
        _Kgrams.at(temp).pushkplus1(text.at((i + k) % text.size()));
      }
    //  wrap around case ***********
    } else {
      for (int x = 0; x < static_cast<int>(k); ++x) {
          temp.push_back(text.at(((i + x) % text.size())));
      }
      if (_Kgrams.find(temp) == _Kgrams.end()) {
        kgram g(temp, 1);
        _Kgrams.insert(std::pair<string, kgram>(temp, g));
      } else {
        _Kgrams.at(temp).increment();  //  idk if this works
      }
      //  increment g + 1 wrap arround
      //  dont have to plus one to i + k
      //  because of 0 count system
      if (i + k < text.size()) {
        _Kgrams.at(temp).pushkplus1(text.at(i + k));
      } else {
        //  std::cout << "DEBUG: index" << ((i + k) % text.size()) << std::endl;
        _Kgrams.at(temp).pushkplus1(text.at(((i + k) % text.size())));
      }
    }
    temp.clear();
  }
  //  create alphabet
  //  std::cout << "DEBUG ALPHA " << _alpha << std::endl;
  std::unordered_set<char> alpha;
  for (int z = 0; z < static_cast<int>(text.size()); ++z) {
    alpha.insert(text.at(z));
  }
  for (char c : alpha) {
        _alpha += c;
  }
}
// Number of occurences of kgram in text
// Throw an exception if kgram is not length k
int RandWriter::freq(const string& kgram) const {
  if (kgram.size() != this->orderK()) {
    throw std::logic_error("freq(): kgram is of invalid length");
  }
  try {
    return _Kgrams.at(kgram).getcount();
  }
  catch(std::exception& e) {
    return 0;
  }
}
// Number of times that character c follows kgram
// if order=0, return num of times that char c appears
// (throw an exception if kgram is not of length k)
int RandWriter::freq(const string& kgram, char c) const {
  if (kgram.size() != this->orderK()) {
    throw std::logic_error("freq(): kgram is of invalid length");
  }
  try {
    return _Kgrams.at(kgram).checkmap(c);
  }
  catch(std::exception& e) {
    return 0;
  }
}
// Random character following given kgram
// (throw an exception if kgram is not of length k)
// (throw an exception if no such kgram)
char RandWriter::kRand(const string& kgram) {
  if (kgram.size() != this->orderK() || freq(kgram) == 0) {
    throw std::logic_error("freq(): kgram is of invalid length");
  }
  std::vector<char> chars;
  std::vector<double> prob;
  std::random_device r;
  int temp;
  char selected_character;
  int index;
  for (int i = 0; i < static_cast<int>(_alpha.size()); ++i) {
    temp = freq(kgram, _alpha[i]);
    if (temp) {
      prob.push_back(temp);
      chars.push_back(_alpha[i]);
    }
  }
  std::discrete_distribution<> dist(prob.begin(), prob.end());
  std::mt19937 gen(r());
  index = dist(gen);
  selected_character = chars[index];
  return selected_character;
}
// Generate a string of length L characters by simulating a trajectory
// through the corresponding Markov chain. The first k characters of
// the newly generated string should be the argument kgram.
// Throw an exception if kgram is not of length k.
// Assume that L is at least k
string RandWriter::generate(const string& kgram, size_t L) {
  if (kgram.size() != this->orderK()) {
    throw std::logic_error("freq(): kgram is of invalid length");
  }
  string kg = kgram;
  string output;
  char temp;
  output = output + kg;
  for (int i = 0; i < (static_cast<int>(L - kgram.size())); ++i) {
    temp = kRand(kg);
    kg.erase(kg.begin());
    kg.push_back(temp);
    output.push_back(temp);
  }
  return output;
}
ostream& operator<<(ostream& o, const RandWriter& r) {
  //
  o << "order: " << r.orderK() << std::endl
    << "alphabet: " << r._alpha << std::endl
    << "k grams and their k + 1 grams: " << std::endl;

  for (auto it = r._Kgrams.begin(); it !=  r._Kgrams.end(); ++it) {
    o << "kgram and count: "
      << it->second.getgram()
      << " "
      << it->second.getcount()
      << std::endl;
      kgram temp = it->second;
    for (auto iter = temp.getmap().begin();
     iter != temp.getmap().end(); ++iter) {
      o << iter->first
        << " "
        << iter->second
        << std::endl;
    }
  }
  return o;
}
size_t RandWriter::orderK() const {
  if (_K < 0) {
    throw std::logic_error("invalid k");
  }
  return _K;
}

//  kgram class ****************
void kgram::pushkplus1(char c) {
  if (_kplus1.find(c) == _kplus1.end()) {
    _kplus1.insert(std::pair<char, int>(c, 1));
  } else {
    _kplus1.at(c)++;
  }
}

unsigned int kgram::checkmap(char c) const {
  try {
    return _kplus1.at(c);
  }
  catch(std::exception& e) {
    return 0;
  }
  return -1;
}
