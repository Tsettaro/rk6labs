class Alpha {
private:
    unsigned set;
public:
    Alpha(){set = 0;}
    Alpha(char *s);

    Alpha operator^(const Alpha&);
    Alpha operator~();

    friend std::ostream& operator<<(std::ostream&, const Alpha&);
};