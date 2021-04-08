
#include "String.h"

// Constructors

String::String() {}
String::String(const char *_string) : mString(_string){}

// Assign left hand side String to the right hand side String
String String::operator=(const String &string) {
    return string;
}

/*
 * DESCRIPTION: Put to lower case of all the character of a string
 * RETURN: Lower character cases
 * Example:
 *      String a{"HELLO"};
 *      -a; // return "hello"
 */

String& String::operator-()
{

    char* tmp = new char;

    for (int i = 0; *mString != '\0'; mString++, i++) {

        int x = (int) *mString;

        if(x >= 65 && x <= 90){
            // BIG LETTER
            *(tmp + i) = (char) (x + 32);

        } else {
            // SMALL LETTER
            *(tmp + i) = *mString;
        }
    }

    mString = tmp;

    return *this;
}

/*
 * DESCRIPTION: Compare the String left hand side length to the String right hand side length
 * RETURN: True, if both sides are equal, else if not equal, return false
 * Example:
 *      String a{"Hi"};
 *      a == "Kent"; // return false
 */

bool String::operator == (const String &string)
{
    int equality = 0;

    if(length(mString) == length(string.mString)) {

        for (int i = 0; *(mString + i) != '\0'; ++i) {

            if (*(mString + i) == *(string.mString + i))
                ++equality;
        }
    }

    return equality >= length(mString);
}

/*
 * DESCRIPTION: Compare the String left hand side length to the String right hand side length
 * RETURN: True, if both sides are not equal, else if equal, return false
 * Example:
 *      String a{"Hi"};
 *      a != "Kent"; // return true
 */

bool String::operator!=(const String &string)
{
    return !this->operator==(string.mString);
}

/*
 * DESCRIPTION: Compare the String left hand side length to the String right hand side length
 * RETURN (boolean) : True, if left hand side is 'less' than right hand side, else false;
 * Example:
 *      String a{"Hi"};
 *      a < "Kent"; // return true
 */

bool String::operator < (const String &string)
{
    return length(mString) < length(string.mString);
}

/*
 * DESCRIPTION: Compare the String left hand side length to the String right hand side length
 * RETURN (boolean) : True, if left hand side is 'greater' than right hand side, else false;
 * Example:
 *      String a{"Hi"};
 *      a > "Kent"; // return false
 */

bool String::operator > (const String &string)
{
    return length(mString) > length(string.mString);
}

/*
 * DESCRIPTION: Concatenate the self string to the given string in right hand side
 * RETURN (const char* ) : The sum of self String and given string in the right hand side
 * Example:
 *      String a{"Hi"};
 *      a += "Kent"; // return "HiKent"
 */

String String::operator+(const String &string)
{
    return String{concatTmp(string.mString)};
}

/*
 * DESCRIPTION: Concatenate the self string to the given string in right hand side
 * RETURN (const char* ) : The sum of self String and given string in the right hand side
 * Example:
 *      String a{"Hi"};
 *      a += "Kent"; // return "HiKent"
 */

String& String::operator += (const String& string)
{

    mString = concatTmp(string.mString);

    return *this;
}

/*
 * DESCRIPTION: Multiply Object String to the given n
 * RETURN (String object) : The product of Object String and given n in right hand side
 * Example:
 *      String a{"Hi"};
 *      String b = a * 3; // return "HiHiHi"
 */

String String::operator * (int n)
{
    return String{repeatTmp(mString, n)};
}

/*
 * DESCRIPTION: Self string multiply to the given n
 * RETURN (const char*) : The product of self string and given n
 * Example:
 *      String a{"Hi"};
 *      a *= 3; // return "HiHiHi"
 */

String& String::operator *= (int n)
{

    mString = repeatTmp(mString, n);

    return *this;
}

/*
 * DESCRIPTION: Get the length of the String for outside class use only
 * RETURN (int): The length of the string
 * Example:
 *     String a{"Hi"};
 *     a.length(); // return 2
 *
 */

// Return the length of class string
int String::length()
{
    return length(mString);
}

// Get the length of the given string and assign to the member -> const char*
int String::length(const char* string)
{
    int length = 0;

    for (int i = 0; *(string + i) != '\0'; ++i)
        ++length;

    return length;
}

// Create temporary string in heap for string concatenation
const char* String::concatTmp(const char* rhs){

    int size = length(this->mString) + length(rhs) + 1;

    char* tmp = new char[size];

    for (int i = 0; i < length(this->mString); ++i)
        *(tmp + i) = *(mString + i);

    for (int i = length(this->mString), j = 0; j < length(rhs); ++i, j++)
        *(tmp + i) = *(rhs + j);

    return tmp;
}

// Create temporary string in heap for string multiplication
const char* String::repeatTmp(const char* rhs, int n){

    char* temp = new char[length(rhs) * n];

    for (int i = 0, j = 0; i < length(rhs) * n; ++i, ++j) {

        if((i % length(rhs)) == 0)
            j = 0;

        *(temp + i) = *(rhs + j);
    }

    return temp;
}

// Debugging Purpose only
const char* String::getString(){
    return this->mString;
}

// void String::toString(int x){

//     // int p;

//     // short v = (x / p) - (x  % p) / p;

//     for (int i = 1; i < 1000000000; i *= 10){
        
//         int n = (int) x;

//         if (n / i <= 10){
            
            
//             int tmp =  (n / i) * i; // 300
//             // std::cout << tmp << std::endl;

//             // int tmp2 = (n - tmp) / (i / 10); // 2
//             // std::cout << tmp2 << std::endl;

//             // int tmp3 = (n - tmp2) / (i / 10); // 5
//             // std::cout << tmp3 << std::endl;

//             for (size_t j = i / 10; j >= 1; j /= 10){

//                 int tmp1 = (n - tmp) / j;
                
//                 if(tmp1 >= 1 && tmp1 <=10){
//                     std::cout << tmp1 << std::endl;
//                 }                

//             }            

//             break;
//         }
//     }    
    
// }

char* String::toString(int x){
    
    int base = 1;
    int count {};

    for(int n = x; n >= 1; n /= 10){ ++count; }

    stringIntSize = count;

    char* _string = new char[count];

    for(int i = 10, j = count - 1; j >= 0; --j, i *= 10)
    {
        base = i;
        
        if(j == count - 1)
            *(_string + j) = 48 + (x  % 10);
        
        *(_string + j - 1) = 48 + ((x % (base * 10)) - (x  % base)) / i;
    } 

    return _string;
}

int *String::toInt(char* x){
    
    int *tmp = new int;
    
    for(int i = stringIntSize - 1, e = 1; i >= 0; --i, e *= 10){
        
        int pos =  *(x + i) * 1;
        *tmp += (pos - 48) * e;
    }
    
    return tmp;
}

/*
 *  TODO:
 *      1. Insertion and Extraction Operator
 *      2. Unary+ Operator (All Caps)
 * */
