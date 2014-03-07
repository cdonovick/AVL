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
