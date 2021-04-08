// Specification
#ifndef LEARNCPP_STRING_H
#define LEARNCPP_STRING_H

class String{

private:
    const char* mString{};
    int length(const char* string);
    const char* concatTmp(const char* rhs);
    const char* repeatTmp(const char* rhs, int n);
    int stringIntSize;

public:
    String();
    String(const char* _string);

    // Assignment
    String operator =(const String&);

    // Unary minus
    String& operator-();
    // Equality
    bool operator == (const String&);
    // Not Equal
    bool operator != (const String&);
    // Less than
    bool operator < (const String&);
    // Greater Than
    bool operator > (const String&);

    // Concatenation
    String operator + (const String &string);

    String& operator += (const String&);

    // Repeat Concatenation
    String operator *  (int n);

    // Repeat and Assign it self
    String& operator *= (int n);

    // Print the String <For Development Only>
    const char* getString();

    // Functions
    int length();

    // Convertion Functions
    char* toString(int);
    int* toInt(char*);

};

#endif
