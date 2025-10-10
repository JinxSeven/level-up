#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>

constexpr int DATA_BLOCK = 512;
constexpr int FILE_SIZE = 8;

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        std::cerr << "Useage ./<executable>.exe/out <filename>.raw \n";
        return 1;
    } 

    std::ifstream inputFile(argv[1], std::ios::binary);

    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file!\n";
        return 2;
    }

    std::ofstream image;
    int count = 0;
    char outName[FILE_SIZE];
    std::uint8_t buffer[DATA_BLOCK];
    //0xff 0xd8 0xff
    while (inputFile.read(reinterpret_cast<char *>(buffer), DATA_BLOCK)) {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) {
            if ((buffer[3] & 0xf0) == 0xe0) {
                if (image.is_open()) {
                    image.close();
                }                
                std::sprintf(outName, "%03i.jpg", count++); 
                image.open(outName, std::ios::binary);
            }
            if (image.is_open()) {
                image.write(reinterpret_cast<char *>(buffer), DATA_BLOCK);
            }
        }
        if (image.is_open()) {
            image.close();
        }
    }
    
    return 0;
}
