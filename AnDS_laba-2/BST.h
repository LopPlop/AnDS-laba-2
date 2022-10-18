#pragma once
#include <iostream>
#include <stack>


//************************************************************ ������� ���������� ************************************************//
#define NotInBST 0 // �������� ��� � BST ������
#define IteratorIsNotInstall 1 // ������ ��� �������� ��������� �� �����������


//****************************************************** ������������ ������������ ��� ******************************************//
using namespace std;

//************************************************************ ����� ��� BST *****************************************************//
template <class Key_T, class Data_T>
class BST
{
    // ����� - ���� BST-������
    class Node
    {
    public:
        Key_T key; // ���� ����
        Data_T data; // ������ ����
        Node* left; // ��������� �� ����� ���������
        Node* right; // ��������� �� ������ ���������
        Node(const Key_T& key, const Data_T& data); // ����������� ���� � �����������
        friend class BST;
    };

    int size; // ���������� ��������� � ������
    Node* root; // ��������� �� ������ ������
    int last_op;  // ���������� ��������� �� ��������� ��������
    int total_op; // ��������� ���������� ���������

    void constructor(); // ���� ������������ �� ���������
    void copy(const BST& tree); // ���� ������������ �����������
public:
    // ����� ������� ���������
    class Iterator
    {
        const BST* tree; // ��������� �� ������� BST-������
        Node* cur; // ������� ����, �� ������� ���������� ��������
        stack<Node*> stkl; // ��������������� ���� ��� ����� ���������
        stack<Node*> stkr; // ��������������� ���� ��� ������ ���������
    public:
        Iterator(); // ����������� ������� ��������� �� ���������
        Iterator(const BST& tree); // ����������� ������� ��������� � ���������� tree - ������� �� BST-������
        Iterator(const BST& tree, const Key_T& key); // ����������� ������� ��������� � �����������: tree - ������ �� BST-������, key - ����
        Iterator(const Iterator& iter); // ����������� ����������� ������� ���������

        bool change(int data);

        Data_T operator*(); // �������� "���������������" - ��������� �������� �������� ���� ������ �� ������
        Iterator& operator++(); // �������� ����������� ����������������� ������� ���������
        Iterator& operator--(); // �������� ����������� ����������������� ������� ���������
        Iterator operator++(int); // �������� ������������ ����������������� ������� ���������
        Iterator operator--(int); // �������� ������������ ����������������� ������� ���������
        Iterator& operator=(const Iterator& iter); // �������� ������������ ������� ���������
        bool operator==(const Iterator& iter); // �������� ��������� ������ ����������
        bool operator!=(const Iterator& iter); // �������� ����������� ������ ����������

        bool is_established(); // ���������� �� ��������
    };
    friend class Iterator;

    // ����� ��������� ���������
    class RIterator
    {
        const BST* tree; // ��������� �� ������� BST-������
        Node* cur; // ������� ����, �� ������� ���������� ��������
        stack<Node*> stkl; // ��������������� ���� ��� ����� ���������
        stack<Node*> stkr; // ��������������� ���� ��� ������ ���������
    public:
        RIterator(); // ����������� ��������� ��������� �� ���������
        RIterator(const BST& tree); // ����������� ��������� ��������� � ���������� tree - ������� �� BST-������
        RIterator(const BST& tree, const Key_T& key); // ����������� ��������� ��������� � �����������: tree - ������ �� BST-������, key - ����
        RIterator(const RIterator& riter); // ����������� ����������� ��������� ���������

        bool change(int data);

        Data_T operator*(); // �������� "���������������" - ��������� �������� �������� ���� ������ �� ������
        RIterator& operator++(); // �������� ����������� ����������������� ��������� ���������
        RIterator& operator--(); // �������� ����������� ����������������� ��������� ���������
        RIterator operator++(int); // �������� ������������ ����������������� ��������� ���������
        RIterator operator--(int); // �������� ������������ ����������������� ��������� ���������
        RIterator& operator=(const RIterator& iter); // �������� ������������ ��������� ���������
        bool operator==(const RIterator& iter); // �������� ��������� �������� ����������
        bool operator!=(const RIterator& iter); // �������� ����������� �������� ����������

        bool is_established(); // ���������� �� ��������
    };
    friend class RIterator;

