package Lab6_java;

public class AccountNotFoundException extends Throwable {
    public AccountNotFoundException(String message){
        super(message);
    }
}
