/* token.c */



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "token.h"


/* Token */
Token * token_new(TokenCode code, char * string)
{
	Token * token;

#ifdef DEBUG
	fprintf(stderr, "token_new(%d, \"%s\")\n", code, string);
#endif
	if((token = malloc(sizeof(Token))) == NULL)
	{
		perror("malloc");
		return NULL;
	}
	token->code = code;
	if((token->string = strdup(string)) == NULL)
	{
		perror("strdup");
		free(token);
		return NULL;
	}
	return token;
}


void token_delete(Token * token)
{
	free(token->string);
	free(token);
}