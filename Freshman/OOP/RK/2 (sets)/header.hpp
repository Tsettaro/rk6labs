class Set{
    unsigned _bit;
    public:
        Set() : _bit(0){};
        Set(char *s);
        Set operator -(Set&);
        Set operator +(Set&);
        //friend std::ostream& operator<<(std::ostream&, const Set&);
        operator char*();
};