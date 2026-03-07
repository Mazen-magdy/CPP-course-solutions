
// H-Index definition:
// A researcher has an H-index = h if they have at least h papers
// with at least h citations each.

// Idea of this solution:
// repeats[i] will store how many papers have at least i citations.

// For each paper with citations[i], we increment all repeats[j]
// for j from 0 up to citations[i]. This means that this paper
// contributes to having at least j citations.

// Example:
// citations = [3,0,6,1,5]
// Paper with 3 citations increases repeats[0..3]
// Paper with 6 citations increases repeats[0..6]
// etc.

// After filling repeats[], we check for the largest i
// where repeats[i] >= i. That means we have at least i papers
// with at least i citations, which satisfies the H-index condition.

// maxRepeats keeps the largest valid H-index we found.

#include <iostream>

using namespace std;

int hIndex(vector<int> &citations)
{
    int repeats[1001] = {0};

    for (int i = 0; i < citations.size(); i++)
    {
        for (int j = 0; j <= citations[i]; j++)
        {
            repeats[j]++;
        }
    }

    int maxRepeats = 0;
    for (int i = 1; i < 1001; i++)
    {
        if (repeats[i] >= i)
        {
            maxRepeats = i;
        }
    }
    return maxRepeats;
}

int main()
{

    // vector<int> citations = {0, 0, 2};
    // vector<int> citations = {0, 0, 2};
    vector<int> citations = {3, 0, 6, 1, 5};
    cout << hIndex(citations) << endl;
    cout << endl;
}