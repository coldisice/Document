#include "document.h"

int main() {
	Document text;
    const std::string yourText = "Hello world!";
    text.getText(&yourText); // or
	text.getText("Bye world!");
	text.showText();
	// will print
	// [SHOW TEXT]
	// Hello world!Bye world!
	return 0;
}