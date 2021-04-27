all:
	g++ -std=c++2a executable/*.cpp headers/*.h -lstdc++fs -o usacu
clean:
	rm -rf *.o usacu