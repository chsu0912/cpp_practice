#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
  if (argc <= 2){
    // get input file name 
    string input_file;
    (argc == 1) ? input_file = "input.txt" : input_file = argv[1];
    
    // get input content
    ifstream rf (input_file);
    if (rf.is_open()){
        std::cout << "Reading " << input_file << " ..." << std::endl;
        string line;
        int line_count = 0;
        while(getline(rf, line)){
            std::cout << "Line " << ++line_count << ": " << line << std::endl;
        }
        ofstream wf ("output.bin", ios::binary);
        if (wf.is_open()){
            std::cout << "Writing 'line_count' to 'output.bin' ..." << std::endl;
            wf.write(reinterpret_cast<const char*> (& line_count), sizeof(line_count));
            wf.close();
        } else {
            std::cout << "Failed to open 'output.bin'." << std::endl;
        }
        rf.close();
    } else {
        std::cout << "Fail to open file '" << input_file << "' to read" << std::endl;
    }
  } else {
    std::cout << "Invalid input" << std::endl;
  }
}