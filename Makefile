CC = g++
LIBS = -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio
ARGS = -Wall -std=c++20

app: main.o engine.o scene.o element.o balloon.o button.o sound-manager.o demo.o
	$(CC) main.o engine.o scene.o element.o balloon.o button.o sound-manager.o demo.o -o app $(LIBS) $(ARGS)

main.o: main.cpp
	$(CC) -c main.cpp $(LIBS) $(ARGS)

demo.o: demo.cpp
	$(CC) -c demo.cpp $(LIBS) $(ARGS)

sound-manager.o: include/sound-manager.cpp
	$(CC) -c include/sound-manager.cpp $(LIBS) $(ARGS)

engine.o: include/engine.cpp
	$(CC) -c include/engine.cpp $(LIBS) $(ARGS)

scene.o: include/scene.cpp
	$(CC) -c include/scene.cpp $(LIBS) $(ARGS)

element.o: include/element.cpp
	$(CC) -c include/element.cpp $(LIBS) $(ARGS)

button.o: include/button.cpp
	$(CC) -c include/button.cpp $(LIBS) $(ARGS)

balloon.o: src/balloon.cpp
	$(CC) -c src/balloon.cpp $(LIBS) $(ARGS)

clean:
	rm *.o app
