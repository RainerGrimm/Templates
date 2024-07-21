CC=g++

LFLAGS=-O3 -std=c++20 -pthread

SRCDIR=.
OBJDIR=obj
BINDIR=bin

# the source files
SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
EXECUTABLES := $(SOURCES:$(SRCDIR)/%.cpp=$(BINDIR)/%)


all: $(EXECUTABLES)	


$(EXECUTABLES): $(BINDIR)/% : $(OBJDIR)/%.o
	$(CC)  $(LFLAGS) $< -o $@

	
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) -c $(LFLAGS) $< -o $@
	
	
clean: 
	rm -f   $(BINDIR)/* $(OBJDIR)/*.o
