// headers.h
#ifndef HEADERS_H
#define HEADERS_H

#ifdef _WIN32
#include <io.h> 
#include <stdlib.h>   // Para malloc, free
#include <fcntl.h>    // Para open      // Para Windows (_open, _read, _write)
#include <stdio.h>
#else
#include <unistd.h>   // Para Unix/Linux (write, read, close)
#endif

#include <stdlib.h>   // Para malloc, free
#include <fcntl.h>    // Para open (disponível em ambos)

#endif // HEADERS_H
