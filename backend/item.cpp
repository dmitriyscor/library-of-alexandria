#include "item.h"

void Pdf::SetTitle(std::string t) {
    this->title = t;
}
void Pdf::SetAuthor(std::string a) {
    this->author = a;
}
void Pdf::SetYear(int y) {
    this->year = y;
}
void Pdf::SetFilename(std::string fn) {
    this->filename = fn;
}