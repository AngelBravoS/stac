#pragma once

#include <iostream>
#include <vector>

class Row {
public:
  Row(void);
  Row(unsigned int size);
  Row(const Row &aCopy);
  unsigned int size() const;
  double &operator[](unsigned int index);
  Row &operator=(const Row &other) = default;

private:
  std::vector<double> Columns;
};
