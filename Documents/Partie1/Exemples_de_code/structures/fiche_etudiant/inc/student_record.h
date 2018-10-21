#define MAX_BUFFER_SIZE 512

struct record
{
    char identity[MAX_BUFFER_SIZE];
    short int birthdate;
    double moyenne;

};

typedef struct record RECORD;
