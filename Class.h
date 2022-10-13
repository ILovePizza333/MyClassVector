#pragma once
#include <iostream>
using namespace std;


template <typename T>
class Vector
{
private:
    T* pArray; // ��������� �� ������
    int nSize, nIndex; // ������ �����

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
    Vector(int = 1);// �� ��������� ������ ������� ����� 1 ��������
    Vector& operator = (Vector& v); // �������� ������������
    Vector( Vector &obj); //����������� �����������
    ~Vector(); // ����������
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
		//��������������� �������� �������������
		T& operator * ()
		{
			return m_pArray[m_nInd];
		}
		//��������������� �������� ++
		Iterator operator ++ (int)
		{
			Iterator it;
			it = *this;
			m_nInd++;
			return it;
		}
		//Iterator() {}
		//��������������� �������� !=
		bool operator != (Iterator& it)
		{
			if (m_nInd != it.m_nInd)
				return true;
			else
				return false;
		}
	};

	//�������� �� ������
	Iterator begin() {
		Iterator ittemp;
		ittemp.m_pArray = pArray;
		ittemp.m_nInd = 0;
		return ittemp;
	}

	//�������� �� �����
	Iterator end() {
		Iterator it;
		it.m_pArray = pArray;
		it.m_nInd = nIndex;
		return it;
	}
};