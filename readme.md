# Documents
Данная библиотека предоставляет класс Document, который предназначен для работы с текстом в файлах с расширением .txt. 

## Использование

Для работы вам потребуются `include/document.h` и `src/document.cpp`.
После чего достаточно подключить заголовочный файл `#include "../../document.h"` в исходный код и объявить объект класса Document:
```
#include "../../document.h"

int main() {
	Document text;
    const std::string yourText = "Hello world!";
    text.getText(&yourText); // or
	text.getText("Bye world!");
	text.showText();
	// will print
	// [SHOW TEXT]
	// Hello world!Bye world!
}
```

## Содержание
- [Функции](#функции)
    - [Работа с текстом](#работа-с-текстом)
        - [showText](#showtext)
        - [insertText](#inserttext)
        - [deleteTextInRange](#deletetextinrange)
        - [deleteTextAt](#deletetextat)
        - [clearText](#cleartext)
        - [getText](#gettext)
        - [textToFile](#texttofile)
    - [Работа с файлами](#работа-с-файлами)
        - [clearTextAtFile](#cleartextatfile)
        - [getTextFromFile](#gettextfromfile)
        - [textToFile](#texttofile)
    - [Вспомогательные функции](#вспомогательные-функции)
        - [findElementRow](#findelementrow)
        - [getInfo](#getinfo)


### Функции
## Работа с текстом
# showText
```void showText()```

Выводит текст в консоль, который до этого был получен при помощи функций: [getTextFromFile()](#gettextfromfile) или [getText()](#gettext).

# insertText
```void insertText(int offset, const std::string* yourText)```

Вставляет текст по указанному смещению.

# deleteTextInRange
```void deleteTextInRange(int index, int count)```

Удаляет `count` символов в тексте начиная от `left`. Фактически дублирует `std::string::erase`. 

# deleteTextAt
```void deleteTextAt(int index)```

Удаляет символ в тексте по указанному индексу.

# clearText
```void clearText()```

Очищает текст, хранящийся в объекте класса Document.

# getText
```void getText(const std::string* yourText)```
```void getText(const char* yourText)```

Подготавливает текст, хранящийся в переменной, к работе.

## Работа с файлами

# clearTextAtFile
```void clearTextAtFile(const std::string *fileName)```

Сохраняет/перезаписывает пустой файл .txt с имененем `fileName` в ту же директорию, из которой запущена программа.

# getTextFromFile
```void getTextFromFile(const std::string *fileName)```

Подготавливает текст, хранящийся в файле, к работе.

# textToFile
```void textToFile(const std::string* fileName)```

Сохраняет текст, хранящийся в объекте класса Document в файл с именем `fileName` в ту же директорию, из которой запущена программа.

## Вспомогательные функции

# findElementRow
```int findElementRow(int id)```

Возвращает номер строки, на которой находится нужная буква текста.

# getInfo
```int getInfo(bool ignorecount=0)```

Используется библиотекой для обновления информации о массиве (количество строк, длина каждой строки и индексы символа перехода строки/нуль символа). Если вы хотите получить количество строк, хранимое в данный момент объектом Document, используйте `int getInfo(1)`.