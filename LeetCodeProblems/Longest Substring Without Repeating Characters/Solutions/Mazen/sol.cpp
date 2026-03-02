/* THIS SOLUTION FAILS AT TEST 610 
    Input "bbbbb"
    Output 2
    Expected 1
*/

int lengthOfLongestSubstring(string s) {
    string buffer =  "";
    string biggest = "";
    for(int i= 0;i<s.length()+1;i++){
        char ch = s[i];
        int initial = i;
        for(int j=0;j<buffer.length();j++)
            if(buffer[j] == ch)
            {
                //problem
                // if(buffer.length()> biggest.length())
                //     biggest = buffer;
                i =i - buffer.length()+1;
                buffer = "";
                break;

            }
        if (initial == i)
            buffer += ch;
        if(buffer.length()> biggest.length())
                    biggest = buffer;
    }
    return biggest.length();
}