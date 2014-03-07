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
