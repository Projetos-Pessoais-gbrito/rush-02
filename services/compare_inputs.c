#include "../headers_profiles/dict_entry.h"
#include "../headers_profiles/include_libs.h"



void compare_inputs(t_dict_entry *entries, int dict_size)
{
    // Declarar uma variável do tipo t_dict_entry
    int i = 0;
    while (i < dict_size - 40) {
        printf("Number: %d, Text: %s\n", entries[i].number, entries[i].text);
        i++;
    }

}