    BST(); // ����������� �� ���������
    BST(const Key_T& key, const Data_T& data); // ����������� � �����������
    BST(const BST& tree);  // ����������� �����������
    ~BST(); // ����������

    Data_T& operator[](const Key_T& key); // �������� ������� � �������� �� �����
    BST& operator=(const BST& tree); // �������� ������������ ��������

    int getSize();  // �������� ������ ������
    int getLastOp(); // �������� ���������� ��������� �� ��������� ��������
    void setLastOp(int value); // ���������� ���������� ��������� �� ��������� ��������
    int getTotalOp(); // �������� ��������� ���������� ���������
    void setTotalOp(int value); // ���������� ��������� ���������� ��������� 
    int getExternalPath(); // �������� ����� �������� ���� ������ �� ����� O(n)
    Data_T& getItemByKey(const Key_T& key); // ������ �������� ������ �� �����
    void setItemByKey(const Key_T& key, const Data_T& data); // ������ �������� �� ��������� �����
    bool isEmpty(); // �������� ������ �� �������
    void clear();  // ������� ������
    bool append(const Key_T& key, const Data_T& data); // �������� ������� � �������� ������ � ������ 
    bool del(const Key_T& key); // ������� ������� � �������� ������
    void print(); // ������� ������ � ����������� �����
    void printAsDict(); // ������� ������ � ����� �������: ����-��������
    void printKeys(); // ������� ����� ������ � ������������ ������� (LtR)
    void printCount(); // ����� ���������� ��������� �� ��������� �������� � ����� ���������� ���������

    Iterator begin(); // ��������� ��������� �� ��������� ������� ������
    Iterator end();  // ��������� ��������� �� ������� ����� ��������� ��������
    RIterator rbegin(); // ��������� ��������� �������� � ����� ������
    RIterator rend();  // ��������� ��������� ��������� ����� ������ ��������� ������
};


//********************************************************** ���������� ������� ���� **************************************************************//
template <class Key_T, class Data_T> BST<Key_T, Data_T>::Node::Node(const Key_T& key, const Data_T& data)
{
    this->key = key;
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}


//********************************************************** ���������� ������� ������� ��������� *************************************************//
template <class Key_T, class Data_T> BST<Key_T, Data_T>::Iterator::Iterator()
{
    this->tree = nullptr;
    this->cur = nullptr;
    this->stkl = {};
    this->stkr = {};
}

template <class Key_T, class Data_T> BST<Key_T, Data_T>::Iterator::Iterator(const BST& tree)
{
    this->tree = &tree;
    this->cur = nullptr;
    this->stkl = {};
    this->stkr = {};
}

template <class Key_T, class Data_T> BST<Key_T, Data_T>::Iterator::Iterator(const BST& tree, const Key_T& key)
{
    Node* cur = tree.root;

    this->tree = &tree;
    this->stkl = {};
    this->stkr = {};

    // ���� ������� � �������� ������, �������� � ����� ������ ��� ����� ��������� ���������� ����
    while (cur != nullptr && key != cur->key)
    {
        if (key < cur->key)
        {
            this->stkl.push(cur);
            cur = cur->left;
        }
        else
        {
            this->stkr.push(cur);
            cur = cur->right;
        }
    }

    this->cur = cur;

    // ���� ������� � ������ key �� ��� ������
    if (this->cur == nullptr)
    {
        this->stkl = {};
        this->stkr = {};
        throw NotInBST;
    }
}

template <class Key_T, class Data_T> BST<Key_T, Data_T>::Iterator::Iterator(const Iterator& iter)
{
    this->tree = iter.tree;
    this->cur = iter.cur;
    this->stkl = iter.stkl;
    this->stkr = iter.stkr;
}

template<class Key_T, class Data_T>
inline bool BST<Key_T, Data_T>::Iterator::change(int data)
{
    if (this->cur == nullptr)
        return false;
    this->cur->data = data;
    return true;
}

template <class Key_T, class Data_T> typename Data_T BST<Key_T, Data_T>::Iterator::operator*()
{
    if (this->cur == nullptr)
        throw IteratorIsNotInstall;
    else
        return this->cur->data;
}

