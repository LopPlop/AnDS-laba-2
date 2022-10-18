// ������������ ���������� � ������������ �����
#include <iostream>
#include <string> 
#include <math.h>
#include <time.h>
#include <locale.h>
#include "BST.h"

#define MAX_SIZE 1000000 // ����������� ���������� ������ ������

using namespace std;
typedef unsigned long long INT_64;

// ���������� � ��������� ���������� LineRand() 
static INT_64 RRand = 15750;
const INT_64 mRand = (1 << 63) - 1;
const INT_64 aRand = 6364136223846793005;
const INT_64 cRand = 1442695040888963407;

// ��������� �������
void sRand();
INT_64 LineRand();
void test_rand(int n);
void test_ord(int n, INT_64 delta);
INT_64 get_value();


int test_menu()
{
    INT_64 start, end, step;

    //setlocale(LC_ALL, "Russian");

    cout << "\t\t\t��������� ������������ �������� �������, �������� � ������ � BST-������." << endl << endl;

    cout << "������� ��������� �������� ����������� ������" << endl;
    start = get_value();
    while (start > MAX_SIZE)
    {
        cout << "������: �������� �������� ��������� ����������� ��������� ���������� ������������ �������� ����������� ������.";
        cout << "��������� ����." << endl;
        start = get_value();
    }
    cout << "������� �������� �������� ����������� ������"<< endl;
    end = get_value();
    while (end > MAX_SIZE)
    {
        cout << "������: �������� �������� ��������� ����������� ��������� ���������� ������������ �������� ����������� ������.";
        cout << "��������� ����." << endl;
        end = get_value();
    }
    //cout << "������� ��� ��� ����������� ������." << endl;
    //step = get_value();

    cout << "������������ ��������..." << endl;
    for (INT_64 i = start; i <= end; i *= 10)
    {
        cout << "���������� ������������ ���������� ������ ������������ " << i << ":" << endl;
        test_rand(i);
        cout << "���������� ������������ ������������ ������ ������������ " << i << ":" << endl;
        test_ord(i, 1000000);
        cout << endl;
    }
    cout << "������������ ��������." << endl;
    cout << "��������� ������� ��������� ���� ������. ������� Enter ��� ������ �� ���������...";
    cin.get();

    return 0;
}

// ������� ��������� ������� ���������� ����� �� ����� ����������
void sRand() { srand(time(0)); RRand = (INT_64)rand(); }

// ������� ��������� ���������� �����  �������� ������������ ����������� Xi+1 =(a * Xi + c) % arr 
//habr.com/ru/post/208178 
INT_64 LineRand()
{
    INT_64 y1, y2;

    y1 = (aRand * RRand + cRand) % mRand;
    y2 = (aRand * y1 + cRand) % mRand;
    RRand = y1 & 0xFFFFFFFF00000000LL ^ (y2 & 0xFFFFFFFF00000000LL) >> 32;

    return RRand;
}

// ������������ ���������� BST-������
void test_rand(int n)
{
    BST<INT_64, int> tree;  // �������� ������ ��� 64 � ��������� ������ ���� INT_64
    INT_64* arr = new INT_64[n]; // ������ ��� ������, ������� ������������ � ������

    sRand(); // ��������� ������� ���������� �����

    for (int i = 0; i < n; i++)  // ���������� ������ � ������� ���������� �� ���������� ������� 
    {
        arr[i] = LineRand();
        tree.append(arr[i], 1);
    }

    // �������� �������� �������� ������ BST-������
    tree.setLastOp(0);
    tree.setTotalOp(0);

    // ����� ������� ������ �� ����� 
    cout << "����������� ������ �� ���������: " << tree.getSize() << "." << endl;

    // ��������� ��������� ����������� �������, �������� � ������ 
    double I = 0;
    double D = 0;
    double S = 0;

    // ��������� ������ ��������, 10% - ������� �������� 
    for (int i = 0; i < n / 2; i++)
        if (i % 10 == 0) // 10% �������� 
        {
            tree.del(LineRand());
            D += tree.getLastOp();
            tree.append(arr[rand() % n], 1);
            I += tree.getLastOp();
            try
            {
                tree.getItemByKey(LineRand());
                S += tree.getLastOp();
            }
            // ��������� ���������� ��� ������ �������� ������ 
            catch (int) { S += tree.getLastOp(); }
        }
        else // 90% �������� �������� 
        {
            int index = rand() % n;

            tree.del(arr[index]);
            D += tree.getLastOp();

            INT_64 key = LineRand();

            tree.append(key, 1);
            I += tree.getLastOp();
            arr[index] = key;
            try
            {
                tree.getItemByKey(arr[rand() % n]);
                S += tree.getLastOp();
            }
            // ��������� ���������� ��� ������ �������� ������ 
            catch (int) { S += tree.getLastOp(); }
        } // ����� ����� 

    // ����� �����������:  
    cout << "����������� ������ ����� ���������: " << tree.getSize() << endl; // ����� ������� ������ ����� ����� 
    cout << "������������� ������(1.39 * log2(n)): " << 1.39 * (log((double)n) / log(2.0)) << endl; // ������������� ������ ����������� �������� BST
    cout << "������� ���������� ��������� �� ���� �������: " << I / (n / 2) << endl; // ����������������� ������ ����������� ������� 
    cout << "������� ���������� ��������� �� ���� ��������: " << D / (n / 2) << endl; // ����������������� ������ ����������� ��������  
    cout << "������� ���������� ��������� �� ���� �����: " << S / (n / 2) << endl; // ����������������� ������ ����������� ������ 
    delete[] arr; // ������������ ������ ������� arr[]
}

