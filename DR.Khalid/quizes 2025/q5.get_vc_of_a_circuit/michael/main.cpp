#include <iostream>

using namespace std;

void get_vc(double c,double r,double vc[],double vs){
    vc[0]=0;
    double dt,k;
    int i;
    for(i=1;i<1000;i++){
        dt=i/1000.0;
        k=dt/(r*c);
        vc[i]=k*(vs-vc[i-1])+vc[i-1];

    }
    return ;
}

int main()
{
    //test
    double r,c,vs;
    cout<<"r= ";
    cin>>r;

    cout<<"c= ";
    cin>>c;
    cout<<"vs= ";
    cin>>vs;

    double vc[1000];
    get_vc(c,r,vc,vs);
    cout<<vc[999];

    return 0;
}
