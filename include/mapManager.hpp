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

        int initializeNotes();
};

extern std::vector<map> mapList;
void loadMapFiles();
