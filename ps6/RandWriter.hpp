//  CopyRight 2024 Braden Maillet
#pragma once
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <utility>

using std::string;
using std::map;
using std::ostream;
using std::vector;
using std::pair;

//  kgram class for map
class kgram {
 public:
  kgram(string kgram, int count) :
    _gram(kgram), _count(count), _kplus1() {}
  void pushkplus1(char c);
  void increment() {_count++;}

  unsigned int checkmap(char c) const;
  string getgram() const {return _gram;}
  unsigned int getcount() const {return _count;}
  unsigned int getcountkplus1(char c) {return _kplus1.at(c);}
  map<char, unsigned int>& getmap() {return _kplus1;}
 private:
  string _gram;
  unsigned int _count;
  //  vector<pair<char, unsigned int>> _k1;
  map<char, unsigned int> _kplus1;
};

class RandWriter {
 public:
// Create a Markov model of order k from given text
// Assume that text has length at least k.
  RandWriter(const string& text, size_t k);
  // Order k of Markov model
  size_t orderK() const;
// Number of occurences of kgram in text
// Throw an exception if kgram is not length k
  int freq(const string& kgram) const;
// Number of times that character c follows kgram
// if order=0, return num of times that char c appears
// (throw an exception if kgram is not of length k)
  int freq(const string& kgram, char c) const;
// Random character following given kgram
// (throw an exception if kgram is not of length k)
// (throw an exception if no such kgram)
  char kRand(const string& kgram);
// Generate a string of length L characters by simulating a trajectory
// through the corresponding Markov chain. The first k characters of
// the newly generated string should be the argument kgram.
// Throw an exception if kgram is not of length k.
// Assume that L is at least k
  string generate(const string& kgram, size_t L);
  friend ostream& operator<<(ostream& o, const RandWriter& r);

 private:
  int _K;
  string _alpha;
  //  key value
  map<string, kgram> _Kgrams;
};
// Overload the stream insertion operator << and display the internal state
// of the Markov model. Print out the order, alphabet, and the frequencies
// of the k-grams and k+1-grams