template <class Key_T, class Data_T> typename BST<Key_T, Data_T>::Iterator& BST<Key_T, Data_T>::Iterator::operator++()
{
    if (this->cur == nullptr)
        throw IteratorIsNotInstall;

    // ���� � ������� ���� ���� ������ �������, �� ��������� � ����
    if (this->cur->right != nullptr)
    {
        this->cur = this->cur->right;
        // ���� � ����� ������� ���� ����� �����, �� �������� �� ���, ������ ���� � ���� ����� ���������
        while (this->cur->left != nullptr)
        {
            this->stkl.push(this->cur);
            this->cur = this->cur->left;
        }
    }
    else
    {
        // ���� ���� ����� ��������� ����, �� ������ ������� - ��� ������� � ������������ ������
        if (this->stkl.empty())
        {
            this->cur = nullptr;
            this->stkl = {};
            this->stkr = {};
        }
        // ����� ������������ � ���������� ������ ��������
        else
        {
            this->cur = this->stkl.top();
            this->stkl.pop();
        }
    }

    return *this;
}

template <class Key_T, class Data_T> typename BST<Key_T, Data_T>::Iterator& BST<Key_T, Data_T>::Iterator::operator--()
{
    if (this->cur == nullptr)
        throw IteratorIsNotInstall;

    // ���� � ������� ���� ���� ����� �������, �� ��������� � ����
    if (this->cur->left != nullptr)
    {
        this->cur = this->cur->left;
        // ���� � ����� ������� ���� ������ �����, �� �������� �� ���, ������ ���� � ���� ������ ���������
        while (this->cur->right != nullptr)
        {
            this->stkr.push(this->cur);
            this->cur = this->cur->right;
        }
    }
    else
    {
        // ���� ���� ������ ��������� ����, �� ������ ������� - ��� ������� � ����������� ������ 
        if (this->stkr.empty())
        {
            this->cur = nullptr;
            this->stkl = {};
            this->stkr = {};
        }
        // ����� ������������ � ���������� ������� ��������
        else
        {
            this->cur = this->stkr.top();
            this->stkr.pop();
        }
    }

    return *this;
}

template <class Key_T, class Data_T> typename BST<Key_T, Data_T>::Iterator BST<Key_T, Data_T>::Iterator::operator++(int)
{
    Iterator temp = *this;

    ++(*this);

    return temp;
}

template <class Key_T, class Data_T> typename BST<Key_T, Data_T>::Iterator BST<Key_T, Data_T>::Iterator::operator--(int)
{
    Iterator temp = *this;

    --(*this);

    return temp;
}

template <class Key_T, class Data_T> typename BST<Key_T, Data_T>::Iterator& BST<Key_T, Data_T>::Iterator::operator=(const Iterator& iter)
{
    this->tree = iter.tree;
    this->cur = iter.cur;
    this->stkl = iter.stkl;
    this->stkr = iter.stkr;

    return *this;
}

template <class Key_T, class Data_T> typename bool BST<Key_T, Data_T>::Iterator::operator==(const Iterator& iter)
{
    if (this->tree == iter.tree && this->cur == iter.cur)
        return true;
    else
        return false;
}

template <class Key_T, class Data_T> typename bool BST<Key_T, Data_T>::Iterator::operator!=(const Iterator& iter) { return !(*this == iter); }

template <class Key_T, class Data_T> typename bool BST<Key_T, Data_T>::Iterator::is_established() { return this->cur != nullptr; }

//********************************************************** ���������� ������� ��������� ��������� *************************************************//
template <class Key_T, class Data_T> BST<Key_T, Data_T>::RIterator::RIterator()
{
    this->tree = nullptr;
    this->cur = nullptr;
    this->stkl = {};
    this->stkr = {};
}

template <class Key_T, class Data_T> BST<Key_T, Data_T>::RIterator::RIterator(const BST& tree)
{
    this->tree = &tree;
    this->cur = nullptr;
    this->stkl = {};
    this->stkr = {};
}

