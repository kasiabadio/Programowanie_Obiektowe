package recycling;

import java.util.Scanner;

public class Wezel {
    @Deprecated
    @Override
    protected void finalize() throws Throwable {
        System.out.println("Finalizowanie obiektu");
        super.finalize();
    }

    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        for(int i = 0; i <= 10000; i++){
            new Wezel();
        }
        s.nextLine();
        s.close();
    }
    
}
