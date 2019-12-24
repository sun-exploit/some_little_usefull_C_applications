/* efface_ecran.c                                                   *
 * Auteur : Eric Bachard  version originale : 2004   */

/* 

Document under The MIT License (MIT)

Copyright (c) 2004-2019 Eric Bachard

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/


#define _GNU_SOURCE
#include <stdio.h> 
#include <stdlib.h> 
#include "efface_ecran.h"

/* ---------efface_ecran------------ */

void efface_ecran(void)
{
    // ce qui suit remplace :
    // system("clear");

    FILE * stdout = popen("clear", "w");
    int anErr = pclose( stdout) ;

    if (anErr != 0 ) 
       fprintf(stderr,"problem with clear\n");
}

