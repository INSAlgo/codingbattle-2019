using System; 
using System.Linq;
using System.Collections.Generic;

class GFG { 

    // Main Method 
    static public void Main(String[] args) 
    {
		string input = Console.ReadLine();
		string pattern = @":";
		string[] numbers = System.Text.RegularExpressions.Regex.Split(input, pattern);
		int localH = int.Parse(numbers[0]);
		int localM = int.Parse(numbers[1]);

		int ETMinsInEarthMin = int.Parse(Console.ReadLine());
		int ETMinsInETHour = int.Parse(Console.ReadLine());

		int resMins = (int) Math.Floor(((localH * ETMinsInETHour) + localM) / ETMinsInEarthMin * 1.0); //yeah ... Math.Floor return a double
		int resHours = (int) Math.Floor(resMins / 60.0) % 24;
		resMins = resMins % 60;

		Console.WriteLine(resHours + ":" + resMins);
    }
} 
