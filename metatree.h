/**
    Template AVL tree
    Copyright (C) 2014 Caleb Donovick

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 */
#ifndef METATREE_H
#define METATREE_H
#include <limits>
#include "avltree.h"

template<typename T>
class metaTree : public AVLTree<T>
{
public:
    metaTree(void) {}
    virtual ~metaTree() {}

    bool balancedCheck(void) const;
    bool bstCheck(void) const;
    bool heightCheck(void) const;
    bool pointerCheck(void) const;
    size_t sizeCheck(void) const;
    T succ(T n) const;
    T pred(T n) const;
protected:
    bool r_balancedCheck(binNode<T>* n) const;
    bool r_bstCheck(binNode<T>* n, T min, T max) const;
    bool r_heightCheck(binNode<T>* n) const;
    bool r_pointerCheck(binNode<T>* n) const;
    size_t r_sizeCheck(binNode<T>* n) const;
};

#include "metatree.cc.h"
#endif // METATREE_H
