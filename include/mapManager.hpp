#pragma once
#include <vector>
#include <filesystem>
#include <fstream>

struct note {
    int channel;
    bool show;
    float length, distance, speed;
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

        int initializeNotes();
};

void writeMapFile();
void loadMapFiles();

extern std::vector<map> mapList;
