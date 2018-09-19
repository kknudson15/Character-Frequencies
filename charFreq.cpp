#include <iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
  int filecount =1;
  int e = 0,t=0,a=0,o=0,i=0,n=0,s=0,h=0,r=0, sum =0;

  string outName;
  string inName;
  char letter;

  ifstream infile;
  ofstream outfile;

  cout << "Welcome! How many Files are you processing:";
  cin >> filecount;

  cout << "\n Please input the name of the output file:";
  cin >> outName;
  outfile.open(outName.c_str()); //opens output stream

  for(int x = 0; x<filecount;x++)
  {
    cout << "\n Please input the name of the file:";
    cin >> inName;

	infile.open(inName.c_str()); //opens input stream
	infile.get(letter); //gets the first character

	while(!infile.eof()) //while not processing the end of line character
	{
		letter = tolower(letter); // converts all characters to lower case

		switch(letter) //counts the letters we are interested
		{
			case 'e':
				e++;
				break;
			case 't':
				t++;
				break;
			case 'a':
				a++;
				break;
			case 'o':
				o++;
				break;
			case 'i':
				i++;
				break;
			case 'n':
				n++;
				break;
			case 's':
				s++;
				break;
			case 'h':
				h++;
				break;
			case 'r':
				r++;
				break;
			default:
				break;
		}

		infile.get(letter); //gets the next character

	}

	sum = e + t + a + o + i + n + s + h + r;


	outfile << "File name: " << inName << endl;
	outfile << "E's:" << e << endl;
	outfile << "T's:" << t << endl;
	outfile << "A's:" << a << endl;
	outfile << "O's:" << o << endl;
	outfile << "I's:" << i << endl;
	outfile << "N's:" << n << endl;
	outfile << "S's:" << s << endl;
	outfile << "H's:" << h << endl;
	outfile << "R's:" << r << endl;
	outfile << "Total Number of characters:" << sum << endl;
	outfile << "--------------------------------------------------------" << endl;

	e = 0,t=0,a=0,o=0,i=0,n=0,s=0,h=0,r=0, sum =0; //clears counts to 0 before moving on to next file.

	cout << inName << " has been processed" << endl; // lets user know that the file was processed.

	infile.close();
	infile.clear(); // clears input stream because we use the same one for all the files.

  }

  outfile.close(); //closes output stream after all processing.

  return 0;
}
