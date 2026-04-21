#include <iostream>
using namespace std;

class Stack
{
    private:
        enum {MAX =  10};
        int arr[MAX];
        int top;
    public:
        Stack()
        {
            top = 0;
        }
        void push(int n)
        {
            arr[++top] = n;
        }
        int pop()
        {
            return arr[top--];
        }
        void display()
        {
            for(int i =1; i < top+1; i++)
            {
                cout<<arr[i]<<endl;
            }
            
        }
        void inverse()
        {
            for(int i = 1; i < top/2.0 + top%2;i++)
            {
                int temp = arr[i];
                arr[i] = arr[top+1-i];
                arr[top+1-i] = temp;
            }
        }
        void removeAdj(Stack s);
};

void Stack::removeAdj(Stack s)
{
    while(s.top != 1)
    {
        int prev = s.pop();
        int prev1 = s.pop();
        if(prev != prev1)
            push(prev);
        s.push(prev1);
    }
    push(s.pop());
    inverse();
}


int main()
{
    Stack s;
    s.push(1);
    s.push(1);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    Stack pure;
    pure.removeAdj(s);
    pure.display();
    return 0;
}