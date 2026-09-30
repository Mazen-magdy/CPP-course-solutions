#include<iostream>
using namespace std ;
struct node 
{   unsigned char digit ;
    node *next;
    node(){next=nullptr;}
};
class num 
{
     private:
     unsigned char max;
     node* first;
     int freq[256];
     public:
     num()
     {     
          max=0;
        first=nullptr;
        for(int i=0;i<256;i++)
        freq[i]=0;

     }
     void add(unsigned char c  )
     {   
           node* link=new node();
               link->digit=c;
               link->next=first;
               first=link;

                freq[c]++;

              if(freq[c]>freq[max])
              max=c;
     }
      unsigned char getMAx()
      {    
        return max;
      }
      node* getFirst()
      {
        return first;
      }
      void print(node* ptr)
      {
            if(ptr==nullptr)
            return ;
            print(ptr->next);
            cout<<ptr->digit;


      } 


};

int main()
{   
        num n;
        int i=0 ;
        n.add('T');
        n.add('a');
        n.add('r');
        n.add('e');
        n.add('k');
        n.add('k');
        //___________________________
    
    n.print(n.getFirst());
    cout<<"\n";
    cout<<n.getMAx();
    

 
return 0 ;
}
