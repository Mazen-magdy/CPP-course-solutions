/**   Burglar and Matches
*    @brief Stores containers in descending order of matches per box, then collects as many boxes as possible.
*
*
*
* */

#include <iostream>

using namespace std;

struct container{
    int boxes;
    int matches;
};

struct Node
{
    container content;
    Node* next;
};

class LinkedContainer{
    private:
        Node* first;
    public:
    LinkedContainer() : first(NULL) {}
    void add(container x){
        int box = x.boxes;
        int match = x.matches;
        if(first == NULL)
        {
            Node* n = new Node;
            n->content.boxes = box;
            n->content.matches = match;
            n->next = NULL; 
            first = n;
        }
        else{
            Node* iter = first;
            Node* prev = NULL;
            while(iter != NULL)
            {

                if(match > iter->content.matches)
                {
                    Node* n = new Node;
                    n->content.boxes = box;
                    n->content.matches = match; 
                    n->next = iter;
                    if(prev == NULL){
                        first = n;   
                    }
                    else{
                        prev->next = n;
                    }
                    return;
                }
                prev = iter;
                iter = iter->next;
            }
            Node* n = new Node;
            n->content.boxes = box;
            n->content.matches = match;
            n->next = NULL; 
            prev->next = n;
        }
    }
    container operator[] (int i){
        if(i == 0)
            return first->content;
        else{
            Node* iter = first;
            while(i != 0)
            {
                iter = iter->next;
                i--;
            }
            return iter->content;
        }
    }
};


int main()
{
    int n,m;
    cin >>n >>m;
    LinkedContainer containers;
    for(int i =0;i<m;i++)
    {
        container c;
        cin >> c.boxes;
        cin >> c.matches;
        containers.add(c);
    }
    // cout << "debug\n";
    // for(int i = 0; i < m;i++)
    // {
    //     cout <<i << ' '<< containers[i].boxes << ' ' << containers[i].matches<<endl;
    // }
    // cout << "End of debug\n";

    int i = 0, match = 0;
    while(n != 0 && i < m)
    {
        int boxes = containers[i].boxes;
        int matches = containers[i].matches;
        if(n > boxes)
        {
            match += boxes * matches;
            n -= boxes;
        }
        else{
            match += n * matches;
            n = 0;
        }
        i++;
    }
    cout <<match<<endl;
    return 0;
}