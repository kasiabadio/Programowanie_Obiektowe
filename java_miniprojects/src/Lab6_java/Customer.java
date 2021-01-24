package Lab6_java;
import java.util.ArrayList;

public class Customer {
    private String name;
    private String surname;
    private String address;
    private int pesel;


    public Customer() {
        name = "Empty";
        surname = "Empty";
        address = "Empty";
        pesel = -1;

    }

    public Customer(String _name, String _surname, String _address, int _pesel) {
        name = _name;
        surname = _surname;
        address = _address;
        pesel = _pesel;

    }

    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public String getAddress() {
        return address;
    }

    public int getPesel() {
        return pesel;
    }


    @Override
    public boolean equals(Object customer) {
        if (getClass() != customer.getClass()) {
            return false;
        }
        Customer customer_cp = (Customer) customer;
        return customer_cp.getSurname().equals(surname);
    }
}
