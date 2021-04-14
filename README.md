# DDR but you have to be on beat and everything
It's like DDR, but you have to be on beat, and everything.

## Building dependencies:
- sdl2 and sdl2\_image
- cmake + make (c++17)
## Building:
```
git clone https://github.com/linuxnoodle/ddr-but-you-have-to-be-on-beat-and-everything/
cd ddr-but-you-have-to-be-on-beat-and-everything
cmake .
make
```
## MapMaking:
Map files are made by serializing a vector of "note" objects to a file.
Currently, you have to set each singular note's parameters exactly, and it's honestly too much work to make a GUI for it.
If you want to write a map, edit `./mapmakingsrc/writer.cpp`, and run `cd ./mapmakingsrc/ && make && ./mapWriter`.
## TODO:
- add menuing (map selector)
