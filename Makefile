# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -Werror

# Nome do executável final
TARGET = rush_02

# Lista de arquivos-fonte
SRCS = main.c ./services/compare_inputs.c ./services/process_data.c

# Gerar uma lista de arquivos-objeto correspondentes
OBJS = $(SRCS:.c=.o)

# Diretório dos headers
HEADERS_DIR = ./headers_profiles

# Include das bibliotecas necessárias
INCLUDES = -I$(HEADERS_DIR)

# Regra padrão para compilar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

# Regra para compilar arquivos .c em arquivos .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Limpar os arquivos de objeto e o executável
clean:
	rm -f $(OBJS)

# Limpar completamente, incluindo o executável
fclean: clean
	rm -f $(TARGET)

# Recompilar tudo do zero
rebuild: fclean $(TARGET)

# Regra para executar o programa com argumentos
run: $(TARGET)
	./$(TARGET) $(ARGS)

# Regra para executar o programa sem argumentos (usando o arquivo padrão)
run_default: $(TARGET)
	./$(TARGET)

.PHONY: clean fclean rebuild run run_default
