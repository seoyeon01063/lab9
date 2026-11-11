#pragma once
#include "book.h"

namespace jangseoyeon2649035
{
    class bookPtr
    {
        book* bPtr;
    public:
        bookPtr(const book& b=book{"bookTitle",1,1000} ):bPtr{new book{b}}
        {
            //std::cout << "constructor\n";
        }
        ~bookPtr()
        {
            //std::cout << "~destructor\n";
            delete bPtr;
        }
        bookPtr(const bookPtr& copy)
        {
            //std::cout << "copy constructor\n";
            bPtr = copy.bPtr ? new book{*copy.bPtr} : nullptr;
        }
        bookPtr(bookPtr&& move) noexcept
        {
            //std::cout << "move constructor\n";
            bPtr=move.bPtr;
            move.bPtr = nullptr;
        }
        bookPtr& operator=(const bookPtr&copy)
        {
            //std::cout << "copy operator=\n";
            if (this !=&copy)
            {
                delete bPtr;
                bPtr = copy.bPtr ? new book{*copy.bPtr} : nullptr;
            }
            return *this;
        }
        bookPtr& operator=(bookPtr&& move) noexcept
        {
            //std::cout << "move operator=\n";
            if (this != &move)
            {
                delete bPtr;
                bPtr= move.bPtr;
                move.bPtr = nullptr;
            }
            return *this;
        }
        void print() const
        {
            if (bPtr)
                std::cout << *bPtr;
            else
                std::cout <<"no data(nullptr)\n";
        }
    };
}