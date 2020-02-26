#include "String.h"


const size_t String::npos = -1; // Max size that an unsigned int can hold.

const size_t String::INIT_CAP = 50; // Initial capacity.


// Constructors for the String class


String::String() 
{
    cap = INIT_CAP;
    p = (char*) malloc(cap * sizeof(char));
    p[0] = '\0';
    sz = 0;
}


// Creates a copy of string S


String::String(const String &s)
 {
    cap = INIT_CAP;
    p = (char*) malloc(cap * sizeof(char));
    sz = s.sz;
    if (sz >= cap)
	{
        expandMem(cap);
    }                
    strcpy(p, s.p); // Copy s's content into p
}


// Creates a copy of portion of string S that begins at position pos 


String::String(const String &s, const size_t &pos, const size_t &n)
 {
    cap = INIT_CAP;
    p = (char*) malloc(cap * sizeof(char));
    sz = n;
    if (sz >= cap)
	{
        expandMem(cap);
    }

    // Iterate through the String

    size_t i = 0;
    for (; (i < sz) && (i + pos < s.sz); i++) {
        p[i] = s.p[i + pos];
    }
    p[i] = '\0';
}


// Creates a string from the copy of first n characters


String::String(const char *c, const size_t &n) 
{
    cap = INIT_CAP;

    p = (char*) malloc(cap * sizeof(char));
    sz = n;
    if (sz >= cap)
	{
        expandMem(cap);
    }
    size_t i = 0;
    for(; (i < n) && (i < strlen(c)); i++)
	{
        p[i] = c[i];
    }
    p[i] = '\0';
}


//creates a string from a copy of characters of c-string s


String::String(const char *s)
 {
    cap = INIT_CAP;
    p = (char*) malloc(cap * sizeof(char));

   // Simply copy the s into the p

    sz = strlen(s);
    if (sz >= cap)
	{
        expandMem(cap);
    }

    // Copy s into p

    strcpy(p, s);
}


//cretaes a string from a copy of n repetitions of character c


String::String(const size_t &t, const char &c)
 {
    cap = INIT_CAP;

    p = (char*) malloc(cap * sizeof(char));

    sz = t;
    if (sz >= cap)
	{
        expandMem(cap);
    }
    for (size_t i = 0; i < t; i++)
	{
        p[i] = c;
    }
    p[sz] = '\0';
}


// Destructor for the String class


String::~String()
{
    // Deallocate the memory.
    free(p);
}


// Overloads assignment operator for Strings


String &String::operator=(const String& s)
 {
    // Copy the size from s to the current String
 
	sz = s.sz;
    if (sz >= cap)
	{
        expandMem(cap);
    }

    // Copy all the characters from s to this string

    for (size_t i = 0; i < sz; i++)
	{
        p[i] = s.p[i];
    }

    // Terminate the string
   
   p[sz] = '\0';

    // Return this string

    return *this;
}


//Assigns a copy of C-String s to a string


String &String::operator=(const char* s)
{

    // Simply copy the s into the p

    sz = strlen(s);
    if (sz >= cap)
	{
        expandMem(cap);
    }

    // Copy the content from s into p

    strcpy(p, s);

    return *this;
}


// Assigns a copy of character c to a string


String &String::operator=(const char& c)
{

    // Assign a single character

    sz = 1;
    if (sz >= cap)
	{
        expandMem(cap);
    }

    // Set the character and terminate the string

    p[0] = c;
    p[1] = '\0';
    return *this;
}

// Overloads += operator for Strings
String &String::operator+=(const String& s)
{
    sz += s.sz;

    // Temp array for merging the two strings

    char *tmp = (char*) malloc((sz + 1) * sizeof(char));

    // Copy p into t

    strcpy(tmp, p);

    // Concat s.p with tmp

    strcat(tmp, s.p);

    if (sz >= cap)
	{
        expandMem(cap);
    }

    // Copy tmp into p
    
	strcpy(p, tmp);

    // Return
	
    return *this;
}


// Appends a copy of c-string cs to a string.


String &String::operator+=(const char* cs)
{
    // Concat a c-string to our current string
    String tmp(cs);
    *this += tmp;
    return *this;
}


// Appends a copy of character c to a string.


String &String::operator+=(const char& c)
{
    // Add a single character to the string
    
	String tmp(1, c);
    *this += tmp;
    return *this;
}


// Returns the length of a string


size_t String::length() const
{
    return sz;
}


// Returns the size of a string


size_t String::size() const
{
    return sz;
}


// Returns number of characters that a string can hold.


size_t String::capacity() const
{
    
	// Return the capacity -1
    
	return cap - 1;
}


// Check whether string is empty


bool String::empty() const 
{
    return *this == String();
}


// Erase all characters of a string.


void String::clear() 
{
    strcpy(p, "");

    // reset size

    sz = 0;
}


// Appends a copy of the character c to a sting,increasing its size by one.


