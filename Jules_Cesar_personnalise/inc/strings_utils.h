/* Header strings_utils.h. This file belongs to customized Jules Cesar algoithm 
 * Copyright 2019 Eric Bachard
 * this file is under GPL v2 license
 * This document is under GPL v2 License. See : http://www.gnu.org/licenses/gpl-2.0.html
 */

#ifndef __STRING_UTILS__H__
#define __STRING_UTILS__H__

int clear_string(char *);

void hash_letter(char, int *, int *);

void dehash_letter(char, int *, int *);

int hash_func(char *, int *);

int check_size(char *);

void new_word(char *, int *);

int new_string(char *, char *, int *, int *);

int refresh_screen(char *, char *, int *, int *);

int create_modified_string(char *, char *, int *, int *);

#endif /* __STRING_UTILS__H__ */


