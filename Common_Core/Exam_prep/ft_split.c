#include <stdlib.h>

int word_len(char *str, int i)
{
    int len;

    len = 0;
    while(str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
    {
        len++;
        i++;
    }
    return (len);
}

int word_count(char *str)
{
    int i;
    int word;
    int count;

    i = 0;
    word = 0;
    count = 0;
    while (str[i])
    {
        if (word == 0 && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            count++;
            word = 1;
        }
        else if (word == 1 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            word = 0;
        i++;
    }
    return (count);
}

char    **ft_split(char *str)
{
    char    **tab;
    int     words;
    int     len;
    int     i;
    int     j;
    int     k;

    words = word_count(str);
    tab = malloc((words + 1) * sizeof(char *));
    if (!tab)
        return (NULL);
    k = 0;
    while (str[k] && (str[k] == ' ' || str[k] == '\t' || str[k] == '\n'))
        k++;
    i = 0;
    while (str[k] && i < words)
    {
        len = word_len(str, k);
        tab[i] = malloc(len + 1);
        if (!tab[i])
            return (NULL);
        j = 0;
        while (len > 0)
        {
            tab[i][j] = str[k];
            j++;
            k++;
            len--;
        }
        tab[i][j] = '\0';
        while (str[k] && (str[k] == ' ' || str[k] == '\t' || str[k] == '\n'))
            k++;
        i++;
    }
    tab[i] = NULL;
    return (tab);
}

