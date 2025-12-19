#ifndef FILE_IO_H
#define FILE_IO_H

#include "deque.h"
#define MAX_FILENAME_LENGTH (256)
#define TEST_MIN_VALUE (-10000)
#define TEST_MAX_VALUE (10000)

int save_deque_to_file(const char* filename, Deque* deque);
Deque* load_deque_from_file(const char* filename);

void generate_test_file(const char* filename, int size, int min_val, int max_val);
void generate_multiple_test_files(int base_count);

#endif