#include "includes.h"

ErrorHandler::ErrorHandler()
{

}

void ErrorHandler::ExceptionHandler(ErrorHandler::ErrorType_t p_errorType)
{
    switch(p_errorType)
    {
    case ErrorType_t::NegativeAngle:
        std::cerr<<"Cannot set negative angle for fingers"<<std::endl;
        //zmienić na message box
        break;
    }
}
