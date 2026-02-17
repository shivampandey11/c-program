#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account
{
       char name[20];
       int accountnumber;
       float balance;
};
int LoggedIn = 0;
int currentAccount = 0;
void createaccount();
void checkbalance();
void loginaccount();
void deposite();
void withdraw();
void transfer();
void logoutaccount();

int main()
{
       int choice;
       while (1)
       {
              printf("\n====BANK MANAGEMENT SYSTEM====\n");
              printf("1. Create Account\n");
              printf("2. Check Balance\n");
              printf("3. Login Account\n");
              printf("4. Deposit Money\n");
              printf("5. Withdraw Money\n");
              printf("6. Transfer Money\n");
              printf("7. Logout Account\n");
              printf("8. Exit\n");
              printf("Enter your choice: ");
              scanf("%d", &choice);

              switch (choice)
              {
              case 1:
                     createaccount();
                     break;
              case 2:
                     checkbalance(0);
                     break;
              case 3:
                     loginaccount();
                     break;
              case 4:
                     deposite(0);
                     break;
              case 5:
                     withdraw(0);
                     break;
              case 6:
                     transfer(0);
                     break;
              case 7:
                     logoutaccount();
                     break;
              case 8:
                     exit(0);
              default:
                     printf("Invalid choice!\n");
              }
       }
}

void createaccount()
{
       struct account a;
       printf("Enter your name:");
       scanf("%s", a.name);

       printf("Enter your account number:");
       scanf("%d", &a.accountnumber);

       printf("Enter your initial balance:");
       scanf("%f", &a.balance);

       FILE *fp = fopen("accounts.dat", "ab");
       fwrite(&a, sizeof(struct account), 1, fp);
       fclose(fp);

       printf("Account created successfully!\n");
}
void loginaccount()
{
       int accountnumber;
       printf("Enter your account number:");
       scanf("%d", &accountnumber);

       FILE *fp = fopen("accounts.dat", "rb");

       struct account a;
       while (fread(&a, sizeof(a), 1, fp))
       {
              if (a.accountnumber == accountnumber)
              {
                     printf("loging sucessfully!\n");
                     LoggedIn = 1;
                     currentAccount = accountnumber;
                     fclose(fp);
                     return;
              }
       }

       printf("Account not found!\n");
       fclose(fp);
}

void deposite(int currentAccount)
{

       if (!LoggedIn)
       {
              printf("login to deposite money!\n");
              return;
       }
       float amount;
       struct account a;
       FILE *fp = fopen("accounts.dat", "rb");

       printf("Enter the amount to deposite:");
       scanf("%f", &amount);

       while (fread(&a, sizeof(a), 1, fp))
       {
              if (a.accountnumber == currentAccount)

              {

                     a.balance += amount;

                     fseek(fp, -sizeof(a), SEEK_CUR);
                     fwrite(&a, sizeof(a), 1, fp);
                     break;
              }
       }

       printf("Amount deposite succesfully!\n");
       fclose(fp);
}

void withdraw(int currentAccount)
{
       if (!LoggedIn)
       {
              printf("please login to withdraw money!\n");
              return;
       }
       float amount;
       struct account a;
       FILE *fp = fopen("accounts.dat", "rb+");

       printf("Enter the amount to withdraw:");
       scanf("%f", &amount);

       while (fread(&a, sizeof(a), 1, fp))
       {
              if (a.accountnumber == currentAccount)
              {
                     if (amount > a.balance)
                     {
                            printf("insufficient balance!\n");
                     }
                     else
                     {
                            a.balance -= amount;
                            fseek(fp, -sizeof(a), SEEK_CUR);
                            fwrite(&a, sizeof(a), 1, fp);
                            printf("Amount withdraw successfully!\n");
                            break;
                     }
              }
       }
       fclose(fp);
}

void transfer(int currentAccount)
{
       if (!LoggedIn)
       {
              printf("Login first!\n");
              return;
       }

       int toAcc;
       float amt;
       struct account a;
       FILE *fp = fopen("bank.dat", "rb+");

       printf("Transfer to account no: ");
       scanf("%d", &toAcc);

       printf("Enter amount: ");
       scanf("%f", &amt);

       struct account sender, receiver;
       int sFound = 0, rFound = 0;

       while (fread(&a, sizeof(a), 1, fp))
       {
              if (a.accountnumber == currentAccount)
              {
                     sender = a;

                     sFound = 1;
              }
              if (a.accountnumber == toAcc)

              {
                     receiver = a;
                     rFound = 1;
              }
       }

       if (sFound && rFound && sender.balance >= amt)
       {
              sender.balance -= amt;
              receiver.balance += amt;

              rewind(fp);

              while (fread(&a, sizeof(a), 1, fp))
              {
                     if (a.accountnumber == sender.accountnumber)
                     {
                            fseek(fp, -sizeof(a), SEEK_CUR);
                            fwrite(&sender, sizeof(sender), 1, fp);
                     }
                     if (a.accountnumber == receiver.accountnumber)
                     {
                            fseek(fp, -sizeof(a), SEEK_CUR);
                            fwrite(&receiver, sizeof(receiver), 1, fp);
                     }
              }

              printf("Transfer Successful!\n");
       }
       else
              printf("Transfer Failed!\n");

       fclose(fp);
}

void checkbalance(int currentAccount)
{
       struct account a;
       int acc;

       printf("Enter account no: ");
       scanf("%d", &acc);

       FILE *fp = fopen("bank.dat", "rb");

       while (fread(&a, sizeof(a), 1, fp))
       {
              if (a.accountnumber == acc)
              {
                     printf("Name: %s\nBalance: %.2f\n", a.name, a.balance);
                     break;
              }
       }

       fclose(fp);
}

void logoutaccount()
{
       LoggedIn = 0;
       currentAccount = -1;
       printf("Logged out successfully!\n");
}
