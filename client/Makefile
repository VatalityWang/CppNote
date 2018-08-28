
EXE:= client
INC_DIR:= ./
SRC_DIR:= ./
SRCS:= $(wildcard $(SRC_DIR)/*.cpp)
LIBS:=-L ./lib   -lpthread
CXXFLAGS:= -std=c++11 -g

$(EXE):$(SRCS)
	g++ -g -o $@ $^  $(LIBS) $(addprefix -I, $(INC_DIR)) $(CXXFLAGS)
clean:
	rm client
