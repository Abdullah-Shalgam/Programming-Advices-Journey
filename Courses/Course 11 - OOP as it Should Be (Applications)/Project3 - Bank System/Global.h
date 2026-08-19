#pragma once
#include <string>

namespace Global
{
    inline const std::string AppName = "Core Banking Suite";
    inline const std::string AppVersion = "v2.5.0";
    inline const std::string CompanyName = "SecureBank Systems Inc.";

    inline const short MaxLoginAttempts = 3;
    inline const short EncryptionKey = 10;

    inline const std::string ClientsFilePath = "Clients.txt";
    inline const std::string UsersFilePath = "Users.txt";
    inline const std::string CurrenciesFilePath = "Currencies.txt";
    inline const std::string LoginRegisterFilePath = "LoginRegister.txt";
    inline const std::string TransferLogFilePath = "TransferLog.txt";
}

#include "clsUser.h"

namespace Global
{
    inline clsUser CurrentUser = clsUser::Find("", "");
    inline std::string CurrentUserLoginTime = "";
}