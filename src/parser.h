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



#ifndef SH_PARSER_H
# define SH_PARSER_H

# include <stdio.h>
# include "sh.h"


/* functions */
int parser(Prefs * prefs, char const * string, FILE * fp, int argc,
		char * argv[]);

#endif /* !SH_PARSER_H */
