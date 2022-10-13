#pragma once
#include <iostream>
using namespace std;


template <typename T>
class Vector
{
private:
    T* pArray; // указатель на вектор
    int nSize, nIndex; // размер стека

public:
	T& at(int i)
	{
		if (i < 0 || i >= nIndex || nIndex == 0)
			throw(1205);
		return pArray[i];
	}
	T& operator[](int i)
	{
		if (i < 0 || i >= nIndex || nIndex == 0)
			throw(1205);
		return pArray[i];
	}
    Vector(int = 1);// по умолчанию размер вектора равен 1 элементу
    Vector& operator = (Vector& v); // оператор присваивания
    Vector( Vector &obj); //конструктор копирования
    ~Vector(); // деструктор
    int Size();
    void PushBack(const T& iobj);
    bool DelBack();
	bool DelAll();
    void PrintVector();
    bool IsEmpty();
    void GetIndex(int index);
	void Change(int index, const T& iobj);
	void Reserve(int count);
	class Iterator
	{
		friend class Vector;
	private:
		T* m_pArray;
		int m_nInd;
	public:
		//переопределение оператор разименования
		T& operator * ()
		{
			return m_pArray[m_nInd];
		}
		//переопределение оператор ++
		Iterator operator ++ (int)
		{
			Iterator it;
			it = *this;
			m_nInd++;
			return it;
		}
		//Iterator() {}
		//переопределение оператор !=
		bool operator != (Iterator& it)
		{
			if (m_nInd != it.m_nInd)
				return true;
			else
				return false;
		}
	};

	//итератор на начало
	Iterator begin() {
		Iterator ittemp;
		ittemp.m_pArray = pArray;
		ittemp.m_nInd = 0;
		return ittemp;
	}

	//итератор на конец
	Iterator end() {
		Iterator it;
		it.m_pArray = pArray;
		it.m_nInd = nIndex;
		return it;
	}
};