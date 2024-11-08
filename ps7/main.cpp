//  Copyright 2024 Braden Maillet
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

using boost::posix_time::ptime;
using boost::posix_time::time_duration;
using std::string;
using std::regex;

int main(int argc, char* argv[]) {
  string number = argv[1];
  string outfilename = "device";
  outfilename += number.at(13);  //  13  11
  outfilename += "_intouch.log.rpt";
  string t("trials/");
  t += outfilename;
  std::ofstream out(t);
  std::ifstream infile(argv[1]);
  regex start(".*\\(log\\.c\\.166\\) server started.*");
  string x = ".*oejs\\.AbstractConnector:Started "
    "SelectChannelConnector@0\\.0\\.0\\.0:9080.*";
  regex end(x);
  string s;
  std::locale loc(std::cout.getloc(),
    new boost::posix_time::time_facet("%Y-%m-%d %H:%M:%S"));
  out.imbue(loc);
  ptime endT;
  ptime startT;
  time_duration td;
  int lineCount = 0;
  int lineStart;
  int lineEnd;

  //  std::cout << "begining: " << std::endl;
  while (getline(infile, s)) {
    lineCount++;
    if (regex_match(s, start)) {
      //  std::cout << "DEBUG: " << s << std::endl;
      startT = boost::posix_time::time_from_string(s.substr(0, 20));
      lineStart = lineCount;
      //  std::cout << "DEBUG: " << startT << std::endl;
      while (getline(infile, s)) {
        lineCount++;
        if (regex_match(s, end)) {
          endT = boost::posix_time::time_from_string(s.substr(0, 20));
          lineEnd = lineCount;
          //  std::cout << "END " << endT << std::endl;
          //  find time and print to file
          //  case that boot succeeded
          td = endT - startT;
          if (out.is_open()) {
            out << "=== Device boot ===\n"
                << lineStart << "(" << argv[1] << "): "
                << startT << " Boot Start" << std::endl
                << lineEnd << "(" << argv[1] << "): "
                << endT << " Boot Completed" << std::endl
                << "  Boot Time: " << td.total_milliseconds()
                << " ms" << std::endl
                << std::endl;
          }
          break;
        }
        if (regex_match(s, start) || infile.eof()) {
          //  std::cout << "start " << startT << std::endl;
          //  print to file
          //  case that boot failed
          if (out.is_open()) {
            out << "=== Device boot ===\n"
                << lineStart << "(" << argv[1] << "): "
                << startT << " Boot Start" << std::endl
                << "**** Incomplete boot ****" << std::endl
                << std::endl;
          }
          startT = boost::posix_time::time_from_string(s.substr(0, 20));
          lineStart = lineCount;
          continue;
        }
      }
    }
  }
  out.close();
  return 0;
}
