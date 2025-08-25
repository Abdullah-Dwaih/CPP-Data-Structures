# C++ Data Structures - Doubly Linked List & Queue

This project is a practical implementation of a **Doubly Linked List** in C++,  
and a **Queue (FIFO)** built on top of it using **Composition**.

---

## 📌 Contents
- `clsDblLinkedList.h` : Template class implementing a Doubly Linked List.
- `clsMyQueue.h` : Queue class implemented using `clsDblLinkedList<T>`.
- `main.cpp` : Example usage.

---

## ⚡ Features
### 🔹 Doubly Linked List
- Insert at the beginning, end, or after a specific node.
- Delete the first or last node.
- Find a node by value or access an item by index.
- Reverse the list.
- Get the size of the list and check if it's empty.
- Clear the entire list.

### 🔹 MyQueue
- `push(value)` : Insert an element at the end of the queue.
- `pop()` : Remove the first element (FIFO).
- `front()` : Access the first element.
- `back()` : Access the last element.
- `size()` : Get the number of elements.
- `isEmpty()` : Check if the queue is empty.
- `Print()` : Print all elements in the queue.

---

## 🚀 Example Usage
```cpp
#include <iostream>
#include "clsMyQueue.h"

int main() {
    clsMyQueue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    q.Print();   // 10 20 30

    std::cout << "Front: " << q.front() << std::endl; // 10
    std::cout << "Back: " << q.back() << std::endl;   // 30

    q.pop();
    q.Print();   // 20 30

    return 0;
}
