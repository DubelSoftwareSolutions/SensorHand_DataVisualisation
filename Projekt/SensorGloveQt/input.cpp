#include "includes.h"

Input::Input():m_ConnectionType(USBConnection)
{

}

void Input::ChangeConnectionType(Input::ConnectionType_t p_ConnecitonType)
{
    m_ConnectionType=p_ConnecitonType;
}
