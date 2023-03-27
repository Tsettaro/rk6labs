class Square{
	protected:
		unsigned _degree;
		unsigned **_table;
	public:
		Square(unsigned degree) : _degree(degree){
		_table = new unsigned*[degree];
		
		for (int i = 0; i < degree; i++) {
			_table[i] = new unsigned[degree];
			for (int j = 0; j < degree; j++){
					_table[i][j] = 0;
				}
			}
		}
		~Square(){
			for (int i = 0; i < _degree; i++){
					delete []_table[i];
				}
				delete []_table;
			}
		
};


class Magic : public Square{
	public:
		Magic(unsigned degree);
		void horse();
		void print();
	protected:
		int width();
		int reflect(int);
};
