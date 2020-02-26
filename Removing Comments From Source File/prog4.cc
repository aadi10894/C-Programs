/*In this program we take the data from the input file prog4-in.cc(This file has comments in it) and then remove the comments from this file and copy the 
  complete data into an output file called prog4-out.cc(so basically this file has same data as in input files except the commented lines).*/


//Importing the header file into our program what we created. Header file consists of constants and prototypes.

#include"prog4.h"


//The following function is used to close the input and outfile file.

void close_files(ifstream& is, ofstream& os){
	is.close();  
	os.close();
}


/*With the help of the following function we will remove the single line and block line comments from the input file prog4-in.cc and output the file without 
  the comments into output file porg4-out.cc*/ 

void process_data(ifstream& is, ofstream& os)
{
	string text;
	int SingleLineCommentPos;
	int BlockLineCommentPos;
	bool flag = false;
	while(getline(is, text))
	{	
		SingleLineCommentPos = text.find("//");
		BlockLineCommentPos = text.find("/*");
		

		//Condition to check if the line passed is still inside the comments section i.e. the line is a comment or not.
		
		if(flag && (text.length() != 0))
		{
			if(text.substr(text.length() -2) == "*/")
			{
				flag = false;
			}
			text = text.erase(0, text.length());			
		}


		//Condition to remove comments starting from the SingleLineComment i.e. //

		else if((SingleLineCommentPos != -1 && BlockLineCommentPos == -1 && text[SingleLineCommentPos -1] != '\"') || 
			   (SingleLineCommentPos != -1 && (SingleLineCommentPos < BlockLineCommentPos) && text[SingleLineCommentPos -1] != '\"'))
			   {
					text = text.erase(SingleLineCommentPos, text.length());			
			   }
				

		//Condition to remove comments starting from the BlockLineCommentPos i.e. /*

		else if((BlockLineCommentPos != -1 && (BlockLineCommentPos < SingleLineCommentPos) && text[BlockLineCommentPos -1] != '\"') || 
			(BlockLineCommentPos != -1 && SingleLineCommentPos == -1 && text[BlockLineCommentPos -1] != '\"')){
			if(text.substr(text.length() -2) != "*/"){
				flag = true;
			}
			text = text.erase(BlockLineCommentPos, text.length());
		}	
		
		//Here copying the line without any comments to the output file
		if(os.is_open())
		{
			os<<text<<endl;
		}
	}
}


//This function is used to open up the input and output files
void open_files(ifstream& is, ofstream& os)
{
	is.open(INFILE);  //opening the input file
	os.open(OUTFILE); //opening the output file
	if(is.fail() || os.fail()) //checking for error in file
	{  
		cout<<"Error in file"<<endl;
		exit(EXIT_FAILURE);
	}
}



int main()
{
	ifstream is;  //creating object for input stream
	ofstream os;  //creating object for output stream
	open_files(is, os); //calling open_files so that we can open up the files
	process_data(is, os);  //calling the process_data function for removing comments within the data
	close_files(is, os); //calling this function to close the input and output file 
	return 0;
}
