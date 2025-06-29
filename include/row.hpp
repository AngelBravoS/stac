#pragma once

#include <iostream>
#include <vector>

class Row {
public:
  Row();
  Row(unsigned int size);
  Row(const Row &aCopy);
  unsigned int size() const;
  double &operator[](unsigned int index);
  Row &operator=(const Row &aCopy);

protected:
  unsigned int rowSize;
  std::vector<double> rowVector;
};
