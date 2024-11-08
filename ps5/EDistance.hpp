//  Copyright 2024 Braden Maillet
#pragma once
#include <vector>
#include <string>
#include <iostream>

class EDistance {
 public:
  EDistance(std::string string1, std::string string2);
  static int penalty(char a, char b);
  static int min3(int a, int b, int c);
  //  optdistance returns the top left of the matrix ie
  //  the most efficient arrangement value
  int optDistance();
  //  aligment will trace back through the matrix
  std::string alignment();

  friend std::ostream& operator<<(std::ostream& out, EDistance& e);
 private:
  //  match mismatch gap score
  enum MMG {match = 0, mis = 1, gap = 2};
  std::vector<std::vector<int>> matrix;
  std::string str1;
  std::string str2;
};
