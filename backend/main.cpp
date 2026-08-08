#include <iostream>
#include "item.cpp"

#include <vector>
#include <sqlite3.h> 

using namespace std;
void readTable();
Pdf returnPdf();

int main() {
    // then the program starts, the bookshelf fills with books that are in ../data/meta.db
    vector<Pdf> bookshelf;
    cout << "Init successful" << endl;

}

void readTable() {

}
// Pdf returnPdf() {
//     Pdf test("title", "author", );
//     return test;
// }