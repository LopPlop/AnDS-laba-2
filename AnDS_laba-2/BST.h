#pragma once
#include <iostream>
#include <stack>


//************************************************************ Макросы исключений ************************************************//
#define NotInBST 0 // Элемента нет в BST дереве
#define IteratorIsNotInstall 1 // Прямой или обратный итераторы не установлены


//****************************************************** Используемые пространства имён ******************************************//
using namespace std;

//************************************************************ Класс АТД BST *****************************************************//
template <class Key_T, class Data_T>
class BST
{
    // Класс - узел BST-дерева
    class Node
    {
    public:
        Key_T key; // Ключ узла
        Data_T data; // Данные узла
        Node* left; // Указатель на левое поддерево
        Node* right; // Указатель на правое поддерево
        Node(const Key_T& key, const Data_T& data); // Конструктор узла с параметрами
        friend class BST;
    };

    int size; // Количество элементов в дереве
    Node* root; // Указатель на корень дерева
    int last_op;  // Количество переборов на последней операции
    int total_op; // Суммарное количество переборов

    void constructor(); // Тело конструктора по умолчанию
    void copy(const BST& tree); // Тело конструктора копирования
public:
    // Класс прямого итератора
    class Iterator
    {
        const BST* tree; // Указатель на текущее BST-дерево
        Node* cur; // Текущий узел, на который установлен итератор
        stack<Node*> stkl; // Вспомогательный стек для левых родителей
        stack<Node*> stkr; // Вспомогательный стек для правых родителей
    public:
        Iterator(); // Конструктор прямого итератора по умолчанию
        Iterator(const BST& tree); // Конструктор прямого итератора с параметром tree - ссылкой на BST-дерево
        Iterator(const BST& tree, const Key_T& key); // Конструктор прямого итератора с параметрами: tree - ссылка на BST-дерево, key - ключ
        Iterator(const Iterator& iter); // Конструктор копирования прямого итератора

        bool change(int data);

        Data_T operator*(); // Оператор "разыменовывания" - получение текущего элемента узла дерева по ссылке
        Iterator& operator++(); // Оператор префиксного инкрементирования прямого итератора
        Iterator& operator--(); // Оператор префиксного декрементирования прямого итератора
        Iterator operator++(int); // Оператор постфиксного инкрементирования прямого итератора
        Iterator operator--(int); // Оператор постфиксного декрементирования прямого итератора
        Iterator& operator=(const Iterator& iter); // Оператор присваивания прямого итератора
        bool operator==(const Iterator& iter); // Оператор равенства прямых итераторов
        bool operator!=(const Iterator& iter); // Оператор неравенства прямых итераторов

        bool is_established(); // Установлен ли итератор
    };
    friend class Iterator;

    // Класс обратного итератора
    class RIterator
    {
        const BST* tree; // Указатель на текущее BST-дерево
        Node* cur; // Текущий узел, на который установлен итератор
        stack<Node*> stkl; // Вспомогательный стек для левых родителей
        stack<Node*> stkr; // Вспомогательный стек для правых родителей
    public:
        RIterator(); // Конструктор обратного итератора по умолчанию
        RIterator(const BST& tree); // Конструктор обратного итератора с параметром tree - ссылкой на BST-дерево
        RIterator(const BST& tree, const Key_T& key); // Конструктор обратного итератора с параметрами: tree - ссылка на BST-дерево, key - ключ
        RIterator(const RIterator& riter); // Конструктор копирования обратного итератора

        bool change(int data);

        Data_T operator*(); // Оператор "разыменовывания" - получение текущего элемента узла дерева по ссылке
        RIterator& operator++(); // Оператор префиксного инкрементирования обратного итератора
        RIterator& operator--(); // Оператор префиксного декрементирования обратного итератора
        RIterator operator++(int); // Оператор постфиксного инкрементирования обратного итератора
        RIterator operator--(int); // Оператор постфиксного декрементирования обратного итератора
        RIterator& operator=(const RIterator& iter); // Оператор присваивания обратного итератора
        bool operator==(const RIterator& iter); // Оператор равенства обратных итераторов
        bool operator!=(const RIterator& iter); // Оператор неравенства обратных итераторов

        bool is_established(); // Установлен ли итератор
    };
    friend class RIterator;

