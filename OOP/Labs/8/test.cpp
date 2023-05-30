#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

class File{
    private:
        string name;
        int parts;
        string get_name(int index){
            return name+ "_" + to_string(index);
        }
    public:
        File (const string &file_name, int p) : name(file_name), parts(p) {};
        void split_file();
};

void File::split_file(){
    int part_size, text_length;
    ifstream in;
    in.open(name, ios::binary);

    if (!in){
        cerr << "ERROR! FILE DOESN'T EXIST!";
        exit(-2);
    }
    if (parts < 1){
        cerr << "ERROR! PARTS LESS THAN 1!";
        exit(-3);
    }

    text_length = in.seekg(0, ios::end).tellg();
    in.seekg(0, ios::beg);
    if (text_length < parts){
        cerr << "ERROR! SIZE OF FILE LESS THAN PARTS!";
        exit(-4);
    }
    part_size = text_length / parts;

    for (int i = 0; i < parts; i++){
        ofstream out;
        char buf[512];
        out.open(get_name(i+1));
        in.read(buf, part_size);
        out.write(buf, part_size);
        out.close();
    }
    in.close();
}
int main(int argc, char **argv){
    if (argc < 3) return -1;
    string name;
    int num_parts;
    name = argv[1];
    num_parts = atoi(argv[2]);
    File f(name, num_parts);
    f.split_file();
}