template <class Key_T, class Data_T> BST<Key_T, Data_T>::RIterator::RIterator(const BST& tree, const Key_T& key)
{
    Node* cur = tree.root;

    this->tree = &tree;
    this->stkl = {};
    this->stkr = {};

    // ���� ������� � �������� ������, �������� � ����� ������ ��� ����� ��������� ���������� ����
    while (cur != nullptr && key != cur->key)
    {
        if (key < cur->key)
        {
            this->stkl.push(cur);
            cur = cur->left;
        }
        else
        {
            this->stkr.push(cur);
            cur = cur->right;
        }
    }

    this->cur = cur;

    // ���� ������� � ������ key �� ��� ������
    if (this->cur == nullptr)
    {
        this->stkl = {};
        this->stkr = {};
        throw NotInBST;
    }
}

template <class Key_T, class Data_T> BST<Key_T, Data_T>::RIterator::RIterator(const RIterator& riter)
{
    this->tree = riter.tree;
    this->cur = riter.cur;
    this->stkl = riter.stkl;
    this->stkr = riter.stkr;
}

template<class Key_T, class Data_T>
inline bool BST<Key_T, Data_T>::RIterator::change(int data)
{
    if (this->cur == nullptr)
        return false;
    this->cur->data = data;
    return true;
}



template <class Key_T, class Data_T> typename Data_T BST<Key_T, Data_T>::RIterator::operator*()
{
    if (this->cur == nullptr)
        throw IteratorIsNotInstall;
    else
        return this->cur->data;
}

template <class Key_T, class Data_T> typename BST<Key_T, Data_T>::RIterator& BST<Key_T, Data_T>::RIterator::operator++()
{
    if (this->cur == nullptr)
        throw IteratorIsNotInstall;

    // ���� � ������� ���� ���� ����� �������, �� ��������� � ����
    if (this->cur->left != nullptr)
    {
        this->cur = this->cur->left;
        // ���� � ����� ������� ���� ������ �����, �� �������� �� ���, ������ ���� � ���� ������ ���������
        while (this->cur->right != nullptr)
        {
            this->stkr.push(this->cur);
            this->cur = this->cur->right;
        }
    }
    else
    {
        // ���� ���� ������ ��������� ����, �� ������ ������� - ��� ������� � ����������� ������ 
        if (this->stkr.empty())
        {
            this->cur = nullptr;
            this->stkl = {};
            this->stkr = {};
        }
        // ����� ������������ � ���������� ������� ��������
        else
        {
            this->cur = this->stkr.top();
            this->stkr.pop();
        }
    }

    return *this;
}

template <class Key_T, class Data_T> typename BST<Key_T, Data_T>::RIterator& BST<Key_T, Data_T>::RIterator::operator--()
{
    if (this->cur == nullptr)
        throw IteratorIsNotInstall;

    // ���� � ������� ���� ���� ������ �������, �� ��������� � ����
    if (this->cur->right != nullptr)
    {
        this->cur = this->cur->right;
        // ���� � ����� ������� ���� ����� �����, �� �������� �� ���, ������ ���� � ���� ����� ���������
        while (this->cur->left != nullptr)
        {
            this->stkl.push(this->cur);
            this->cur = this->cur->left;
        }
    }
    else
    {
        // ���� ���� ����� ��������� ����, �� ������ ������� - ��� ������� � ������������ ������
        if (this->stkl.empty())
        {
            this->cur = nullptr;
            this->stkl = {};
            this->stkr = {};
        }
        // ����� ������������ � ���������� ������ ��������
        else
        {
            this->cur = this->stkl.top();
            this->stkl.pop();
        }
    }

    return *this;
}

template <class Key_T, class Data_T> typename BST<Key_T, Data_T>::RIterator BST<Key_T, Data_T>::RIterator::operator++(int)
{
    RIterator temp = *this;

    ++(*this);

    return temp;
}

template <class Key_T, class Data_T> typename BST<Key_T, Data_T>::RIterator BST<Key_T, Data_T>::RIterator::operator--(int)
{
    RIterator temp = *this;

    --(*this);

    return temp;
}

template <class Key_T, class Data_T> typename BST<Key_T, Data_T>::RIterator& BST<Key_T, Data_T>::RIterator::operator=(const RIterator& riter)
{
    this->tree = riter.tree;
    this->cur = riter.cur;
    this->stkl = riter.stkl;
    this->stkr = riter.stkr;

    return *this;
}

template <class Key_T, class Data_T> typename bool BST<Key_T, Data_T>::RIterator::operator==(const RIterator& riter)
{
    if (this->tree == riter.tree && this->cur == riter.cur)
        return true;
    else
        return false;
}

