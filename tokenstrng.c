#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_len(char *str, char *delims);
int get_word_cnt(char *str, char *delims);
int *get_next_wrd(char *str, char *delims);

/**
 * strtow - takes a string and separates its words
 * @str: string to separate into words
 * @delims: delimitors to use to delimit words
 * Return: 2D array pointers
 */
char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int WC, wrdlen, h, y = 0;

	if (str == NULL || !*str)
		return (NULL);
	WC = get_word_cnt(str, delims);

	if (WC == 0)
		return (NULL);
	words = malloc((WC + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (y < WC)
	{
		wrdlen = get_word_len(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_wrd(str, delims);
		}
		words[y] = malloc((wrdlen + 1) * sizeof(char));
		if (words[y] == NULL)
		{
			while (y >= 0)
			{
				y--;
				free(words[y]);
			}
			free(words);
			return (NULL);
		}
		h = 0;
		while (h < wrdlen)
		{
			words[y][h] = *(str + h);
			h++;
		}
		words[y][h] = '\0';
		str = get_next_wrd(str, delims);
		y++;
	}
		words[y] = NULL;
		return (words);
}

/**
 * is_delim - checks if stream hes delimitor char
 * @ch: character in stream
 * @delims: pointer to null terminated array of delimitors
 * Return: 1 (success) 0 (failure)
 */
int is_delim(char ch, char *delims)
{
	int y = 0;

	while (delims[y])
	{
		if (delims[y] == ch)
			return (1);
		y++;
	}
	return (0);
}

/**
 * get_word_len - gets the word length of cur word in str
 * @str: string to get word len from current word
 * @delims: delimitors to use to delimit words
 * Return: word length of curent wrd
 */
int get_word_len(char *str, char *delims)
{
	int wdlen = 0, pending = 1, y = 0;

	while (*(str + y))
	{
		if (is_delim(str[y], delims))
			pending = 1;
		else if (pending)
		{
			wdlen++;
		}
		if (wdlen > 0 && is_delim(str[y], delims))
			break;
		y++;
	}
	return (wdlen);
}

/**
 * get_word_cnt - gets the word cnt of a string
 * @str: string to get word count from
 * @delims: delinitors to use to delimit words
 * Return: the word count of the string
 */
int get_word_cnt(char *str, char *delims)
{
	int WC = 0, pending = 1, y = 0;

	while (*(str + y))
	{
		if (is_delim(str[y], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			WC++;
		}
		y++;
	}
	return (WC);
}

/**
 * get_next_wrd - gets the next word in string
 * @str: string to get word count from
 * @delims: delinitors to use to delimit words
 * Return: pointer to first char of next wrd
 */

int *get_next_wrd(char *str, char *delims)
{
	int pending = 0;
	int y = 0;

	while (*(str + y))
	{
		if (is_delim(str[y], delims))
			pending = 1;
		else if (pending)
			break;
		y++;
	}
	return (str + y);
}
