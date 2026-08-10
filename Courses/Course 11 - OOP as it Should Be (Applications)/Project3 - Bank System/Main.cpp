#include <iostream>
#include "clsBankClient.h"

void ReadClientInfo(clsBankClient& Client)
{
    Client.SetFirstName(InputValidateLib::ReadText("\nEnter FirstName: "));
    Client.SetLastName(InputValidateLib::ReadText("\nEnter LastName: "));
    Client.SetEmail(InputValidateLib::ReadText("\nEnter Email: "));
    Client.SetPhone(InputValidateLib::ReadText("\nEnter Phone: "));
    Client.SetPinCode(InputValidateLib::GetValidPIN("\nEnter PinCode (4 digits): "));
    Client.SetAccoutBalance(InputValidateLib::ReadDblPositiveNumber("\nEnter Account Balance: "));
}

void UpdateClient()
{
    string AccountNumber = InputValidateLib::ReadText("\nPlease Enter client Account Number: ");
    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        AccountNumber = InputValidateLib::ReadText("\nAccount Number is not found, choose another one: ");
        cout << endl;
    }
    
    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    cout << "\n\nUpdate Client Info:";
    cout << "\n____________________\n";
    ReadClientInfo(Client);

    clsBankClient::enSaveResults SaveResult = Client.Save();

    switch (SaveResult)
    {

    case  clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Updated Successfully :-)\n";
        Client.Print();
        break;
    }

    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError account was not saved because it's Empty";
        break;
    }

    }

}

int main()
{
    UpdateClient();
    return 0;
}