
#include <iostream>
#include <string>
using namespace std;

//checkLength
bool checkLength(string pass) {
    if (pass.length() < 8 || pass.length() > 32)
    {
        return false;
    }
    return true;
}



//checkLowercase 97-122
bool checkLowercase(string pass)
{
    //bool flag = false;
    for (int i = 0; i < pass.length(); i++)
    {
        if (pass[i] >= 'a' && pass[i] <= 'z')
        {
            return true;
        }
    }
    return false;
}



//checkUppercase 65-90
bool checkUppercase(string pass)
{
    for (int i = 0; i < pass.length(); i++)
    {
        if (pass[i] >= 'A' && pass[i] <= 'Z')
        {
            return true;
        }
    }
    return false;
}



//checkDigits 48-57
bool checkDigits(string pass)
{
    for (int i = 0; i < pass.length(); i++)
    {
        if (pass[i] >= '0' && pass[i] <= '9')
        {
            return true;
        }
    }
    return false;
}



//checkSpecialCharacters !@#$%^&*()-_+=~|\/?<>[]
bool checkSpecialCharcters(string pass)
{
    int specCharNum = 0;

    string specialCharacters = "!@#$%^&*()-_+=~|\\/?<>[]";

    for (size_t i = 0; i < pass.length(); i++)
    {
        if (specialCharacters.find(pass[i]) != string::npos)
        {
            specCharNum++;

            if (specCharNum >= 2)
            {
                return true;
            }
        }
    }

    return false;
}




//checkSpaces
bool checkSpaces(string pass)
{
    for (int i = 0; i < pass.length(); i++)
    {
        if (pass[i] == ' ')
        {
            return false;
        }
    }
    return true;
}


bool checkPassword(string pass)
{
    bool length = checkLength(pass);
    bool lowercase = checkLowercase(pass);
    bool uppercase = checkUppercase(pass);
    bool digits = checkDigits(pass);
    bool specialCharacters = checkSpecialCharcters(pass);
    bool spaces = checkSpaces(pass);

    if (length && lowercase && uppercase && digits && specialCharacters && spaces)
    {
        return true;
    }
    return false;
}



int main()
{
    string password = "Parolala1111#";

    if (checkPassword(password))
        cout << "uspeshna parola" << endl;
    else
        cout << "neuspeshna parola:(" << endl;
}