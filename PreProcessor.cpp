
//Objective:
//make: 11,10,00
//into: 3,2,0

// Libraries------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>

using namespace std;               

//Globabl Variables-----------------------------------------------------------------------------------------
string INPUT = "input.txt";
string OUTPUT = "output.txt";  //these globabl variables are used for the input and output files

//Functions-------------------------------------------------------------------------------------------------

//Function checks to see if Files can be accessed
void checkFiles()
{
	ofstream outputFile;
	ifstream inputFile;

	inputFile.open(INPUT);
	if (inputFile.is_open())
		cout << "Input File opened successfully." << endl;
	else
		cout << "InputFile has failed to open." << endl;

	inputFile.close();

	outputFile.open(OUTPUT);
	if (outputFile.is_open())
		cout << "Output File opened successfully." << endl;
	else
		cout << "Output File has failed to open." << endl;

	outputFile.close();



	return;
}

//Function removes previous data written to the output File
void clearOutputFile()
{
	ofstream outputFile;

	outputFile.open(OUTPUT, std::ofstream::out | std::ofstream::trunc);			//clears everything within the file
	outputFile.close();

	return;
}

//Function reads the input file character by character then converts the data from binary to decimal
//then outputs it to the output File
//make: 11,10,00
//into: 3,2,0
void readConvertAndWrite()
{
	ofstream outputFile;
	ifstream inputFile;
	char character;
	int counter = 0;						//used to keep track of how many numbers have been written to the outputFile

	inputFile.open(INPUT);
	outputFile.open(OUTPUT);
	
	while (inputFile.get(character))
	{
		//3 possible cases char is a 1 or 0 or ,

		//case 1
		if (character == '1')
		{
			inputFile.get(character);		//check next character

			if (character == '0')
			{
				//binary 10 so output 2
				outputFile << "2";
				counter++;
			}
			else if (character == '1')
			{
				//binary 11 so output 3
				outputFile << "3";
				counter++;
			}
			else
				cout << "Case 1: Error" << endl;
		}
		//case 2:
		else if (character == '0')
		{
			inputFile.get(character);		//check next character

			if (character == '0')
			{
				//binary 00 so output 0
				outputFile << "0";
				counter++;
			}
			else if (character == '1')
			{
				//binary 01 so output 1
				outputFile << "1";
				counter++;
			}
			else
				cout << "Case 2: Error" << endl;
		}
		//case 3
		else if (character == ',')
		{
			//just wrtie a , to the outputFile
			outputFile << ",";
		}
		//case unkown
		else
			cout << "Error unkown character" << endl;

	}

	cout << counter << " numbers have been converted from binary to decimal" << endl;


	inputFile.close();
	outputFile.close();
	return;
}






//Main---------------------------------------------------------------------------------------------

void main()
{
	ofstream outputFile;
	ifstream inputFile;

	
	checkFiles();
	clearOutputFile();
	readConvertAndWrite();
	


	system("pause");
	return;
}

