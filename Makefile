# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinc  # -Iinc указывает путь к заголовочным файлам

# Папки с исходниками и объектными файлами
SRC_DIR = src
OBJ_DIR = obj

# Главный исполняемый файл
TARGET = ProjectForWork.exe

# Исходные файлы (.c) и объектные файлы (.o)
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Сборка всего проекта
all: $(TARGET)

# Компоновка (собираем ProjectForWork.exe из объектных файлов)
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Компиляция каждого .c в .o (создаём obj/, если его нет)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Создание папки для объектных файлов (если её нет)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Очистка (удаляет объектные файлы и ProjectForWork.exe)
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
