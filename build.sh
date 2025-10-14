CFLAGS="-Ideps/include/ -std=c++17 -Ldeps/lib/ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL deps/lib/libraylib.a"
clang++ src/main.cpp src/player.cpp src/objects.cpp src/inventory.cpp -o bin/game $CFLAGS
./bin/game