CXX = g++ #Nazwa kompilatora C++
CXXFLAGS = -Wall -g #Opcje kompilatora 
FILES = *.cpp #Zbieracz plików
PROG = Lab06 #Definicja zmiennej o nazwie PROG i przypisanie jej wartosci main

ALL = "KOMPILUJE"
DEL = "USUWAM"
VAL = "BADAM PAMIEC"
all:
	reset
	@echo $(ALL)
	$(CXX)$(CXXFLAGS)-o $(PROG)$(FILES)  # tworze plik wykonywalny
	
clean:
	@echo $(DEL)
	rm -f $(PROG) # czyszcze plik wykonywalny
val:
	valgrind -v  ./$(PROG) # sprawdzam wycieki pamieci

