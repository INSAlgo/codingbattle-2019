using System; 
using System.Linq;
using System.Collections.Generic;
using System.Globalization;

class GFG { 

	static public double distance(double x1, double y1, double x2, double y2){
		return Math.Sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	}

    // Main Method 
    static public void Main(String[] args) 
    {
		string input = Console.ReadLine();
		string pattern = @" ";
		string[] numbers = System.Text.RegularExpressions.Regex.Split(input, pattern);

		double Xb = double.Parse(numbers[0], CultureInfo.InvariantCulture);
		double Yb = double.Parse(numbers[1], CultureInfo.InvariantCulture);

		input = Console.ReadLine();
		numbers = System.Text.RegularExpressions.Regex.Split(input, pattern);
		int N = int.Parse(numbers[0]);
		int T = int.Parse(numbers[1]);		
		int vitesseMax = 100;
		List<string> coupables = new List<string>();
		double lastX = 0;
		double lastY = 0;

		for(int i = 0; i < N; i++){
			string suspect = Console.ReadLine();
			bool criminel = false;
			for(int j = 0; j < T; j++){
				input = Console.ReadLine();
				numbers = System.Text.RegularExpressions.Regex.Split(input, pattern);
				double X = double.Parse(numbers[0], CultureInfo.InvariantCulture);
				double Y = double.Parse(numbers[1], CultureInfo.InvariantCulture);

				if(j > 0 && distance(lastX, lastY, Xb, Yb) + distance(Xb, Yb, X, Y) <= vitesseMax)
					criminel = true;
				lastX = X;
				lastY = Y;
			}
			if(criminel)
				coupables.Add(suspect);
		}

		Console.WriteLine(String.Join(" ", coupables));
    }
} 
