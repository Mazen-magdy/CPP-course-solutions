#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T content;
    Node* next;
};
template <typename T>
class Set
{
    private:
        Node<T>* first;
        T freqArr[256] = {0};
    public:
        Set() : first(NULL){}
        void put(T c)
        {
            if(first == NULL)
            {
                Node<T>* newNode = new Node<T>;
                newNode->content = c;
                newNode->next = NULL;
                first = newNode;
            }
            else
            {
                Node<T>* iter = first;
                while(iter->next != NULL)
                {
                    iter = iter->next;
                }
                Node<T>* newNode = new Node<T>;
                newNode->content = c;
                newNode->next = NULL;
                iter->next = newNode;
            }
            freqArr[c]++;
            return;
        }
        T get()
        {
            int reps = 0; 
            T ele = 0;
            for(int i = 0; i < 256; i++)
            {
                if(freqArr[i] >reps)
                {
                    reps = freqArr[i];
                    ele = i;
                }
            }
            return ele;
        }

};


int main()
{
    Set<unsigned char> s;
    s.put('A');
    s.put('A');
    s.put('z');
    s.put('y');
    cout << "started\n";
    cout << s.get();
    return 0;
}