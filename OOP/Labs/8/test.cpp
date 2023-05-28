#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv){
    int parts, part_size, file_size;
    ifstream in;
    if (argc < 3) return -1;
    in.open(argv[1], ios::binary);
    if (!in){
        cerr << "ERROR! FILE DOESN'T EXIST!";
        return -2;
    }
    parts = atoi(argv[2]);
    file_size = in.seekg(0, ios::end).tellg();
    in.seekg(0, ios::beg);
    if (file_size < parts){
        cerr << "ERROR! SIZE OF FILE LESS THAN PARTS!";
        return -3;
    }
    part_size = file_size / parts;
    cout << part_size << endl;

    for (int i = 0; i < parts; i++){
        ofstream out;
        string name = argv[1];
        char buf[512];
        out.open(name+ "_" + to_string(i+1));
        in.read(buf, part_size);
        out.write(buf, part_size);
        out.close();
    }
    in.close();
}