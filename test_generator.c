#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>   
#include <ctype.h>    
#include "deque.h"
#include "file_io.h"
#include "sorting.h"
#include "inout.h"
int main() {
    printf("Генератор тестовых данных для дека\n");
    srand(time(NULL));
    
    int choice;
    do {
        printf("\n1. Сгенерировать один тестовый файл\n");
        printf("2. Сгенерировать серию файлов для сравнения\n");
        printf("3. Выйти\n");
        printf("Выберите опцию: ");
        
        char choice_str[MAX_CHOICE_LENGTH];
        if (fgets(choice_str, sizeof(choice_str), stdin) == NULL) {
            printf("Ошибка чтения ввода!\n");
            continue;
        }
        
        choice_str[strcspn(choice_str, "\n")] = '\0';
        
        int is_number = 1;
        for (int i = 0; choice_str[i] != '\0'; i++) {
            if (!isdigit((unsigned char)choice_str[i])) {
                is_number = 0;
                break;
            }
        }
        
        if (!is_number) {
            printf("Ошибка: введите число от 1 до 3!\n");
            continue;
        }
        
        choice = atoi(choice_str);
        
        if (choice == 1) {
            int size, min, max;
            char filename[MAX_FILENAME_LENGTH];
            
            printf("Введите имя файла: ");
            if (fgets(filename, sizeof(filename), stdin) == NULL) {
                printf("Ошибка ввода имени файла!\n");
                continue;
            }
            filename[strcspn(filename, "\n")] = '\0';
            
            printf("Введите количество чисел: ");
            char size_str[MAX_CHOICE_LENGTH];
            if (fgets(size_str, sizeof(size_str), stdin) == NULL) {
                printf("Ошибка ввода размера!\n");
                continue;
            }
            
            size_str[strcspn(size_str, "\n")] = '\0';
            int valid_size = 1;
            for (int i = 0; size_str[i] != '\0'; i++) {
                if (!isdigit((unsigned char)size_str[i])) {
                    valid_size = 0;
                    break;
                }
            }
            
            if (!valid_size) {
                printf("Ошибка: размер должен быть числом!\n");
                continue;
            }
            
            size = atoi(size_str);
            
            printf("Введите минимальное значение: ");
            char min_str[MAX_CHOICE_LENGTH ];
            if (fgets(min_str, sizeof(min_str), stdin) == NULL) {
                printf("Ошибка ввода минимального значения!\n");
                continue;
            }
            
            min_str[strcspn(min_str, "\n")] = '\0';
            int valid_min = 1;
            int has_minus = 0;
            for (int i = 0; min_str[i] != '\0'; i++) {
                if (i == 0 && min_str[i] == '-') {
                    has_minus = 1;
                    continue;
                }
                if (!isdigit((unsigned char)min_str[i])) {
                    valid_min = 0;
                    break;
                }
            }
            
            if (!valid_min) {
                printf("Ошибка: минимальное значение должно быть числом!\n");
                continue;
            }
            
            min = atoi(min_str);
            
            printf("Введите максимальное значение: ");
            char max_str[MAX_CHOICE_LENGTH ];
            if (fgets(max_str, sizeof(max_str), stdin) == NULL) {
                printf("Ошибка ввода максимального значения!\n");
                continue;
            }
            
            max_str[strcspn(max_str, "\n")] = '\0';
            int valid_max = 1;
            has_minus = 0;
            for (int i = 0; max_str[i] != '\0'; i++) {
                if (i == 0 && max_str[i] == '-') {
                    has_minus = 1;
                    continue;
                }
                if (!isdigit((unsigned char)max_str[i])) {
                    valid_max = 0;
                    break;
                }
            }
            
            if (!valid_max) {
                printf("Ошибка: максимальное значение должно быть числом!\n");
                continue;
            }
            
            max = atoi(max_str);
            
            if (max <= min) {
                printf("Ошибка: максимальное значение должно быть больше минимального!\n");
                continue;
            }
            

            Deque* deque = create_deque();
            for (int i = 0; i < size; i++) {
                push_rear(deque, min + rand() % (max - min + 1));
            }
            

            if (save_deque_to_file(filename, deque)) {
                printf("Создан файл: %s с %d элементами\n", filename, size);
            } else {
                printf("Ошибка сохранения файла!\n");
            }
            
            delete_deque(deque);
            
        } else if (choice == 2) {
            printf("Создание серии тестовых файлов...\n");
            generate_multiple_test_files(5);
            
        } else if (choice != 3) {
            printf("Неверный выбор! Введите число от 1 до 3.\n");
        }
        
    } while (choice != 3);
    
    return 0;
}