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

std::vector<note> notes;

void writeNote(int channel, float length, float distance, float bpm){
    note currentNote;
    currentNote.channel = channel;
    currentNote.length = length;
    currentNote.distance = distance;
    currentNote.speed = (1/bpm)/60;
    currentNote.show = true;
    notes.push_back(currentNote);
}

// Yes, I should probably make it so that you don't have to individually set the notes for everything.
// No, I do not have enough time to do that.

int main(){
    writeNote(0, 32, 110.5, 104.23);
    writeNote(1, 32, 142.3, 104.23);
    writeNote(2, 32, 174.1, 104.23);
    writeNote(3, 32, 210, 104.23);

    for (unsigned long int i = 0; i < notes.size(); ++i){
        std::cout << "channel: " << notes[i].channel << "\nlength: " << notes[i].length << "\ndistance: " << notes[i].distance << "\nspeed: " << notes[i].speed << "\nshow: " << notes[i].show << "\n\n";
    }

    std::ofstream outputMap = std::ofstream("output.map", std::ios::out);
    writeMapFile(outputMap, notes);
    return 0;
}
