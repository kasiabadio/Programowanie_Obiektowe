package Lab7_java;

import java.lang.*;
import java.io.*;

// typy generyczne:
// tworzenie bardziej złożonych klas
// sprawdzanie poprawności typów na etapie kompilacji

public class GenericsType<T> {
    private T t;

    public T get(){
        return this.t;
    }

    public void set(T t1){
        this.t = t1;
    }

    public static void main(String[] args){
        // prints PUT
        GenericsType<String> type = new GenericsType<>();
        type.set("PUT");
        System.out.println(type.get());

        // prints UAM
        GenericsType<Serializable> type1 = new GenericsType<>();
        type1.set("UAM");
        System.out.println(type1.get());

        // prints 10
        type1.set(10);
        System.out.println(type1.get());

        Checker<Integer> isOddAnonymous = new Checker<Integer>(){
            @Override
            public boolean check(Integer object) {
                return object % 2 != 0;
            }
        };

        System.out.println(isOddAnonymous.check(123)); // true
        System.out.println(isOddAnonymous.check(124)); // false

        Checker<Integer> isOddLambda = object -> object % 2 != 0;
        System.out.println(isOddLambda.check(123)); // true
        System.out.println(isOddLambda.check(124)); // false
    }
}
