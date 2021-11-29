LST_C=$(wildcard src/*.c)
LST_O=$(LST_C:%.c=%.o)

DIR_INSTALL_CMOCKA=../../cmocka-1.1.5/install

%.o	:	%.c
	gcc -c -Iinc -I$(DIR_INSTALL_CMOCKA)/include -L$(DIR_INSTALL_CMOCKA)/lib64 -lcmocka $+ -o $@

all	:	$(LST_O)
	gcc $+ -o test1 -L$(DIR_INSTALL_CMOCKA)/lib64 -lcmocka
	./test1
