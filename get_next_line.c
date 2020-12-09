#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

#define BUFFER_SIZE 1024

int     ft_strlen(const char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}
int ft_count(char *s)
{
    int i =0;
    while (s[i] && s[i] != '\n')
        i++;
    return(i);
}
char    *ft_stock(char *line, char *buff, int i)
{
    int j =0; char *newline; int len=0;
    len = (line ? ft_strlen(line) : 0);
    newline = malloc(len + i + 1);
    while (j < len)
        newline[j] = line[j], j++;
    if (line)
        free(line);
    while (j < len +i)
        newline[j] = buff[j - len], j++;
    newline[j] = '\0';
    return(newline);
}

int get_next_line(char **line)
{
    int i = 0; int ret =0; static char *str; char *buff; char *tmp;
    *line = ft_stock(NULL,"",0);
    if (str)
    {
        i = ft_count(str);
        *line = ft_stock(*line, str, i);
        if (str[i] == '\n')
        {
            tmp = str;
            str = ft_stock(0, str + i + 1, ft_strlen(str) - i - 1);
            free(tmp); tmp = NULL;
            return(1);
        }
        free(str); str=NULL;
    }
    buff = malloc(BUFFER_SIZE + 1);
    while ((ret = (read(0, buff, BUFFER_SIZE))))
    {
        if (ret == -1)
            return (-1);
        if (buff[ret] != -1)
            buff[ret] = '\0';
        i = ft_count(buff);
        *line = ft_stock(*line, buff,i);
        if (buff[i] == '\n')
        {
            str = ft_stock(str, buff + i + 1, ret -i-1);
            free(buff); buff = NULL;
            return(1);
        }
    }
    free(buff); buff = NULL;
    return(0);
}