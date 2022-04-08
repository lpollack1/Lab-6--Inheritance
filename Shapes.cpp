//
// Created by Lance Pollack on 3/18/22.
//
#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include "Shapes.h"
using namespace std;

const float pi = 3.14159f;
// ------------------------SHAPE-----------------------------
Shape::~Shape(){}

// ------------------------Shape2D-----------------------------
void Shape2D::ShowArea() const{
    cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
}
bool Shape2D::operator>(const Shape2D &rhs) const{
    if(this->Area() > rhs.Area()){
        return true;
    }
    else{
        return false;
    }
}
bool Shape2D::operator<(const Shape2D &rhs) const{
    if(this->Area() < rhs.Area()){
        return true;
    }
    else {
        return false;
    }
}
bool Shape2D::operator==(const Shape2D &rhs) const{
    if(this->Area() == rhs.Area()){
        return true;
    }
    else {
        return false;
    }
}
Shape2D::~Shape2D(){}

// ------------------------SQUARE-----------------------------
Square::Square(){
    length = 0;
}
Square::Square(float length){
    this->length = length;
}
void Square::Scale(float scalefactor){
    length = scalefactor*length;
}
float Square::Area() const{
    return length*length;
}
void Square::Display() const{
    cout << "The area of the Square is : " << Area() << endl;
    cout << "Length of a side: " << length << endl;
}
string Square::GetName2D() const{
    return "Square";
}
Square::~Square(){}

// ------------------------CIRCLE-----------------------------
Circle::Circle(){
    radius = 0;
}
Circle::Circle(float radius){
    this->radius = radius;
}
void Circle::Scale(float scalefactor){
    radius = scalefactor*radius;
}
float Circle::Area() const{
    return pi*radius*radius;
}
void Circle::Display() const{
    cout << "The area of the Circle is : " << Area() << endl;
    cout << "Radius: " << radius << endl;
}
string Circle::GetName2D() const{
    return "Circle";
}
Circle::~Circle(){}

// ------------------------TRIANGLE-----------------------------
Triangle::Triangle(){
    base = 0;
    height = 0;
}
Triangle::Triangle(float base, float height){
    this->base = base;
    this->height = height;
}
void Triangle::Scale(float scalefactor){
    base *= scalefactor;
    height *= scalefactor;
}
void Triangle::Display() const{
    cout << "The area of the Triangle is : " << Area() << endl;
    cout << "Base: " << base << endl;
    cout << "Height: " << height << endl;
}
float Triangle::Area() const{
    return (0.5*base*height);
}
string Triangle::GetName2D() const{
    return "Triangle";
}
Triangle::~Triangle(){}

// ------------------------Shape3D-----------------------------

void Shape3D::ShowVolume() const{
    cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
}
bool Shape3D::operator>(const Shape3D &rhs) const{
    if(this->Volume() > rhs.Volume()){
        return true;
    }
    else{
        return false;
    }
}
bool Shape3D::operator<(const Shape3D &rhs) const{
    if(this->Volume() < rhs.Volume()){
        return true;
    }
    else{
        return false;
    }
}
bool Shape3D::operator==(const Shape3D &rhs) const{
    if(this->Volume() == rhs.Volume()){
        return true;
    }
    else{
        return false;
    }
}
Shape3D::~Shape3D(){}

// ------------------------TRI PYRAMID-----------------------------
TriangularPyramid::TriangularPyramid(): Triangle(){
    height = 0;
}
TriangularPyramid::TriangularPyramid(float height, float baseL, float baseH): Triangle(baseL, baseH){
    this->height = height;
}
float TriangularPyramid::Volume() const{
    float V = ((float)1/3)*height*Triangle::Area();
    return V;
}
string TriangularPyramid::GetName3D() const{
    return "TriangularPyramid";
}
void TriangularPyramid::Scale(float scalefactor){
    height *= scalefactor;
    Triangle::Scale(scalefactor);
}
void TriangularPyramid::Display() const{
    cout << "The volume of the TriangularPyramid is : " << Volume() << endl;
    cout << "The height is: " << height <<endl;
    Triangle::Display();
}
TriangularPyramid::~TriangularPyramid(){}

// ------------------------CYLINDER-----------------------------
Cylinder::Cylinder(): Circle(){
    height = 0;
}
Cylinder::Cylinder(float height, float radius): Circle(radius){
    this->height = height;
}
float Cylinder::Volume() const{
    float V = height*Circle::Area();
    return V;
}
string Cylinder::GetName3D() const{
    return "Cylinder";
}
void Cylinder::Scale(float scalefactor){
    height *= scalefactor;
    Circle::Scale(scalefactor);
}
void Cylinder::Display() const{
    cout << "The volume of the Cylinder is : " << Volume() << endl;
    cout << "The height is: " << height << endl;
    Circle::Display();
}
Cylinder::~Cylinder(){}

// ------------------------SPHERE-----------------------------
Sphere::Sphere(): Circle(){
    radius = 0;
}
Sphere::Sphere(float radius): Circle(radius){
    this->radius = radius;
}
float Sphere::Volume() const{
    float V = ((float)4/3)*radius*Circle::Area();
    return V;
}
string Sphere::GetName3D() const{
    return "Sphere";
}
void Sphere::Scale(float scalefactor){
    radius *= scalefactor;
}
void Sphere::Display() const{
    cout << "The volume of the Sphere is : " << Volume() << endl;
    Circle::Display();
}
Sphere::~Sphere(){}