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
#ifndef BINNODE_H
#define BINNODE_H
#include <algorithm>

template<typename T>
class binNode
{
public:
    binNode() : m_lChild(nullptr), m_rChild(nullptr), m_parent(nullptr), m_height(0) {}
    binNode(T data) : m_lChild(nullptr), m_rChild(nullptr), m_parent(nullptr), m_height(0), m_data(data) {}

    virtual ~binNode() {}

    void setLeft(binNode* lChild);
    void setRight(binNode* rChild);
    void setHeight(void);
    void setData(T data);
    void clearParent(void);

    binNode* getLeft(void) const;
    binNode* getRight(void) const;
    binNode* getParent(void) const;

    size_t getHeight(void) const;
    int getBalance(void) const;
    T getData(void) const;

protected:
    binNode* m_lChild;
    binNode* m_rChild;
    binNode* m_parent;

    size_t m_height;

    T m_data;
};

#include "binnode.cc.h"
#endif // BINNODE_H
