#include <iostream>
#include <cstring>

using namespace std;

int choiceNum;
enum
{
    CREATE_ACCOUNT = 1,
    DEPOSIT,
    WITHDRAW,
    SHOWALL_ACCOUNT,
    EXIT
};


struct Account{
    int id;
    char name[20];
    int balance;
};

Account accArr[100];
int accNum = 0;

void showMenu();
void createAccount();

int main()
{

    while (1)
    {
        showMenu();
        cin >> choiceNum;
        cout << "selected : " << choiceNum << endl;
        switch (choiceNum)
        {
        case CREATE_ACCOUNT:
            createAccount();
            break;
        case DEPOSIT:
            cout << "hello 2" << endl;
            break;
        case WITHDRAW:
            cout << "hello 3" << endl;
            break;
        case SHOWALL_ACCOUNT:
            cout << "hello 4" << endl;
            break;
        case EXIT:
            return 0;
        default:
            cout << "wrong selected number!" << endl;
        }
    }

    return 0;
}

void showMenu()
{
    cout << "------MENU-------" << endl;
    cout << "1. create account" << endl;
    cout << "2. deposit" << endl;
    cout << "3. withdraw" << endl;
    cout << "4. show all account" << endl;
    cout << "5. exit" << endl;
}

void createAccount()
{
    int id;
    char name[20];
    int balance;

    cout << "Insert ID : ";
    cin >> id;
    cout << "Insert NAME : ";
    cin >> name;
    cout << "Insert balance : ";
    cin >> balance;

    accArr[accNum].id = id;
    strcpy(accArr[accNum].name, name);
    accArr[accNum].balance = balance;

    cout << "created account is : " << accArr << endl;

    accNum++;


}