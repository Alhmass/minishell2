/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** This Function concatenates two strings.
*/

#include <stdlib.h>
#include "../../includes/lib.h"

char *my_inv_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    char *final = malloc(sizeof(char) * ((dest_len + src_len) + 1));
    int i = 0;
    int k = 0;

    if (final == NULL)
        return (NULL);
    while (src[i] != '\0') {
        final[i] = src[i];
        i++;
    }
    while (dest[k] != '\0') {
        final[i] = dest[k];
        i++;
        k++;
    }
    final[i] = '\0';
    return (final);
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int x = 0;

    while (dest[x] != '\0') {
        x++;
    }
    while (src[i] != '\0') {
        dest[x] = src[i];
        x++;
        i++;
    }
    return (dest);
}

char *characters_cat(char *dest, char *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    char *final = malloc(sizeof(char) * ((dest_len + src_len) + 1));

    final = my_strcpy(final, dest);
    final = my_strcat(final, src);
    final[dest_len + src_len] = '\0';
    return (final);
}
