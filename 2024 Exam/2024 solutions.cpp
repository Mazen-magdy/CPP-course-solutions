#include <iostream>
#include <string.h>
using namespace std;
/* Q U E S T I O N  2 */
int a2(int a[], int n);
int b2(int a[], int n, int m);
int c2(int ** a, int n);

/* Q U E S T I O N 3  a*/

int getindex1(char x[], char y[]);

/* Q U E S T I O N 3  b*/

int getindex(char x[],char y[]);
/* Q U E S T I O N  4  a*/
void student3(int a[],int n,int& s1,int& s2,int& s3);
/* Q U E S T I O N  4  b*/
void swap(int& a, int& b);
void sort(int a[], int n);
// 4b didn't solved

int main()
{
    
    //----- T E S T  F O R  Q U E S T I O N  2  a -----//
    //int a[] = {1, 2, 3, 4, 5};
    //cout << a2(a, 5);



    //----- T E S T  F O R  Q U E S T I O N  2  b -----//
    
    
    // int a[] = {6, 2, 3, 4, 5};
    // cout << b2(a, 5, 2);




    //----- T E S T  F O R  Q U E S T I O N  2  c -----//
    // int ** a = new int*[4];
    // for(int i = 0; i < 4; i++)
    //     a[i] = new int[4];

    // a[0][0] = 1; a[0][1] = 1; a[0][2] = 0; a[0][3] = 1;
    // a[1][0] = 1; a[1][1] = 1; a[1][2] = 0; a[1][3] = 1;
    // a[2][0] = 1; a[2][1] = 1; a[2][2] = 0; a[2][3] = 1;
    // a[3][0] = 1; a[3][1] = 1; a[3][2] = 0; a[3][3] = 1;

    // cout << c2(a, 4);

    //----- T E S T  F O R  Q U E S T I O N  3  a -----//
    // cout << getindex1("hello", "lo") << endl;

    //----- T E S T  F O R  Q U E S T I O N  3  b -----//

    // cout << getindex("hello", "lo") << endl;

    //----- T E S T  F O R  Q U E S T I O N  4  a -----//
    // int a[10] = {1,4,25 ,8,13,20,3,6,7,9};
    // int s1 , s2 ,s3 ;
    // student3(a,10,s1,s2,s3);
    // cout << s1 << ' ' << s2 << ' ' << s3 << endl;


    //----- T E S T  F O R  Q U E S T I O N  4  b -----//
    // int a[10] = {1,4,25 ,8,13,20,3,6,7,9};  // 1 3 4 6 7 8 9 13 20 25
    // int b[3];
    // b4(a, 10, b);
    // cout << b[0] << ' ' << b[1] << ' ' << b[2] << endl;
    return 0;

}

/* Q U E S T I O N  2 */

int a2(int a[], int n)
{
    bool swt = false;
    for(int i = 0 ; i < n ; i++)
     {
        swt = false;
        for(int j = i + 1 ; j < n ; j++)
        if(a[i] < a[j])
        {
            swt = true;
            break;
        }
        if(swt)
            continue;
        else
            return a[i];
     }
    return -1;
}
int b2(int a[], int n, int m)
{
    int *c = new int[n];  // an array to get if the number is repeated or not
    for(int i = 0; i < n; i++)     // initialize the array with m - 1 to indicate that the number is not repeated
        c[i] = m - 1;
    for(int i = 0; i < n; i++)
    {
        if(c[a[i] - m] == m - 1) // if the number is not repeated then assign the number to the index of the number - m
            c[a[i] - m] = a[i];
        else return a[i]; // if the number is repeated then return the number
    }
    return -1; // if there is no repeated number
}
int c2(int ** a, int n)
{
    int i, j, k, z; // i for size of the square, j for the column, k for the row, z for the starting row
    int max = 0, counter = 0; // max for the maximum number of 1s, counter for the number of 1s

    for(i = n; i > 0 ; i--) // loop for the size of the square
    {
        for(z = 0 ; z < n - i + 1; z++) // loop for the starting row
        {
            for(j = 0; j < n; j++) // loop for the column
            {
                for(k = z; k < i + z; k++) // loop for the row
                {
                    if(a[k][j] == 0) 
                        break;
                }
                if(k != i + z || k == 1) // if the loop broke before the end of the square or if the square is 1x1
                {
                    if(counter > max ) // if the counter is greater than the max then assign the counter to the max
                    {
                        max = counter;
                    }
                    counter = 0; // reset the counter
                }
                else  // if the loop didn't break before the end of the square
                {
                    counter += k - z;  // add the number of 1s to the counter
                }
            }
            if(counter > max)
            {
                max = counter;
            }
            
                counter = 0;
        }
    }
    return max;
}

/* Q U E S T I O N 3  a*/
int getindex1(char x[], char y[])
{
	int index = -1;
	bool t = false;
	for (int i = 0; i < strlen(x); i++)
	{
		if (x[i]==y[0])
		{
			for (int j = 0; j < strlen(y); j++)
			{
				if (x[i+j] != y[j])
				{break;}
				if (j + 1 == strlen(y))
				{index = i; t = true;}
			}
		}
	}
	if (t)
	{return index;}
	else
	{return -1;}
}

/* Q U E S T I O N 3  b*/

int getindex(char x[],char y[])
{
	int index = -1, counter = 0;
	bool t = false;
	for (int i = 0; i < strlen(x); i++)
	{	counter = 0;
		for (int j = 0; j < strlen(y); j++)
		{
			if (x[i+j]!=y[j]){counter++;}
			if (counter>1){break;}
			if (j+1==strlen(y))
			{t = true;index = i;}
		}
	}
	if (t)
	{return index;}
	else
	{return -1;}	
}

/* Q U E S T I O N  4  a*/
void student3(int a[],int n,int& s1,int& s2,int& s3)
{
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}int min=INT_MAX,index=0;
	for (int i = 0; i < n-2; i++)
	{
		if (a[i+2]-a[i]<min)
		{
			min = a[i + 2] - a[i];
			index = i;
		}
	}
	s1 = a[index]; s2 = a[index + 1]; s3 = a[index + 2];
}
/* Q U E S T I O N  4  b*/
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void sort(int a[], int n)
{
    for(int i = n - 1; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

// 4b didn't solved 
