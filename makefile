# Kyle Halek
# CPE 3600 - Dr. Rothe Section 131
# Lab 9 - System calls
# Makefile: creates all info files

CC = gcc
CFLAGS = -Wall -Werror
LIBS = -lncurses

all: info pinfo pmod finfo

info: info.c
	$(CC) $(CFLAGS) info.c -o info $(LIBS)

pinfo: pinfo.c
	$(CC) $(CFLAGS) pinfo.c -o pinfo $(LIBS)

pmod: pmod.c
	$(CC) $(CFLAGS) pmod.c -o pmod $(LIBS)

finfo: finfo.c
	$(CC) $(CFLAGS) finfo.c -o finfo $(LIBS)

clean:
	rm -f info pinfo pmod finfo





# # typing make in ubuntu will return *** no targets. stop since there is nothing in here
# # Kyle Halek
# #comments
# #target: prerequisites
# #commands to make the target

# EXECUTABLE = make
# CC = gcc
# CFLAGS = -c -Wall -ggdb
# #-MMD will create the header files (dependency files). In the case of math.h
# LFLAGS = -lncurses
# SOURCES = main.c myMath.c control.c info.c pinfo.c
# OBJECTS = $(SOURCES:.c=.o) 

# all: $(EXECUTABLE) $(SOURCES)

# $(EXECUTABLE): $(OBJECTS)
# 	$(CC) $(OBJECTS) $(LFLAGS) -o $@
# #now typing make will run line 8 command

# -include *.d
# #*.d: if you wanted to remove all .o files you can do *.o  : *.d removes all the dependency files

# %.o: %.c
# 	$(CC) $(CFLAGS) $< -o $@
# 	$(CC) -MM $<>$*.d
	
	
# clean: 
# 	rm -f $(EXECUTABLE)
# 	rm -f $(OBJECTS)
# 	rm -f *.d
