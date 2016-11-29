CC=g++
C_BUILD=-std=c++11 -I  
C_BUILD_DIRECTORI=/home/marc/Programació/proves
SOURCE_calculadora=calculator01_\{\}.cpp
OUTPUT_calculadora=-o calculator01_\{\}
calculadora=calculator01_\{\}
ECHO=@echo #echoing
RM=rm
CALCULADORA=COMPILACIÓ DE LA CALCULADORA
all:
	$(ECHO) "Per compilar :"
	$(ECHO) "		 make calculadora01"
	$(ECHO) "Per esborrar : "
	$(ECHO) "		make rm_calculadora01"

calculadora01:
	$(ECHO)  $(CALCULADORA) 
	$(CC) $(C_BUILD) $(C_BUILD_DIRECTORI) $(SOURCE_calculadora) $(OUTPUT_calculadora) 
rm_calculadora01:
	$(RM) $(calculadora)	
#calculator01_\{\}.cpp -o calculator01_\{\} #$(SOURCE) $(OUTPUT)

recompila:
	$(RM) $(calculadora)
	$(CC) $(C_BUILD) $(C_BUILD_DIRECTORI) $(SOURCE_calculadora) $(OUTPUT_calculadora) 
