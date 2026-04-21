#include <iostream>

using namespace std;

struct Link
{
    int data;
    Link* next;
};
class LinkedStack
{
    private:
        int top;
        Link* first;
    public:
        LinkedStack(): top(1), first(NULL)
        { }
        void push(int n);
        int pop();
        bool operator==(LinkedStack);
        void display()
        {
            Link* iter = first;
            while(iter != NULL)
            {
                cout<< iter->data<< ' ';
                iter = iter->next;
            }
            cout << endl;
        }
};
void LinkedStack:: push(int n)
{
    Link*l = new Link;
    l -> data = n;
    l-> next = first;
    first = l;
    top++;
}

int LinkedStack::pop()
{
    int result = first ->data;
    first = first->next;
    top--;
    return result;
}

bool LinkedStack::operator==(LinkedStack s)
{
    if(top != s.top)
        return 0;
    Link* iter = first;
    while(iter != NULL)
    {
        if(iter->data != s.first->data)
            return 0;
        iter = iter-> next;
        s.first = s.first->next;
    }
    return 1;
}

int main()
{
    LinkedStack s,s1;
    s1.push(1); s.push(1);
    s1.push(2); s.push(2);
    s1.push(3); s.push(3);
    s1.push(4); s.push(4);
    s1.push(5); s.push(5);
    // s.display();
    cout << (s == s1) << endl;
    // s.display();
    return 0;
}