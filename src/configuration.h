#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#define LISPY_MACOSX 0
#define LISPY_WINDOWS 1

#define LISPY_UNKNOWN 0xFFF

#if defined (__APPLE__) || defined(MACOSX)
    #define LISPY_OS LISPY_MACOSX
#elif defined(_WIN32) || defined(_WIN64)
    #define LISPY_OS LISPY_WINDOWS
#else
    #define LISPY_OS LISPY_UNKNOWN
#endif

#endif
