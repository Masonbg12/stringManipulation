// READING AND VALIDATING PASSWORD STRINGS
// Mason Gillespie

//preprocessor directives
#include "stdio.h"
#include "ctype.h"
#include "string.h"

//function prototypes
void nameManipulation();
void passwordValidation();

//main function
int main()
{
    // calling nameManipulation()
    nameManipulation();

    puts("\n");

    // calling passwordValidation()
    passwordValidation();

    return 0;
}

// function will read in user input into three separate c-strings and shuffle the c-strings
// into the desired format of "last, first middle" and store the output into fullName which will
// be printed to the screen
void nameManipulation()
{
    char first[21];     // holds first name
    char middle[21];    // holds middle name
    char last[21];      // holds last name
    char fullName[62];  // holds name in desired form for output

    // prompting user for input and reading input using scanf() which reads to first whitespace
    // and stores in respective c-string
    puts("Please enter your first, middle, and last name separated by spaces on one line:");
    scanf("%s", first);
    scanf("%s", middle);
    scanf("%s", last);

    // copying last name to fullName
    strcpy(fullName, last);
    // concatenating comma and space
    strcat(fullName, ", ");
    // concatenating first name
    strcat(fullName, first);
    // concatenating space
    strcat(fullName, " ");
    // concatenating middle name
    strcat(fullName, middle);
    // printing out full name in desired form
    printf("%s", fullName);

}// end of nameManipulation()

// function will prompt user for a password with criteria printed on the screen and will validate
// the password or show the user what the password is missing
void passwordValidation()
{
    // password can handle up to a 98 character long password for function to run correctly
    char password[100];
    // c-stings hold string literal criteria for password
    char firstCriteria[] = "between 6 and 14 characters long";
    char secondCriteria[] = "at least one uppercase and one lowercase character";
    char thirdCriteria[] = "at least 1 digit";
    char fourthCriteria[] = "at least one punctuation symbol";
    // ints are used as boolean variables to keep track of password validity
    int criteria1  = 0,
        criteria2a = 0,
        criteria2b = 0,
        criteria3  = 0,
        criteria4  = 0;

    // prompting user for input
    puts("Please enter a password with the following criteria:");
    // printing out criteria
    printf("%s\n", firstCriteria);
    printf("%s\n", secondCriteria);
    printf("%s\n", thirdCriteria);
    printf("%s\n\n", fourthCriteria);

    // storing password in c-string
    scanf("%s", password);

    // testing that the password length is between 6 and 14
    if (strlen(password) >= 6 && strlen(password) <= 14)
        criteria1 = 1;

    // for loop will iterate through the length of password be each character
    // int (bool) variables will be set to 1 (true) is there are any occurrences
    // of what is being tested
    for (int x = 0; x < strlen(password); x++)
    {
        // testing password for possible upper case letter
        if (!criteria2a)
            if (isupper(password[x]))
                criteria2a = 1;

        // testing password for possible lower case letter
        if (!criteria2b)
            if (islower(password[x]))
                criteria2b = 1;

        // testing password for possible digit
        if (!criteria3)
            if (isdigit(password[x]))
                criteria3 = 1;

        // testing password for possible punctuation
        if (!criteria4)
            if (ispunct(password[x]))
                criteria4 = 1;
    }

    // if there are any failed cases then an error message will print
    if (!criteria1 || !criteria2a || !criteria2b || !criteria3 || !criteria4)
    {
        puts("Error:");

        // printing out which criteria was failed during validation

        if (!criteria1)
            printf("%s\n", firstCriteria);

        if (!criteria2a || !criteria2b)
            printf("%s\n", secondCriteria);

        if (!criteria3)
            printf("%s\n", thirdCriteria);

        if (!criteria4)
            printf("%s\n", fourthCriteria);
    }
}
