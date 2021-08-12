package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        int[] a={5, 4, 3, 2, 1};
        StringBuilder b = new StringBuilder();
        try
        {
            a[5]=10;
        }
        catch(Exception e)
        {
            System.out.println(a[0]);
        }
        for(int i=0; i<a.length; ++i)
        {
            System.out.println(i + "-" + a[i]);
        }
        for(var i=0; i<a.length; ++i) {
            String x;
            x = System.in.toString();
            b.append(a[a.length - i - 1]);
            System.out.print(b.toString() + " ");
        }
    }
}

