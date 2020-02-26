/* In this program we are encoding the text with the help of Caesar cipher technique. We have two data files prog3.d1 (Reading the shift and key values) and using this file we are going to encode contents present in  prog3.d2 */

#include "prog3.h"

// In the following function for character 'c' of the shift value and the second shift value obtained from the key, it returns the new position of 'c' after shifting.

int new_position(const char& c, const int& shift, const string& key)
{
	int newPosition = 0;
	int charIndex = alphabets.find(toupper(c)); //Here we are getting the Index of character 'c' in alphabets string.
        char ValueOfIndexInKey = key[charIndex]; // Here we are getting the value at index that we obtained from the above step in the key string.
	int diff = ((int(toupper(c)) - int(ValueOfIndexInKey)) + shift); //Here we are calculating the difference inorder to shift the letters.
	if(diff > 0)
	{
		for(int var = charIndex + 1; var <= (charIndex + diff); var++)
		{
			newPosition = var % 26; //Since we have 26 alphabets
		}
	}
	else if(diff < 0)
	{
		while(diff < 0)
		{
			(charIndex == 0) ? charIndex = 25 : charIndex -=1;
			newPosition = charIndex % 26;
			diff += 1;
		}
	}	
	else
	{
		newPosition = charIndex;
	}
	return newPosition;
}

/* The following function returns a new string formed by shifiting every letter in the string forward the number of letters indicated by shift and key, cycling back to the beginning of the alphabe if necessary. To implement shifting this function calls the auxillary function new_position */

string encodeCaesarCipher(string str, const int& shift, const string& key)
{
	string encodedString;
	for(unsigned int i = 0; i < str.length(); i++)
	{
		//We are checking if the character is a letter or not
		if(isalpha(str[i]))
		{
			//We are checking if the character is in lower case and upper case and passing the character to the new_position function which returns the new position of x
			encodedString += (islower(str[i])) ? tolower(alphabets[new_position(str[i], shift, key)]) : alphabets[new_position(str[i], shift, key)];
		}
		else
		{
			encodedString += str[i];
		}
	}
	return encodedString;
}

/* The following function opens up the second file prog3.d2 to resd the text to encode and if it can't open it displays and error message. It prints out the shift and key values and gets the text input from the data file. To process each input file it calls encodeCaesarCipher function and prints out the encrypted text returned by this function and finally it closes the data file. */

void process_infile(const int& shift, const string& key)
{
	string texttoEncode;
	string encryptedText;
	ifstream secondFile; //Here we are creating the file object to read the text encode from the second file.
	secondFile.open(SECONDFILE);
	if(secondFile.is_open())
	{
		//After opening the file, condition to check if the file is opened or not
		while(getline(secondFile, texttoEncode))
		{
			//We are reading the text from the second data file.
			encryptedText += encodeCaesarCipher(texttoEncode, shift, key) + "\n"; //here encodeCaesarCipher is called hich returns encodedString
		}
		secondFile.close();
	}
	else if(secondFile.fail())
	{
		cout<<"Error couldn't open the file"<<endl;
		exit(EXIT_FAILURE);
	}

	//We are printing the shift, key and encryptedText
	
	cout<<"Shift = "<<shift<<endl;
	cout<<"Key = "<<'"'<<key<<'"'<<"\n"<<endl;
	cout<<encryptedText<<endl;
}

int main()
{
	int shift;
	string key;
	ifstream firstFile; //Here I am creating the object ifstream to read from the file prog3.d1
	firstFile.open(FIRSTFILE); //Opening the file prog3.d1
	if(firstFile.is_open())
	{
		//Condition to check if the file is opened or not.
		while(firstFile >> shift >> key) // Here we are reading the shift and key value from the file one after another till the end of file.
		{
			process_infile(shift, key); //Here process_infile function is called where we are passing the shift and key values from the file.
		}
		firstFile.close();
	}
	else if(firstFile.fail())
	{
		//Condition which satisfies in case any error occurs in the file.
		cout<<"Error in file"<<endl;
		exit(EXIT_FAILURE);
	}
	return 0;
}	
