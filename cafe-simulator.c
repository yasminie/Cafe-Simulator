
#include <stdio.h>

void greeting(void); //welcome the user to the coffee shop
void order(double *balance); //user will make a purchase
void viewAccount(double *balance); //display current account balance of user
void transaction(double *balance, double price); //transaction with user account
void reload(double *balance); //reload your account balance
void displayMenu(void); //display beverage/food options and prices

int main() {

    // Declare variables
    char option = '\0';
    double balance = 0;

    greeting();
    // Menu driven component
    while (option != ('E' | 'e'))
    {
        // Presents menu options and selection for user
        printf("Please select one of the following options.\n");
        printf("O: Order\n");
        printf("V: View Account Summary\n");
        printf("D: Display Menu\n");
        printf("R: Reload Account\n");
        printf("E: Exit\n");
        printf("\n");

        printf("Please select what you would like to do.\n");
        printf("Option Selected: ");
        scanf(" %c", &option);

        // Directs user to option and corresponding function
        switch (option)
        {
            case 'O':
            case 'o':
                printf("\n");
                printf("You have selected the Order Option.\n");
                order(&balance); // function call
                break;
            case 'V':
            case 'v':
                printf("\n");
                printf("You selected View Account Summary Option.\n");
                viewAccount(&balance); // function call
                break;
            case 'D':
            case 'd':
                printf("\n");
                printf("You selected Display Menu Option.\n");
                displayMenu(); // function call
                break;
            case 'R':
            case 'r':
                printf("\n");
                printf("You selected Reload Account Option.\n");
                reload(&balance); // function call
                break;
        }
        // If e is entered the program will end
        if (option == ('E' | 'e'))
        {
            printf("\n");
            printf("Thank you for visiting Knightro's Coffee Shop!\n");
            printf("You have $%.2lf in your account.\n", balance);
            printf("Have a great day!\n");
            printf("Go Knights! Charge on!\n");
        }
    }

    return 0;
}

// Function definiton: prints greeting to user
void greeting(void)
{
    printf("Welcome to Knightro's Coffee Shop!\n");
    printf("We serve delicious coffee and snacks!\n");
    printf("How can we help you today?\n");
    printf("\n");
}

// Function defintion: takes selection and proceeds with function call
void order(double *balance)
{
    // Declare variables
    int orderOption;
    double price;

    // Displays menu to order
    displayMenu();

    // Collects order input
    printf("What would you like today?\n");
    printf("Option Selected: ");
    scanf("%d", &orderOption);

    // Prints name and total and proceeds with cost of selected item into function
    switch (orderOption)
    {
        case 1:
            price = 3.53;
            printf("\n");
            printf("Hot Coffee has been selected. Total cost is: $3.53.\n");
            transaction(balance, price); // function call
            break;
        case 2:
            price = 4.20;
            printf("\n");
            printf("Iced Coffee has been selected. Total cost is: $4.20.\n");
            transaction(balance, price); // function call
            break;
        case 3:
            price = 3.13;
            printf("\n");
            printf("Hot Latte has been selected. Total cost is: $3.13.\n");
            transaction(balance, price); // function call
            break;
        case 4:
            price = 4.12;
            printf("\n");
            printf("Iced Latte has been selected. Total cost is: $4.12.\n");
            transaction(balance, price); // function call
            break;
        case 5:
            price = 3.99;
            printf("\n");
            printf("Bagel (includes cream cheese) has been selected. Total cost is: $3.99.\n");
            transaction(balance, price); // function call
            break;
        case 6:
            price = 4.99;
            printf("\n");
            printf("Big Scone has been selected. Total cost is: $4.99.\n");
            transaction(balance, price); // function call
            break;
        case 7:
            price = 5.03;
            printf("\n");
            printf("Frozen Coffee has been selected. Total cost is: $5.03.\n");
            transaction(balance, price); // function call
            break;
        case 8:
            price = 1.50;
            printf("\n");
            printf("Bottle Water has been selected. Total cost is: $1.50.\n");
            transaction(balance, price); // function call
            break;
        default:
            printf("Sorry, please try again!\n");
            printf("\n");
    }
}

// Function definition: prints balance according to the current state of the account
void viewAccount(double *balance)
{
    printf("Here is your current account balance.\n");
    printf("You have $%.2lf in your account.\n", *balance);
    printf("\n");
}

// Function defintion: checks balance to pay for item and reload if not
void transaction(double *balance, double price)
{
    printf("\n");
    printf("Beginning Transaction Process.\n");

    // If the user has enough money the purchase will be subtracted from their account
    // and their account balance is updated
    if (*balance >= price)
    {
        printf("Your account balance before official transaction: $%.2lf\n", *balance);
        printf("Billing $%.2lf to your account.\n", price);
        printf("Transaction successful!\n");
        *balance = *balance - price;
        printf("You have now $%.2lf in your account balance.\n", *balance);
        printf("\n");
    }
    // If the user does not have enough money the purchase is rejected and
    // they are asked to reload their account
    else if (*balance < price)
    {
        printf("You do not have enough in your account.\n");
        printf("Please reload your account balance.\n");
        printf("\n");
        reload(balance);
    }
}

// Lets the user update their account balance
void reload(double *balance)
{
    // Declare variable
    int reloadOption;

    // Prints reload options and collects input
    printf("How much would you like to reload to your account?\n");
    printf("1: $1.00\n");
    printf("2: $5.00\n");
    printf("3: $10.00\n");
    printf("Option Selected: ");
    scanf("%d", &reloadOption);

    // Adds and updates balance depending on amount added to account
    switch (reloadOption)
    {
        case 1:
            *balance += 1;
            printf("$1.00 has been added to your account successfully!\n");
            printf("\n");
            break;
        case 2:
            *balance += 5;
            printf("$5.00 has been added to your account successfully!\n");
            printf("\n");
            break;
        case 3:
            *balance += 10;
            printf("$10.00 has been added to your account successfully!\n");
            printf("\n");
            break;
        default:
            printf("Sorry, please try again!\n");
            printf("\n");
    }
}

// Displays shop menu (food items)
void displayMenu(void)
{
    printf("Here are the options!\n");
    printf("1. Hot Coffee                          $3.53\n");
    printf("2. Iced Coffee                         $4.20\n");
    printf("3. Hot Latte                           $3.13\n");
    printf("4. Iced Latte                          $4.12\n");
    printf("5. Bagel (includes cream cheese)       $3.99\n");
    printf("6. Big Scone                           $4.99\n");
    printf("7. Frozen Coffee                       $5.03\n");
    printf("8. Bottle Water                        $1.50\n");
    printf("\n");
}
