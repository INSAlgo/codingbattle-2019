using System; 
using System.Linq;
using System.Collections.Generic;

class GFG { 

    // Main Method 
    static public void Main(String[] args) 
    {
		int N = int.Parse(Console.ReadLine());
		List<int> tab = new List<int>();
		string input = Console.ReadLine();
		string pattern = @"\s";
		string[] numbers = System.Text.RegularExpressions.Regex.Split(input, pattern);

		foreach(string s in numbers){
			tab.Add(int.Parse(s));
		}

		tab = tab.OrderBy(o => o).ToList();

		int a = 0, b = 0, c = 0;
		int mini = -1;
		bool first = true;
		for(int i = 0; i < N - 2; i++) {
			if(first || tab[i + 2] - tab[i] < mini){
				first = false;
				a = tab[i];
				b = tab[i + 1];
				c = tab[i + 2];
				mini = tab[i + 2] - tab[i];
			}
		}
    	Console.WriteLine(a + " " + b + " " + c);
    }
} 
