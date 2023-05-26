#include"assambler.h"
/*===================================================================================================================================================================*/
char* add_ext_to_filename(const char* filename, const char* ext) {
    
    const char* am_ext = ".am";
    size_t am_ext_len = strlen(am_ext);
    size_t filename_len = strlen(filename);
    if (filename_len > am_ext_len &&
        strcmp(filename + filename_len - am_ext_len, am_ext) == 0) {
        filename_len -= am_ext_len;
    }

    
    size_t new_ext_len = strlen(ext);
    size_t new_filename_len = filename_len + new_ext_len + 1;
    char* new_filename = (char*)malloc(new_filename_len);
    if (new_filename == NULL) {
        printf(" Error: Failed to allocate memory for new filename\n");
        exit(1);
    }

    
    strncpy(new_filename, filename, filename_len);
    strcpy(new_filename + filename_len, ext);

    return new_filename;
}

/*===================================================================================================================================================================*/





