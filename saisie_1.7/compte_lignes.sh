#!/bin/bash

echo  "Nombre de lignes au total :" $(( `cat sources/*.c | wc -l` + `cat inc/*.h | wc -l` ))

echo  "Nombre de fprintf() utilisés :" `cat sources/*.c | grep fprintf | wc -l`

echo  "Nombre de #define utilisés :" $(( `cat sources/*.c | grep \#define | wc -l` + `cat inc/*.h | grep \#define | wc -l` ))