// ������������ ������������ BST-������
// delta - �������� ����� ��������������� ������������� �������
void test_ord(int n, INT_64 delta)
{
    BST< INT_64, int > tree; // �������� ������ ��� 64 � ��������� ������ ���� INT_64  
    INT_64* arr = new INT_64[n]; // ������ ��� ������, ������� ������������ � ������

    sRand(); // ��������� ������� ���������� �����

    // ���������� ������ � ������� ���������� � ������������� ������� ������� �� ��������� [0, delta, 2 * delta, ... ,delta * n] 
    for (int i = 0; i < n; i++)
    {
        arr[i] = i * delta;
        tree.append(arr[i], 1);
    }

    // �������� �������� �������� ������ BST-������
    tree.setLastOp(0);
    tree.setTotalOp(0);

    cout << "����������� ������ �� ���������: " << tree.getSize() << endl; // ����� ������� ������ �� �����

    // ��������� ��������� ����������� �������, �������� � ������
    double I = 0;
    double D = 0;
    double S = 0;

    // ��������� ������ ��������, 10% - ������� �������� 
    for (int i = 0; i < n / 2; i++)
    {
        if (i % 10 == 0)  // 10% �������� 
        {
            int key = LineRand() % (delta * n);

            key += ~(key % 2); // ��������� �������� ���� 
            tree.del(key);
            D += tree.getLastOp();
            tree.append(arr[rand() % n], 1);
            I += tree.getLastOp();
            key = LineRand() % (delta * n);
            key += ~(key % 2); // ��������� �������� ���� 
            try
            {
                tree.getItemByKey(key);
                S += tree.getLastOp();
            }
            catch (int) { S += tree.getLastOp(); } // ��������� ���������� ��� ������ �������� ������ 
        }
        else  // 90% �������� �������� 
        {
            int index = rand() % n;

            tree.del(arr[index]);
            D += tree.getLastOp();

            int key = LineRand() % (delta * n);

            key += key % 2;  // ��������� ������ ���� 
            tree.append(key, 1);
            I += tree.getLastOp();
            arr[index] = key;
            try
            {
                tree.getItemByKey(arr[rand() % n]);
                S += tree.getLastOp();
            }
            catch (int) { S += tree.getLastOp(); } // ��������� ���������� ��� ������ �������� ������ 
        }
    }

    // ����� �����������:
    cout << "����������� ������ ����� ���������: " << tree.getSize() << endl; // ����� ������� ������ ����� ����� 
    cout << "������������� ������(n / 2): " << n / 2 << endl; // ������������� ������ ����������� �������� BST 
    cout << "������� ���������� ��������� �� ���� �������: " << I / (n / 2) << endl; // ����������������� ������ ����������� �������
    cout << "������� ���������� ��������� �� ���� ��������: " << D / (n / 2) << endl; // ����������������� ������ ����������� ��������
    cout << "������� ���������� ��������� �� ���� �����: " << S / (n / 2) << endl; // ����������������� ������ ����������� ������
    delete[] arr; // ������������ ������ ������� arr[]
}

INT_64 get_value()
{
    string buf;
    INT_64 val;

    cout << ">>> ";
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
            cout << "������: �������� ������ ������� ������." << endl;
        }
        catch (out_of_range)
        {
            cout << "������: �������� ����� ����� �� ��������� int." << endl;
        }

        cout << ">>> ";
        getline(cin, buf);
    }

    return val;
}

