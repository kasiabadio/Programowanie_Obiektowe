package Lab6_java;

public class Account {
    private int accountNumber;
    private Customer owner;
    private double balance;
    private int password;
    private String login;

    public Account(){}

    public Account(int _accountNumber, Customer _owner, int _password, String _login) {
        balance = 0;
        accountNumber = _accountNumber;
        owner = _owner;
        password = _password;
        login = _login;
    }

    public void login(Customer _owner, String _login, int _password) throws AccountLoginFailedException{
        int checksum = 0;

        if (login.equals(_login)){
            System.out.println("Login prawidłowy");
            checksum += 1;
        }else{
            System.out.println("Login nieprawidłowy");
        }

        if(password == _password){
            System.out.println("Hasło prawidłowe");
            checksum += 1;
        }else{
            System.out.println("Hasło nieprawidłowe");
        }

        if (checksum == 2){
            System.out.println("Logowanie powiodło się\n");
        }else{
            throw new AccountLoginFailedException("Logowanie nie powiodło się\n", _owner, _login, _password);
        }

    }

    public Customer getCustomer(){
        return owner;
    }

    public int getNumber(){
        return accountNumber;
    }

    public double getBalance(){
        return balance;
    }

    public double withdraw(double _amount){
        return balance - _amount;
    }

    public void addCash(double _cash){
        balance += _cash;
    }

}
