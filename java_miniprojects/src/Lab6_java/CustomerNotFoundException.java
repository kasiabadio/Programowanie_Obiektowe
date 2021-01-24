package Lab6_java;

public class CustomerNotFoundException extends Throwable {
    public CustomerNotFoundException(String message){
        super(message);
    }
}
