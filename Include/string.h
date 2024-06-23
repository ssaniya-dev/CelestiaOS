#ifndef __STRING_H
#define __STRING_H

#include "../Include/types.h"
#include "../Structures/list.h"
#include "func.h"

// From: https://github.com/szhou42/osdev

int memcmp(uint8_t *data1, uint8_t *data2, int n);

void *memcpy(void *dst, const void *src, int n);

void *memset(void *dst, char val, int n);

uint16_t *memsetw(uint16_t *dest, uint16_t val, uint32_t count);

uint16_t *memsetdw(uint32_t *dest, uint32_t val, uint32_t count);

int strlen(const char *s);

char *strncpy(char *destString, const char *sourceString, int maxLength);

int strcmp(const char *dst, char *src);

int strcpy(char *dst, const char *src);

void strcat(void *dest, const void *src);

int strncmp(const char *s1, const char *s2, int c);

char *strstr(const char *in, const char *str);

void itoa(char *buf, unsigned long int n, int base);

int atoi(char *string);

int isspace(char c);

int isprint(char c);

char *strdup(const char *src);

char *strsep(char **stringp, const char *delim);

list_t *str_split(const char *str, const char *delim, unsigned int *numtokens);

char *list2str(list_t *list, const char *delim);

#endif