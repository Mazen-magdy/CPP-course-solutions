#include <iostream>

using namespace std;

class Mystack
{
    private:
    int* arr;
    int top, max, max3;
    public:
    Mystack() : arr(NULL), top(0), max(0), max3(0) {}
    void add(bool signal)
    {
        if(!signal)
        {
            if(arr == NULL)
            {
                arr = new int[1];
                *arr = 1;
                top = 1;
                max = 1;
            }
            else
            {
                arr[top-1]++;
                if(arr[top-1] > max)
                    max = arr[top -1 ];
                if(top > 2)
                {
                    int sum = arr[top - 1] + arr[top - 2] + arr[top - 3];
                    if(sum > max3) max3 = sum;
                }
            }
        }
        else
        {
            int * newarr = new int[top+1];
            for(int i = 0; i < top;i++)
            {
                newarr[i] = arr[i];
            }
            newarr[top++] = 0;
            delete [] arr;
            arr = newarr;

        }
    }
    int fmax()
    {
        return max;
    }
    int fmax3()
    {
        return max3;
    }
};


int main()
{
    Mystack s;
    s.add(0);   s.add(0);
    s.add(0);   s.add(0);
    s.add(0);   s.add(0);
    s.add(1);
    s.add(0);   s.add(0);
    s.add(0);   s.add(0);
    s.add(1);
    s.add(0);   s.add(0);
    s.add(0);   s.add(0);
    s.add(0);   s.add(0);
    s.add(1);
    s.add(0);   s.add(0);
    s.add(0);   s.add(0);
    s.add(1);
    cout << "max is: "<< s.fmax()<< endl;
    cout << "max 3 is: "<< s.fmax3() << endl;
    return 0;
}