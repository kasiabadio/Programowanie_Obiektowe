package Lab6_java;
import java.util.ArrayList;

public class Customer implements SearchCustomers, SearchAccounts{
    private String name;
    private String surname;
    private String address;
    private int pesel;
    ArrayList<Customer> customer_array = new ArrayList<>();


    public Customer(){
        name = "Empty";
        surname = "Empty";
        address = "Empty";
        pesel = -1;

    }

    public Customer(String _name, String _surname, String _address, int _pesel){
        name = _name;
        surname = _surname;
        address = _address;
        pesel = _pesel;

    }

    public String getName(){
        return name;
    }

    public String getSurname(){
        return surname;
    }

    public String getAddress(){
        return address;
    }

    public int getPesel(){
        return pesel;
    }

    public void addToCustomerList(Customer _customer){
        customer_array.add(_customer);
    }

    @Override
    public boolean equals(Object customer){
        if (getClass() != customer.getClass()){
            return false;
        }
        Customer customer_cp = (Customer) customer;
        return customer_cp.getSurname().equals(surname);
    }

    @Override
    public Customer findByName(String name) throws CustomerNotFoundException {

        return null;
    }

    @Override
    public ArrayList<Account> findAllCustomerAccounts(Customer customer) throws AccountNotFoundException {

        return null;
    }

    @Override
    public Account findByNumber(int number) throws AccountNotFoundException {
        return null;
    }
}

