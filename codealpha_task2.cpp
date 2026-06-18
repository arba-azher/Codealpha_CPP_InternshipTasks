#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Account
{
private:
    string userId;
    string userPass;

public:

    bool isValidUsername(const string& uName)
    {
        if(uName.empty())
        {
            cout << "Username cannot be empty.\n";
            return false;
        }

        if(uName.length() < 5)
        {
            cout << "Username must be at least 5 characters long.\n";
            return false;
        }

        return true;
    }

    bool isValidPassword(const string& pwd)
    {
        if(pwd.empty())
        {
            cout << "Password cannot be empty.\n";
            return false;
        }

        if(pwd.length() < 8)
        {
            cout << "Password must be at least 8 characters long.\n";
            return false;
        }

        return true;
    }

    void signUp()
    {
        cout << "\nEnter Username: ";
        cin >> userId;

        cout << "Enter Password: ";
        cin >> userPass;

        if(!isValidUsername(userId) || !isValidPassword(userPass))
            return;

        string userFile = userId + ".txt";

        ifstream checkUser(userFile);

        if(checkUser.is_open())
        {
            cout << "Username already exists.\n";
            checkUser.close();
            return;
        }

        checkUser.close();

        ofstream saveUser(userFile);

        if(!saveUser)
        {
            cout << "Unable to create account.\n";
            return;
        }

        saveUser << userId << endl;
        saveUser << userPass << endl;

        saveUser.close();

        cout << "Account created successfully!\n";
    }

    void signIn()
    {
        string loginId, loginPass;

        cout << "\nEnter Username: ";
        cin >> loginId;

        cout << "Enter Password: ";
        cin >> loginPass;

        string userFile = loginId + ".txt";

        ifstream openUser(userFile);

        if(!openUser)
        {
            cout << "User not found.\n";
            return;
        }

        string storedId, storedPass;

        getline(openUser, storedId);
        getline(openUser, storedPass);

        openUser.close();

        if(loginId == storedId && loginPass == storedPass)
            cout << "Login successful!\n";
        else
            cout << "Incorrect password.\n";
    }
};

int main()
{
    Account userObj;
    int menuChoice;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Sign Up\n";
        cout << "2. Sign In\n";
        cout << "3. Exit\n";
        cout << "Select Option: ";
        cin >> menuChoice;

        switch(menuChoice)
        {
            case 1:
                userObj.signUp();
                break;

            case 2:
                userObj.signIn();
                break;

            case 3:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid option!\n";
        }

    } while(menuChoice != 3);

    return 0;
}
