/***************************************************************************
 *   Copyright (C) 2018 by Ángel Bravo Sáenz                               *
 *   angelbravosaenz@gmail.com                                             *
 *                                                                         *
 *   This file is part of Stac.                                            *
 *                                                                         *
 *   Stac is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   Stac is distributed in the hope that it will be useful,               *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with Stac; if not, write to the                                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include "vector.hpp"

Vector::Vector() {
}

Vector::Vector(unsigned int size) {
	for (unsigned int i = 0; i < size; ++i)
		vector.insert(vector.end(), 0.0);
	longitudVector = convierteLongEnInt(vector.size());
}

Vector::Vector(const Vector &aCopy) {
	std::vector< double >::const_iterator iter;
	for (iter = aCopy.vector.begin(); iter != aCopy.vector.end(); ++iter) {
		double d = (*iter);
		vector.insert(vector.end(), d);
	}
}

unsigned int Vector::size() const {
    unsigned int size = static_cast<unsigned int>(vector.size());
    return size;
}

double &Vector::operator[](unsigned int index) {
    if (index < 0 || index > vector.size())
        throw "Array Index out of Bounds";
    return vector[ index ];
}

void Vector::ordenarVector() {
	std::sort(vector.begin(), vector.end());
}
