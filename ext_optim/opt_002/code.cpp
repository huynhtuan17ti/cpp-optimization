#include <iostream>
#include <string>
using namespace std;

class TextBlockV1{
public:
    TextBlockV1(string text): m_text(text) {}
    ~TextBlockV1(){}
    const char& operator[](size_t position) const {
        // assume that a lot of code here
        return m_text[position]; 
    }
    char& operator[](size_t position) { // <-- duplicate to above operator
        // assume that a lot of code here
        return m_text[position]; 
    }
private:
    string m_text;
};

class TextBlockV2{
public:
    TextBlockV2(string text): m_text(text) {}
    ~TextBlockV2(){}
    const char& operator[](size_t position) const {
        // assume that a lot of code here
        return m_text[position];
    }
    char& operator[](size_t position) {
        return const_cast<char&> ( // cast away const
            static_cast<const TextBlockV2&>(*this)[position] // add const to this's type and call const version of operator[]
        );
    }
private:
    string m_text;
};

int main() {
    TextBlockV1 tb("OptimC++");
    TextBlockV2 tbV2("OptimC++");

    cout << "[*] TextBlockV1 object" << '\n';
    cout << "Before operation: " << tb[2] << '\n';
    tb[2] = 'T';
    cout << "After operation: " << tb[2] << '\n';

    cout << "[*] TextBlockV1 object" << '\n';
    cout << "Before operation: " << tbV2[2] << '\n';
    tbV2[2] = 'T';
    cout << "After operation: " << tbV2[2] << '\n';
}