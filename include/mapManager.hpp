#pragma once
#include <vector>
#include <filesystem>
#include <fstream>

// basically a linked list node that holds length and distance 
struct note {
    float length, distanceFromPrevious;
    note* nextNote;
};

class map {
    private:    
        std::filesystem::path filePath, songPath;
        std::vector<note> notes;

    public:
        std::filesystem::path getMapPath() { return filePath; };
        std::filesystem::path getSongPath() { return songPath; };
        std::vector<note> getNotes() { return notes; };

        map(std::filesystem::path fPath, std::filesystem::path sPath){
            filePath = fPath;
            songPath = sPath;
        }        

        int initializeNote(){
            if (std::filesystem::exists(filePath)){
                unsigned int length = 0;
                std::filebuf fileBuffer;
                fileBuffer.open(filePath.c_str(), std::ios::in);
                std::istream mapFile(&fileBuffer);

                mapFile.read((char*)&length, sizeof(length));
                notes.resize(length);
                if (length > 0)
                    mapFile.read((char*)&notes[0], length * sizeof(note));
                return 0;
            } else {
                return -1;
            }
        }
};

extern std::vector<map> mapList;
void loadMapFiles();
