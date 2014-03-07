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
#ifndef METATREE_CC
#define METATREE_CC
template<typename T>
bool metaTree<T>::balancedCheck(void) const
{
    return r_balancedCheck(this->m_root);
}

template<typename T>
bool metaTree<T>::r_balancedCheck(binNode<T> *n) const
{
    if (n == nullptr) {
        return true;
    } else {
        return (std::abs(n->getBalance() < 2)
                && r_balancedCheck(n->getLeft())
                && r_balancedCheck(n->getRight()));
    }
}

template<typename T>
size_t metaTree<T>::sizeCheck(void) const
{
    return r_sizeCheck(this->m_root);
}

template<typename T>
size_t metaTree<T>::r_sizeCheck(binNode<T> *n) const
{
    if (n == nullptr) {
        return 0;
    } else {
        return 1 + r_sizeCheck(n->getLeft()) + r_sizeCheck(n->getRight());
    }
}

template<typename T>
bool metaTree<T>::bstCheck(void) const
{
    return r_bstCheck(this->m_root, std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
}

template<typename T>
bool metaTree<T>::r_bstCheck(binNode<T> *n, T min, T max) const
{
    if (n == nullptr) {
        return true;
    } else if (n->getData() > min && n->getData() < max) {
        return r_bstCheck(n->getLeft(), min, n->getData())
               && r_bstCheck(n->getRight(), n->getData(), max);
    } else if (max == std::numeric_limits<T>::max() && n->getData() == max) {
        return r_bstCheck(n->getLeft(), min, n->getData())
               && r_bstCheck(n->getRight(), n->getData(), max - 1);
    } else if (min == std::numeric_limits<T>::min() && n->getData() == min) {
        return r_bstCheck(n->getLeft(), min + 1, n->getData())
               && r_bstCheck(n->getRight(), n->getData(), max);
    } else {
        return false;
    }
}

template<typename T>
bool metaTree<T>::heightCheck(void) const
{
    return r_heightCheck(this->m_root);
}

template<typename T>
bool metaTree<T>::r_heightCheck(binNode<T> *n) const
{
    if (n == nullptr) {
        return true;
    } else {
        /*
         * n's height is correct (based on its children) and its children's heights are correct
         */
        return ((n->getHeight() == std::max(((n->getLeft() == nullptr) ? -1 : n->getLeft()->getHeight()),
                                            ((n->getRight() == nullptr) ? -1 : n->getRight()->getHeight())) + 1)
                && r_heightCheck(n->getLeft())
                && r_heightCheck(n->getRight()));
    }
}

template<typename T>
bool metaTree<T>::pointerCheck(void) const
{
    return r_pointerCheck(this->m_root);
}

template<typename T>
bool metaTree<T>::r_pointerCheck(binNode<T> *n) const
{
    if (n == nullptr) {
        return true;
    } else {
        /*
         * n is either the root and has nullptr as a parent or is pointed at by its parent
         * and n does not point at its self and n's children pass the same test
         */
        if ((n == this->m_root) ^ (n->getParent() == nullptr)) {
            return false;
        }

        if (n != this->m_root && n != n->getParent()->getLeft() &&  n != n->getParent()->getRight()) {
            return false;
        }
        if (n ==  n->getLeft()) {
            return false;
        }
        if (n ==  n->getRight()) {
            return false;
        }

        return r_pointerCheck(n->getLeft()) && r_pointerCheck(n->getRight());
    }
}

template<typename T>
T metaTree<T>::succ(T n) const
{
    binNode<T> *m = this->getSuccessor(this->r_find(this->m_root, n));
    if (m != nullptr) {
        return m->getData();
    } else {
        return std::numeric_limits<T>::min();
    }
}

template<typename T>
T metaTree<T>::pred(T n) const
{
    binNode<T> *m = this->getPredecessor(this->r_find(this->m_root, n));
    if (m != nullptr) {
        return m->getData();
    } else {
        return std::numeric_limits<T>::min();
    }
}
#endif // METATREE_CC
