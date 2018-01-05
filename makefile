#Writen by Carlos Santos
#09-28-17
#Used for byte extraction on the Mormon geneoligy dbf file

TARGET=./src/runner.cpp
OUTPUT=./read.out
INFO =./src/info.cpp
EXTRACT = ./src/extract.cpp

FILE=./src/F1.DBF
LEN=-1
MODE=1
DUMP_NUM=-1
R1=33
R2=186
RANGE=10

#default command when running make
default: compile clears

#Compiles Main
compile: 
	g++ $(INFO) $(EXTRACT) $(TARGET) -o $(OUTPUT) 
#clear screen
clears:
	clear
#runs program version 1
run-1:
	$(OUTPUT) $(FILE) $(LEN) $(MODE) $(DUMP_NUM) $(R1) $(R2) $(RANGE)
#runs program version 2
run-2:
	$(OUTPUT) $(FILE) $(LEN) $(MODE) $(DUMP_NUM) $(R1) $(R2) $(RANGE)      
#Cleans
clean:
	rm $(OUTPUT) 
