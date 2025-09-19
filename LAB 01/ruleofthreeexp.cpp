#include <iostream>
#include <cstring>
using namespace std;

class Note {
    char* text;   // dynamically allocated string
public:
    // Constructor
    Note(const char* t) {
        text = new char[strlen(t) + 1];
        strcpy(text, t);
    }

    // 1. Destructor
    ~Note() {
        delete[] text;
    }

    // 2. Copy Constructor
    Note(const Note& other) {
        text = new char[strlen(other.text) + 1];
        strcpy(text, other.text);
    }

    // 3. Copy Assignment Operator
    Note& operator=(const Note& other) {
        if (this != &other) {
            delete[] text;
            text = new char[strlen(other.text) + 1];
            strcpy(text, other.text);
        }
        return *this;
    }

    void show() { cout << text << endl; }
};

int main() {
    Note n1("Hello C++");
    Note n2 = n1;    // Copy Constructor
    Note n3("Temp");
    n3 = n1;         // Copy Assignment

    cout << "n1: "; n1.show();
    cout << "n2: "; n2.show();
    cout << "n3: "; n3.show();

    return 0;
}

