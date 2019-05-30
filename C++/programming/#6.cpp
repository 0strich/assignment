#include <iostream>
using namespace std;

class CPoint{
protected:
    double m_x, m_y;
public:
    CPoint(double x, double y);
    virtual double Compute_Unit() = 0;
    virtual void Print_Point();
};

class CLengthPoint : public CPoint{
protected:
    double m_z;
public:
    CLengthPoint(double x, double y, double z) : CPoint(x, y) {}
    void Compute_Unit();
    void Print_Point();
};

class CVolumePoint : public CPoint{
protected:
    double m_z;
public:
    CVolumePoint(double x, double y, double z) : CPoint(x, y) {}
    double Compute_Unit();
    void Print_Point();
};

class CAreaPoint : public CVolumePoint{
public:
    CAreaPoint(double x, double y, double z) : CVolumePoint(x, y, z) {}

};

int main(){

    return 0;
}
