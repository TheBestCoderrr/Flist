#include <iostream>
#include "Flist.h"
using namespace std;

int main()
{
    FList<int> list;
    for (int i = 0; i < 5; i++)
        list.push_back(10 * i);
    list.print();
    list.push_front(44);
    list.print();
    list.insert(1, 99);
    list.print();
    list.pop_position(5);
    list.print();
    list.DeleteAll();
    
    cout << endl;
    FList<float> list2;
    list2.push_back(10.5);
    list2.push_back(20);
    list2.push_back(20);
    list2.push_back(33.789);
    list2.push_back(41.134);
    list2.push_back(20);
    list2.push_back(10.6);
    list2.print();
    list2.Replace(20, 11.11);
    list2.print();
    list2.Reverse();
    list2.print();
}