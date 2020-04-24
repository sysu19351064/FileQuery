//
//  Shaoe.hpp
//  query
//
//  Created by 李苹果 on 2020/4/24.
//  Copyright © 2020 李苹果. All rights reserved.
//

#ifndef Shaoe_hpp
#define Shaoe_hpp

#include <stdio.h>
#include <iostream>
class Shape{
    int area;
public:
    Shape(int area_):area(area_){
        std::cout<<"constructor of Shape"<<std::endl;
    }
    int GetArea(){
        return area;
    }
};
class Rectangle:public Shape{
    int long_;
    int wide;
public:
    Rectangle(int area_,int Long_,int wide_):Shape(area_),long_(Long_),wide(wide_){
        std::cout<<"constrcutor of Rectangle"<<std::endl;
    }
    int GetArea(){
        return long_*wide;
    }
};
class Circle:public Shape{
    int radius;
public:
    Circle(int area_,int radius_):Shape(area_),radius(radius_){
        std::cout<<"constrcutor of Circle"<<std::endl;
    }
    double GetArea(){
        return 3.14*radius*radius;
    }
};
class Square:public Rectangle{
    int wide;
public:
    Square(int area_,int Long_,int wide_,int wide__):Rectangle(area_,Long_,wide_),wide(wide__){
        std::cout<<"constrcutor of Square"<<std::endl;
    }
    int Getarea(){
        return wide*wide;
    }
};

#endif /* Shaoe_hpp */
