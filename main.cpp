//
//  main.cpp
//  query
//
//  Created by 李苹果 on 2020/4/23.
//  Copyright © 2020 李苹果. All rights reserved.
//

#include <string>
#include <fstream>
#include<iostream>
#include "Query.hpp"
#include "Shaoe.hpp"
//using namespace std;
int main(  )
{
    void RunQuery();
    void RunShape();
    RunShape();
    RunQuery();
    return 0;
    
}
void RunQuery(){
    std::string flename("/Users/lipingguo/Desktop/untitled folder/TwoCities.txt");
    FileQuery query(flename);
    query.PrintSentencesFiltered("epoch,the");
    query.ReplaceWord("was","is","/Users/lipingguo/Desktop/untitled folder/TwoDucks.txt");
    query.PrintSentencesOrdered();
    query.PrintWordCount();
}
void RunShape(){
    Shape a(0);
    Rectangle b(0,2,3);
    Circle c(0,3);
    Square d(0,2,3,3);
    std::cout<<"area of Shape:"<<a.GetArea()<<std::endl;
    std::cout<<"area of Rectangle:"<<b.GetArea()<<std::endl;
    std::cout<<"area of Circle:"<<c.GetArea()<<std::endl;
    std::cout<<"area of Square:"<<d.GetArea()<<std::endl;
}
