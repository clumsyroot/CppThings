#include <iostream>

int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    // cin >> name; // cin 仅读取一个单词, 读到空白符为止
    // cin.get(name, ArSize).get(); // get() 不会读取换行符 即读取到换行符就停止
    cin.getline(name, 20); // 会读取并舍弃换行符
    cout << "Enter your favorite dessert:\n";
    // cin >> dessert;
    cin.getline(dessert, 20);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    return 0;
}