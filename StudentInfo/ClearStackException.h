#ifndef CLEAR_STACKK_EXCEPTION_H_
#define CLEAR_STACKK_EXCEPTION_H_
#include <exception>
#include <string>
class ClearStackException  : public std::exception
{
private:
    /* data */
    std::string myMsg;
public:
    ClearStackException(std::string);
    const char * what() const  override;
    ~ClearStackException() =default;
};
const char * ClearStackException::what() const  
{
    return myMsg.c_str();
}
ClearStackException::ClearStackException(std::string msg)
{
    myMsg = msg;
}




#endif