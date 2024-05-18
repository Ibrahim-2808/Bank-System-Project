Bank Management System in C++*

*Introduction:*
This C++ program implements a basic Bank Management System. It provides functionalities for account creation, login, deposit/withdrawal of funds, loan application, and administrative operations such as updating the interest rate.

*Key Features:*
1. *Account Management:*
   - Users can create accounts by providing a unique username and password.
   - Existing usernames are prevented from being reused to ensure uniqueness.
   - Authentication mechanisms verify user credentials during login.

2. *Transaction Operations:*
   - Account holders can deposit and withdraw funds from their accounts.
   - Withdrawal operations are validated against the account's balance to prevent overdrawing.

3. *Loan Application:*
   - Users can apply for loans by specifying the loan amount and term (in years).
   - The system calculates the total repayment amount based on the loan amount, term, and the current interest rate.

4. *Admin Functions:*
   - Administrators have access to a menu for updating the interest rate.
   - This functionality provides flexibility in managing the bank's interest policies.

*Implementation Details:*
- The program is structured using object-oriented principles with two main classes: Account and BankSystem.
- Account details are stored in an unordered map, ensuring efficient retrieval and modification.
- User interactions are facilitated through console input and output, ensuring ease of use.

*Usage:*
1. Upon launching the program, users are presented with options to create an account, log in, or access the admin menu.
2. Account creation requires providing a unique username and password.
3. Users can log in using their credentials and perform various account operations such as deposit, withdrawal, and loan application.
4. Admins can update the interest rate through the dedicated admin menu.

*Future Enhancements:*
- Integration of additional security measures like data encryption to safeguard sensitive information.
- Implementation of error handling mechanisms to enhance program robustness.
- Introduction of a graphical user interface (GUI) for improved user experience.
- Expansion of functionalities to support transactions between accounts and external bank transfers.

*Conclusion:*
The Bank Management System in C++ provides a solid foundation for managing bank accounts and transactions. Its modular design, coupled with essential features, makes it suitable for use in educational settings or as a basis for further development in the banking software domain.
İbrahim Halil Uğur 231504807
