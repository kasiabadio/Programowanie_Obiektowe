package Lab6_java;
import Lab6_java.Customer.*;

import java.util.ArrayList;

public class Bank implements SearchAccounts, SearchCustomers{
    ArrayList<Customer> customer_array = new ArrayList<>();
    ArrayList<Account> account_array = new ArrayList<>();

    public void printCustomerList(){
        int j = 0;
        while (j < customer_array.size()){
            System.out.println(customer_array.get(j).getName() + " " + customer_array.get(j).getSurname() + "\n");
            j++;
        }
    }

    public void addToCustomerList(Customer _customer){
        customer_array.add(_customer);
    }
    public void addToAccountList(Customer _customer){
        Account temp_customer = new Account(1234, _customer, 4747, "Login");
        account_array.add(temp_customer);
    }

    @Override
    public Customer findByName(String name) throws CustomerNotFoundException {
        int i = 0;
        while (i < customer_array.size()){
            if (customer_array.get(i).getName().equals(name)){
                return customer_array.get(i);
            }
            i++;
        }
        throw new CustomerNotFoundException("Nie znaleziono takiego klienta");
    }

    @Override
    public ArrayList<Account> findAllCustomerAccounts(Customer customer) throws AccountNotFoundException {
        int j = 0;
        ArrayList<Account> acc_customer = new ArrayList<>();
        while (j < account_array.size()){
            if (account_array.get(j).getCustomer().getPesel() == customer.getPesel()){
                acc_customer.add(account_array.get(j));
            }
            j++;
        }
        if (acc_customer.isEmpty()){
            throw new AccountNotFoundException("Nie znaleziono żadnego konta");
        }
        return acc_customer;
    }

    @Override
    public Account findByNumber(int number) throws AccountNotFoundException {
        return null;
    }
}

