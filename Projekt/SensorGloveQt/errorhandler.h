#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

/*!
 * \file
 * \brief Definicja klasy ErrorHandler
 *
 * Plik zawiera definicję klasy ErrorHandler
 *
 */

/*!
 * \brief Klasa obsługująca błędy i wyjątki
 *
 */
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
