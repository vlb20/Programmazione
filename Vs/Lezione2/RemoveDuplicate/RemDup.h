/*• In the Account example the main function contains six statements that each display an Account
object’s name and balance. Study these statements and you’ll notice that they differ only in
the Account object being manipulated—account1 or account2.

• In this exercise, you’ll define a new displayAccount function that contains one copy of that
output statement. The member function’s parameter will be an Account object and the member
function will output the object’s name and balance.

• You’ll then replace the six duplicated statements in main with calls to displayAccount,
passing as an argument the specific Account object to output. Modify the account object to
define the following displayAccount function

• void displayAccount(Account accountToDisplay) { // place the statement that displays //
accountToDisplay's name and balance here}

• Replace the comment in the member function’s body with a statement that displays
accountToDis-play’s name and balance. Once you’ve completed displayAccount’s declaration,
modify main to replace the statements

• that display each Account’s name and balance with calls to displayAccount of the form:
displayAccount(nameOfAccountObject);

• In each call, the argument should be the account1 or account2 object, as appropriate. Then,
test the updated program to ensure that it produces the same output as shown in the class.*/