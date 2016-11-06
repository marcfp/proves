CC=g++
C_BUILD=-std=c++11 -I  
C_BUILD_DIRECTORI=/home/marc/Programació/proves
SOURCE_calculadora=calculator01_\{\}.cpp
OUTPUT_calculadora=-o calculator01_\{\}
ECHO=@echo #echoing
CALCULADORA=COMPILACIÓ DE LA CALCULADORA
all:
	$(ECHO) "compilació : make calculadora01"

calculadora01:
	$(ECHO)  $(CALCULADORA) 
	$(CC) $(C_BUILD)$(C_BUILD_DIRECTORI) $(SOURCE_calculadora) $(OUTPUT_calculadora) 
#calculator01_\{\}.cpp -o calculator01_\{\} #$(SOURCE) $(OUTPUT)
