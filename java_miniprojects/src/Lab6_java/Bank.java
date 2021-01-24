package Lab6_java;
import Lab6_java.Customer.*;

import java.util.ArrayList;

public class Bank implements SearchAccounts, SearchCustomers{
    ArrayList<Customer> customers = new ArrayList<Customer>();
    ArrayList<Account> accounts = new ArrayList<Account>();


    @Override
    public Account findByNumber(int number) throws AccountNotFoundException {
        return null;
    }

    @Override
    public ArrayList<Account> findAllCustomerAccounts(Customer customer) throws AccountNotFoundException {
        return null;
    }

    @Override
    public Customer findByName(String name) throws CustomerNotFoundException {
        return null;
    }
}
