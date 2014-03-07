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
