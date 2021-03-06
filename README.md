# DisplayAsciiTable
C++ program that displays the ascii table either vertically or horizontally, which I made in the Data Structure course taught by professor Porter Scobey.


## Program Description

ProgramDescription
This program displays a table of printable ASCII characters, along with their
corresponding decimal, octal and hexadecimal codes, four per line, except
possibly for the last line. The table has a suitable header and a pause at
the end of the first screen if the display consumes more than a single screen
of output. If there is a second screen for the table display, that part of
the table also has a suitable header and is followed by a pause. And if the
complete table occupies less than a full screen, the table is also followed
by a pause.

The printable ASCII characters extend from the blank space character (' ',
with code 32 decimal) to the tilde character ('~', with code 126 decimal).
The characters with codes in the range 0 to 31 and also code 127 are non-
printable "control characters".

The program is menu-driven, and the menu options permit the user to quit the
program, to read this information, and to choose whether the table display
will have the characters increasing across rows or down columns. Once that
display choice is made from the menu, the user is prompted to supply the two
characters that will determine the range of values to appear in the table.

When asked to enter a range-determining character for the start or end of the
table, the user may enter more than one character, but it will be the first
one entered that is used, and the rest will be ignored. The character to be
used must, of course, lie within the range of printable characters. If it does
not, an error is reported and the user is asked to try again.

This error will occur, for example, if the user enters a TAB character.
There will also be a problem if the user simply presses Enter (RETURN) when
asked to enter a character. That newline character will be read, but the
program will also "hang" until the user presses Enter again, posssibly but
not necessarily after entering more characters. In any case, the character
read for use in the table will be the newline character, which is invalid
since it is in the collection of non-printable characters.

The program also requires the start character for the table to precede the end
character, and if this is not the case an error is reported and the user is
asked to try again.

__Your terminal screen is the best for this program with the resolution of  79 x 25.__
__*Note Compiler gcc 9.3.0 or above is requred, if you would like to comile on your end.__ <br>
__*Excutable directory has the excutalbe file and a text file that is required by the program. Note that the excutable file is only compatible with linux.__

### Instructor Supplied Package
You can see the description of the package at [this link](https://cs.smu.ca/~porter/csc/common_341_342/code/utilities2021/utilities_docs/).

### To Compile
The build.sh file has the script to compile required files to make the excutable files.

`./build.sh`


