#include "exception.hpp"

MenuException::MenuException(const char* message){
        m = message;
}
const char* MenuException::what() const noexcept{
        return m;
}