template <class Key_T, class Data_T> typename bool BST<Key_T, Data_T>::RIterator::operator!=(const RIterator& riter) { return !(*this == riter); }

template <class Key_T, class Data_T> typename bool BST<Key_T, Data_T>::RIterator::is_established() { return this->cur != nullptr; }


//************************************************************* ���������� ������� ������ *********************************************************//
//��������� ������:
template <class Key_T, class Data_T> typename void BST<Key_T, Data_T>::constructor()
{
    this->root = nullptr;
    this->size = 0;
    this->last_op = 0;
    this->total_op = 0;
}

template <class Key_T, class Data_T> typename void BST<Key_T, Data_T>::copy(const BST& tree)
{
    /* ������� ������ tree � ������ ������ this ���������, �������� ����-����� ������ tree ��� ������ this*/

    Node* tree_cur = tree.root, * this_cur = nullptr; // ��������� �� ������� ���� tree � this 
    stack<Node*> tree_stk, this_stk; // ��������������� ����� ��� ������ ��������

    constructor();

    // ���� tree ���������� �����, �� ������ ������ ������
    if (tree_cur == nullptr)
        return;
    else
        this_cur = this->root = new Node(*tree_cur); // ����� �������� ������ � ����������

    // ������� ������ tree � ������ ������ this, �������� ��������������� ���� tree � ��������������� ���� this
    tree_stk.push(tree_cur);
    this_stk.push(this_cur);
    while (!tree_stk.empty())
    {
        tree_cur = tree_stk.top();
        tree_stk.pop();

        this_cur = this_stk.top();
        this_stk.pop();

        if (tree_cur->right != nullptr)
        {
            this_cur->right = new Node(*tree_cur->right);
            tree_stk.push(tree_cur->right);
            this_stk.push(this_cur->right);
        }
        if (tree_cur->left != nullptr)
        {
            this_cur->left = new Node(*tree_cur->left);
            tree_stk.push(tree_cur->left);
            this_stk.push(this_cur->left);
        }
    }
    this->size = tree.size;
    this->last_op = 0;
    this->total_op = 0;
}

//�������� ������:
template <class Key_T, class Data_T> BST<Key_T, Data_T>::BST() { constructor(); }

template <class Key_T, class Data_T> BST<Key_T, Data_T>::BST(const Key_T& key, const Data_T& data)
{
    this->root = new Node(key, data);
    this->size = 1;
    this->last_op = 0;
    this->total_op = 0;
}

template <class Key_T, class Data_T> BST<Key_T, Data_T>::BST(const BST& tree) { copy(tree); }

template <class Key_T, class Data_T> BST<Key_T, Data_T>::~BST() { clear(); }

template <class Key_T, class Data_T> typename Data_T& BST<Key_T, Data_T>::operator[](const Key_T& key) { return getItemByKey(key); }

template <class Key_T, class Data_T> typename BST<Key_T, Data_T>& BST<Key_T, Data_T>::operator=(const BST& tree)
{
    clear();
    copy(tree);
    this->last_op = tree.last_op;
    this->total_op = tree.total_op;

    return *this;
}

template <class Key_T, class Data_T> typename int BST<Key_T, Data_T>::getSize() { return this->size; }

template <class Key_T, class Data_T> typename int BST<Key_T, Data_T>::getLastOp() { return this->last_op; }

template <class Key_T, class Data_T> typename void BST<Key_T, Data_T>::setLastOp(int value) { this->last_op = value; }

template <class Key_T, class Data_T> typename int BST<Key_T, Data_T>::getTotalOp() { return this->total_op; }

template <class Key_T, class Data_T> typename void BST<Key_T, Data_T>::setTotalOp(int value) { this->total_op = value; }

