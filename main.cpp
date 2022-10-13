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
    cout << "1)PushBack " << endl; // ������� �������� � �����
    cout << "2)Read(i) " << endl; // ������ i ��������
    cout << "3)DeleteBack " << endl;  //�������� ���������� ��-��
    cout << "4)ClearAll " << endl; //�������
    cout << "5)IsEmpty? " << endl; //�������� �� �������
    cout << "6)Size(count of elements)" << endl; //������ �������(���-�� ��-���)
    cout << "7)PrintVector " << endl; //������ �������
    cout << "8)Change " << endl; // ��������� ������������� ��������
    cout << "9)Reserve" << endl; // ��������������
    cout << "10)Iterator check(print vector)" << endl; // �������� ���������
   
    cout << "\n"; //����� ����������
    
    Vector <int> myVector(1); //�������� ������� ������ ������
    myVector.PushBack(99); 
    myVector.PushBack(199);
    myVector.PrintVector();

    /*
    //�������� ������ � �������
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
    //�������� ������������ �����������
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
            cout << "\nEnter element " << endl; // ���������� ��-�� � �����
            cin >> element;
            myVector.PushBack(element);
            break;
        case 2:
            cout << "\nEnter element " << endl; // ������ ��-�� � �����
            cin >> element;
            myVector.GetIndex(element);
            break;
        case 3:
            cout << "DelBack " << endl; //�������
            result = myVector.DelBack(); // �������� ���������� ��-��
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
            result = myVector.Size(); //������ �������(���-�� ��-���)
            cout << "Size: " << result << "\n" << endl;
            break;
        case 7:
            cout << "PrintVector: " << endl; //������ �������
            myVector.PrintVector(); // ����� ������� �� �����
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
            cout << "\nEnter element " << endl; // ���������� ��-�� � �����
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
