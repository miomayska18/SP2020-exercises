
#include <iostream>
#include <string>
using namespace std;

enum CHECK_PASS_RESULT
{
	success,
	invalidLength,
	noLowercaseLetters,
	noUppercaseLetters,
	noDigits,
	noSpecialCharacters,
	containsSpaces
};

//checkLength
bool checkLength(string pass) {
	if (pass.length() < 8 || pass.length() > 32)
	{
		return false;
	}
	return true;
}



//checkLowercase 97-122
bool containsLowercaseLetters(string pass)
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
bool containsUppercaseLetters(string pass)
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
bool containsDigits(string pass)
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
bool containsSpecialCharcters(string pass)
{
	int specCharNum = 0;
	// pass = pass$#w0rd*!
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
bool containsSpaces(string pass)
{
	for (size_t i = 0; i < pass.length(); i++)
	{
		if (pass[i] == ' ')
		{
			return true;
		}
	}
	return false;
}


CHECK_PASS_RESULT checkPassword(string pass)
{
	//bool length = checkLength(pass);
	if (checkLength(pass) == true)
	{
		if (containsLowercaseLetters(pass) == true)
		{
			if (containsUppercaseLetters(pass) == true)
			{
				if (containsDigits(pass) == true)
				{
					if (containsSpecialCharcters(pass) == true)
					{
						if (containsSpaces(pass) == false)
						{
							return CHECK_PASS_RESULT::success;
						}
						else
						{
							return CHECK_PASS_RESULT::containsSpaces;
						}
					}
					else
					{
						return CHECK_PASS_RESULT::noSpecialCharacters;
					}
				}
				else
				{
					return CHECK_PASS_RESULT::noDigits;
				}
			}
			else
			{
				return CHECK_PASS_RESULT::noUppercaseLetters;
			}
		}
		else
		{
			return CHECK_PASS_RESULT::noLowercaseLetters;
		}
	}
	else
	{
		return CHECK_PASS_RESULT::invalidLength;
	}


	//bool lowercase = checkLowercase(pass);
	//bool uppercase = checkUppercase(pass);
	//bool digits = checkDigits(pass);
	//bool specialCharacters = checkSpecialCharcters(pass);
	//bool spaces = checkSpaces(pass);

	//if (length && lowercase && uppercase && digits && specialCharacters && spaces)
	////if (checkLength(pass) && 
	////    checkLowercase(pass) && 
	////    checkUppercase(pass) && 
	////    checkDigits(pass) && 
	////    checkSpecialCharcters(pass) && 
	////    checkSpaces(pass))
	//{
	//    return true;
	//}


	//return false;
}



int main()
{

	string password;
	int result;
	/*password = "Paorla";
	cout << checkDigits(password) << endl;
	password = "Paorla12334";
	cout << checkDigits(password) << endl;
	password = "Paorla0";
	cout << checkDigits(password) << endl;
	password = "Paorla9";
	cout << checkDigits(password) << endl;*/

	password = "Parolala6#%";

	result = checkPassword(password);

	switch (result)
	{
		case CHECK_PASS_RESULT::success: cout << "the password is okay" << endl;
			break;
		case CHECK_PASS_RESULT::invalidLength: cout << "invalid password length!" << endl;
			break;
		case CHECK_PASS_RESULT::noLowercaseLetters: cout << "the password doesn't contain any lowercase letters!" << endl;
			break;
		case CHECK_PASS_RESULT::noUppercaseLetters: cout << "the password doesn't contain any uppercase letters!" << endl;
			break;
		case CHECK_PASS_RESULT::noDigits: cout << "the password doesn't contain any digits!" << endl;
			break;
		case CHECK_PASS_RESULT::noSpecialCharacters: cout << "the password should contain at least two special characters" << endl;
			break;
		case CHECK_PASS_RESULT::containsSpaces: cout << "the password shouldn't contain any spaces!" << endl;
			break;
	}
	
}