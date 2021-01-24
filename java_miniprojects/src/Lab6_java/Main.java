package Lab6_java;

public class Main {
    public static void main(String[] args) throws AccountLoginFailedException {
        // testowanie klasy Customer
        System.out.println("Klienci: ");
        Customer customer3 = new Customer();
        System.out.println(customer3.getName() + " " + customer3.getSurname());
        Customer customer = new Customer("Kasia", "Kowalska", "Wroclawska", 282829191);
        System.out.println(customer.getName() + " " + customer.getSurname());
        Customer customer1 = new Customer("Julia", "Kowalska", "Klonowa", 991189919);
        System.out.println(customer1.getName() + " " + customer1.getSurname());
        Customer customer2 = new Customer("Magdalena", "Pogorzelec", "Klonowa", 991189919);
        System.out.println(customer2.getName() + " " + customer2.getSurname() + "\n");

        boolean are_surnames_egual = customer.equals(customer1);
        System.out.println("Porównanie nazwisk klientów: " + customer.getName() + " " + customer.getSurname() + ", " +
                customer1.getName() + " " + customer1.getSurname());
        if(are_surnames_egual){
            System.out.println("Nazwiska są takie same!");
        }else{
            System.out.println("Nazwiska są różne!");
        }
        System.out.println("Porównanie nazwisk klientów: " + customer1.getName() + " " + customer1.getSurname() + ", " +
                customer2.getName() + " " + customer2.getSurname());

        boolean are_surnames_egual1 = customer1.equals(customer2);
        if(are_surnames_egual1){
            System.out.println("Nazwiska są takie same!");
        }else{
            System.out.println("Nazwiska są różne!\n");
        }

        // testowanie klasy Account
        Account account1 = new Account(1, customer1, 1234, "ko_julia");
        account1.login(customer1, "ko_julia", 1234);
        // account1.login(customer1, "k_julia", 1234);


    }
}
