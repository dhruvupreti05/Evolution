# Paths and libraries
SRCDIR = ./src
INCDIR = ./src/include
OBJDIR = ./build
LIBRARY = /opt/homebrew/Cellar/sfml/2.6.1

# Compiler settings
CC = g++
CXXFLAGS = -std=c++17 -I $(LIBRARY)/include -I $(INCDIR)
LDFLAGS = -L $(LIBRARY)/lib -lsfml-graphics -lsfml-window -lsfml-system


# Makefile targets
APPNAME = evolution

# Ensure the object directory exists
$(shell mkdir -p $(OBJDIR))

# Targets and dependencies
$(APPNAME): $(OBJDIR)/main.o $(OBJDIR)/player.o $(OBJDIR)/lake.o
	$(CC) $(OBJDIR)/main.o $(OBJDIR)/player.o $(OBJDIR)/lake.o $(LDFLAGS) -o $(APPNAME)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(INCDIR)/Player.h $(INCDIR)/lake.h
	$(CC) -c $(SRCDIR)/main.cpp $(CXXFLAGS) -o $(OBJDIR)/main.o

$(OBJDIR)/player.o: $(SRCDIR)/player.cpp $(INCDIR)/Player.h
	$(CC) -c $(SRCDIR)/player.cpp $(CXXFLAGS) -o $(OBJDIR)/player.o

$(OBJDIR)/lake.o: $(SRCDIR)/lake.cpp $(INCDIR)/lake.h
	$(CC) -c $(SRCDIR)/lake.cpp $(CXXFLAGS) -o $(OBJDIR)/lake.o

clean:
	rm -f $(OBJDIR)/*.o $(APPNAME)
