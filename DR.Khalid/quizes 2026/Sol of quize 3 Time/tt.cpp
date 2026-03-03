
#include<iostream>
#include<cmath>
using namespace std;
enum ampm {AM,PM};
struct TIM
{
    int hour;
    int minn;
    ampm w; //w is am/pm

};
void fun(TIM t1,TIM t2,int& hour,int& minn)
{
    if(t1.w==PM&&t1.hour!=12)
    {
        t1.hour+=12;
    }
    if(t2.w==PM&&t1.hour!=12)
    {
        t2.hour+=12;

    }
     if(t1.w==AM&&t1.hour==12)
    {
        t1.hour=0;
    }
    if(t2.w==AM&&t2.hour==12)
    {
        t2.hour=0;

    }
    int temp;
    temp=(t1.hour*60+t1.minn)-(t2.hour*60+t2.minn);
    if(temp<0){temp*=-1;}
    hour=temp/60;temp-=hour*60;
    minn=temp;

}
int main()
{ int t;
cout<<"Enter Num of tests"<<endl;
cin>>t;
for(int i=1;i<=t;i++){
    int hour,minn;
    int w1,w2;
    TIM t1,t2;

     cin>>t1.hour>>t1.minn>>w1;
    cin>>t2.hour>>t2.minn>>w2;

    t1.w=static_cast<ampm>(w1); //
    t2.w=static_cast<ampm>(w2);
    fun(t1,t2,hour,minn);
    cout<<"The difference in hours and minutes: "<<hour<<" : "<<minn;
cout<<endl;
}


    return 0;
}

