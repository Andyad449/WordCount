#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ��������
void count_characters(const char* filename);
void count_words(const char* filename);

// ������
int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c|-w] <input_file_name>\n", argv[0]);
        return 1;
    }

    const char* parameter = argv[1];
    const char* filename = argv[2];

    if (strcmp(parameter, "-c") == 0) {
        count_characters(filename);
    }
    else if (strcmp(parameter, "-w") == 0) {
        count_words(filename);
    }
    else {
        printf("��Ч�Ĳ�����ʹ��-c��ͳ���ַ�����-w��ͳ�Ƶ�������\n");
        return 1;
    }

    return 0;
}

// ͳ���ַ����ĺ���
void count_characters(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int character_count = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        character_count++;
    }

    fclose(file);
    printf("�ַ�����%d\n", character_count);
}

// ͳ�Ƶ������ĺ���
void count_words(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int word_count = 0;
    int in_word = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch) || ch == ',') {
            if (in_word) {
                in_word = 0;
                word_count++;
            }
        }
        else {
            in_word = 1;
        }
    }
    if (in_word) {
        word_count++;
    }

    fclose(file);
    printf("��������%d\n", word_count);
}
