/**
    Templated AVL tree
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
#ifndef AVLTREE_CC
#define AVLTREE_CC
template<typename T>
AVLTree<T>::~AVLTree(void)
{
    destroy(m_root);
}

template<typename T>
bool AVLTree<T>::search(T data) const
{
    return r_search(m_root, data);
}

template<typename T>
bool AVLTree<T>::empty(void) const
{
    return (m_root == nullptr);
}

template<typename T>
void AVLTree<T>::insert(T data)
{
    if (empty()) {
        m_root = new binNode<T>(data);
        m_size++;
    } else {
        r_insert(m_root, data);
    }
}

template<typename T>
void AVLTree<T>::remove(T data)
{
    binNode<T> *n = r_find(m_root, data);
    if(n != nullptr) {
        r_remove(n);
    }
}

template<typename T>
size_t AVLTree<T>::size(void) const
{
    return m_size;
}


template<typename T>
void AVLTree<T>::destroy(binNode<T> *n)
{
    if (n != nullptr) {
        destroy(n->getLeft());
        destroy(n->getRight());
        delete n;
    }
}

template<typename T>
bool AVLTree<T>::r_search(binNode<T> *n, T data) const
{
    if(n == nullptr) {
        return false;
    } else if (data == n->getData()) {
        return true;
    } else if (data < n->getData()) {
        return r_search(n->getLeft(), data);
    } else {
        return r_search(n->getRight(), data);
    }
}

template<typename T>
binNode<T> *AVLTree<T>::r_find(binNode<T> *n, T data) const
{
    if(n == nullptr) {
        return nullptr;
    } else if (data == n->getData()) {
        return n;
    } else if (data < n->getData()) {
        return r_find(n->getLeft(), data);
    } else {
        return r_find(n->getRight(), data);
    }
}

template<typename T>
void AVLTree<T>::r_insert(binNode<T> *n, T data)
{
    if (data < n->getData()) {
        if (n->getLeft() == nullptr) {
            binNode<T> *child = new binNode<T>(data);
            n->setLeft(child);
            m_size++;
            balanceUp(n);
        } else {
            r_insert(n->getLeft(), data);
        }

    } else if (data > n->getData()) {
        if (n->getRight() == nullptr) {
            binNode<T> *child = new binNode<T>(data);
            n->setRight(child);
            m_size++;
            balanceUp(n);
        } else {
            r_insert(n->getRight(), data);
        }
    }
}

template<typename T>
void AVLTree<T>::r_remove(binNode<T> *n)
{
    if(n->getLeft() != nullptr && n->getRight() != nullptr) {
        binNode<T> *r = getSuccessor(n);
        n->setData(r->getData());
        r_remove(r);
    } else {
        binNode<T> *child;
        binNode<T> *parent = n->getParent();
        if(n->getLeft() == nullptr && n->getRight() == nullptr) {
            child = nullptr;
        } else if (n->getLeft() == nullptr) {
            child = n->getRight();
        } else {
            child = n->getLeft();
        }

        if(parent == nullptr) {
            child->clearParent();
            m_root = child;
        } else {
            if (parent->getLeft() == n) {
                parent->setLeft(child);
            } else {
                parent->setRight(child);
            }

            balanceUp(parent);
        }

        delete n;
        m_size--;
    }
}

template<typename T>
binNode<T> *AVLTree<T>::getSuccessor(binNode<T> *n) const
{
    if (n->getRight() != nullptr) {
        n = n->getRight();
        while(n->getLeft() != nullptr) {
            n = n->getLeft();
        }

        return n;
    } else {
        binNode<T> *p = n->getParent();
        while(p != nullptr && n == p->getRight()) {
            n = p;
            p = p->getParent();
        }

        return p;
    }
}

template<typename T>
binNode<T> *AVLTree<T>::getPredecessor(binNode<T> *n) const
{
    if (n->getLeft() != nullptr) {
        n = n->getLeft();
        while(n->getRight() != nullptr) {
            n = n->getRight();
        }

        return n;
    } else {
        binNode<T> *p = n->getParent();
        while(p != nullptr && n == p->getLeft()) {
            n = p;
            p = p->getParent();
        }

        return p;
    }
}

template<typename T>
void AVLTree<T>::balanceNode(binNode<T> *n)
{
    int balance = n->getBalance();

    if (balance < -1) {
        if (n->getRight()->getBalance() > 0) {
            rotateRight(n->getRight());
        }

        rotateLeft(n);

    } else if (balance > 1) {
        if (n->getLeft()->getBalance() < 0) {
            rotateLeft(n->getLeft());
        }

        rotateRight(n);
    }
}

template<typename T>
void AVLTree<T>::balanceUp(binNode<T> *n)
{
    if (n != nullptr) {
        binNode<T> *p = n->getParent();
        n->setHeight();
        balanceNode(n);
        balanceUp(p);
    }
}

template<typename T>
void AVLTree<T>::rotateRight(binNode<T> *n)
{
    binNode<T> *parent = n->getParent();
    binNode<T> *temp = n->getLeft();

    n->setLeft(temp->getRight());

    temp->setRight(n);

    if (parent == nullptr) {
        //n is root
        m_root = temp;
        temp->clearParent();
    } else if (parent->getLeft() == n) {
        //n is a left child
        parent->setLeft(temp);
    } else {
        //n is a right child
        parent->setRight(temp);
    }
}

template<typename T>
void AVLTree<T>::rotateLeft(binNode<T> *n)
{
    binNode<T> *parent = n->getParent();
    binNode<T> *temp = n->getRight();

    n->setRight(temp->getLeft());

    temp->setLeft(n);

    if (parent == nullptr) {
        //n is root
        m_root = temp;
        temp->clearParent();
    } else if (parent->getLeft() == n) {
        //n is a left child
        parent->setLeft(temp);
    } else {
        //n is a right child
        parent->setRight(temp);
    }
}


#endif // AVLTREE_CC
