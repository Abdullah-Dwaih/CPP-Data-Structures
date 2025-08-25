#include <iostream>
#include "clsMyQueue.h"

using namespace std;




int main()
{
    clsMyQueue <int> MyQueue;

    MyQueue.push(1);
    MyQueue.push(2);
    MyQueue.push(3);
    MyQueue.push(4);
    MyQueue.Print();

    cout << MyQueue.front()<<endl;
   cout <<  MyQueue.back()<<endl;
   cout <<  MyQueue.size()<<endl;
    return 0;
}