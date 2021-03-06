﻿#include <crtdefs.h>

#include <stdarg.h>

template <typename T>
class Temp
{
private:
    T t;

public:
    Temp() {}
    Temp(const T t) : t(t) {}
    inline operator T *()
    {
        return &t;
    }
};

template <typename T, size_t SIZE>
class TempArray
{
private:
    T t[SIZE];

public:
    TempArray() {}
    TempArray(const T *ts)
    {
        for (size_t i = 0; i < SIZE; i++)
        {
            t[i] = ts[i];
        }
    }
    TempArray(const T...)
    {
        va_list valist;
        va_start(valist, SIZE);
        for (size_t i = 0; i < SIZE; i++)
        {
            t[i] = va_arg(valist, T);
        }
        va_end(valist);
    }
    inline operator T *()
    {
        return t;
    }
};

//  usage: if a function needs a pointer to output but useless
//  the objects of this class will be instantly deconstructed when the function return

void func1(int *lpint);     // output int but useless
void func2(wchar_t *lpstr); // output wchar_t array but useless
void func3(bool *lpbool);   // output bool array but useless

int wmain(int argc, wchar_t **argv, wchar_t **envp)
{
    func1(Temp<int>(3));                                // type is int, value is 3
    func2(TempArray<wchar_t, 5>(L"ASDF"));         // length: 5 , vlaue is {L'A', L'S', L'D' ,L'F'}
    func3(TempArray<bool, 3>(true, false, false)); // length: 3 , vlaue is {true, false, false}
    return 0;
}