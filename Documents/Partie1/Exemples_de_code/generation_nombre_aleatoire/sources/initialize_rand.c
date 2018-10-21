#include <stdlib.h>
#include <time.h>
#include "initialize_rand.h"

void initialize_rand(void)
{
    time_t  t1;
    (void)time(&t1);
    srand(t1);

}