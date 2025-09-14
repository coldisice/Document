#pragma once
#include <string>
#include <vector>

class Document{
private:
    std::string result=""; // массив для хранения отформатированного текста
    std::string buffer=""; // вспомогательный массив, использующийся при осуществлении операций над исходным текстом
    int rows=1; // переменная для хранения количества строк в массиве result
    std::vector<int> endStr{}; // массив для хранения конца строк (включая символ перехода строки, если таковой есть, иначе до нуль-символа)
    std::vector<int> lengthStr{}; // массив для хранения длины строк (не включая символ перехода строки)
public:
    
    void showText(); // функция для вывода текста, сохраненного в массиве result
    void insertText(int offset, std::string yourText); // функция для вставки нужного текста в массив result начиная с указанного элемента 
    void deleteTextInRange(int left, int right); // функция для удаления текста в определенном промежутке в массиве result
    void deleteText(int offset);// удаляет символ в определенном месте в массиве result
    void clearTextAtFile(std::string fileName="Output.txt"); // удаляет текст, хранящийся в файле с указанным имененем или стандартном Output.txt
    void clearText(); // очищает текст в массиве result
    void getTextFromFile(std::string fileName="Input.txt"); // импортирует текст, хранящийся в файле в массив result
    void getText(std::string yourText); // импорт текста в массив 
    void textToFile(std::string fileName="Output.txt"); // сохраняет текст, хранящийся в массиве result в файл со стандартным именем Output.txt или имененем, указанным пользователем


    int findElementRow(int id); // позволяет получить строку, на которой находится элемент
    int getInfo(bool ignorecount); // обновляет информацию о тексте в массиве result
    
    void debug__showEndStr(); // используется для дебага
    void debug__lengthStr(); // используется для дебага
};

