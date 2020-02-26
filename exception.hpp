#ifndef exception_hpp
#define exception_hpp

#include <exception>

struct MenuException: public std::exception{
    const char* m;
    MenuException(const char* message);
    const char* what() const noexcept;
};

#endif /* exception_hpp */

