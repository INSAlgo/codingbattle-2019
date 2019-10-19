using System; 
using System.Linq;
using System.Collections.Generic;

class GFG { 
  
	static string SortString(string input)
	{
	    char[] characters = input.ToArray();
	    Array.Sort(characters);
	    return new string(characters);
	}

    // Main Method 
    static public void Main(String[] args) 
    {
		string M = Console.ReadLine();
		string MSorted = SortString(M);
		int N = int.Parse(Console.ReadLine());

		List<string> outDic = new List<string>();

		for(int i = 0; i < N; i++) {
			String m = Console.ReadLine();
			if(m[0] == M[0] && m[m.Length - 1] == M[M.Length - 1]) {
				String mSorted = SortString(m);
				if(mSorted == MSorted)
					outDic.Add(m);
			}
		}

		outDic.Sort();
		
		foreach(String s in outDic) {
			Console.WriteLine(s);
		}
    } 
} 
