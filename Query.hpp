//
//  Query.hpp
//  query
//
//  Created by 李苹果 on 2020/4/23.
//  Copyright © 2020 李苹果. All rights reserved.
//

#ifndef Query_hpp
#define Query_hpp

#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>
class FileQuery{
    using line_no=std::vector<std::string>::size_type;
    std::vector<std::string>sentences_;
    std::map<std::string,std::set<line_no>> wm;
public:
    FileQuery(std::string flename);
    void PrintSentencesOrdered();
    void PrintSentencesFiltered(const std::string&str);
    void PrintWordCount();
    void ReplaceWord(const std::string&old,const std::string& new_,std::string flename);
};

#endif /* Query_hpp */
