#include "./headers_profiles/dict_entry.h"
#include "./headers_profiles/include_libs.h"

void compare_inputs(t_dict_entry *entries, int dict_size);

// Função para contar quantas linhas válidas existem no arquivo
int count_dict_size(char *content) {
    int count = 0;
    const char *ptr = content;
    while (*ptr) {
        if (*ptr == '\n') {
            count++;
        }
        ptr++;
    }
    return count;
}

// Função principal para ler e parsear o dicionário
int read_and_parse_dict(char *filename, t_dict_entry **dict_entries) {
    int fd, bytes_read;
    char buffer[4096];  // Buffer para ler o arquivo
    fd = open(filename, O_RDONLY);

    if (fd == -1) {
        write(1, "Erro ao abrir o arquivo", 23);
        return -1;
    }

    // Lê o conteúdo do arquivo
    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        close(fd);
        return -1;
    }
    buffer[bytes_read] = '\0';  // Garantir que a string é terminada com '\0'
    close(fd);

    int dict_size = count_dict_size(buffer);
    *dict_entries = malloc(dict_size * sizeof(t_dict_entry));
    // Parsear o conteúdo do dicionário
    char *line = buffer;
    char *next_line = 0;
    int i = 0;

    while (line) {
        char *current = line;
        next_line = '\0';
        
        // Procura o próximo '\n'
        while (*current != '\0') {
            if (*current == '\n') {
                *current = '\0';
                next_line = current + 1;
                break;
            }
            current++;
        }

        // Encontra o ':' separando o número do texto
        char *colon_pos = line;
        while (*colon_pos != '\0' && *colon_pos != ':') {
            colon_pos++;
        }

        if (*colon_pos == ':') {
            *colon_pos = '\0';
            (*dict_entries)[i].number = atoi(line); // Parte numérica
            (*dict_entries)[i].text = colon_pos + 1; // Parte textual
            i++;
        }
        line = next_line;
    }

    compare_inputs(*dict_entries, dict_size);

    return dict_size;
}

// Função para liberar a memória alocada
void free_dict_entries(t_dict_entry *dict_entries, int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        free(dict_entries[i].text);
    }
    free(dict_entries);
}