#include "../include/mapManager.hpp"

std::vector<map> mapList;

void loadMapFiles(){
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
            if (!mapFile.empty() && !audioFile.empty()){
                map newMap(mapFile, audioFile);
                mapList.push_back(newMap);
            }
        }
    }
}
