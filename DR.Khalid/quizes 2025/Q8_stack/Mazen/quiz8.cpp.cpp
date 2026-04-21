#include <iostream>

using namespace std;


class Stack
{
	enum {MAX = 10};
	int st[MAX];
	int top;
	public:
	Stack() {top = 0;}
	void push (int var)
	{
		st[++top] = var;
	}
	int pop()
	{return st[top--] ;}
bool isEmpty();
};

bool Stack:: isEmpty()
{
	return (top > 0 )? false : true;
}

Stack quiz ( Stack x)
{
	int prev = x.pop();
	int current;
	Stack reverse;
    while ( !x.isEmpty())
	{

		current = x.pop();
		if ( prev != current )
        {
		 reverse.push(prev);
        }
		prev = current;
	}
	reverse.push(prev); // the last element remaining of the duplicates
	Stack ans;

	while(!reverse.isEmpty())
		ans.push(reverse.pop());


		return ans;}



int main (){
	Stack r;
	r.push(1);
		r.push(5);
			r.push(4);
				r.push(3);
							r.push(4);
				r.push(3);

	Stack m = quiz(r);
	while(!m.isEmpty())
	cout<<m.pop()<<endl;















}
