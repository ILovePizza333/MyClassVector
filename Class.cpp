#include "Class.h"

// конструктор
template <typename T>
Vector<T>::Vector(int s)
{
    pArray = new T[s];
    nIndex = 0;
    nSize = s;
}

// конструктор copy
template <typename T>
Vector<T>::Vector( Vector& obj)
{
    nSize = obj.nSize;
    nIndex = obj.nIndex;
    pArray = new T[nSize];
    for (int i = 0; i < nSize; i++) {
        pArray[i] = obj.pArray[i];
    }
}

//переопределение оператор присваивания
template <typename T>
Vector<T>& Vector<T>::operator=(Vector& v)
{
    delete pArray;
    nSize = v.nSize;
    nIndex = v.nIndex;
    pArray = new T[nSize];
    memcpy(pArray, v.pArray, sizeof(T) * (nIndex + 1));
}

// деструктор
template <typename T>
Vector<T>::~Vector()
{
    if (nSize != 0) {
    delete[] pArray; // удаляем вектор
    }
    nIndex = 0;
    nSize = 0;
}

// вывод вектора на экран
template <typename T>
void Vector<T>::PrintVector()
{
    //реализация без итератора
    for (int ix = 0; ix <= nSize - 1; ix++)
    {
        cout << "|" << pArray[ix] << endl;
    }
}

// вставка в конец
template <typename T>
void Vector<T>::PushBack(const T &iobj)
{
    //cout << "pushback" << endl;
    if (nSize == nIndex) {
        T* temp = new T[nSize + 1];
        memcpy(temp, pArray, sizeof(T) * nSize);
        nSize += 1;
        delete pArray;
        pArray = temp;

    }
    pArray[nIndex] = iobj;
    nIndex++;
}

// Возврат размера
template <typename T>
int Vector<T>::Size()
{
    return nSize;
}

// Проверка на пустоту
template <typename T>
bool Vector<T>::IsEmpty()
{
    if (nSize == 0) { 
        return 1;
    }
    else {
        return 0;
    }
}

// удаление конца
template <typename T>
bool Vector<T>::DelBack()
{ 
    int Size_old = nSize;
    if (nSize != 0) {
        T* temp = new T[nSize - 1];
        for (int i = 0; i < nSize - 1; i++) {
            temp[i] = pArray[i];

        }
        // memcpy(temp, pArray, sizeof(T) * nSize-1);
        nSize -= 1;
        delete pArray;
        pArray = temp;
        cout << "nSize" << nSize << endl;
        for (int ix = nSize - 1; ix >= 0; ix--)
        {
            cout << "|" << pArray[ix] << endl;
        }
        nIndex--;

    }
    if (Size_old-nSize==1 ||Size_old==0) {
        return 1;
    }
    else {
        return 0;
    }
}


// удаление всего
template <typename T>
bool Vector<T>::DelAll()
{
    if (nSize != 0) {
        T* temp = new T[0];
        nSize = 0;
        delete pArray;
        pArray = temp;
        nIndex=0;
    }
    return 1;
}



// получение элемента по индексу
template <typename T>
void Vector<T>::GetIndex(int index)
{
    if (index >= 0 && index <= nSize-1) {
        cout << pArray[index] << endl;
    }
}

// изменение существующего элемента
template <typename T>
void Vector<T>::Change(int index, const T& iobj)
{
    if (index >= 0 && index <= nSize - 1) {
        pArray[index] = iobj;
    }
}

// резервирование
template <typename T>
void Vector<T>::Reserve(int count)
{
    T* temp = new T[nSize + count];
    memcpy(temp, pArray, sizeof(T) * nSize);
    nSize += count;
    delete pArray;
    pArray = temp;
}