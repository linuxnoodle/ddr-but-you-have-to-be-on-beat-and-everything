CC=g++

mapWriter: writer.cpp
	$(CC) writer.cpp -O2 -o mapWriter

.PHONY: install
install: mapWriter
	./mapWriter && cp ./output.map ../maps/white-space/output.map
