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
    T t[SIZE]();

public:
    TempArray() {}
    operator T *()
    {
        return t;
    }
};

//  usage: if a function needs a pointer to output but useless

void func1(int *pi);
void func2(int *pia); // int array

int wmain()
{
    func1(Temp<int>());
    func2(TempArray<int, 3>()); // length: 3
    return 0;
}