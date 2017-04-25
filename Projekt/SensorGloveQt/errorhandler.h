#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H


class ErrorHandler
{
public:
    enum ErrorType_t
    {
        NegativeAngle=0
    };

    ErrorHandler();

    void ExceptionHandler(ErrorType_t p_errorType);
};

#endif // ERRORHANDLER_H