template <class Key_T, class Data_T> typename int BST<Key_T, Data_T>::getExternalPath()
{
    /* ������� ������ ��������, ������ ������� ���� � ��������� �� ������ */

    Node* cur = this->root; // ������� ���� ������
    size_t cur_level = 0; // ������� ������� ��������
    size_t result = 0; // ����� �������� ����
    stack<Node*> stk1, stk2; // ��������������� ����� �����
    stack<size_t> level_stk1, level_stk2; // ��������������� ����� �������

    if (cur == nullptr)
        return result;

    stk1.push(cur);
    level_stk1.push(cur_level);
    while (!stk1.empty() || !stk2.empty())
    {
        if (!stk1.empty())
        {
            cur = stk1.top();
            stk1.pop();
            cur_level = level_stk1.top();
            level_stk1.pop();

            stk2.push(cur);
            level_stk2.push(cur_level);

            if (cur->right != nullptr)
            {
                stk1.push(cur->right);
                level_stk1.push(cur_level + 1);
            }
        }
        else
        {
            cur = stk2.top();
            stk2.pop();
            cur_level = level_stk2.top();
            level_stk2.pop();

            // ���� ���� �������, �� ��������� ��� ������� � ����������
            if (cur->left == nullptr || cur->right == nullptr)
                result += cur_level;

            if (cur->left != nullptr)
            {
                stk1.push(cur->left);
                level_stk1.push(cur_level + 1);
            }
        }
    }

    return result;
}

template <class Key_T, class Data_T> typename Data_T& BST<Key_T, Data_T>::getItemByKey(const Key_T& key)
{
    /* ������� ������ � ������ �������� � ������, ������ ��������� */

    Node* cur = this->root;

    this->last_op = 1;

    while (cur != nullptr && key != cur->key)
    {
        if (key < cur->key)
            cur = cur->left;
        else
            cur = cur->right;
        this->last_op++;
    }

    this->last_op++;
    this->total_op += this->last_op;

    if (cur == nullptr)
        throw NotInBST;
    else
        return cur->data;
}

template <class Key_T, class Data_T> typename void BST<Key_T, Data_T>::setItemByKey(const Key_T& key, const Data_T& data) { getItemByKey(key) = data; }

template <class Key_T, class Data_T> typename bool BST<Key_T, Data_T>::isEmpty() { return this->size == 0; }

template <class Key_T, class Data_T> typename void BST<Key_T, Data_T>::clear()
{
    /* ������� ������ ����������, �������� ���������� ������� � ���� stk2, � ����� ������� ���, ���� �������� ������
    ������� � ����� */

    Node* cur = this->root; // ������� ����
    stack<Node*> stk1, stk2; // ��������������� ����� ��� ������ ������

    // ���� ������ �����, �� �������
    if (cur == nullptr)
        return;

    // ������� ������, �������� ���� ������
    stk1.push(cur);
    while (!stk1.empty())
    {
        cur = stk1.top();
        stk1.pop();

        stk2.push(cur);

        if (cur->left != nullptr)
            stk1.push(cur->left);
        if (cur->right != nullptr)
            stk1.push(cur->right);
    }

    // ������� �� �����, ����������� ������ �� ��� ����� ������ � ������� �� �� �����
    while (!stk2.empty())
    {
        cur = stk2.top();
        stk2.pop();

        delete cur;
    }
    this->root = nullptr;
    this->size = 0;
}

template <class Key_T, class Data_T> typename bool BST<Key_T, Data_T>::append(const Key_T& key, const Data_T& data)
{
    /* ���� ������� ������ � ������ key, ���� �� ����, �� �� ��������� �������, ���� ��� ��� �� ��������� ����� ��� ������
    � ����������� �� key � ����� ����������� ����, �� �������� �����. ���� key ������ ����� � ���� ����, �� ��������� �����,
    ���� ������, �� ������ */

    Node* cur = this->root; // ������� �������

    this->last_op = 1;

    // ���� ������ ���������� �����, �� ��������� ������� � ������ ������
    if (cur == nullptr)
    {
        this->root = new Node(key, data);
        this->size++;
        this->total_op += this->last_op;
        return true;
    }

    // ����� ��������� ������� ��� �������� � ��� �� ������
    while (true)
    {
        // ���� ������� � ����� ������ ��� ���� � ������, �� ������ �� ���������
        if (key == cur->key)
        {
            this->total_op += this->last_op;
            return false;
        }
        if (key < cur->key)
            if (cur->left != nullptr)
                cur = cur->left;
            else
                break;
        else
            if (cur->right != nullptr)
                cur = cur->right;
            else
                break;
        this->last_op++;
    }

    // ���������� �������� � ������ � ����������� �� ��������� �����
    if (key < cur->key)
        cur->left = new Node(key, data);
    else
        cur->right = new Node(key, data);

    this->last_op++;
    this->size++;
    this->total_op += this->last_op;
    return true;
}

