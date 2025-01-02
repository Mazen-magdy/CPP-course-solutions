#include <iostream>
using namespace std;

/* Q u e s t i o n  1  */
int a1( int a[][20]);

int b1(int a[][20]);

int* c1( int a[][20]);

// letter d can't solve it because it's not clear what the question is asking for

int e1(int a[][20]);

int f1(int a[][20]);

int* g1(int a[][20]);

/* Q u e s t i o n  2  */

int a2( char str[]);

int b2();

void c2(char str[]);

char** d2(char str[]); // needs testing

/* Q u e s t i o n  3  */

    // question 3 is not solved

/* Q u e s t i o n  4  */
double Bisection(double a , double b);

int main()
{
    return 0;
}

int a1( int a[][20])
{
    int sum = 0;
    for(int i = 0; i <20; i++ )
        for(int j = 0; j <20; j++ )
        {
            if(a[i][j] >= 0)
                sum++;
        }
    return sum;
}
int b1(int a[][20])
{
    int sume = 0;
    int sumi = 0;
    for(int i = 0; i <20; i++ )
        for(int j = 0; j <20; j++ )
        {
            if(a[i][j] % 7 == 0)
                {
                    sumi++;
                    sume += a[i][j];
                }
        }

    return sume / sumi;
}
int* c1( int a[][20])
{
    int * m = &a[0][0]; // m is the maximum value
    for(int i = 0; i <20; i++ )
        for(int j = 0; j <20; j++ )
            if(a[i][j] > *m)
                m = &a[i][j];
    return m;
}
int e1(int a[][20])
{
    int sum = 0;
    for(int i = 0; i <20; i++ )
            sum += a[i][i];
    return sum;
}
int f1(int a[][20])
{
    int sum = 0;
    int msumi; // stand for maximum sum index
    for(int j = 0; j <20; j++ )
        {
            for(int i = 0; i <20; i++ )
                sum += a[i][j];
            if(sum > msumi)
                msumi = j;
        }
    return msumi;
}
int* g1(int a[][20])
{
    int sum = 0;
    int msumi;
    int msum = 0; // stand for maximum sum
    for(int j = 0; j <20; j++ )
    {
        for(int i = 0; i <20; i++ )
            {
                sum += a[i][j];   
            }
        if(sum > msum)
            {
                msumi = j;
                msum = sum;
            }
    }
    int *A = new int[20];
    for(int j = 0; j <20; j++ )
        A[j] = a[msumi][j];
    return A;
}
/* Q u e s t i o n  2  */

int a2( char str[])
{
    int count = 0;
    for(int i = 0; i > -1; i++)
    {
        if(str[i] == '\0' )
        {
            if(str[i-1] == 'x')
                count++;
            break;
        }
        if(str[i] == ' ' && str[i-1] == 'x')
            count++;
    }
    return count;
}
int b2()
{
    char current, previous;
    int count = 0;
    cin.get(current);
    while(current != '\n')
    {

        if(current == ' ' && previous != ' ')
            count++;
        previous = current;
        cin.get(current);
    }
    cout << count;
}
void c2(char str[])
{
    char str2[100];
    char current;
    int i = 0; 
    int len = 0;    // length of the input  string
    while(true)         // gets the length of the string
    {
        if(str[len] == '\0')
            break;
        len++;
    }
    cin.get(current);
    while(true)
    {
        str2[i] = current;
        if(current != str[i])
            i = 0;
        if( i == len) break;
        else i++;
        cin.get(current);
    }
    return;
}
char** d2(char str[]) // needs testing
{
    int nword = 0;
    int backwall = 0;
    char ** words = new char*[20];
    for(int i = 0; i > -1; i++)
    {
        if(str[i] == '\0' )
        {
            if(str[i-1] != ' ')
                {
                    words[nword] = new char[i-backwall];
                    for(int j = backwall; j < i; j++)
                        words[nword][j] = str[j];
                    nword++;
                    for(int j = 0; j > -1; j++)
                        if(str[j] >= 'a' && str[j] <= 'z' || str[j] >= 'A' && str[j] <= 'Z')
                        {
                            backwall = j;
                            break;
                        }
                }
            break;
        }
        if(str[i] == ' ' && str[i-1] == ' ')
            {
                    words[nword] = new char[i-backwall];
                    for(int j = backwall; j < i; j++)
                        words[nword][j] = str[j];
                    nword++;
                    for(int j = 0; j > -1; j++)
                        if(str[j] >= 'a' && str[j] <= 'z' || str[j] >= 'A' && str[j] <= 'Z')
                        {
                            backwall = j;
                            break;
                        }
                }
    }

    return words;
}
/* Q u e s t i o n  4  */

double Bisection(double a , double b)
{
    double c = a+b / 2;
    while( a - b < 0.001 && a - b > -0.001)
    {
        if(f(c) > 0)
        {
            b = c;
            
        }
        else
        {
            a = c;
        }
        c = a+b / 2;
    }
    return c;
}