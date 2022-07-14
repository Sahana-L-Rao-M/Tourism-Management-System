a.exe:Main.o details_of_packages.o
	gcc Main.o details_of_packages.o
Main.o:Main.c details_of_packages.c
	gcc -c Main.c
details_of_packages.o:details_of_packages.c header.h
	gcc -c details_of_packages.c
