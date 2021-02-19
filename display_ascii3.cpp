/** @file display_ascii3.cpp
Driver file for the AsciiGenerator class.

@author Ayumu Saito
*/


#include <iostream>
#include <string>
using namespace std;

#include "utilities.h"
#include "AsciiGenerator.h"
using Scobey::DisplayOpeningScreen;
using Scobey::Pause;
using Scobey::ReadChar;
using Scobey::TextItems;
using Scobey::Menu;
using Scobey::userSaysYes;

//Function prototypes
void BuildMenu
(
    Menu& menu //out
);
/**<
Sets title of, and adds options to, menu.
@param menu The menu to receive the title and options.
@pre menu has been initialized and is empty.
@post menu has a title and four options.
*/

void GetAsciiRangeFromUser
(
    char& firstChar, //out
    char& lastChar   //out
);
/**<
Gets the end points of the required ASCII range from the user.
@param firstChar The low end of the character interval to be displayed.
@param lastChar The high end of the character interval to be displayed.
@pre None
@post The user has entered the low endpoint of the range, which is in
firstChar, and the high endpoint of the range, which is in lastChar, and
firstChar <= lastChar.

If the first character of whatever the user enters when prompted for the
start character for the table is not a printable character, the
following message is displayed:

Error: The first character of that entry was not a printable character.
Try again. Be careful to enter valid starting/ending characters for the
table.

If the first character of whatever the user enters when prompted for

the end character for the table is not a printable character, the
following message is displayed:

Error: The first character of that entry was not a printable character.
Try again. Be careful to enter valid starting/ending characters for the
table.

If the both characters entered by the user lie within the range of printable
characters, but the second precedes the first in the ASCII sequence, the
following message is displayed:

Error: The starting character for the table display must not follow
the ending character in the ASCII sequence. Try again.
*/

int main()
{
    DisplayOpeningScreen
    (
        "Ayumu Saito",
        "\nSubmission 03"
        "\nDisplaying Printable ASCII Characters and Their Codes, Part 3 ",
        11, 12
    );

    Menu menu;
    BuildMenu(menu);

    char firstChar;
    char lastChar;

    int choice;
    do
    {
        menu.display();
        choice = menu.getChoice();

        switch (choice)
        {
        case 1:
            break;
        case 2:
        {
            TextItems textItem("display_ascii3.txt");
            textItem.displayItem("ProgramDescription");
            break;
        }
        case 3:
        {
            bool nextValid;
            do
            {
                GetAsciiRangeFromUser(firstChar, lastChar);
                AsciiGenerator generator(firstChar, lastChar);
                generator.displayHorizontally();

                nextValid = userSaysYes
                    (
                        "Display another range using this format?"
                    );
            }
            while (nextValid);
            break;
        }
        case 4:
        {
            bool nextValid;
            do
            {
                GetAsciiRangeFromUser(firstChar, lastChar);
                AsciiGenerator generator(firstChar, lastChar);
                generator.displayVertically();

                nextValid = userSaysYes
                    (
                        "Display another range using this format?"
                    );
            }
            while (nextValid);
            break;
        }
        default:
            break;
        }//end of switch

        if (choice == 1 || choice == -1)
        {
            cout << "Program now terminating." << endl;
            Pause();
        }
    }
    while (choice != 1 && choice != -1);
}

void BuildMenu
(
    Menu& menu //out
)
{
    menu.setTitle("Menu");
    menu.addOption("Quit");
    menu.addOption("Get information");
    menu.addOption
    (
        "Display ASCII codes horizontally (increasing across rows)"
    );
    menu.addOption
    (
        "Display ASCII codes vertically (increasing down columns)"
    );
}

void GetAsciiRangeFromUser
(
    char& firstChar, //out
    char& lastChar   //out
)
{

    cout << R"(
Choose ASCII character end points for the range of values you wish to display.
Both end point characters must lie in the range of characters from ' ' to '~'.
Also, the start character must precede the end character in the ASCII sequence.

)";

   /*
   Set the default valid value to false.
   If the user inputs correct characters in the while-loop below,
   this value will be set as true.
   */
   bool valid = false;

    /*
    This do-while loop exit out when user inputs characters that are
    expected. Otherwise, it keeps on prompting the user to input characters
    untill the user inputs the expected characters.
    */
    do
    {
        ReadChar
        (
            "Enter start character for the table display: ",
            firstChar
        );

        /*
        If the firstChar is printable, then promt the user to input the
        last character for the table. If not (else), display the proper
        error message.
        */
        if (firstChar >= (int)' ' && firstChar <= (int) '~')
        {
            ReadChar
            (
                "Enter end character for the table display "
                "(>= previous value): ",
                lastChar
            );

            /*
            If the lastChar is printable, then set valid to true so that
            function ends. If not (else), display the proper error
            message. Note that valid is still false here, so the function
            starts it over again asking the first character.
            */
            if (lastChar >= (int)' ' && lastChar <= (int)'~')
            {
                if(lastChar - firstChar >= 0)
                {
                    valid = true;
                }
                else //If lastChar appears before firstChar in ascii table
                {
                    cout << "\nError: The starting character for the table "
                        "display must not follow"
                        "\nthe ending character in the ASCII sequence. "
                        "Try again.\n"
                        << endl;
                }
            }
            else //If the lastChar is not printable
            {
                cout << "\nError: The first character of that entry was not "
                "a printable character."
                "\nTry again. Be careful to enter valid starting/ending "
                "characters for the table.\n"
                << endl;
            }
        }
        else //If the firstChar is not printable
        {
            cout << "\nError: The first character of that entry was not a "
                "printable character."
                "\nTry again. Be careful to enter valid starting/ending "
                "characters for the table.\n"
                << endl;
        }
    }
    while(valid == false);
}
