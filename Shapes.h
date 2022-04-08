//
// Created by Lance Pollack on 3/18/22.
//
#include <iostream>
#include <iomanip>
#include <random>
#include <string>
using namespace std;

#define PI 3.14159f

class Shape{
public:
    virtual void Scale(float scalefactor) = 0;
    virtual void Display() const =0;
    virtual ~Shape();
};

class Shape2D : virtual public Shape{
public:
    virtual float Area() const = 0;
    void ShowArea() const;
    virtual string GetName2D() const = 0;
    bool operator>(const Shape2D &rhs) const;
    bool operator<(const Shape2D &rhs) const;
    bool operator==(const Shape2D &rhs) const;
    ~Shape2D();
};

class Square: public Shape2D{
private:
    float length;

public:
    Square();
    Square(float length);
    void Scale(float scalefactor);
    void Display() const;
    float Area() const;
    string GetName2D() const;
    ~Square();
};
class Circle: public Shape2D{
private:
    float radius;

public:
    Circle();
    Circle(float radius);
    void Scale(float scalefactor);
    void Display() const;
    float Area() const;
    string GetName2D() const;
    ~Circle();
};
class Triangle: public Shape2D{
private:
    float base;
    float height;

public:
    Triangle();
    Triangle(float base, float height);
    void Scale(float scalefactor);
    void Display() const;
    float Area() const;
    string GetName2D() const;
    ~Triangle();
};

class Shape3D : virtual public Shape{
public:
    virtual float Volume() const = 0;
    void ShowVolume() const;
    virtual string GetName3D() const = 0;
    bool operator>(const Shape3D &rhs) const;
    bool operator<(const Shape3D &rhs) const;
    bool operator==(const Shape3D &rhs) const;
    ~Shape3D();
};

class TriangularPyramid: public Shape3D, private Triangle{
private:
    float height;

public:
    TriangularPyramid();
    TriangularPyramid(float height, float baseL, float baseH);
    float Volume() const;
    string GetName3D() const;
    void Scale(float scalefactor);
    void Display() const;
    ~TriangularPyramid();
};
class Cylinder: public Shape3D, private Circle{
private:
    float height;

public:
    Cylinder();
    Cylinder(float height, float radius);
    float Volume() const;
    string GetName3D() const;
    void Scale(float scalefactor);
    void Display() const;
    ~Cylinder();
};
class Sphere: public Shape3D, private Circle{
private:
    float radius;

public:
    Sphere();
    Sphere(float radius);
    float Volume() const;
    string GetName3D() const;
    void Scale(float scalefactor);
    void Display() const;
    ~Sphere();
};