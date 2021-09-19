CC = g++
LIBS = -lsfml-graphics -lsfml-system -lsfml-window
ARGS = -Wall -std=c++20

app: main.o engine.o scene.o element.o balloon.o button.o
	$(CC) main.o engine.o scene.o element.o balloon.o button.o -o app $(LIBS) $(ARGS)

main.o: main.cpp
	$(CC) -c main.cpp $(LIBS) $(ARGS)

engine.o: src/engine.cpp
	$(CC) -c src/engine.cpp $(LIBS) $(ARGS)

scene.o: src/scene.cpp
	$(CC) -c src/scene.cpp $(LIBS) $(ARGS)

element.o: src/element.cpp
	$(CC) -c src/element.cpp $(LIBS) $(ARGS)

balloon.o: src/balloon.cpp
	$(CC) -c src/balloon.cpp $(LIBS) $(ARGS)

button.o: src/button.cpp
	$(CC) -c src/button.cpp $(LIBS) $(ARGS)

clean:
	rm *.o app
