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

#include "matriz.hpp"

Matriz::Matriz(unsigned int rows,unsigned  int cols) {
    rows == cols ? cuadrada = true : cuadrada = false;
    for (unsigned int i = 0; i < rows; ++i) {
        Row r(cols);
        Array.insert(Array.end(), r);
    }
}

Row &Matriz::operator[](unsigned int index) {
    if (index < 0 || index > Array.size())
        throw "Array Index out of Bounds";
    return Array[ index ];
}

unsigned int Matriz::RowCount() {
    unsigned int size = convierteLongEnInt(Array.size());
    return size;
}

unsigned int Matriz::ColumnCount() {
    if (Array.size())
        return Array[0].size();
    return 0;
}
