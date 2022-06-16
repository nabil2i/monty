#include "monty.h"

/**
 * count - counts the number of tokens contained in a string
 * @str: string to check
 *
 * Return: number of words
 */
int count(char *str)
{
	int i = 0, flag = 0, ntokens = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			flag = 0;
		}
		else if (flag == 0)
		{
			ntokens++;
			flag = 1;
		}
	}
	return (ntokens);
}

/**
 * tokenizer - splits a string into tokens
 * @str: string to split
 *
 * Return: a pointer to an array of tokens
 */
char **tokenizer(char *str)
{
	char **tokens, *temp_token;
	int i, num_tokens, len, num_characters = 0, first_character, end_character, j;

	j = 0;
	len = strlen(str);
	num_tokens = count(str);
	if (num_tokens <= 0)
		return (NULL);
	tokens = (char **)malloc(sizeof(char *) * (num_tokens + 1));
	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n')
		{
			if (num_characters != 0)
			{
				end_character = i;
				temp_token = (char *)malloc(sizeof(char) * (num_characters + 1));
				if (!temp_token)
				{
					return (NULL);
				}
				while (first_character < end_character)
				{
					*temp_token++ = str[first_character++];
				}
				*temp_token = '\0';
				tokens[j] = temp_token - num_characters;
				j++;
				num_characters = 0;
			}
		}
		else
		{
			if (num_characters == 0)
				first_character = i;
			num_characters++;
		}
	}
	tokens[j] = NULL;
	return (tokens);
}
