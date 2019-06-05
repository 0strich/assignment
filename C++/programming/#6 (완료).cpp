#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class CPoint{
protected:
    double m_x, m_y;
public:
    CPoint(double x, double y);
    virtual double Compute_Unit() = 0;              // 부피, 거리, 면적을 계산하기 위한 순수 가상함수
    virtual void Print_Point();                     // 좌표를 출력하는 가상함수
};
CPoint::CPoint(double x, double y){
    m_x = x;
    m_y = y;
}
void CPoint::Print_Point(){
    cout << "(x : " << m_x << ", y : " << m_y << ", ";
}

class CLengthPoint : public CPoint{
    double m_z;
public:
    CLengthPoint(double x, double y, double z);
    double Compute_Unit();
    void Print_Point();
};
CLengthPoint::CLengthPoint(double x, double y, double z) : CPoint(x, y){
     m_z = z;
}
double CLengthPoint::Compute_Unit(){
    return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}
void CLengthPoint::Print_Point(){
    CPoint::Print_Point();
    cout << "z = " << m_z << ')' << endl;
}

class CVolumePoint : public  CPoint{
protected:
    double m_z;
public:
    CVolumePoint(double x, double y, double z);
    double Compute_Unit();
    void Print_Point();
};
CVolumePoint::CVolumePoint(double x, double y, double z) : CPoint(x, y){
    m_z = z;
}
double CVolumePoint::Compute_Unit(){
    return m_x * m_y * m_z;
}
void CVolumePoint::Print_Point(){
    CPoint::Print_Point();
    cout << "z = " << m_z << ')' << endl;
}

class CAreaPoint : public CVolumePoint{
public:
    CAreaPoint(double x, double y, double z) : CVolumePoint(x, y, z){}
    double Compute_Unit();
};
double CAreaPoint::Compute_Unit(){
    return 2 * (m_x * m_y + m_y * m_z + m_z * m_x);
}

int main(){
    CPoint *ptr;
    CLengthPoint lengthPt(5.7, 12.5, 3.4);
    CVolumePoint volumePt(11.6, 4.1, 5.4);
    CAreaPoint areaPt(3.7, 8.9, 4.5);

    ptr = &lengthPt;
    cout << "객체 lengthPt의 좌표 : ";
    ptr->Print_Point();
    cout << "객체 lengthPt의 원점으로부터의 거리 : " << round(ptr->Compute_Unit()*10)/10 << endl;

    ptr = &volumePt;
    cout << "객체 volumePt의 좌표 : ";
    ptr->Print_Point();
    cout << "객체 volumePt의 육면체 부피 : " << round(ptr->Compute_Unit()*10)/10 << endl;

    ptr = &areaPt;
    cout << "객체 areaPt의 좌표 : ";
    ptr->Print_Point();
    cout << "객체 areaPt의 육면체 겉넓이 : " << round(ptr->Compute_Unit()*10)/10 << endl;

    return 0;
}
