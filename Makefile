# Компилятор
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Директории
SRC_DIR = .
BIN_DIR = bin

# Исходные файлы и объектные файлы
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/Logger.cpp
OBJS = $(SRCS:.cpp=.o)

# Имя исполняемого файла
TARGET = $(BIN_DIR)/app

# Цель по умолчанию
all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR) *.o