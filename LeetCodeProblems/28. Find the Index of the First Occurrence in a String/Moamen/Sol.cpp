// This function searches for the first occurrence of "needle"
// inside "haystack" and returns its starting index.
// If the substring is not found, it returns -1.

// Step 1:
// Store all positions in "haystack" where the first character
// of "needle" appears. These are the only possible starting points
// for a valid match.

// Step 2:
// For each possible starting position, compare characters
// one by one with the characters of "needle".

// Step 3:
// If characters keep matching, increase the tracker.
// If a mismatch happens, reset the tracker and move
// to the next possible starting index.

// Step 4:
// If tracker reaches needle.size(), it means the full
// substring was matched, so return the starting index.

// The check (haystack.size() - i < needle.size())
// stops the search early if there are not enough
// characters left to match the needle.

#include <iostream>

using namespace std;

int strStr(string haystack, string needle)
{

    if (haystack.size() < needle.size())
    {
        return -1;
    }

    int *firstIndexes = new int[haystack.size()];
    int count = 0;
    for (int i = 0; i < haystack.size(); i++)
    {
        if (haystack[i] == needle[0])
        {
            firstIndexes[count] = i;
            count++;
        }
    }

    if (count == 0)
    {
        return -1;
    }

    int start = 1;
    int index = -1;
    int tracker = 0;
    for (int i = firstIndexes[0]; i < haystack.size(); i++)
    {
        if (haystack.size() - i < needle.size() && tracker == 0)
        {
            index = -1;
            break;
        }
        if (haystack[i] == needle[tracker])
        {
            if (tracker == 0)
            {
                index = i;
            }
            tracker++;
        }
        else
        {
            tracker = 0;
            index = -1;
            if (start < count)
            {
                i = firstIndexes[start] - 1;
                start++;
            }
        }

        if (tracker == needle.size())
        {
            break;
        }
    }
    return index;
}

int main()
{
    string haystack = "aaa";
    string needle = "aaa";
    cout << strStr(haystack, needle) << endl;
    return 0;
}