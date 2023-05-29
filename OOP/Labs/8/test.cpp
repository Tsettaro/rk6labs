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
        File(const string &file_name, int p) : parts(p) {name = file_name;};
        void split_file();
};

void File::split_file(){
    int part_size, file_size;
    ifstream in;
    in.open(name, ios::binary);
    if (!in){
        cerr << "ERROR! FILE DOESN'T EXIST!";
        exit(-2);
    }
    file_size = in.seekg(0, ios::end).tellg();
    in.seekg(0, ios::beg);
    if (file_size < parts){
        cerr << "ERROR! SIZE OF FILE LESS THAN PARTS!";
        exit(-3);
    }
    part_size = file_size / parts;
    //cout << part_size << endl;

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