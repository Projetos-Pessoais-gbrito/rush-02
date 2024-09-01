#include "./headers_profiles/dict_entry.h"
#include "./headers_profiles/include_libs.h"

int process_dictionary(char *filename);

void receive_inputs(int argc, char *argv[])
{
    printf("entrei");
    while(argv[argc - 1])
    {
        printf("%s", argv[argc - 1]);
        argv[argc - 1]++;
    }
}

int main(int argc, char *argv[]) {
    int result = process_dictionary("numbers.dict");
    if(argc > 1)
    {
        printf("%s", argv[1]);
    }
    return result;
}
