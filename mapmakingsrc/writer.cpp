#include <iostream>
#include <vector>
#include <fstream>

struct note {
    int channel;
    bool show;
    float length, distance, speed;
};

void writeMapFile(std::ostream& s, const std::vector<note>& data){
     unsigned int len = data.size();
     s.write((char*)&len, sizeof(len));
     s.write((const char*)&data[0], len * sizeof(note));
}

// Yes, I should probably make it so that you don't have to individually set the notes for everything.
// No, I do not have enough time to do that.

int main(){
    note note1;
    note note2;
    note note3;
    note note4;

    note1.channel = 0;
    note2.channel = 1;
    note3.channel = 2;
    note4.channel = 3;

    note1.show = true;
    note2.show = true;
    note3.show = true;
    note4.show = true;

    note1.length = 32;
    note2.length = 32;
    note3.length = 32;
    note4.length = 32;

    note1.distance = -600;
    note2.distance = -400;
    note3.distance = -200;
    note4.distance = 0;

    note1.speed = 0.7;
    note2.speed = 0.7;
    note3.speed = 0.7;
    note4.speed = 0.7;

    std::vector<note> notes{note1, note2, note3, note4};
    std::ofstream outputMap = std::ofstream("output.map", std::ios::out);
    writeMapFile(outputMap, notes);
    return 0;
}
