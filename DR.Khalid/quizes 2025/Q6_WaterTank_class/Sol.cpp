#include<iostream>
using namespace std;
const double pi=3.14159;
class tank{
private:
    double r;
    double h;
    double w;// water height
public:
    tank(double radius,double height,double volume)
    {
        r=radius;
        h=height;
        w=volume/(r*r*pi);
    }
    double current_vol()
    {
        return (r*r*w*pi);
    }
    void add(tank&source)
    {
      double dest_capacity=r*r*pi*(h-w);   //calc the destination available capacity
      double source_w=source.current_vol();
      if(source_w>dest_capacity)
      {
          cout<<"error\n";
          return;
      }
      w+=source_w/(r*r*pi);
      source.w=0;
    }
    void get_values()
    {
        cout<<"Radius: "<<r<<"\n";
        cout<<"Tank height: "<<h<<"\n";
        cout<<"Water height: "<<w<<"\n";
    }
};
int main()
{
    tank tank1(3,5,30);
    tank tank2(4,3,25);
    tank tank3(4,5,100);
    cout<<"Tank 1 values:\n\n";
    tank1.get_values();
    double vol=tank2.current_vol();
    cout<<"Tank 2 water volume = "<<vol<<"\n\n";
    tank1.add(tank2);
    tank1.get_values();
    tank2.get_values();
    tank1.add(tank3);
    return 0;
}
