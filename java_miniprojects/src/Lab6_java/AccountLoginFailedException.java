package Lab6_java;

class AccountLoginFailedException extends Exception{
    static final long serialVersionUID = 1L;
    private Customer owner;
    private int password;
    private String login;

    AccountLoginFailedException(){}
    AccountLoginFailedException(Customer _owner, int _password, String _login){
        owner = _owner;
        password = _password;
        login = _login;
    }

    AccountLoginFailedException(String errorMsg, String _login, int _password){
        super(errorMsg);
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
