#pragma once

#include <vector>
#include <iostream>

class Row {
	public:
		Row(void);
		Row(unsigned int size);
		Row(const Row &aCopy);
		unsigned int size();
		double &operator[](unsigned int index);
	private:
		std::vector< double > Columns;
};
