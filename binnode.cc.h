#ifndef BINNODE_CC
#define BINNODE_CC

template<typename T>
void binNode<T>::setLeft(binNode* lChild)
{
    m_lChild = lChild;

    if (m_lChild != nullptr) {
        m_lChild->m_parent = this;
    }

    setHeight();
}

template<typename T>
void binNode<T>::setRight(binNode* rChild)
{
    m_rChild = rChild;

    if (m_rChild != nullptr) {
        m_rChild->m_parent = this;
    }

    setHeight();
}

template<typename T>
void binNode<T>::setHeight(void)
{
    m_height = std::max(((m_lChild == nullptr) ? -1 : m_lChild->m_height),
                        ((m_rChild == nullptr) ? -1 : m_rChild->m_height)) + 1;
}

template<typename T>
void binNode<T>::setData(T data)
{
    m_data = data;
}

template<typename T>
void binNode<T>::clearParent(void)
{
    m_parent = nullptr;
}

template<typename T>
binNode<T>* binNode<T>::getLeft(void) const
{
    return m_lChild;
}

template<typename T>
binNode<T>* binNode<T>::getRight(void) const
{
    return m_rChild;
}

template<typename T>
binNode<T>* binNode<T>::getParent(void) const
{
    return m_parent;
}

template<typename T>
size_t binNode<T>::getHeight(void) const
{
    return m_height;
}

template<typename T>
int binNode<T>::getBalance(void) const
{
    return (((m_lChild == nullptr) ? -1 : m_lChild->m_height)
            - ((m_rChild == nullptr) ? -1 : m_rChild->m_height));
}

template<typename T>
T binNode<T>::getData(void) const
{
    return m_data;
}

#endif // BINNODE_CC
