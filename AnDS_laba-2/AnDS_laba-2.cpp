// Включаемые заголовки
#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>
#include <ctime>
#include "BST.h"
#include "Test_BST.h"

// Максимальный задаваемый размер дерева
#define MAX_SIZE 1000


// Прототипы функций
int get_val();


int main()
{
    BST<int, int> tree; // Используемое BST-дерево
    int choose; // Выбираемый пункт меню

    setlocale(LC_ALL, "Russian");
    srand(time(nullptr));

    cout << "\tПрограмма \"АТД BST-дерево\"." << endl;

    cout << "Выберите тип заполнения BST-дерева:" << endl;
    cout << "1: Пустое дерево." << endl;
    cout << "2: Дерево с случайными данными." << endl;

    choose = get_val();
    while (choose < 1 || choose > 2)
    {
        cout << "Ошибка: данного пункта меню не существует. Повторите ввод." << endl;
        choose = get_val();
    }
    switch (choose)
    {
        case 1:
        {
            break; // дерево изначально пустое, поэтому ничего не делаем
        }
        case 2:
        {
            int size;

            cout << "Введите количество элементов дерева" << endl;
            size = get_val();
            while (size > MAX_SIZE || size < 0)
            {
                cout << "Ошибка: введённый размер меньше 0 или превышает " << MAX_SIZE << ". Повторите ввод." << endl;
                size = get_val();
            }
            for (int i = 0; i < size; i++)
                tree.append(i, rand());
            tree.setLastOp(0);
            tree.setTotalOp(0);
        }
    }
    cout << "BST-дерево успешно создано." << endl << endl;

    bool isExit = false;
    while (!isExit)
    {
        cout << "Меню программы:" << endl;
        cout << "01 - Получить размер текущего дерева." << endl;
        cout << "02 - Получить количество переборов в дереве на последней операции." << endl;
        cout << "03 - Получить количество переборов в дереве с момента его создания." << endl;
        cout << "04 - Получить длину внешнего пути дерева." << endl;
        cout << "05 - Получить элемент дерева по ключу." << endl;
        cout << "06 - Установить новое значение элемента дерева по ключу." << endl;
        cout << "07 - Проверка дерева на пустоту." << endl;
        cout << "08 - Очистка дерева." << endl;
        cout << "09 - Добавить элемент в дерево с заданным ключом." << endl;
        cout << "10 - Удалить элемент из дерева по ключу." << endl;
        cout << "11 - Вывести дерево в древовидной форме." << endl;
        cout << "12 - Вывести дерево в форме словаря(ключ-значение)." << endl;
        cout << "13 - Вывести ключи дерева в симметричном порядке. (LtR)" << endl;
        cout << "14 - Вывести статистику переборов в дереве." << endl;
        cout << "15 - Перейти в раздел управления \"Прямой итератор\"." << endl;
        cout << "16 - Перейти в раздел управления \"Обратный итератор\"." << endl;
        cout << "17 - Перейти к тестированию." << endl;
        cout << "0  - Выйти из программы." << endl;

        cout << "Выберите пункт меню:" << endl;
        choose = get_val();
        while (choose < 0 || choose > 17)
        {
            cout << "Ошибка: данного пункта меню не существует. Повторите ввод." << endl;
            choose = get_val();
        }

        switch (choose)
        {
        case 1:
        {
            cout << "Размер текущего дерева: " << tree.getSize() << "." << endl;
            break;
        }
        case 2:
        {
            cout << "Количество переборов в дереве на последней операции: " << tree.getLastOp() << "." << endl;
            break;
        }
        case 3:
        {
            cout << "Количество переборов в дереве с момента его создания: " << tree.getTotalOp() << "." << endl;
            break;
        }
        case 4:
        {
            cout << "Длина внешнего пути дерева: " << tree.getExternalPath() << "." << endl;
            break;
        }
        case 5:
        {
            cout << "Введите ключ:" << endl;
            int key = get_val();

            try
            {
                cout << "Элемент дерева с данным ключом: " << tree[key] << "." << endl;
            }
            catch (int exception)
            {
                if (exception == NotInBST)
                    cout << "Exception" << endl;
            }
            break;
        }
        case 6:
        {
            cout << "Введите ключ:" << endl;
            int key = get_val();
            cout << "Введите элемент:" << endl;
            int val = get_val();

            try
            {
                tree[key] = val;
                cout << "Элемент успешно установлен." << endl;
            }
            catch (int exception)
            {
                if (exception == NotInBST)
                    cout << "Ошибка: элемента с данным ключом в дереве нет." << endl;
            }
            break;
        }
        case 7:
        {
            if (!tree.isEmpty())
                cout << "Дерево содержит элементы." << endl;
            else
                cout << "Дерево пусто." << endl;
            break;
        }
        case 8:
        {
            tree.clear();
            cout << "Дерево успешно очищено." << endl;
            break;
        }
        case 9:
        {
            cout << "Введите ключ:" << endl;
            int key = get_val();
            cout << "Введите элемент:" << endl;
            int val = get_val();

            cout << tree.append(key, val) << endl;
            break;
        }
        case 10:
        {
            cout << "Введите ключ:" << endl;
            int key = get_val();

            cout << tree.del(key) << endl;
          
            break;
        }
        case 11:
        {
            cout << "Структура текущего BST-дерева в древовидном виде:" << endl;
            tree.print();
            break;
        }
        case 12:
        {
            cout << "Структура текущего BST-дерева в виде словаря \"ключ-значение\":" << endl;
            tree.printAsDict();
            break;
        }
        case 13:
        {
            cout << "Ключи текущего BST-дерева от наименьшего к наибольшему:" << endl;
            tree.printKeys();
            break;
        }
        case 14:
        {
            cout << "Статистика переборов элементов в дереве:" << endl;
            tree.printCount();
            break;
        }
        case 15:
        {
            BST<int, int>::Iterator iter;
            iter = BST<int, int>::Iterator(tree);
            bool isExit = false;
            while (!isExit)
            {
                cout << "Меню \"Прямой итератор\":" << endl;
                cout << "\t1: Запрос итератора begin." << endl;
                cout << "\t2: Запрос итератора end." << endl;
                cout << "\t3: Установить итератор по заданному ключу." << endl;
                cout << "\t4: Получить элемент итератора." << endl;
                cout << "\t5: Инкрементировать итератор." << endl;
                cout << "\t6: Декрементировать итератор." << endl;
                cout << "\t7: Пройти по всем элементам дерева, начиная с данного, с помощью итератора." << endl;
                cout << "\t8: Вывести дерево." << endl;
                cout << "\t9: Выйти из данного раздела." << endl;
                //cout << "\t10: Изменение текущего ключа" << endl;

                cout << "Выберите пункт меню:" << endl;
                choose = get_val();
                while (choose < 1 || choose > 11)
                {
                    cout << "Ошибка: данного пункта меню не существует. Повторите ввод." << endl;
                    choose = get_val();
                }

                switch (choose)
                {
                case 1:
                {
                    iter = tree.begin();
                    cout << "Установлен итератор begin." << endl;
                    break;
                }
                case 2:
                {
                    iter = tree.end();
                    cout << "Установлен итератор end." << endl;
                    break;
                }
                case 3:
                {
                    try
                    {
                        int data = 0;
                        cout << "Введите значение: ";
                        cin >> data;
                        iter.change(data);
                        cout << "Ключ изменен: " << *iter << "." << endl;
                    }
                    catch (int exception)
                    {
                        if (exception == IteratorIsNotInstall)
                            cout << "Ошибка: итератор не установлен." << endl;
                    }
                    break;
                }
                case 4:
                {
                    try
                    {
                        cout << "Ключ элемента дерева, на который в данный момент установлен итератор: " << *iter << "." << endl;
                    }
                    catch (int exception)
                    {
                        if (exception == IteratorIsNotInstall)
                            cout << "Exception" << endl;
                    }
                    break;
                }
                case 5:
                {
                    try
                    {
                        iter++;
                        if (!iter.is_established())
                            cout << "Внимание: итератор перешёл в состояние \"неустановлен\"." << endl;
                        else
                            cout << "Итератор успешно изменён." << endl;
                    }
                    catch (int exception)
                    {
                        if (exception == IteratorIsNotInstall)
                            cout << "Exception" << endl;
                    }
                    break;
                }
                case 6:
                {
                    try
                    {
                        iter--;
                        if (!iter.is_established())
                            cout << "Внимание: итератор перешёл в состояние \"неустановлен\"." << endl;
                        else
                            cout << "Итератор успешно изменён." << endl;
                    }
                    catch (int exception)
                    {
                        if (exception == IteratorIsNotInstall)
                            cout << "Exception" << endl;
                    }
                    break;
                }
                case 7:
                {
                    if (!iter.is_established())
                    {
                        cout << "Exception" << endl;
                        break;
                    }
                    cout << "Все элементы дерева, пройденные итератором: ";
                    for (BST<int, int>::Iterator end = tree.end(); iter != end; iter++)
                        cout << *iter << " ";
                    cout << endl << "Внимание: итератор перешёл в состояние \"неустановлен\"." << endl;
                    break;
                }
                case 8: {
                    tree.print();
                    break;
                }
                case 9:
                {
                    cout << "Выходим из раздела \"Прямой итератор\"..." << endl;
                    isExit = true;
                    break;
                }
                case 10:
                {
                    int data = 0;
                    cout << "Введите значение: ";
                    cin >> data;
                    iter.change(data);
                    try
                    {  
                        cout << "Ключ изменен: " << *iter << "." << endl;
                    }
                    catch (int exception)
                    {
                        if (exception == IteratorIsNotInstall)
                            cout << "Ошибка: итератор не установлен." << endl;
                    }
                    break;
                }
                }
                cout << endl;
            }

            break;
        }
        case 16:
        {
            BST<int, int>::RIterator riter;
            riter = BST<int, int>::RIterator(tree);

            bool isExit = false;
            while (!isExit)
            {
                cout << "Меню \"Обратный итератор\":" << endl;
                cout << "\t1: Установить итератор rbegin" << endl;
                cout << "\t2: Установить итератор rend" << endl;
                cout << "\t3: Установить итератор по заданному ключу." << endl;
                cout << "\t4: Получить элемент итератора." << endl;
                cout << "\t5: Инкрементировать итератор." << endl;
                cout << "\t6: Декрементировать итератор." << endl;
                cout << "\t7: Пройти по всем элементам дерева, начиная с данного, с помощью итератора." << endl;
                cout << "\t8: Вывести дерево." << endl;
                cout << "\t9: Выйти из данного раздела." << endl;
                //cout << "\t10: Изменить значение итератора" << endl;
                cout << "Выберите пункт меню:" << endl;
                choose = get_val();
                while (choose < 1 || choose > 11)
                {
                    cout << "Ошибка: данного пункта меню не существует. Повторите ввод." << endl;
                    choose = get_val();
                }

                switch (choose)
                {
                case 1:
                {
                    riter = tree.rbegin();
                    cout << "Установлен итератор rbegin." << endl;
                    break;
                }
                case 2:
                {
                    riter = tree.rend();
                    cout << "Установлен итератор rend." << endl;
                    break;
                }
                case 3:
                {
                    try
                    {
                    int data = 0;
                    cout << "Введите значение: ";
                    cin >> data;
                    riter.change(data);
                        cout << "Ключ изменен: " << *riter << "." << endl;
                    }
                    catch (int exception)
                    {
                        if (exception == IteratorIsNotInstall)
                            cout << "Exception" << endl;
                    }
                    break;
                }
                case 4:
                {
                    try
                    {
                        cout << "Ключ элемента дерева, на который в данный момент установлен итератор: " << *(riter) << "." << endl;
                    }
                    catch (int exception)
                    {
                        if (exception == IteratorIsNotInstall)
                            cout << "Exception" << endl;
                    }
                    break;
                }
                case 5:
                {
                    try
                    {
                        riter++;
                        if (!riter.is_established())
                            cout << "Внимание: итератор перешёл в состояние \"неустановлен\"." << endl;
                        else
                            cout << "Итератор успешно изменён." << endl;
                    }
                    catch (int exception)
                    {
                        if (exception == IteratorIsNotInstall)
                            cout << "Exception" << endl;
                    }
                    break;
                }
                case 6:
                {
                    try
                    {
                        riter--;
                        if (!riter.is_established())
                            cout << "Внимание: итератор перешёл в состояние \"неустановлен\"." << endl;
                        else
                            cout << "Итератор успешно изменён." << endl;
                    }
                    catch (int exception)
                    {
                        if (exception == IteratorIsNotInstall)
                            cout << "Exception" << endl;
                    }
                    break;
                }
                case 7:
                {
                    if (!riter.is_established())
                    {
                        cout << "Exception" << endl;
                        break;
                    }
                    cout << "Все элементы дерева, пройденные итератором: ";
                    for (BST<int, int>::RIterator rend = tree.rend(); riter != rend; riter++)
                        cout << *riter << " ";
                    cout << endl << "Внимание: итератор перешёл в состояние \"неустановлен\"." << endl;
                    break;
                }
                case 8:
                {
                    tree.print();
                    break;
                }
                case 9:
                {
                    cout << "Выходим из раздела \"Обратный итератор\"..." << endl;
                    isExit = true;
                    break;
                }
                case 10:
                {
                    int data = 0;
                    cout << "Введите значение: ";
                    cin >> data;
                    riter.change(data);
                    try
                    {
                        cout << "Ключ изменен: " << *riter << "." << endl;
                    }
                    catch (int exception)
                    {
                        if (exception == IteratorIsNotInstall)
                            cout << "Exception" << endl;
                    }
                    break;
                }
                }
                cout << endl;
            }

            break;
        }
        case 17:
        {
            test_menu();
            break;
        }
        case 0:
        {
            cout << "Выходим из программы..." << endl;
            isExit = true;
            break;
        }
        }
        cout << endl;
    }

    cout << "Программа успешно завершила свою работу. Нажмите Enter для выхода из программы...";
    cin.get();

    return 0;
}


int get_val()
{
    string buf;
    int val;

    cout << "Ввод >> ";
    getline(cin, buf);

    while (true)
    {
        try
        {
            val = stoi(buf);
            break;
        }
        catch (invalid_argument)
        {
            cout << "Ошибка: неверный формат входных данных." << endl;
        }
        catch (out_of_range)
        {
            cout << "Ошибка: введённое число вышло из диапазона int." << endl;
        }

        cout << "Ввод >> ";
        getline(cin, buf);
    }

    return val;
}
