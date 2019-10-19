using System; 
  
class GFG { 
  
    // Main Method 
    static public void Main(String[] args) 
    {
		int nbPerson = int.Parse(Console.ReadLine());
		int nbSeat = int.Parse(Console.ReadLine());

		Console.WriteLine(Math.Ceiling(nbPerson / (double) nbSeat));
    } 
} 
