#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30

void setWordAndFunc(char *line, char *word, char *func)
{
    char *currLetter = '\0';
    int index = 0;
    currLetter = line;
    while (*currLetter != ' ')
    {
        word[index++] = *currLetter++;
    }
    *func = *(currLetter + 1);
}

void a(char *line, char *word)
{
    int length = strlen(word);
    char *wordPtr = word;
    char *linePtr = line;
    for (char *ptr = line; *ptr != '\n'; ptr++)
    {
        int count = 0;
        while (*linePtr == *wordPtr && count != length)
        {
            count++;
            linePtr++;
            wordPtr++;
        }
        if (count == length)
        {
            printf("%s", line);
            return;
        }
        linePtr = ptr;
        wordPtr = word;
    }
}

void b(char *line, char *word)
{
    int length = strlen(word);
    int lineWordLength = 0;
    for (char *p = strtok(line, " "); p != NULL; p = strtok(NULL, " "))
    {
        int isRemovedLetter = 0;
        int count = 0;
        char *linePtr = p;
        char *wordPtr = word;
        while ((*wordPtr == *linePtr || !isRemovedLetter) && *wordPtr != 0 && *linePtr != 0)
        {
            if (*wordPtr != *linePtr)
            {
                isRemovedLetter = 1;
                linePtr++;
                continue;
            }
            count++;
            wordPtr++;
            linePtr++;
        }
        if (length == count && (*linePtr == 0 || isRemovedLetter == 0))
        {
            p[strcspn(p, "\n")] = 0;
            puts(p);
        }
    }
}

int main()
{
    char *line = NULL;
    size_t size;
    int firstLine = 1;
    char func = '\0';
    char word[WORD] = {0};
    while (getline(&line, &size, stdin) != -1)
    {
        if (firstLine)
        {
            setWordAndFunc(line, word, &func);
            firstLine = 0;
        }
        else
        {
            if (func == 'a')
            {
                a(line, word);
            }
            else
            {
                b(line, word);
            }
        }
    }
}
