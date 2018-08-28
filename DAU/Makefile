# INC_DIR:=../
# SRC_DIR:=./
# #EXE_DIR := ./bin
# CC:= g++
# CPPFLAGS := -std=c++11 -g -Wno-deprecated
# #LIBS := -ljson -lpthread
# INC_FILE:=	$(addprefix -I, $(INC_DIR))
# CPP_FILE:= $(wildcard ./*.cpp) 
# #OBJS_HPP :=$(wildcard  $(INC_DIR)/*.hpp) $(wildcard $(INC_DIR)/*.h)
# TARGET:= DAU
# $(TARGET):$(CPP_FILE)
# 	$(CC) $(CPPFLAGS) -o $@ $(CPP_FILE) $(INC_FILE)
#    #$(LIBS)
# clean:
# 	rm -rf $(TARGET)

CC:= g++
EXE:= DAU
INC_DIR:=../#头文件路径
SRC_DIR:=./#编译主要文件路径
SRCS:=$(wildcard  $(SRC_DIR)/*.cpp) #当前路径
#LIBS:=-L ../lib   -lev #编译所有库的路径
CXXFLAGS:= -std=c++11   #编译选项
$(EXE):$(SRCS)
	$(CC) -g -Wall -ggdb -o $@ $^  $(addprefix -I, $(INC_DIR)) $(CXXFLAGS)
	
clean:
	rm $(EXE)


#g++ -g -Wall -ggdb -o dau.cpp 
#$(LIBS)

# CC = gcc
# CSAPP_INC = ./s
# CSAPP_SRC = ./
# CFLAGS = -Wall -O2 -I $(CSAPP_INC) -I .
# LDLIBS = -lpthread
# PROGS =	DAU\
# all: $(CSAPP_SRC)/csapp.o $(PROGS) 
# $(PROGS): $(CSAPP_SRC)/csapp.o
# $(CSAPP_SRC)/csapp.o: $(CSAPP_SRC)/csapp.c $(CSAPP_INC)/csapp.h
# # Convert text file in place between Windows and Linux EOL conventions
# windows2linux:
# 	perl -pi -e "s/\r\n/\n/g" eol.txt
# 	cat -v eol.txt

# linux2windows:
# 	perl -p -i -e "s/\n/\r\n/g" eol.txt
# 	cat -v eol.txt

# clean:
# 	rm -f $(PROGS) *.o *~
