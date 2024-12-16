#include <iostream>
using namespace std;

template <typename T>
class MyData
{
private:
    T value;
public:
    MyData(T value) : value(value) {}
    void SetData(T value)
    {
        this->value = value;
    }
    T GetData() const
    {
        return value;
    }
};

template <typename T>
class Node
{
private:
    MyData<T> myData;
    Node* next;
    Node* prev;
public:
    Node(MyData<T> myData) : myData(myData), next(nullptr), prev(nullptr) {}
    MyData<T> GetMyData() const
    {
        return myData;
    }
    void SetMyData(MyData<T> myData)
    {
        this->myData = myData;
    }
    Node* GetNext() const
    {
        return next;
    }
    void SetNext(Node* next)
    {
        this->next = next;
    }
    Node* GetPrev() const
    {
        return prev;
    }
    void SetPrev(Node* prev)
    {
        this->prev = prev;
    }
};

template <typename T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;
public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    size_t GetSize() const
    {
        return size;
    }
    void InsertAtEnd(MyData<T> value)
    {
        Node<T>* newNode = new Node<T>(value);
        if (tail == nullptr)
        {
            tail = newNode;
            head = newNode;
        }
        else
        {
            newNode->SetPrev(tail);
            tail->SetNext(newNode);
            tail = newNode;
        }
        size++;
    }
    void InsertAtBeginning(MyData<T> value)
    {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->SetNext(head);
            head->SetPrev(newNode);
            head = newNode;
        }
        size++;
    }
    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node<T>* temp = head;
            head = head->GetNext();
            delete temp;
        }
    }
};

int main()
{
    LinkedList<int> list;
    list.InsertAtEnd(MyData<int>(10));
    list.InsertAtBeginning(MyData<int>(5));

    cout << "List size: " << list.GetSize() << endl;
}
