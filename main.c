#include "./headers_profiles/dict_entry.h"
#include "./headers_profiles/include_libs.h"

int read_and_parse_dict(char *filename, t_dict_entry **dict_entries);

void free_dict_entries(t_dict_entry *dict_entries, int dict_size);

int process_dictionary(char *filename) {
    t_dict_entry *dict_entries = NULL;
    int dict_size = read_and_parse_dict(filename, &dict_entries);
    
    if (dict_size == -1) {
        write(1, "Dict Error\n", 11);
        return 1;
    }
    
    // Aqui você pode adicionar mais lógica para processar o dicionário, se necessário
    
    free_dict_entries(dict_entries, dict_size);
    return 0;
}

int main() {
    int result = process_dictionary("numbers.dict");
    return result;
}
