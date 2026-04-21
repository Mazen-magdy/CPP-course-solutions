#include <iostream>

using namespace std;

const float pi=3.14159;

class water_tank{
    private:
    double rad,hight,water_h;

    public:

    water_tank(double r,double h,double vol):rad(r) , hight(h) , water_h(vol/(pi*rad*rad)) {    }
    /*
    another way
    water_tank(double r,double h,double vol)
    {
        rad=r;
        hight=h;
        water_h=vol/(pi*rad*rad);
    }
    */
    double water_vol()
    {
        return pi*rad*rad*water_h;
    }
    void show_waterlevel()//for test
    {
    cout<<water_h<<endl;
    }
    void add_water(water_tank wt2){
        //METHOD:getting the additional hight of the added water when it put on the tank.
        //       if the additional hight make water level more than the tank hight ,print error.
        double additinal_h=wt2.water_vol()/(pi*rad*rad);
        if(additinal_h+water_h<=hight)water_h+=additinal_h;
        else cout<<"error"<<endl;
    }

};

int main()
{
                   //test case
    water_tank wt1(5 ,100,3926.9875),wt2(5,100,3926.9875),wt3(5,100,3141.59),wt4(5,100,5497.7825) ;
                   //add 2 to 1 accebted
                   //add 4 to 2 not
                   wt1.add_water(wt2);
                   wt1.show_waterlevel();
                   wt3.add_water(wt4);
                   wt3.show_waterlevel();


    return 0;
}
