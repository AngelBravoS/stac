#include "row.hpp"

Row::Row(void) {
}

Row::Row(unsigned int size) {
    // Initialize the column
    for (unsigned int i = 0; i < size; ++i)
        Columns.insert(Columns.end(), 0.0);
}

Row::Row(const Row &aCopy) {
    std::vector< double >::const_iterator iter;
    for (iter = aCopy.Columns.begin(); iter != aCopy.Columns.end(); ++iter) {
        double d = (*iter);
        Columns.insert(Columns.end(), d);
    }
}

unsigned int Row::size() {
    unsigned int size = static_cast<unsigned int>(Columns.size());
    return size;
}

double &Row::operator[](unsigned int index) {
    if (index < 0 || index > Columns.size())
        throw "Array Index out of Bounds";
    return Columns[ index ];
}

