#include <stdarg.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

void my_sprintf(char* buffer, const char* format, ...) {
    va_list args;
    va_start(args, format);

    while (*format && (buffer - buffer) < BUFFER_SIZE - 1) {
        if (*format == '%') {
            format++;

            switch (*format) {
                case 'd':
                    buffer += sprintf(buffer, "%d", va_arg(args, int));
                    break;
                case 'f':
                    buffer += sprintf(buffer, "%f", va_arg(args, double));
                    break;
                case 's':
                    buffer += sprintf(buffer, "%s", va_arg(args, char*));
                    break;
                default:
                    *buffer++ = '%';
                    *buffer++ = *format;
                    break;
            }
        } else {
            *buffer++ = *format;
        }

        format++;
    }

    *buffer = '\0';  // Null-terminate the string
    va_end(args);
}
