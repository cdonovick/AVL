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
#ifndef AVLTREE_H
#define AVLTREE_H
#include "binnode.h"

template<typename T>
class AVLTree
{
public:
    /*
    class iterator;
    iterator find(T data) const { return r_find(m_root, data); }
    */
    AVLTree(void) : m_root(nullptr), m_size(0){};
    virtual ~AVLTree(void);

    bool search(T data) const;
    bool empty(void) const;

    void insert(T data);
    void remove(T data);

    size_t size(void) const;
protected:
    binNode<T>* m_root;
    size_t m_size;

    void destroy(binNode<T>* n);

    bool r_search(binNode<T>* n, T data) const;
    binNode<T>* r_find(binNode<T>* n, T data) const;

    void r_insert(binNode<T>* n, T data);

    void r_remove(binNode<T>* n);

    binNode<T>* getSuccessor(binNode<T>* n) const;
    binNode<T>* getPredecessor(binNode<T>* n) const;

    void balanceNode(binNode<T>* n);
    void balanceUp(binNode<T>* n);
    void rotateRight(binNode<T>* n);
    void rotateLeft(binNode<T>* n);

};

#include "avltree.cc.h"
#endif // AVLTREE_H