    BST(); // Конструктор по умолчанию
    BST(const Key_T& key, const Data_T& data); // Конструктор с параметрами
    BST(const BST& tree);  // Конструктор копирования
    ~BST(); // Деструктор

    Data_T& operator[](const Key_T& key); // Оператор доступа к элементу по ключу
    BST& operator=(const BST& tree); // Оператор присваивания деревьев

    int getSize();  // Получить размер дерева
    int getLastOp(); // Получить количество переборов на последней операции
    void setLastOp(int value); // Установить количество переборов на последней операции
    int getTotalOp(); // Получить суммарное количество переборов
    void setTotalOp(int value); // Установить суммарное количество переборов 
    int getExternalPath(); // Получить длину внешнего пути дерева за время O(n)
    Data_T& getItemByKey(const Key_T& key); // Чтение элемента дерева по ключу
    void setItemByKey(const Key_T& key, const Data_T& data); // Запись элемента по заданному ключу
    bool isEmpty(); // Проверка дерева на пустоту
    void clear();  // Очистка дерева
    bool append(const Key_T& key, const Data_T& data); // Добавить элемент с заданным ключом в дерево 
    bool del(const Key_T& key); // Удалить элемент с заданным ключом
    void print(); // Вывести дерево в древовидной форме
    void printAsDict(); // Вывести дерево в форме словаря: ключ-значение
    void printKeys(); // Вывести ключи дерева в симметричном порядке (LtR)
    void printCount(); // Вывод количества переборов на последней итерации и общее количество переборов

    Iterator begin(); // Установка итератора на начальный элемент списка
    Iterator end();  // Установка итератора на элемент после конечного элемента
    RIterator rbegin(); // Установка обратного итератор в конец списка
    RIterator rend();  // Установка обратного итератора перед первым элементом списка
};


//********************************************************** Реализация методов узла **************************************************************//
template <class Key_T, class Data_T> BST<Key_T, Data_T>::Node::Node(const Key_T& key, const Data_T& data)
{
    this->key = key;
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}


