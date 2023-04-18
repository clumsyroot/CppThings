// stock.cpp -- implement the Stock class
#include "stock.h"
#include <iostream>

// 构造函数
Stock::Stock()
{
    // std::cout << "Default constructor called\n";
    // company = "no name";
    // shares = 0;
    // share_val = 0.0;
    // total_val = 0.0;
}
Stock::Stock(const std::string &co, long n, double pr)
{
    std::cout << "Constructor using " << co << "called\n";
    company = co;
    if (n < 0)
    {
        std::cerr << "Number of shares can't be nagative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    }
    else
    {
        shares = n;
    }
    share_val = pr;
    set_tot();
}
// 析构函数
Stock::~Stock()
{
    std::cout << "Bye, " << company << "!\n";
}

// void Stock::acquire(const std::string &co, long n, double pr)
// {
//     company = co;
//     if (n < 0)
//     {
//         std::cout << "Number of shares can't be negative; "
//                   << company << " shares set to 0.\n";
//         shares = 0;
//     }
//     else
//     {
//         shares = n;
//     }

//     share_val = pr;
//     set_tot();
// }

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares solf can't be nagative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted. \n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    std::cout << "Company: " << company
              << " Shares: " << shares << "\n"
              << " Share Price: $" << share_val
              << " Total Worth: $" << total_val << "\n";
}