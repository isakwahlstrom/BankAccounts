#include <iostream>
#include <string.h>
#include <vector>
#define ACCOUNTSIZE 1000
#define NUMBERSIZE 6
#define NAMESIZE 20

using namespace std;



class Account {
    public:
    string accountnumber;
    string surname;
    string lastname;
    int balance;
    
    public:
    Account(string number, string firstname, string lastName, int Balance) {
        accountnumber = number;
        surname = firstname;
        lastname = lastName;
        balance = Balance;
    }
    public:
    Account() {
        accountnumber = "";
        surname = "";
        lastname = "";
        balance = 0;
    }


    string getNumber() {return accountnumber;}
    string getFirstName() {return surname;}
    string getLastName() {return lastname;}
    int getBalance() {return balance;}
    void setBalance(int balance2) {balance = balance2;}
     
};
void printAllAccounts(const vector<Account>&list);
void printMenu();
void changeBalance(vector<Account>& list);
void enterAccount(vector<Account>& list);
void balanceSort(vector<Account>& list, int used);
void nameSort(vector<Account>& list,int used);
void numberSort(vector<Account>& list, int used);
void sortAccount(vector<Account>& list,int used);
int main() {
    vector<Account> listOfAccounts;
    Account janne("123455","Janne","Andersson",93);
    Account ds("123458","ds","Bennison",9000);
    listOfAccounts.push_back(janne);
    listOfAccounts.push_back(ds);

    printAllAccounts(listOfAccounts);
    enterAccount(listOfAccounts);
    printAllAccounts(listOfAccounts);
    sortAccount(listOfAccounts,listOfAccounts.size());
    printAllAccounts(listOfAccounts);


    return 0;
}

void printMenu() {
   cout     << "(1) Registrera nya konton\n"
            << "(2) Skriva ut alla konton\n"
            << "(3) Sortera konton\n"
            << "(4) Soka efter konto\n"
            << "(5) Andra saldot pa ett konto\n"
            << "(6) Avregistrera ett konto\n"
            << "(7) Overforing\n"
            << "(8) Avsluta\n"
            << "Ange val:";
}
void printAllAccounts(const vector<Account>& list) {
    for(Account accs: list) {
        cout << "Number: " << accs.getNumber() << " Name: " << accs.getFirstName() << " " << accs.getLastName() << " Balance: " << accs.getBalance() << endl;
    }
}
void changeBalance(vector<Account>& list) {
    string number;
    char type;
    int amount;
    cout << "Enter accountnumber of which account to change balance:";
    cin >> number;
    for(int j=0; j<list.size();j++) {
        if(list[j].accountnumber.compare(number)==0) { 
            cout << "Withdrawal or input: [w][i]: ";
            cin >> type;
            cout << "Enter amount: ";
            cin >> amount;
            switch(type) {
                case 'w': if(list[j].balance - amount>=0) {list[j].balance = list[j].balance - amount; } else {cout<< "Balance can't be less than zero" << endl;} break;
                case 'i': list[j].balance = list[j].balance + amount; break;
                default: break;
            }
              cout << number;
        } else {
            if(j==list.size()-1) {
                cout << "No accounts found with that number" << endl;
            }
        }
    }
}
void enterAccount(vector<Account>& list) {
    string aNumber;
    string lastName;
    string firstName;
    int existing = 0;
    //int nrofAccs = list.size();
    cout << "You're about to register a new account\n";
    do { 
        if(list.size()<1000) {
            cout << "Enter accountnumber(or q to quit): "; 
            cin >> aNumber;
            //cout << aNumber;
            if(aNumber!="q") {
                //cout << aNumber;
                for(int j=0;j<list.size();j++) {
                    if(list[j].accountnumber.compare(aNumber)==0) {
                        cout << "Account already exists."; 
                        existing=1;
                    } 
                }
                if(existing==0) {
                   cout << "Enter lastname: ";
                   cin >> lastName;
                   cout << "Enter firstname: ";
                   cin >> firstName;
                   if(list.size()<1000) {
                    Account newAcc(aNumber,firstName,lastName,0);
                    list.push_back(newAcc);
                   }
                }
                
            }
            existing=0;
        } else {
            cout << "Too many accounts registered." << endl;
            aNumber="q";
        }
    } while(aNumber!="q");
}
void balanceSort(vector<Account>& list, int used) {
    Account tmpAccount;
    for(int j=0;j<used;j++) {
        for(int i=0; i<used-1-j;i++) {
            if((list[i].balance < list[i+1].balance)) {
                swap(list[i],list[i+1]);
            }
        }    
    }   
}
void nameSort(vector<Account>& list,int used) {
    Account tmpAccount;
    for(int j=0;j<used;j++) {
        for(int i=0; i<used-1-j;i++) {
            if(list[i].lastname.compare(list[i+1].lastname)<0) {
                swap(list[i],list[i+1]);
            }
        }    
    }   
}
void numberSort(vector<Account>& list, int used) {
    Account tmpAccount;
    for(int j=0;j<used;j++) {
        for(int i=0; i<used-1-j;i++) {
                if(list[i].accountnumber.compare(list[i+1].accountnumber)<0) {
                    swap(list[i],list[i+1]);
                }
        }     
    }     
}
void sortAccount(vector<Account>& list,int used) {
    int cmd;
    cout << "Vill du sortera efter konto-nr(1), agare(2), eller saldo(3): ";
    cin >> cmd;
    switch(cmd) {
        case 1: numberSort(list,used); break;
        case 2: nameSort(list,used);   break;
        case 3: balanceSort(list,used); break;
        default: cout<<"Invalid statement, use 1 through 3\n"; break;
    }

}