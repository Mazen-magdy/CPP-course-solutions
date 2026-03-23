/** ACCEPTED
 *  Run Time : 3 ms
 *  Memory : 10.88MB 
 * 
 * 
 */
#include <iostream>
#include <string>
#include <cassert>
using namespace std;


string convert(string s, int numRows) {
    string buffer;
    if(numRows == 1){
        buffer = s;
        return buffer;
    }
    for(int i = 0; i< numRows;i++)
    {
        int next = i;
        int middle = 0;
        while(next < s.length())
        {
            buffer += s[next];
            if(middle)
            {
                next += 2*i;
                middle = 0;
            }
            else
            {
                next += 2*numRows - 2 - 2 * i; // starts with zero and increases with each row
                middle = i* (numRows-1-i); // excludes the first and last row
            }
            if(i == (numRows-1))
                next += 2*numRows - 2; // excluding the increment with the last row
        }
    }
    return buffer;
}


void test_convert() {
    // Test case 1: Single row
    assert(convert("PAYPALISHIRING", 1) == "PAYPALISHIRING");
    
    // Test case 2: Two rows
    assert(convert("PAYPALISHIRING", 2) == "PYAIHRNAPLSIIG");
    
    // Test case 3: Three rows
    assert(convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    
    // Test case 4: Four rows
    assert(convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    
    // Test case 5: numRows equals string length
    assert(convert("ABCD", 4) == "ABCD");
    
    // Test case 6: numRows greater than string length
    assert(convert("AB", 5) == "AB");
    
    // Test case 7: Single character
    assert(convert("A", 1) == "A");
    
    // Test case 8: Empty string
    assert(convert("", 1) == "");
    
    cout << "All tests passed!" << endl;
}

int main(){
    test_convert();
    return 0;
}

