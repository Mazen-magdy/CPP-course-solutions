#include <iostream>

using namespace std;
struct Rct{
    int ULX, ULY; //Upper Left corner coordinates x, y
    int LRX,LRY; //Lower Right corner coordinates x, y
    // to represent a rectangle
};

struct Cir{
    int x, y; // circular center coordinates
    int radius; // radius of the circular
    // to represent a circle
};

Rct smallest_rectangle(Cir c1,Cir c2){
    Rct r;
    //max left
    if(c1.x-c1.radius>c2.x-c2.radius) r.ULX=c2.x-c2.radius;
    else r.ULX =c1.x-c1.radius;

    //max right
    if(c1.x+c1.radius>c2.x+c2.radius) r.LRX=c1.x+c1.radius;
    else r.LRX =c2.x+c2.radius;

    //max lower
    if(c1.y-c1.radius>c2.y-c2.radius) r.LRY=c2.y-c2.radius;
    else r.LRY =c1.y-c1.radius;

    //max upper
    if(c1.y+c1.radius>c2.y+c2.radius) r.ULY=c1.y+c1.radius;
    else r.ULY =c2.y+c2.radius;

    return r;

}
int main()
{
    Cir c1,c2;
    Rct r;
    //enter ur test case:-
    cout<<"c1.x=";
    cin>>c1.x;
    cout<<"c1.y=";
    cin>>c1.y;
    cout<<"c1.radius=";
    cin>>c1.radius;


    cout<<"c2.x=";
    cin>>c2.x;
    cout<<"c2.y=";
    cin>>c2.y;
    cout<<"c2.radius=";
    cin>>c2.radius;


    r=smallest_rectangle(c1,c2);

    cout<<"Upper Left corner coordinates ("<<r.ULX<<" , "<<r.ULY<<")."<<endl;
    cout<<"Lower Right corner coordinates ("<<r.LRX<<" , "<<r.LRY<<")."<<endl;
    return 0;
}
