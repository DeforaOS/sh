/* $Id$ */
/* Copyright (c) 2004-2014 Pierre Pronchery <khorben@defora.org> */
/* This file is part of DeforaOS Unix sh */
/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. */



#ifndef SH_SCANNER_H
# define SH_SCANNER_H

# include <stdio.h>
# include "token.h"
# include "sh.h"


/* Scanner */
/* types */
typedef enum _ScannerPrompt { SP_PS1 = 0, SP_PS2, SP_PS4 } ScannerPrompt;
# define SP_LAST SP_PS4
# define SP_COUNT (SP_LAST + 1)

typedef struct _Scanner
{
	FILE * fp;
	ScannerPrompt prompt;
	const char * string;
	int (*next)(struct _Scanner *);
} Scanner;


/* functions */
void scanner_init(Scanner * scanner, Prefs * prefs, FILE * fp,
		char const * string);

Token * scanner_next(Scanner * scanner);

#endif /* !SH_SCANNER_H */
