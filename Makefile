all:
	g++ -std=c++2a executable/*.cpp headers/*.h -lstdc++fs -o main
clean:
	rm -rf *.o main