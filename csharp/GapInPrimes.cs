using System;
using System.Collections.Generic;

class GapInPrimes {

    public static void Main(){

        long[] test = Gap(10, 300, 400);

	if(test != null) {
	    foreach(var i in test){
		Console.WriteLine(i);
	    }	    
	}
	else
        {
            Console.WriteLine("null");
        }

    }

    /* 
       This is a problem from CodeWars
       Exceeding execution time, 
       Need to optimize
    */

    static List<long> primes = new List<long>();
    public static long[] Gap(int g, long m, long n){
        long s = m;
	while(n - s >= g){
	    if(isPrime(s) && isPrime(s + g)) {
                bool bet = false;
                for (int i = 1; i < g; i++){
		    if(isPrime(s+i)) {
			bet = true;
                        break;
                    }
                }
		if(!bet)
		    return new long[2] { s, (s + g) };
            }
	    
            s++;
        }
        return null;
    }

    public static bool isPrime(long s){
	// if(primes.Contains(s)) return true;

        for (long i = 2; i < s / 2; i++){
	    if(s % i == 0) {
                return false;
            }
        }

	// primes.Add(s);
	return true;
    }

}
