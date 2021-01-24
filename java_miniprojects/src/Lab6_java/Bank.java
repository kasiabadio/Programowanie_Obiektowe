package Lab6_java;

import java.util.Random;

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
        Random rand = new Random();
        int int_random_acc_num = rand.nextInt(100000);
        Account temp_customer = new Account(int_random_acc_num, _customer, 4747, "Login");
        account_array.add(temp_customer);
    }

    @Override
    public void findByName(String name) throws CustomerNotFoundException {
        int i = 0;
        while (i < customer_array.size()){
            if (customer_array.get(i).getName().equals(name)){
                return;
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
            if (account_array.get(j).getCustomer().getName().equals(customer.getName()) && account_array.get(j).getCustomer().getSurname().equals(customer.getSurname())){
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
        int k = 0;
        while (k < account_array.size()){
            if (account_array.get(k).getNumber() == number){
                return account_array.get(k);
            }
            k++;
        }
        throw new AccountNotFoundException("Nie znaleziono konta o takim numerze");
    }
}

