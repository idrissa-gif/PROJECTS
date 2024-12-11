#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
public:

    Furniture(double p,double d,Material m):price(0),discount(0),madeof(Material::Wood)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("");
    }
};



enum class BedSize {Single,SemiDouble,Double};

class Bed:public Furniture
{
private:
    BedSize Bsize;
public:
    Bed(double p,double d,Material m,BedSize b):Furniture(p,d,m), Bsize(BedSize::Single)
    {
        setBsize(b);

        cout<<"Bed element successfully set "<<endl;
    }
    void setBsize(BedSize val)
    {
        Bsize=val;
    }
    string getBsize()
    {
        if(Bsize==BedSize::Single)
            return string("Single");
        else if(Bsize==BedSize::SemiDouble)
            return string("SemiDouble");
        else if(Bsize==BedSize::Double)
            return string("Double");
        else
            return string("");
    }
};

enum class SofaSize {One, Two, Three, Four, Five};

class Sofa:public Furniture
{
private:
    SofaSize seat;
public:
    Sofa(double p,double d,Material m,SofaSize s):Furniture(p,d,m),seat(SofaSize::One)
    {
        setSeat(s);

        cout<<"Sofa element successfully set "<<endl;
    }
    void setSeat(SofaSize s)
    {
        seat=s;
    }
};

enum class AlmirahSize {Single , SemiDouble , Double};

class Almirah:public Furniture
{
private:
    AlmirahSize almirahSize;
public:
    Almirah(double p,double d,Material m,AlmirahSize al) : Furniture(p,d,m),almirahSize(AlmirahSize::Single)
    {
        SetAlmirah(al);
        cout<<"Almirah element successfully set "<<endl;
    }
    void SetAlmirah(AlmirahSize al)
    {
        almirahSize = al;
    }
};
int main()
{
    Furniture* f_list[4];

    /**
        task 1
        So that following lines can be executed without error
    */
    f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa(11000,234,Material::Steel,SofaSize::Five);
    f_list[2] = new Almirah(13000,345,Material::Wood,AlmirahSize::Double);
    f_list[3] = new Bed(10090,123,Material::Wood,BedSize::Single);

    delete f_list[0];
    delete f_list[1];
    delete f_list[2];
    delete f_list[3];
    /**task 1 ends here*/
    return 0;
}
