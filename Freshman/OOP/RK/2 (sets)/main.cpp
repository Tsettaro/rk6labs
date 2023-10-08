#include "header.hpp"
#include <iostream>

Set::Set(char *s){
    _bit = 0;
    while (*s){
        _bit |= (1 << (tolower(*s)-'a'));
    }
}
Set Set::operator+(Set& b){
    Set result;
    result._bit = this->_bit | b._bit;
    return result;
}

Set Set::operator-(Set& b){
    Set result;
    result._bit = this->_bit & ~(b._bit);
    return result;
}

Set::operator char*(){
    static char s[32];
    int i = 0, j = 0;
    unsigned b = _bit;
    while (b > 0){
        if (b & 1){
            s[j++] = 'a' + i;
        }
        i++;
        b = b >> 1;
    }
    s[j] = '\0';
    return s;

}
// std::ostream& operator<<(std::ostream& os, const Set& s) {
//     unsigned bit = 1;
//     for (int i = 0; i < 26; i++){
//         if ((s._bit & bit) > 0){
//             os << (char)('a'+i);
//         }
//         bit = bit << 1;
//     }
//     return os;
// }

int main(int argc, char **argv){
    if (argc < 3) return -1;
    Set a(argv[1]);
    Set b(argv[2]);
    Set c = (a + b) - b;
    std::cout << (char*)c;
    //std::cout << c << '\n';
}