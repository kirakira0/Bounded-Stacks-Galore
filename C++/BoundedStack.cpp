#include <stdexcept>
#include <memory>
#include <string>
using namespace std;

struct StackFullException : public exception
{
    const char *what() const throw()
    {
        return "Stack is full";
    }
};

struct StackEmptyException : public exception
{
    const char *what() const throw()
    {
        return "Stack is empty";
    }
};

class Stack
{
    int top;
    int capacity;
    unique_ptr<string[]> items;

    void validate_not_full()
    {
        if (top == capacity)
            throw StackFullException();
    }

    void validate_not_empty()
    {
        if (top == 0)
            throw StackEmptyException();
    }

    void validate_item_length(string item)
    {
        if (item.length() <= 0 || item.length() > MAX_ITEM_LENGTH)
        {
            throw invalid_argument("Item length is too small or too large");
        }
    }

public:
    static const int MAX_CAPACITY = 256;
    static const int MAX_ITEM_LENGTH = 128;

    Stack(int capacity) : capacity(capacity), top(0)
    {
        if (capacity <= 0 || capacity > MAX_CAPACITY)
        {
            throw out_of_range("Stack too small or too large");
        }
        this->items = unique_ptr<string[]>(new string[capacity]);
    }

    void push(string item)
    {
        validate_item_length(item);
        validate_not_full();
        items[top++] = item;
    }

    string pop()
    {
        validate_not_empty();
        string valueToReturn = items[--top];
        items[top] = "";
        return valueToReturn;
    }

    int size()
    {
        return top;
    }
};