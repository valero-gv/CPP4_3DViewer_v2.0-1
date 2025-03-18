//
// Created by valero on 9/1/24.
//

#include "validation.h"

int isValidString_v(const string& str) {
  if (str[0] != 'v') {
    return 0;
  }
  double x, y, z;
  std::istringstream iss(str.substr(1));
  if (iss >> x >> y >> z) {
    return 1;
  }
  return 0;
}

int isValidString_p(const string& str) {
  int slash = 0;
  if (str.empty() || str[0] != 'f') {
    return slash;
  }
  string token;
  std::istringstream stream(str.substr(1));
  while (stream >> token) {
    bool isValid = true;
    for (char c : token) {
      if (!(std::isdigit(c) || c == '.' || c == 'e' || c == '+' || c == '-')) {
        isValid = false;
        break;
      }
    }
    if (!isValid) {
      break;
    }
  }
  for (char c : str.substr(1)) {
    if (c == '/') {
      slash++;
    }
  }
  return slash;
}