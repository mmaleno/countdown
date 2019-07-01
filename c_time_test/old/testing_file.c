// file to test things in

#include <stdio.h>

//#define TESTING_PARAM = 0;

#if defined(__linux__)
    #define TESTING_PARAM 5
#elif defined(__unix__) || defined(__APPLE__) && defined(__MACH__)
    #define TESTING_PARAM 6
#endif

int main()
{
/*
int big = 360;

int quotient = 399 / 100;

printf("%d\n", quotient);
*/

printf("%d\n", TESTING_PARAM);

return 0;

}