template <class Key_T, class Data_T> typename bool BST<Key_T, Data_T>::del(const Key_T& key)
{
    /* ��� �������� �������� �� ������ ������� ���� ������� � �������� ������, ���� ������ �������� ���, �� ������ �� �������
    � ���������� false, ����� ������� ������� � ���������� true */

    Node* cur = this->root; // ������� ������� ������
    Node* par = nullptr; // ������������ ���� ��� ��������

    this->last_op = 1;

    // ����� ��������
    while (cur != nullptr && key != cur->key)
    {
        par = cur;

        if (key < cur->key)
            cur = cur->left;
        else
            cur = cur->right;
        this->last_op++;
    }

    // ���� ������� �� ������, �� �� ������� ������
    if (cur == nullptr)
        return false;

    // ������ ��������� �������� ��� �������� ���������� ��������
    // ������ - ������� �� �������� ��������
    if (cur->left == nullptr && cur->right == nullptr)
    {
        if (cur == this->root) // ���� ��������� ������� - ������ ������
            this->root = nullptr;
        else
            // ������������ �����, ������� ��� � ������� �������� ����������� null
            if (par->left == cur)
                par->left = nullptr;
            else
                par->right = nullptr;
    }
    // ������ - ������� �������� ������ ������� �������
    else if (cur->left == nullptr)
    {
        if (cur == this->root)
            this->root = this->root->right;
        else
        {
            // ������������ ����� ����������� ������ ����� ���������� ��������
            if (par->left == cur)
                par->left = cur->right;
            else
                par->right = cur->right;
        }
    }
    // ������ - ������� �������� ������ ������ �������
    else if (cur->right == nullptr)
    {
        if (cur == this->root)
            this->root = this->root->left;
        else
        {
            // ������������ ����� ����������� ����� ����� ���������� ��������
            if (par->left == cur)
                par->left = cur->left;
            else
                par->right = cur->left;
        }
    }
    // �������� - ������� �������� ��� �������
    else
    {
        Node* del = cur; // ��������� �� ��������� �������

        cur = cur->right; // ��������� � ����� ������ ��������. ������ cur - ��������� �� ���������� �������
        this->last_op++;

        // ���� ���������� �������
        while (cur->left != nullptr)
        {
            par = cur;
            cur = cur->left;
            this->last_op++;
        }

        // ���� � ������ ����������� �������� ����������� �������������� ��������� ���������� ��������
        del->key = cur->key;
        del->data = cur->data;
        if (del->right == cur)  // ���� ���������� ������� - ��� ������ ������ ��������
            del->right = cur->right; // �� ��������� ������ ����� ���������� �������� � ������ ������ �����������
        else
            par->left = cur->right; // ����� ����� ����� �������� ����������� �������� ����������� ������ ����� ����������� ��������
    }

    delete cur;
    this->last_op++;
    this->total_op += this->last_op;
    this->size--;

    return true;
}

template <class Key_T, class Data_T> typename void BST<Key_T, Data_T>::print()
{
    /* ������� ������ ��������, ������ � ������� ��������� ������ */

    Node* cur = this->root; // ������� ���� ������
    size_t cur_level = 0; // ������� ������� ��������
    stack<Node*> stk1, stk2, stk3; // ��������������� ����� �����
    stack<size_t> level_stk1, level_stk2, level_stk3; // ��������������� ����� �������

    if (cur == nullptr)
    {
        cout << endl;
        return;
    }

    stk1.push(cur);
    level_stk1.push(cur_level);
    while (!stk1.empty() || !stk2.empty())
    {
        if (!stk1.empty())
        {
            cur = stk1.top();
            stk1.pop();
            cur_level = level_stk1.top();
            level_stk1.pop();

            stk2.push(cur);
            level_stk2.push(cur_level);

            if (cur->left != nullptr)
            {
                stk1.push(cur->left);
                level_stk1.push(cur_level + 1);
            }
        }
        else
        {
            cur = stk2.top();
            stk2.pop();
            cur_level = level_stk2.top();
            level_stk2.pop();

            stk3.push(cur);
            level_stk3.push(cur_level);

            if (cur->right != nullptr)
            {
                stk1.push(cur->right);
                level_stk1.push(cur_level + 1);
            }
        }
    }

    while (!stk3.empty())
    {
        cur = stk3.top();
        stk3.pop();
        cur_level = level_stk3.top();
        level_stk3.pop();

        for (size_t i = 0; i < cur_level; i++)
            cout << "   ";
        cout << cur->key << endl << endl;
    }
    cout << endl;
}

