CC = g++
LIBS = -lsfml-graphics -lsfml-system -lsfml-window
ARGS = -Wall -std=c++20

app: main.o
	$(CC) main.o engine.o scene.o element.o balloon.o -o app $(LIBS) $(ARGS)

main.o: main.cpp
	$(CC) -c main.cpp src/engine.cpp src/scene.cpp src/element.cpp src/balloon.cpp $(LIBS) $(ARGS)

engine.o: src/engine.cpp
	$(CC) -c engine.cpp $(LIBS) $(ARGS)

scene.o: src/scene.cpp
	$(CC) -c scene.cpp $(LIBS) $(ARGS)

element.o: src/element.cpp
	$(CC) -c element.cpp scene.cpp $(LIBS) $(ARGS)

balloon.o: src/balloon.cpp
	$(CC) -c balloon.cpp scene.cpp $(LIBS) $(ARGS)

clean:
	rm *.o app
