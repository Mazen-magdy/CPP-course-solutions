#include <iostream>
using namespace std;

class MAT
{
    private:
    int a[1000];
    public:
    MAT(int arr[1000])
    {
        for(int i = 0; i<1000;i++)
            a[i] = arr[i];
    }
    int getMax()
    {
        int max = a[0];
        for(int i = 0; i < 1000; i++)
        {
            if(a[i] > max)
                max = a[i];
        }
        return max;
    }
    void shift(int n, int A, int B)
    {
        if(n+A >= 1000 || n+B >= 1000)
        {
            cout<<"error index out of Bound"<<endl;
            return;
        }
        for(int i =0; i <n;i++)
        {
            int temp = a[A+i];
            a[A+i] = a[B+i+1];
            a[B+i+1] = temp;
        }
    }
    void printLast10() // additional not required in the question
    {
        for(int i = 990; i < 1000; i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
};


int main()
{
    int arr[1000];
    for(int i = 0; i < 1000; i++)
        arr[i] = i;
    MAT m(arr);
    cout<<m.getMax()<<endl;
    m.printLast10();
    m.shift(9, 0, 990);
    m.printLast10();
}