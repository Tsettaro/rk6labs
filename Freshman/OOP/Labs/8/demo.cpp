#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, char **argv){
	unsigned short i = 0; //code of word
	unsigned offset = 0; // смещение
	
	if (argc < 3) {
		std::cerr << "UPS" << std::endl;
		return(-1);
	}
	std::ofstream output;
	
	output.open(argv[2]);
	if (output == 0){
		std::cerr << "UPS" << std::endl;
		return(-2);
	}
	
	std::ifstream input(argv[1]);
	if (input == 0){
		std::cerr << "UPS" << std::endl;
		return(-2);
	}
	output.fill('0');
	output << std::oct << std::setw(7) << offset;
	
	while (input.read((char *)&i, 2)) {
		offset += 2;
		output << " " << std::hex << std::setw(4) << i;
		i = 0;
		if ((offset % 16) == 0){
			output << std::endl << std::oct << std::setw(7) << offset;
		}
	}
	if (input.gcount() == 1) {
		output << " " << std::hex << std::setw(4) << i;
		offset++;
	}
	output << std::endl;
	
	if (offset % 16){
		output << std::oct << std::setw(7) << offset << std::endl;
	}
}
