//
//  Query.cpp
//  query
//
//  Created by 李苹果 on 2020/4/23.
//  Copyright © 2020 李苹果. All rights reserved.
//

#include "Query.hpp"
FileQuery::FileQuery(std::string flename){
    std::ifstream ifs(flename);
    std::string text;
    while(getline(ifs, text)){//分解行，并存入vector中
        sentences_.push_back(text);
    }
}

void FileQuery::PrintSentencesOrdered(){
    void swap(std::string&s1,std::string&s2);
    unsigned long n=sentences_.size()-1;
    int i=0;
   //按字典序选择排序
    for(i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(sentences_[j]<sentences_[i]){
                swap(sentences_[j], sentences_[i]);
            }
        }
    }
    //遍历vector，按顺序输出
    for(auto s:sentences_)
        std::cout<<s<<std::endl;
}
void swap(std::string&s1,std::string&s2){
    std::string temp;
    temp=s1;
    s1=s2;
    s2=temp;
}
void FileQuery::PrintSentencesFiltered(const std::string&str){
    std::vector<std::string> inclusion;
    std::string word;
    std::istringstream str_(str);
    //以逗号为界分割单词
    while(getline(str_,word,',')){
        inclusion.push_back(word);
    }
    for(auto c:inclusion){
        std::cout<<c<<std::endl;
    }
    //set查询单词更简便，因此利用已有的vector初始化set
    std::set<std::string> include(inclusion.begin(),inclusion.end());
        for(auto s:sentences_){
            std::istringstream line(s);
            std::string word;
            int flag=1;
            //以flag为标志，判断单词包含
            while(line>>word){
                if(include.find(word)!=include.end()){
                    flag=0;
                    break;
                }
            }
            if(flag==1) std::cout<<s<<std::endl;
        }
}
void FileQuery::PrintWordCount(){
    std::map <std::string, size_t> word_count;
    for(auto s:sentences_){
        std::istringstream in(s);
        std::string word;
        while(in>>word){
            std::string::iterator itl;
            //全部转为小写，消除大小写敏感性
            for(itl=word.begin();itl!=word.end();itl++){
                *itl=tolower(*itl);
            }
            //消除标点符号
            word.erase(remove_if(word.begin(),word.end(),ispunct),word.end());
                       ++word_count[word];
        }
    }
    //建立map，便于单词记数
    auto map_it=word_count.cbegin();
    while(map_it!=word_count.cend()){
        std::cout<<map_it->first<<" occurs "<<map_it->second<<((map_it->second>1)?" times":" time")<<std::endl;
        ++map_it;
    }
}
void FileQuery::ReplaceWord(const std::string&old,const std::string& new_,std::string flename){
    std::ofstream ofs(flename);
    for(auto s:sentences_){
        std::istringstream in(s);
        std::string word;
        std::vector<std::string> line;
        while(in>>word){
            if(old==word) word=new_;
            line.push_back(word);
        }
        //与单词记数类似，找到关键单词，替换，存入vector
        //遍历vector，存入输出流
        std::ostringstream ou;
        for(auto c:line){
            ofs<<c<<" ";
        }
        ofs<<std::endl;
        //ofs<<ou<<std::endl;
    }
    ofs.close();
}
