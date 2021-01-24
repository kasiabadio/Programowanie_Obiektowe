package Lab6_java;

class AccountLoginFailedException extends Exception{
    static final long serialVersionUID = 1L;
    private Customer owner;
    private int password;
    private String login;

    AccountLoginFailedException(){}

    // Create a constructor with String parameter which is the detail message of the exception
    AccountLoginFailedException(String errorMsg, Customer _owner, String _login, int _password){
        super(errorMsg); // call the super constructor and pass a message
        owner = _owner;
        login = _login;
        password = _password;
    }

    Customer getCustomer(){ return owner; }

    String getLogin(){
        return login;
    }

    int getPassword(){
        return password;
    }

}
