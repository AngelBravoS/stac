#include "row.hpp"

Row::Row() = default;

Row::Row(unsigned int size) : rowVector(size, 0.0) {}

Row::Row(const Row &aCopy) : rowVector(aCopy.rowVector) {}

unsigned int Row::size() const {
  unsigned int size = static_cast<unsigned int>(rowVector.size());
  return size;
}

double &Row::operator[](unsigned int index) {
  if (index >= rowVector.size())
    throw "Array Index out of Bounds";
  return rowVector[index];
}

Row &Row::operator=(const Row &aCopy) {
  if (this == &aCopy)
    return *this; // Evita la autoasignación
  rowVector = aCopy.rowVector;
  rowSize = aCopy.size();
  return *this;
}
