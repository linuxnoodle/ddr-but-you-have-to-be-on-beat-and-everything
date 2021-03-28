#include "../include/mapManager.hpp"

std::vector<map> mapList;

// Vector serializer, implement for mapmaking
void writeMapFile(std::ostream& s, const std::vector<map>& data){
     unsigned int len = data.size();
     s.write((char*)&len, sizeof(len));
     s.write((const char*)&data[0], len * sizeof(map));
}

int map::initializeNotes(){
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

void loadMapFiles(){
    // Loops through the maps folder, and looks through it for directories, 
    // then looks in those directories for .wav and .json files
    for (const auto &entry: std::filesystem::directory_iterator("./maps/")){
        if (std::filesystem::is_directory(entry.path())){
            std::filesystem::path mapFile, audioFile;
            for (const auto &subentry: std::filesystem::directory_iterator(entry.path())){
                if (subentry.path().extension() == ".map"){
                    mapFile = subentry.path();
                } else if (subentry.path().extension() == ".wav"){
                    audioFile = subentry.path();
                }
            }
            // Makes a map object, then gives it the paths to the .wav and .map files
            if (!mapFile.empty() && !audioFile.empty()){
                map newMap(mapFile, audioFile);
                mapList.push_back(newMap);
            }
        }
    }
}
