bin/tmlang.bin: src/*.c
	gcc -o bin/tmlang.bin -I src src/*.c

run:
	./bin/tmlang.bin ./source.tml
