CC = g++
RM = rm -f

FLAGS =
LANGUAGE = c++11
TARGET = results_presentation

INCLUDE = -I ./include

ODIR = ./bin
SRC = ./src

CPPS = $(wildcard $(SRC)/*.cpp)
OBJS = $(addprefix $(ODIR)/,$(notdir $(CPPS:.cpp=.o)))

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(FLAGS) -std=$(LANGUAGE) ./$^ $(SFML) -o $(ODIR)/$@

$(ODIR)/%.o: $(SRC)/%.cpp
	$(CC) $(FLAGS) -c $(GS2DINCLUDE) $(INCLUDE) ./$< -o ./$@

clean :
	$(RM) $(ODIR)/*.o $(ODIR)/$(TARGET)
