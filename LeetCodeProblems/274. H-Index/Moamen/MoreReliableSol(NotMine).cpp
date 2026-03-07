// Let’s take a small example:

// citations = [3, 0, 6, 1, 5]
// If we sort it, we get:

// sorted_array = [0, 1, 3, 5, 6]
// Now, start checking from the right (highest citations):

// 6 → yes (that’s 1 paper with ≥1 citation) → h = 1

// 5 → yes (2 papers with ≥2) → h = 2

// 3 → yes (3 papers with ≥3) → h = 3

// 1 → no (only 3 papers with ≥4)

// So the answer is 3, because we have 3 papers with at least 3 citations each.


#include <iostream>

using namespace std;


int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h_index = 0;
        for (int i = citations.size() - 1; i >= 0; i--) {
            if (citations[i] > h_index)
                h_index++;
            else
                break;
        }
        return h_index;
    }