template <class Key_T, class Data_T> typename void BST<Key_T, Data_T>::printAsDict()
{
    /* ������� ������ ��������, ������ � ������� ��������� ������ � ���� ������� */

    Node* cur = this->root; // ������� ���� ������
    stack<Node*> stk1, stk2, stk3; // ��������������� ����� �����

    if (cur == nullptr)
    {
        cout << "{}" << endl;
        cout << endl;
        return;
    }

    stk1.push(cur);
    while (!stk1.empty() || !stk2.empty())
    {
        if (!stk1.empty())
        {
            cur = stk1.top();
            stk1.pop();

            stk2.push(cur);

            if (cur->right != nullptr)
                stk1.push(cur->right);
        }
        else
        {
            cur = stk2.top();
            stk2.pop();

            stk3.push(cur);

            if (cur->left != nullptr)
                stk1.push(cur->left);
        }
    }

    cout << "{";
    while (stk3.size() > 1)
    {
        cur = stk3.top();
        stk3.pop();

        cout << cur->key << ": " << cur->data << ", ";
    }
    cur = stk3.top();
    stk3.pop();

    cout << cur->key << ": " << cur->data << "}" << endl;
    cout << endl;
}

template <class Key_T, class Data_T> typename void BST<Key_T, Data_T>::printKeys()
{
    /* ������� ������ ��������, ������ � ������� ������ ������ ������ */

    Node* cur = this->root; // ������� ���� ������
    stack<Node*> stk1, stk2, stk3; // ��������������� ����� �����

    if (cur == nullptr)
    {
        cout << "[]" << endl;
        cout << endl;
        return;
    }

    stk1.push(cur);
    while (!stk1.empty() || !stk2.empty())
    {
        if (!stk1.empty())
        {
            cur = stk1.top();
            stk1.pop();

            stk2.push(cur);

            if (cur->right != nullptr)
                stk1.push(cur->right);
        }
        else
        {
            cur = stk2.top();
            stk2.pop();

            stk3.push(cur);

            if (cur->left != nullptr)
                stk1.push(cur->left);
        }
    }

    cout << "[";
    while (stk3.size() > 1)
    {
        cur = stk3.top();
        stk3.pop();

        cout << cur->key << ", ";
    }
    cur = stk3.top();
    stk3.pop();

    cout << cur->key << "]" << endl;
    cout << endl;
}

template <class Key_T, class Data_T> typename void BST<Key_T, Data_T>::printCount()
{
    cout << "���������� ��������� �� ��������� ��������: " << this->last_op << "." << endl;
    cout << "��������� ���������� ���������: " << this->total_op << "." << endl;
}

template <class Key_T, class Data_T> typename BST<Key_T, Data_T>::Iterator BST<Key_T, Data_T>::begin()
{
    Node* cur = this->root;

    if (cur == nullptr)
        return Iterator(*this);

    // ���� ������� ������ � ����������� ������ � ������������� �������� �� ����
    while (cur->left != nullptr)
        cur = cur->left;

    return Iterator(*this, cur->key);
}

template <class Key_T, class Data_T> typename BST<Key_T, Data_T>::Iterator BST<Key_T, Data_T>::end() { return Iterator(*this); }

template <class Key_T, class Data_T> typename BST<Key_T, Data_T>::RIterator BST<Key_T, Data_T>::rbegin()
{
    Node* cur = this->root;

    if (cur == nullptr)
        return RIterator(*this);

    // ���� ������� ������ � ������������ ������ � ������������� �������� �� ����
    while (cur->right != nullptr)
        cur = cur->right;

    return RIterator(*this, cur->key);
}

template <class Key_T, class Data_T> typename BST<Key_T, Data_T>::RIterator BST<Key_T, Data_T>::rend() { return RIterator(*this); }
