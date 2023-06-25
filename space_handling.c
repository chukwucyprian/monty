#include "monty.h"
/**
 * remove_new_line - removes new line character
 * @str: string
 * Return: nothing
 */
void remove_new_line(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '\t')
			str[i] = ' ';
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
}
/**
 * space_handle - removes excess spaces
 * @str: buffer or string
 * Return: nothing
 */
void space_handle(char *str)
{
	int len, j = 0, i = 0;
	char strc[250];

	for (len = 0; str[len] != '\0'; len++)
		;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	if (len)
	{
		len--;
		while (str[len] == ' ' && len >= 0)
			str[len--] = '\0';
	}
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			strc[j++] = str[i];
		if (str[i] == ' ' && str[i + 1] != ' ')
			strc[j++] = str[i];
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			strc[j++] = ' ';
			while (str[i] == ' ')
				i++;
			strc[j++] = str[i];
		}
		i++;
	}
	strc[j] = str[i];
	for (i = 0; str[i] != '\0'; i++)
	if (i > 0)
	{
		i--;
		while (str[i])
			str[i--] = '\0';
	}
	if (strc[0])
		strcpy(str, strc);
}

