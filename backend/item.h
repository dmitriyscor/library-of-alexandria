#include <string>


class Pdf {
private:
    std::string title;
    std::string author;
    int year;
    int id;
    std::string filename;

public:

    Pdf(std::string t, std::string a, int y, int id, std::string f) : title(t), author(a), year(y), id(id), filename(f) {}

    // setters
    void SetTitle(std::string);
    void SetAuthor(std::string);
    void SetYear(int);
    void SetFilename(std::string);


};