#pragma once
enum Types
{
    Static,
    Dynamic
};

template <typename T>
class Stack
{

private:

    T* stackPtr;
    int maxSize;
    int current;
    Types type;

public:

    Stack(const int size, const Types typeP);

    ~Stack();


    void push(const T& value);

    void pop();

    T& top() const;

    bool empty() const;

    bool fill() const;

    int size() const;

    void clear();

    void resize();

};
