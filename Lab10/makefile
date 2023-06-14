#Kyle Nguyen
#CSC60-03 Prof Biel
#Lab 10 Makefile

lab10: lab10.o ParseCmd.o ProcessExtCmd.o Redirect.o RunExtCmd.o lab9_10.h
	gcc lab10.o ParseCmd.o ProcessExtCmd.o Redirect.o RunExtCmd.o -o lab10

lab10.o: lab10.c lab9_10.h
	gcc -c lab10.c

ParseCmd.o: ParseCmd.c lab9_10.h
	gcc -c ParseCmd.c

ProcessExtCmd.o: ProcessExtCmd.c lab9_10.h
	gcc -c ProcessExtCmd.c

Redirect.o: Redirect.c lab9_10.h
	gcc -c Redirect.c

RunExtCmd.o: RunExtCmd.c lab9_10.h
	gcc -c RunExtCmd.c
