#include "Alpha.hpp"
#include <iostream>
Alpha::Alpha(char *s){
    set = 0;
    while(*s){
        set |= (1 << (tolower(*s) - 'a'));
        s++;
    }
}

Alpha Alpha::operator~(){
    Alpha result;
    result.set = ~ set;
    return result;
}

Alpha Alpha::operator^(const Alpha& other) {
    Alpha result;
    result.set = (set ^ other.set);
    return result;
}

std::ostream& operator<<(std::ostream& os, const Alpha& s) {
    unsigned bit = 1;
    for (int i = 0; i < 26; i++) {
        if ((s.set & bit) > 0) {
            os << (char)('a' + i);
        }
        bit = bit << 1;
    }
    return os;
}

int main(int argc, char **argv) {

    if (argc < 3) return -1;

    Alpha s1(argv[1]);
    Alpha s2(argv[2]);

    Alpha result = ~ (s1 ^ s2);
    std::cout << "Result: " << result << std::endl;

    return 0;
}