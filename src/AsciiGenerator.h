/** @file AsciiGenerator.h

Header class for the asciiGenerator class.
*/


class AsciiGenerator
{
public:
    AsciiGenerator
    (
        char firstChar, //in
        char lastChar   //in
    );
    /**<
    Two-parameter constructor. Note that this class has no default
    constructor, so the only way to create an AsciiGenerator object
    is to use this constructor.
    @param firstChar The low endpoint of the ASCII value range to be displayed.
    @param lastChar The high endpoint of the ASCII value range to be displayed.
    @pre ' ' <= firstChar <= lastChar <= '~'.
    @post The object has been constructed with values in the input parameters
    stored internally.
    */

    void displayHorizontally();
    /**<
    Displays ASCII characters and their decimal, octal and hexadecimal
    codes in row-wise fashion, i.e. with codes increasing from left to right.
    @pre The object has been initialized.
    @post A table of ASCII character/code values has been displayed, with
    codes increasing from left to right across the rows. Each ASCII character
    and each of its three numerical codes appears right-justified in a
    fieldwidth of 4 spaces. The range of values displayed depends on those
    used to construct the object.
    */

    void displayVertically();
    /**<
    Displays ASCII characters and their decimal, octal and hexadecimal
    codes in column-wise fashion, i.e. with codes increasing from top
    to bottom down each column.
    @pre The object has been initialized.
    @post A table of ASCII character/code values has been displayed, with
    codes increasing  from top to bottom, down the columns. Each ASCII
    character and each of its three numerical codes appears right-justified
    in a fieldwidth of 4 spaces.  The range of values displayed depends on
    those used to construct the object.
    */

private:
    char firstChar;
    char lastChar;
};
