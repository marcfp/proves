CC=g++
C_BUILD=-std=c++11 -I  
C_BUILD_DIRECTORI=/home/marc/Programació/proves
SOURCE=calculator01\{\}.cpp
OUTPUT=-o calculator01\{\}
calculadora01:
	#g++  -std=c++11 -I /home/marc/Programació/proves calculator01_\{\}.cpp -o calculator01_\{\} 
	$(CC) $(C_BUILD)$(C_BUILD_DIRECTORI) calculator01_\{\}.cpp -o calculator01_\{\} #$(SOURCE) $(OUTPUT)
