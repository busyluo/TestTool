#ifndef UTILS_H
#define UTILS_H

#define DISABLE_COPY(Class) \
    Class(const Class &) = delete;\
    Class &operator=(const Class &) = delete;

#endif // UTILS_H
