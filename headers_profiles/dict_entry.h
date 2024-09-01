#ifndef DICT_ENTRY_H
#define DICT_ENTRY_H

typedef struct s_dict_entry {
    int number;
    char *text;
} t_dict_entry;

void compare_inputs(t_dict_entry *entries, int dict_size);

#endif