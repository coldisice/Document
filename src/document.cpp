#include "document.h"

#include <fstream>

#include <iostream>

int Document::getInfo(bool ignorecount = 0){
    if (!(ignorecount)){
        int lengthStr=0;
        for (int i = 0; i < Document::result.size();i++){
            if (Document::result.at(i)=='\n' || Document::result.at(i)=='\0') {
                Document::rows++;
                Document::endStr.push_back(i);
                Document::lengthStr.push_back(lengthStr);
                lengthStr=0;
            }
            else {
                lengthStr++;
                if (Document::result.size()-i==1){
                    Document::endStr.push_back(i);
                    Document::lengthStr.push_back(lengthStr);
                }
                continue;
            }
        }

    }
    return Document::rows;
}

void Document::showText(){
    std::cout << Document::result;
}

int Document::findElementRow(int id){
    for (int i = 0; i<Document::endStr.size();i++){
        if (id<Document::endStr[i]) return i;
        else continue;
    }
    return -1;
}

void Document::insertText(int offset, std::string yourText){
    for (int j = 0; j < yourText.size();j++){
        Document::buffer = Document::result;
        Document::result.push_back(' ');
        for (int i =0;i<(Document::result.size()-offset);i++){
        Document::result[Document::result.size()-1-i]=Document::buffer[Document::buffer.size()-1-i];
        }
        Document::result[offset] = yourText[yourText.size()-1-j];
    }
    Document::buffer.clear();
    Document::endStr.clear();
    Document::lengthStr.clear();
    getInfo();
}

void Document::deleteTextInRange(int left, int right){
    Document::buffer = Document::result;
    Document::result = Document::buffer.substr(0,left);
    Document::result += Document::buffer.substr(right+1,Document::buffer.size());
    Document::endStr.clear();
    Document::lengthStr.clear();
    getInfo();
}

void Document::deleteText(int offset) {
    Document::buffer = Document::result;
    Document::result = Document::buffer.substr(0,offset);
    Document::result += Document::buffer.substr(offset+1,Document::buffer.size());
    Document::endStr.clear();
    Document::lengthStr.clear();
    getInfo();
}

void Document::clearTextAtFile(std::string fileName){
    std::ofstream out(fileName);
    out.close();
}

void Document::clearText(){
    Document::result.clear();
    Document::endStr.clear();
    Document::lengthStr.clear();
    getInfo();
}

void Document::getTextFromFile(std::string fileName){
    std::ifstream in(fileName);
    if (in.is_open()){
        while (std::getline(in, buffer)){
            Document::buffer="";
            Document::result+=Document::buffer;
            
        }
        Document::result+="\n";
    }
    in.close();
    Document::endStr.clear();
    Document::lengthStr.clear();
    getInfo();
}

void Document::getText(std::string yourText){
    Document::result+=yourText;
    Document::endStr.clear();
    Document::lengthStr.clear();
    getInfo();
}

void Document::textToFile(std::string fileName){
    std::ofstream out;
    out.open(fileName);
    if (out.is_open()){
        out << Document::result;
    }
    out.close();
}
