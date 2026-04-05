#include <iostream>
#include <string>
using namespace std;

string decodeCiphertext(string encodedText, int rows) {
    if(encodedText.length() == 0)
        return "";
    int cols = encodedText.length() / rows;
    //cout << cols;
    char matrix[rows][cols];
    for(int i =0; i < rows; i++)
        for(int j = 0; j< cols; j++)
        {
            matrix[i][j] = encodedText[j + i * cols];
        }
    for(int i = 0; i<rows;i++)
    {
        for(int j = 0; j< cols; j++)
            cout<< matrix[i][j];
        cout << endl;
    }
    string result ;
    int k = 0;
    for( int i =0; i < cols - rows +2; i++)
        for( int j = 0; j < rows; j++)
        {
            if(j+i >= cols)
                break;
            result += matrix[j][j+i];
            k++;
        }
    cout<< k<<endl;
    k--;
    while(result[k] == ' ')
    {
        result.pop_back();
        k--;
    }
    return result;
}

int main()
{
    string s = "ch   ie   pr";
    int rows = 3;
    cout << decodeCiphertext(s, rows);
}