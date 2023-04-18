#include <iostream>

struct inflatable
{
    std::string name; // 结构可以将 string 类作为结构成员
    // char name[20];
    float volume;
    double price;
};

struct perks
{
    int key_number;
    std::string car;
} mr_smith, ms_jones; // 同时完成定义和创建

int main()
{
    using namespace std;
    inflatable guest = {"Glorious Gloria", 1.88, 29.99};
    inflatable pal = {"Audacious Arthur", 3.12, 32.99};
    // inflatable guy{"Daphne", 0.12, 9.98}; // can omit the = in C++ 11

    cout << "Size of struct inflatable(guest) is " << sizeof(guest) << " Bytes.\n";
    cout << "Size of struct inflatable(pal) is " << sizeof(pal) << " Bytes.\n";

    cout << "Expand your guest list with " << guest.name;
    cout << " and " << pal.name << "!\n";

    cout << "You can have both for $";
    cout << guest.price + pal.price << "!\n";

    // char test[10] = "apple";
    // test = "orange"; // INVALID: incompatible types in assignment of ‘const char [7]’ to ‘char [10]’

    mr_smith.car = "BMW";
    mr_smith.key_number = 1;
    cout << "Mr.smith's key number is " << mr_smith.key_number
         << " and car is " << mr_smith.car << ".\n";

    cout << endl;
    // 结构数组
    perks guys[10]; // array of 10 perks structures
    // guys 本身是一个数组 存储了 10 个 perks 结构体
    guys[0].key_number = 1;
    guys[0].car = "BMW";

    perks tensors[2] = {{1, "BMW"}, {2, "Benz"}};
    cout << "mr." << tensors[0].key_number << "'s car is " << tensors[0].car << ".\n";
    cout << "mr." << tensors[1].key_number << "'s car is " << tensors[1].car << ".\n";

    return 0;
}