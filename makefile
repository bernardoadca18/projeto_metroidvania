# Nome do executável
EXECUTABLE := main

# Compilador e flags
CXX := g++-12
CXXFLAGS := -g -std=c++20 -w
LDFLAGS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Diretório dos arquivos headers
INCLUDE_DIR := ./src/include

# Diretório de saída para o executável
OUTPUT_DIR := ./src/build

# Arquivos fonte
# SOURCES := src/main.cpp $(wildcard src/include/*.cpp)
SOURCES := src/main.cpp $(shell find src/include -name '*.cpp')

# Objetos gerados a partir dos arquivos fonte
OBJECTS := $(SOURCES:.cpp=.o)

# Escaneando o diretório de cabeçalhos e listando os arquivos
#HEADERS := $(wildcard $(INCLUDE_DIR)/*.h)
HEADERS := $(shell find $(INCLUDE_DIR) -name '*.h')

# Regra para compilar os objetos
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Regra para linkar os objetos e gerar o executável
$(EXECUTABLE): $(OBJECTS)
	mkdir -p ${OUTPUT_DIR}
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(OUTPUT_DIR)/$(EXECUTABLE) $(LDFLAGS)
	find src -name "*.o" -type f -delete

# Limpar arquivos intermediários
clean:
	find src -name "*.o" -type f -delete
#	rm -f $(OBJECTS)

# Limpar tudo (objetos e executável)
clean-all: clean
	rm -f $(OUTPUT_DIR)/$(EXECUTABLE)
