﻿
namespace std
{
    class nullptr_t
    {
    public:
        template <class T>
        inline operator T *() const
        {
            return 0;
        }

        template <class C, class T>
        inline operator T C::*() const
        {
            return 0;
        }

    private: //or use "= delete"
        void operator&() const;
    };
}

const std::nullptr_t mynullptr = {};
