package Lab6_java;

import java.util.ArrayList;

interface SearchAccounts {
    Account findByNumber(int number)
        throws AccountNotFoundException;
    ArrayList<Account> findAllCustomerAccounts(Customer customer)
        throws AccountNotFoundException;

}
