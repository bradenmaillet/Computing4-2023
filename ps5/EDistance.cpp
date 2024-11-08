//  Copyright 2024 Braden Maillet
#include <vector>
#include <string>
#include "EDistance.hpp"

EDistance::EDistance(std::string string1, std::string string2) {
  std::vector<int> temp;
  int columLen = string1.size() + 1;
  int rowLen = string2.size() + 1;
  temp.assign(rowLen, 0);
  this->str1 = string1;
  this->str2 = string2;
  //  creates matrix of 0's at correct size
  //  may just be less than
  for (int i = 0; i <= columLen; i++) {
    //  this is a row
    this->matrix.push_back(temp);
  }
}
int EDistance::penalty(char a, char b) {
  return (a == b) ? match : mis;
}
int EDistance::min3(int a, int b, int c) {
  if (a <= b) {
    return (a <= c)? a : c;
  } else if (b <= c) {
    return (b <= c)? b : c;
  } else {
    return c;
  }
  std::cout << "min3 " << a << " " << b << " " << c << std::endl;

  return -1;
}
//  optdistance returns the top left of the matrix ie
//  the most efficient arrangement value
int EDistance::optDistance() {
  int columLen = this->str1.size();
  int rowLen = this->str2.size();
  int count = 0;
  int j, k, i, l;
  //  implement creation of graph
  //  create edges of graph
  for (j = rowLen; j >= 0; j--) {
    this->matrix[columLen][j] = count;
    count += 2;
  }
  count = 0;
  for (k = columLen; k >= 0; k--) {
    this->matrix[k][rowLen] = count;
    count += 2;
  }
  for (i = columLen - 1; i >= 0; i--) {
    for (l = rowLen - 1; l >= 0; l--) {
      //  std::cout << i << " " << l << std::endl;
      //  min of three operations
      this->matrix[i][l] = min3(
        (this->matrix[i+1][l] + 2),
        (this->matrix[i][l+1] + 2),
        (this->matrix[i+1][l+1] +
        (penalty(this->str1[i],
        this->str2[l]))));
    }
  }
  return this->matrix[0][0];
}
//  aligment will trace back through the matrix
std::string EDistance::alignment() {
  int columLen = this->str1.size();
  int rowLen = this->str2.size();
  int i = 0, j = 0;
  std::string final;
  while (1) {
      if (i >= columLen) {
        //  reached edge
        //  push gaps to string 2
        //  return
        for (; j < rowLen; j++) {
          final.push_back('-');
          final.push_back(' ');
          final.push_back(this->str2[j]);
          final = final + " 2\n";
        }
        return final;
      }
      if (j >= rowLen) {
        //  reached edge
        //  push gaps to string 1
        //  return
        if (i == columLen)
          return final;
        for (; i < columLen; i++) {
          final.push_back(this->str1[i]);
          final.push_back(' ');
          final.push_back('-');
          final = final + " 2\n";
        }
        return final;
      }
      //  match case
      if ((this->matrix[i][j] == this->matrix[i + 1][j + 1])
        && (this->str1[i] == this->str2[j])) {
        //  std::cout << "match" << std::endl;
        final.push_back(this->str1[i]);
        final.push_back(' ');
        final.push_back(this->str2[j]);
        final = final + " 0\n";
        i++;
        j++;
      }
      //  mismatch case
      if ((this->matrix[i][j] - 1 == this->matrix[i + 1][j + 1])
        && (this->str1[i] != this->str2[j])) {
        //  std::cout << "mismatch" << std::endl;
        final.push_back(this->str1[i]);
        final.push_back(' ');
        final.push_back(this->str2[j]);
        final = final + " 1\n";
        i++;
        j++;
      }
      //  gap case Right
      if (this->matrix[i][j] - 2 == this->matrix[i][j + 1]) {
        //  std::cout << "GR" << std::endl;
        final.push_back('-');
        final.push_back(' ');
        final.push_back(this->str2[j]);
        final = final + " 2\n";
        j++;
      }
      //  gap case Right
      if (this->matrix[i][j] - 2 == this->matrix[i + 1][j]) {
        //  std::cout << "GR" << std::endl;
        final.push_back(this->str1[i]);
        final.push_back(' ');
        final.push_back('-');
        final = final + " 2\n";
        i++;
      }
  }
}
//  output operator for debugging
std::ostream& operator<<(std::ostream& out, EDistance& e) {
  int i, j;
  int columLen = e.str1.size() + 1;
  int rowLen = e.str2.size() + 1;
  for (i = 0; i < columLen; i++) {
    for (j = 0; j < rowLen; j++) {
      out << e.matrix[i][j] << " ";
    }
    out << std::endl;
  }
  return out;
}
