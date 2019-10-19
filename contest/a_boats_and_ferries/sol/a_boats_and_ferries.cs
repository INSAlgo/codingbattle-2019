using System; 
using System.Linq;
using System.Collections.Generic;

class GFG { 

    // Main Method 
    static public void Main(String[] args) 
    {
		int p = Convert.ToInt32(Console.ReadLine());
		int b = Convert.ToInt32(Console.ReadLine());
		int f = Convert.ToInt32(Console.ReadLine());

		Console.WriteLine(Math.Max(p - (500 * f + 4 * b), 0));
    }
} 
