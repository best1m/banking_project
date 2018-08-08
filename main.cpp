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

struct Account
{
    int id;
    char name[20];
    int balance;
};

Account accArr[100];
int accNum = 0;

void showMenu();
void createAccount();
void deposit();
void withdraw();
void showAllAccount();

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
            deposit();
            break;
        case WITHDRAW:
            withdraw();
            break;
        case SHOWALL_ACCOUNT:
            showAllAccount();
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

    cout << "created account is : " << accArr[0].id << endl;

    accNum++;
}

void deposit()
{

    int id;
    int money;

    cout << "ID : ";
    cin >> id;

    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i].id == id)
        {
            cout << "how much do u wanna get balance?";
            cin >> money;
            cout << "balance is : " << money << endl;
            accArr[i].balance += money;
        }
        else
        {
            cout << "wrong id" << endl;
        }
    }

    cout << "deposit completed" << endl;
}

void withdraw()
{
    int id;
    int money;

    cout << "ID : ";
    cin >> id;

    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i].id == id)
        {
            cout << "how much do u wanna send to balance?";
            cin >> money;
            cout << "balance is : " << money << endl;

            if (accArr[i].balance > money)
            {
                accArr[i].balance -= money;
            }
            else
            {
                cout << "not enough money" << endl;
            }
        }
        else
        {
            cout << "wrong id" << endl;
        }
    }

    cout << "withraw completed" << endl;
}

void showAllAccount()
{
    for (int i = 0; i < accNum; i++)
    {
        cout << "ID : " << accArr[i].id << endl;
        cout << "name : " << accArr[i].name << endl;
        cout << "balance : " << accArr[i].balance << endl;
    }
}