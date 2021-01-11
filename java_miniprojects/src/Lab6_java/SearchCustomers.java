package Lab6_java;

interface SearchCustomers {
    Customer findByName(String name)
        throws CustomerNotFoundException;
}
