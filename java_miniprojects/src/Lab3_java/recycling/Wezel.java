package Lab3_java.recycling;

import java.util.*;

public class Wezel {
    ArrayList<Wezel> polaczenia = new ArrayList<>();
    public HashMap<Wezel, Boolean> polaczenia_hashmap = new HashMap<>();
    //public Map<Wezel, Boolean> polaczenia_treemap = new TreeMap<Object, Boolean>();


    @Deprecated
    @Override


    protected void finalize() throws Throwable{
        System.out.println("Finalizowanie obiektu");
        super.finalize();
    }

    void dodajPolaczenie(Wezel w){
        polaczenia.add(w);

    }

    void dodajPolaczenieHashmap(Wezel w, boolean b){
        polaczenia_hashmap.put(w, b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i <= 1000000; i++) {
            // arraylist
            Wezel w1 = new Wezel();
            Wezel w2 = new Wezel();
            w1.dodajPolaczenie(w2);
            w2.dodajPolaczenie(w1);

            // hashmap
            Wezel w3 = new Wezel();
            Wezel w4 = new Wezel();
            w3.dodajPolaczenieHashmap(w4, true);
            w4.dodajPolaczenieHashmap(w3, true);


        }
        scanner.nextLine();
        scanner.close();
    }

}
