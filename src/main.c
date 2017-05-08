#include "configuration.h"

#include <stdio.h>
#include <stdlib.h>

#if LISPY_OS == LISPY_WINDOWS
static char input[2048];
#elif LISPY_OS == LISPY_MACOSX
// this header is included with OSX's command line tools
// Install it by doing xcode-select --install on the command line
#include <editline/readline.h>
#endif

int main(int argc, char** argv)
{
    /* Print version and exit information*/
    puts("Lispy version 0.0.1");
    puts("Press Ctrl+C to exit");

    while (1)
    {
#if LISPY_OS == LISPY_WINDOWS
        fputs("lispy> ", stdout);

        fgets(input, 2048, stdin);

        printf("You entered: %s", input);
#elif LISPY_OS == LISPY_MACOSX
        char* input = readline("lispy> ");

        add_history(input);

        printf("You entered: %s", input);

        free(input);
#endif
    }

    return 0;
}
