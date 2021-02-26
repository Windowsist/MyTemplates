//#include <crtdefs.h>
typedef unsigned long long size_t;

//#include <stdarg.h>
typedef char *va_list;
extern "C" extern void __cdecl __va_start(va_list *, ...);

template <typename T>
class Temp
{
private:
    T t;

public:
    Temp() {}
    Temp(T t) : t(t) {}
    operator T *()
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
    TempArray(T...)
    {
        va_list valist;
        __va_start(&valist, SIZE); // va_start(valist, SIZE);
        for (size_t i = 0; i < SIZE; i++)
        {
            t[i] = ((sizeof(T) > sizeof(__int64) || (sizeof(T) & (sizeof(T) - 1)) != 0) ? **(T **)((valist += sizeof(__int64)) - sizeof(__int64)) : *(T *)((valist += sizeof(__int64)) - sizeof(__int64))); //va_arg(valist, T);
        }
        valist = ((va_list)0); //va_end(valist);
    }
    operator T *()
    {
        return t;
    }
};

//  usage: if a function needs a pointer to output but useless
//  the objects of this class will be instantly deconstructed when the function return

void func1(int *lpint);     // output int but useless
void func2(wchar_t *lpstr); // output wchar_t array but useless

int wmain(int argc, wchar_t **argv, wchar_t **envp)
{
    func1(Temp<int>(3));                   // value is 3
    func2(TempArray<wchar_t, 5>(L"ASDF")); // length: 5 , vlaue is {L'A', L'S', L'D' ,L'F'}
    return 0;
}