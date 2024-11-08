// Copyright 2024 Braden Maillet
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "RandWriter.hpp"

int main(int argc, char* argv[]) {
  size_t k = static_cast<size_t>(atoi(argv[1]));
  int output = atoi(argv[2]);
  string kgr;
  string text;
  string line;
  while (std::getline(std::cin, line)) {
        text += line;  //  Append the line and add newline character
  }
  //  std::cout << text << " " << text.size() << std::endl;
  RandWriter r(text, k);
  for (int i = 0; i < static_cast<int>(k); ++i) {
    kgr.push_back(text.at(i));
  }
  std::cout << r.generate(kgr, output) << std::endl;
  return 0;
}
