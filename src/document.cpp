#include "document.h"

#include <fstream>

#include <iostream>

int Document::getInfo(bool ignorecount) {
    if (!(ignorecount)){
        int lengthStr = 0;
        for (int i = 0; i < this->result.size(); i++)  {
            if (this->result.at(i) == '\n' || this->result.at(i) == '\0') {
                this->rows++;
                this->endStr.push_back(i);
                this->lengthStr.push_back(lengthStr);
                lengthStr = 0;
            }
            else {
                lengthStr++;
                if (this->result.size() - i == 1) {
                    this->endStr.push_back(i);
                    this->lengthStr.push_back(lengthStr);
                }
                continue;
            }
        }
    }
    return this->rows;
}

void Document::showText() {
    std::cout << "\n[SHOW TEXT]\n";
    for (int i = 0; i < this->result.size(); i++){
        if (this->result[i] == '\n') std::cout << "\n";
        else std::cout << this->result[i];
    }
}

int Document::findElementRow(int id) {
    for (int i = 0; i < this->endStr.size(); i++) {
        if (id < this->endStr[i]) {
            return i;
        }
        else continue;
    }
    return -1;
}

void Document::insertText(int offset, const std::string* yourText) {
    this->result.insert(offset, *yourText);
    this->endStr.clear();
    this->lengthStr.clear();
    this->getInfo();
}

void Document::deleteTextInRange(int index, int count) {
    this->result.erase(index, count);
    this->endStr.clear();
    this->lengthStr.clear();
    this->getInfo();
}

void Document::deleteTextAt(int index) {
    this->result.erase(index, 1);
    this->endStr.clear();
    this->lengthStr.clear();
    this->getInfo();
}

void Document::clearTextAtFile(const std::string* fileName) {
    std::ofstream out(*fileName);
    out.close();
}

void Document::clearText() {
    this->result.clear();
    this->endStr.clear();
    this->lengthStr.clear();
    this->getInfo();
}

void Document::getTextFromFile(const std::string* fileName) { // при чтении есть возможность записать конец каждой строки с помощью .back по идее, собственно как и индексы конца строк
    std::ifstream in(*fileName);
    if (in.is_open()){
        while(std::getline(in, buffer)){
            this->result += this->buffer;
            if (buffer[buffer.size() == '\n']) { 
                this->result.push_back('\n');
            }
            this->buffer.clear();
        }
    }
    else {
        std::cout << "\n[ERROR] File not found or you forgot extension .txt in name\n";
    }
    in.close();
    this->endStr.clear();
    this->lengthStr.clear();
    this->getInfo();
}

void Document::getText(const std::string* yourText) {
    this->result += *yourText;
    this->endStr.clear();
    this->lengthStr.clear();
    this->getInfo();
}

void Document::textToFile(const std::string* fileName) {
    std::ofstream out;
    out.open(*fileName);
    if (out.is_open()){
        out << this->result;
    }
    else {
        std::cout << "\n[ERROR] File not found or you forgot extension .txt in name\n";
    }
    out.close();
}


// перегруженные функции

void Document::getText(const char* yourText) {
    int* i = {new int {0}};
    while(*(yourText + *i) != '\0') {
        this->result += *(yourText + *i);
        (*i)++;
    }
    delete i;
    this->endStr.clear();
    this->lengthStr.clear();
    this->getInfo();
}