//********************************************************** Реализация методов прямого итератора *************************************************//
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

    // Ищем элемент с заданным ключом, добавляя в стеки правых или левых родителей проходимые узлы
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

    // Если элемент с ключом key не был найден
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

    // Если у данного узла есть правый потомок, то переходим к нему
    if (this->cur->right != nullptr)
    {
        this->cur = this->cur->right;
        // Если у этого потомка есть левая ветвь, то проходим по ней, занося узлы в стек левых родителей
        while (this->cur->left != nullptr)
        {
            this->stkl.push(this->cur);
            this->cur = this->cur->left;
        }
    }
    else
    {
        // Если стек левых родителей пуст, то данный элемент - это элемент с максимальным ключом
        if (this->stkl.empty())
        {
            this->cur = nullptr;
            this->stkl = {};
            this->stkr = {};
        }
        // Иначе возвращаемся к ближайшему левому родителю
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

    // Если у данного узла есть левый потомок, то переходим к нему
    if (this->cur->left != nullptr)
    {
        this->cur = this->cur->left;
        // Если у этого потомка есть правая ветвь, то проходим по ней, занося узлы в стек правых родителей
        while (this->cur->right != nullptr)
        {
            this->stkr.push(this->cur);
            this->cur = this->cur->right;
        }
    }
    else
    {
        // Если стек правых родителей пуст, то данный элемент - это элемент с минимальным ключом 
        if (this->stkr.empty())
        {
            this->cur = nullptr;
            this->stkl = {};
            this->stkr = {};
        }
        // Иначе возвращаемся к ближайшему правому родителю
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

//********************************************************** Реализация методов обратного итератора *************************************************//
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

    // Ищем элемент с заданным ключом, добавляя в стеки правых или левых родителей проходимые узлы
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

    // Если элемент с ключом key не был найден
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

    // Если у данного узла есть левый потомок, то переходим к нему
    if (this->cur->left != nullptr)
    {
        this->cur = this->cur->left;
        // Если у этого потомка есть правая ветвь, то проходим по ней, занося узлы в стек правых родителей
        while (this->cur->right != nullptr)
        {
            this->stkr.push(this->cur);
            this->cur = this->cur->right;
        }
    }
    else
    {
        // Если стек правых родителей пуст, то данный элемент - это элемент с минимальным ключом 
        if (this->stkr.empty())
        {
            this->cur = nullptr;
            this->stkl = {};
            this->stkr = {};
        }
        // Иначе возвращаемся к ближайшему правому родителю
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

    // Если у данного узла есть правый потомок, то переходим к нему
    if (this->cur->right != nullptr)
    {
        this->cur = this->cur->right;
        // Если у этого потомка есть левая ветвь, то проходим по ней, занося узлы в стек левых родителей
        while (this->cur->left != nullptr)
        {
            this->stkl.push(this->cur);
            this->cur = this->cur->left;
        }
    }
    else
    {
        // Если стек левых родителей пуст, то данный элемент - это элемент с максимальным ключом
        if (this->stkl.empty())
        {
            this->cur = nullptr;
            this->stkl = {};
            this->stkr = {};
        }
        // Иначе возвращаемся к ближайшему левому родителю
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


//************************************************************* Реализация методов списка *********************************************************//
//Приватные методы:
template <class Key_T, class Data_T> typename void BST<Key_T, Data_T>::constructor()
{
    this->root = nullptr;
    this->size = 0;
    this->last_op = 0;
    this->total_op = 0;
}

template <class Key_T, class Data_T> typename void BST<Key_T, Data_T>::copy(const BST& tree)
{
    /* Обходим дерево tree и данное дерево this префиксно, создавая узлы-копии дерева tree для дерева this*/

    Node* tree_cur = tree.root, * this_cur = nullptr; // Указатели на текущие узлы tree и this 
    stack<Node*> tree_stk, this_stk; // Вспомогательные стеки для обхода деревьев

    constructor();

    // Если tree изначально пусто, то создаём пустое дерево
    if (tree_cur == nullptr)
        return;
    else
        this_cur = this->root = new Node(*tree_cur); // Иначе копируем корень и продолжаем

    // Обходим дерево tree и заодно дерево this, добавляя просматриваемые узлы tree в соответствующие узлы this
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

//Открытые методы:
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
    /* Обходим дерево инфиксно, находя внешние узлы и складывая их уровни */

    Node* cur = this->root; // Текущий узел дерева
    size_t cur_level = 0; // Текущий уровень элемента
    size_t result = 0; // Длина внешнего пути
    stack<Node*> stk1, stk2; // Вспомогательные стеки узлов
    stack<size_t> level_stk1, level_stk2; // Вспомогательные стеки уровней

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

            // Если узел внешний, то добавляем его уровень к результату
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
    /* Обходим дерево в поиске элемента с ключом, равным заданному */

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
    /* Обходим дерево постфиксно, добавляя пройденные вершины в стек stk2, и затем очищаем его, путём удаление каждой
    вершины в стеке */

    Node* cur = this->root; // Текущий узел
    stack<Node*> stk1, stk2; // Вспомогательные стеки для обхода вершин

    // Если дерево пусто, то выходим
    if (cur == nullptr)
        return;

    // Обходим дерево, формируя стек вершин
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

    // Проходя по стеку, освобождаем память из под узлов дерева и удаляем их из стека
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
    /* Ищем элемент дерева с ключом key, если он есть, то не добавляем элемент, если его нет то добавляем влево или вправо
    в зависимости от key и ключа внутреннего узла, до которого дошли. Если key меньше ключа в этом узле, то добавляем влево,
    если больше, то вправо */

    Node* cur = this->root; // Текущий элемент

    this->last_op = 1;

    // Если дерево изначально пусто, то добавляем элемент в корень дерева
    if (cur == nullptr)
    {
        this->root = new Node(key, data);
        this->size++;
        this->total_op += this->last_op;
        return true;
    }

    // Поиск свободной позиции или элемента с тем же ключом
    while (true)
    {
        // Если элемент с таким ключом уже есть в дереве, то ничего не добавляем
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

    // Добавление элемента в дерево в зависимости от заданного ключа
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
    /* Для удаления элемента из дерева сначала ищем элемент с заданным ключом, если такого элемента нет, то ничего не удаляем
    и возвращаем false, иначе удаляем элемент и возвращаем true */

    Node* cur = this->root; // Текущий элемент дерева
    Node* par = nullptr; // Родительский узел для текущего

    this->last_op = 1;

    // Поиск элемента
    while (cur != nullptr && key != cur->key)
    {
        par = cur;

        if (key < cur->key)
            cur = cur->left;
        else
            cur = cur->right;
        this->last_op++;
    }

    // Если элемент не найден, то не удаляем ничего
    if (cur == nullptr)
        return false;

    // Четыре возможных ситуации при удалении найденного элемента
    // Первая - элемент не содержит потомков
    if (cur->left == nullptr && cur->right == nullptr)
    {
        if (cur == this->root) // Если найденный элемент - корень дерева
            this->root = nullptr;
        else
            // Родительской ветви, которая идёт к данному элементу присваиваем null
            if (par->left == cur)
                par->left = nullptr;
            else
                par->right = nullptr;
    }
    // Вторая - элемент содержит только правого потомка
    else if (cur->left == nullptr)
    {
        if (cur == this->root)
            this->root = this->root->right;
        else
        {
            // Родительской ветви присваиваем правую ветвь найденного элемента
            if (par->left == cur)
                par->left = cur->right;
            else
                par->right = cur->right;
        }
    }
    // Третья - элемент содержит только левого потомка
    else if (cur->right == nullptr)
    {
        if (cur == this->root)
            this->root = this->root->left;
        else
        {
            // Родительской ветви присваиваем левую ветвь найденного элемента
            if (par->left == cur)
                par->left = cur->left;
            else
                par->right = cur->left;
        }
    }
    // Четвёртая - элемент содержит оба потомка
    else
    {
        Node* del = cur; // Указатель на удаляемый элемент

        cur = cur->right; // Переходим к корню правых потомков. Теперь cur - указатель на замещающий элемент
        this->last_op++;

        // Ищем замещающий элемент
        while (cur->left != nullptr)
        {
            par = cur;
            cur = cur->left;
            this->last_op++;
        }

        // Ключ и данные замещающего элемента присваиваем соотвествующим атрибутам удаляемого элемента
        del->key = cur->key;
        del->data = cur->data;
        if (del->right == cur)  // Если замещающий элемент - это корень правых потомков
            del->right = cur->right; // то связываем правую ветвь удаляемого элемента с правой ветвью замещающего
        else
            par->left = cur->right; // иначе левой ветви родителя замещающего элемента присваиваем правую ветвь замещающего элемента
    }

    delete cur;
    this->last_op++;
    this->total_op += this->last_op;
    this->size--;

    return true;
}

template <class Key_T, class Data_T> typename void BST<Key_T, Data_T>::print()
{
    /* Обходим дерево инфиксно, выводя в консоль структуру дерева */

    Node* cur = this->root; // Текущий узел дерева
    size_t cur_level = 0; // Текущий уровень элемента
    stack<Node*> stk1, stk2, stk3; // Вспомогательные стеки узлов
    stack<size_t> level_stk1, level_stk2, level_stk3; // Вспомогательные стеки уровней

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
    /* Обходим дерево инфиксно, выводя в консоль структуру дерева в виде словаря */

    Node* cur = this->root; // Текущий узел дерева
    stack<Node*> stk1, stk2, stk3; // Вспомогательные стеки узлов

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
    /* Обходим дерево инфиксно, выводя в консоль список ключей дерева */

    Node* cur = this->root; // Текущий узел дерева
    stack<Node*> stk1, stk2, stk3; // Вспомогательные стеки узлов

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
    cout << "Количество переборов на последней операции: " << this->last_op << "." << endl;
    cout << "Суммарное количество переборов: " << this->total_op << "." << endl;
}

template <class Key_T, class Data_T> typename BST<Key_T, Data_T>::Iterator BST<Key_T, Data_T>::begin()
{
    Node* cur = this->root;

    if (cur == nullptr)
        return Iterator(*this);

    // Ищем элемент дерева с минимальным ключом и устанавливаем итератор на него
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

    // Ищем элемент дерева с максимальным ключом и устанавливаем итератор на него
    while (cur->right != nullptr)
        cur = cur->right;

    return RIterator(*this, cur->key);
}

template <class Key_T, class Data_T> typename BST<Key_T, Data_T>::RIterator BST<Key_T, Data_T>::rend() { return RIterator(*this); }
