#include "Stack.h"
#include <iostream>
#include <assert.h>
using namespace std;

template class Stack<char>;//Мега костыль)

template <typename T>
Stack<T>::Stack(const int size, const Types typeP)
    : maxSize{ size }, type{ typeP }
{
    stackPtr = new T[maxSize];
    current = -1;
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] stackPtr;
}

template <typename T>
void Stack<T>::resize()
{

    T* tempPtr = new T[maxSize];
    for(size_t i{0};i < maxSize;i++) tempPtr[i] = stackPtr[i];
    delete[] stackPtr;

    stackPtr = new T[maxSize * 1.5 + 1];
    for (size_t i{ 0 }; i < maxSize; i++) stackPtr[i] = tempPtr[i];
    delete[] tempPtr;

    maxSize = maxSize * 1.5 + 1;
    cout << maxSize << endl;

}

template <typename T>
void Stack<T>::push(const T& value)
{
    if(type == Static) assert( current < maxSize - 1 and "Stack is full");
    else if (type == Dynamic && current == maxSize - 1) resize();

    stackPtr[++current] = value;
}
template <typename T>
void Stack<T>::pop()
{
    assert(current > -1 and "Stack is empty");
    current--;
}

template <typename T>
T& Stack<T>::top() const
{
    assert(current > -1 and "Stack is empty");
    return stackPtr[current];
}

template <typename T>
bool Stack<T>::empty() const
{
    return current < 0;
}

template <typename T>

bool Stack<T>::fill() const
{
    return current != -1 && current == maxSize - 1;
}

template <typename T>
int Stack<T>::size() const
{
    return current + 1;
}

template <typename T>
void Stack<T>::clear()
{
    while(current >= 0)
    {
       pop();
    }
}