void String::push_back(const char& c) 
{
    // Use the overloaded += for const char&
    
	*this += c;
}


// Returns reference to index


char& String::operator[](const size_t &i)
{
    return p[i];
}


// Returns a constant reference to the character at index i


const char& String::operator[] (const size_t& i) const
{
    return p[i];
}


// Returns a reference to character at poition of a string and performs a range check.


char& String::at(const size_t& pos)
{
    if (pos >= sz)
	{
        cout<<"out_of_range exception!";

        // if we have an out of range error, return an empty character ( or something else? )

        return p[sz];
    } 
	else 
	{
        return p[pos];
    }
}

// Constant version of index function
const char& String::at(const size_t& pos) const 
{
    if ( pos >= sz) 
	{
        cout<< "out_of_range exception!";
    
		// if we have an out of range error, return an empty character ( or something else? )

        return p[sz];
    }
    return p[pos];
}

String String::substr(const size_t& pos, const size_t& n) 
{

    // If pos is equal to the length of the string, return an empty string

    if (pos == this->length()) 
	{
        return String();
    } 
	else if (pos > this->length() ) 
	{
    
		// If pos is higher than the length of the string, return an empty string and an error
        
		cout<<"out_of_range exception!";
        return String();
    } 
	else 
	{
        
		// If pos is smaller than the length of the String create a temporary string
        
		String tmp;
        
		// Add characters to it
        
		for (size_t i = 0; (i < n) && (i + pos < sz); i++) 
		{
        
			// Check again if we don't go out of the range

            tmp += p[i + pos];
        }
        return tmp;
    }
}

const char* String::c_str() const 
{
    // Return the internal buffer, which is a c-string
    
	return p;
}

const char* String::data() const 
{

    // Return the internal buffer, which is a c-string

    return p;
}

void String::expandMem(const size_t& n)
{
    
	// Allocate memory for a temporary buffer

    char* tmp = (char*) malloc((cap) * sizeof(char));
    
	// Copy the current buffer into the tmp buffer
    
	strcpy(tmp, p);
    
	// Free the current buffer
    
	free(p);
    
	// Allocate memory for the new buffer ( n extra bytes )
    
	p = (char*) malloc((cap + n) * sizeof(char));
    
	// Copy back p's content
    
	strcpy(p, tmp);
    
	// Free tmp
    
	free(tmp);
    
	// Extend the capacity
    
	cap += n;
}

// Overloads stream insertion and extraction operators for Strings
ostream& operator<<(ostream &os, const String &s) 
{

    for (size_t i = 0; i < s.sz; i++) 
	{ 
		// Insert each character.
        os << s.p[i];
        if(s.p[i] == '\0') 
		{ 
			
			// If we get to a '\0', break out of the loop
            
			break;
        }
    }

    return os; // Returns stream
}

istream& operator>>(istream &is, String &s)
{
    return getline(is, s); // Getline
}

istream& getline(istream &is, String &s, const char &del)
{
    char ch;
    s.clear(); // Clear the string
    while (is.get(ch) && ch != del) 
	{ 
		// Read all the characters from the istream till we reach the del or the istream ends
        s.push_back(ch);
    }
    return is; // Return string
}


// For string concateination we are using operator overloading


String operator+(const String& s1, const String& s2) 
{
    String a(s1);
    a += s2;
    return a; // Returns newly constructed string with the value being concatenated s1 followed by s2
}

String operator+(const String& s, const char* c) 
{
    String a(s);
    a += c;
    return a; // Returns newly constructed string with the value being concatenated s followed by c
}

String operator+(const char* c, const String& s) 
{
    String a(c);
    a += s;
    return a; // Returns newly constructed string with the value being concatenated c followed by s
}

String operator+(const String& s, const char& c) 
{
    String a(s);
    a += c;
    return a; // Returns newly constructed string with the value being concatenated s followed by char c
}

String operator+(const char& c, const String& s) 
{
    String a;
    a += c;
    a += s;
    return a; // Returns newly constructed string with the value being concatenated char c followed by s
}


// Relational operators


bool operator==(const String &s1, const String &s2) 
{
    return strcmp(s1.p, s2.p) == 0; // Tests whether string s1 and string s2 are same. 
}


bool operator!=(const String& s1, const String& s2) 
{
    return !(s1 == s2); // Tests whether string s1 and string s2 are different.
}

bool operator< (const String& s1, const String& s2)
{
    return strcmp(s1.p, s2.p) < 0; // Tests whether string s1 comes before string s2.
}


bool operator<=(const String& s1, const String& s2) 
{
    return (s1 == s2) || (s1 < s2); // Tests whether string s1 comes before string s2.
}

bool operator> (const String& s1, const String& s2) 
{
    return (s1 != s2) && !(s1 < s2); // Tests whether string s1 comes before string s2.
}


bool operator>=(const String& s1, const String& s2) 
{
    return (s1 == s2) || (s1 > s2); // Tests whether string s1 and s2 in ascii order or are they same.
}
