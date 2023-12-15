/*
 *
 */

#ifndef COMPILER_H
#define COMPILER_H

#include <stdio.h>

/* Compiler messages */
enum {
    COMPILER_FILE_COMPILED_OK,
    COMPILER_FAILED_WITH_ERRORS
};

/* State for compilation process */
struct compile_process {
    /* The flags in regards to how this file should be compiled */
    int flags;

    /* File to be compiled */
    struct compile_process_input_file {
        FILE* fp;
        const char* abs_path;
    } cfile;

    /* File to generate */
    FILE* ofile;
};

/* Prototypes */
int compile_file(const char* filename, const char* out_filename, int flags);
struct compile_process* compile_process_create(const char* filename, const char* filename_out, int flags);

#endif