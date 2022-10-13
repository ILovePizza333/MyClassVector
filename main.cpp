#pragma once
#include <iostream>
#include "Class.h"
#include "Class.cpp"
using namespace std;

void TestV(Vector < double >* aVec)
{
    for (int i = 0; i < aVec->Size(); i++)
    {
        cout << aVec->at(i) << "  ";
    }
}

int main()
{
    {
        Vector<double> oV;
        try
        {
            oV[0];
        }
        catch (int val)
        {
            int a = val;
        }
       
        for(int i=0; i<10; i++)
        oV.PushBack(0.01+i);
        double tmp = oV[0];
        cout << oV[0] << " ";
        TestV(&oV);
        return 0;
        Vector<double>::Iterator beg = oV.begin(),
            end = oV.end();
        while (beg != end)
        {
            cout << *beg++ <<" ";
        }
        cout << oV.Size();
        cout << oV.IsEmpty();
       
    }
    cout << "Instruction " << endl;
    cout << "1)PushBack " << endl; // вставка элемента в конец
    cout << "2)Read(i) " << endl; // чтение i элемента
    cout << "3)DeleteBack " << endl;  //удаление последнего эл-та
    cout << "4)ClearAll " << endl; //очистка
    cout << "5)IsEmpty? " << endl; //проверка на пустоту
    cout << "6)Size(count of elements)" << endl; //размер вектора(кол-во эл-тов)
    cout << "7)PrintVector " << endl; //печать вектора
    cout << "8)Change " << endl; // изменение существующего элемента
    cout << "9)Reserve" << endl; // резервирование
    cout << "10)Iterator check(print vector)" << endl; // проверка итератора
   
    cout << "\n"; //Конец инструкции
    
    Vector <int> myVector(1); //создание объекта класса вектор
    myVector.PushBack(99); 
    myVector.PushBack(199);
    myVector.PrintVector();

    /*
    //проверка вектор в векторе
    cout << "\n---vector in vector---";
    {

        Vector <Vector<int>*> mainVector;
        mainVector.PushBack(&myVector);
        mainVector.Size();
        mainVector.PrintVector();
        mainVector.GetIndex(0);
        mainVector.GetIndex(1);
        //.....
    }
    cout << "\n---vector in vector end---\n";
    */
    /*
    //проверка конструктора копирования
    Vector <int> obj1;
    obj1.PushBack(2);
    obj1.PushBack(34);
    Vector <int> obj2 = obj1;
    obj1.~Vector();
    obj2.PrintVector();
    */

    while (1) {
        cout << "\nEnter command: " << endl;
        int input;
        int element;
        int index;
        int result;
        int t;
        cin >> input;
        cout << endl;
        switch (input) {
        case 1:
            cout << "\nEnter element " << endl; // добавление эл-та в конец
            cin >> element;
            myVector.PushBack(element);
            break;
        case 2:
            cout << "\nEnter element " << endl; // чтение эл-та в конец
            cin >> element;
            myVector.GetIndex(element);
            break;
        case 3:
            cout << "DelBack " << endl; //очистка
            result = myVector.DelBack(); // удаление последнего эл-та
            if (result == 1) {
                cout << "Del ok" << endl;
            }
            else {
                cout << "Del Error" << endl;
            }
            break;
        case 4:
            cout << "delAll" << endl;
            result = myVector.DelAll();
            if (result == 1) {
                cout << "Del ok" << endl;
            }
            else {
                cout << "Del Error" << endl;
            }
            break;
        case 5:
            result = myVector.IsEmpty();
            if (result == 1) {
                cout << "Vector is Empty" << endl;
            }
            else {
                cout << "Vector is not Empty" << endl;
            }
            break;
        case 6:
            result = myVector.Size(); //размер вектора(кол-во эл-тов)
            cout << "Size: " << result << "\n" << endl;
            break;
        case 7:
            cout << "PrintVector: " << endl; //печать вектора
            myVector.PrintVector(); // вывод вектора на экран
            break;
        case 8:
            cout << "\nEnter index " << endl;
            cin >> index;
            cout << "\nEnter element " << endl;
            cin >> element;
            myVector.Change(index, element);
            break;
        case 9:
            cout << "\nEnter count " << endl;
            cin >> element;
            myVector.Reserve(element);
            break;
        case 10:
            Vector<int>::Iterator beg = myVector.begin();
            Vector<int>::Iterator pos = myVector.begin();
            Vector<int>::Iterator end = myVector.end();
            cout << "\nPrint mass\n";
            while (pos != end)
            {
                t = *pos++;
                cout << "|" << t << endl;
            }
            cout << "\nprint for index\n";
            cout << "\nEnter element " << endl; // добавление эл-та в конец
            cin >> element;
            pos = beg;
            while (element > 0)
            {
                pos++;
                element--;
            }
            if (pos != end) {
            t = *pos;
            cout << t << endl;
        }
            break;
        default:
            cout << "\nError, repeat\n";
        }
      /*
        Vector<int>::Iterator beg = myVector.begin();
        Vector<int>::Iterator pos = myVector.begin();
        Vector<int>::Iterator end = myVector.end();

        while (pos != end)
        {
            int t = *pos++;
            cout << "\npos" << t << endl;
        }
        */
    }
    return 0;
}
