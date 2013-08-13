//  cipher.cpp  --  mini-RSA encryption routine
//  Written by David L. Clarke 
//  Modified by S. L. Fitzhugh 29 Feb 2004 
//  Modified by Eric Whyne - March 2004 


#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <string>	    // string class (avoid using strcmp/strcpy)
#include <bitset>

using namespace std;

union ch_int
{
   char  Ch[2];
   int Int; //this is better as an integer instead of a short... - Eric
};

int power(int a, int b) //I use this function in int2ch() - Eric
{
	if(b==0) return 1; // Special Case. - Eric
	int counter = 1;
	int result = a;
	for(counter; counter < b; counter++)
	{
		result = (result * a);
	}
	return result;
}

class transcribe
{
   ch_int  CI;
public:
           transcribe() {}
   int     ch2int();
   int     int2ch();
   int     getInt();
   void    putInt(int);
   void    wrtInt();
   void    wrtCh ();
};

int transcribe::ch2int()
{
   CI.Int = 0;
	char temp[3];       // need extra array location for get()
	cin.get(temp,3,'\0'); //Get next 2 characters, stop when \0 is encountered. - Eric
	

   if(temp[0] == '\0') 
   	return (0);
   else {
   	for(int n = 0; n<2; n++){
		CI.Ch[n] = temp[n];
		}
	 return (1);
      };
     }

int transcribe::int2ch()
{
   char  dig[4];
   int   i, j, k = 0;

   for (i = 0;  i < 4;  i++)
   {
      if ( ! (cin.get(dig[i])) )  return 0;
      if (dig[i] == '\n' && ! (cin.get(dig[i])))  return 0;
      if (dig[i] <= '9')  j = int(dig[i]) - int('0');
      else                j = int(dig[i]) - int('a') + 10;
      k = k * 16 + j;
   }
   CI.Int = k;
   return 1;
}

int  transcribe::getInt()        {  return (CI.Int);  }

void transcribe::putInt(int i)   {  CI.Int = i;  }


void transcribe::wrtInt()
{
   cout << hex << setw(4) << setfill('0') << CI.Int;
}

void transcribe::wrtCh()
{
   cout << CI.Ch[0] << CI.Ch[1];
}



int modular_exponentiation (int a, int b, int n)
{
	if(b==0) return 1; //Special case. - Eric
	int counter = 1;
	int result = a;
	for(counter; counter < b; counter++) //Need to take little pieces so we don't overflow our integer space! - Eric
	{
		result = (result * a) % n;
	}
	return result;
}

int Usage(char pname[])
{
	cout<<endl<<"Usage: "<<pname<<" <mode> <key> <n> "<<endl<<endl
	    <<"\t<mode> is either encryption or decryption (e or d)"<<endl
	    <<"\t<key> is the public or private key being used in integer form"<<endl
	    <<"\t<n> is the mod to use"<<endl
	    <<endl<<"\tOptionally key or n may be specified as 0 to use the default key of 569 and default n of 33043"<<endl<<endl;
	return 1;
}
// Eric Notes:
// key = "79"; //private
// key = "1019"; //public
// mod = "3337"; //N

int main(int argc,  char *argv[])
{
   transcribe  trans;
   string      key, mod, mode;
   int         K,   N;
   int         col = 0;
   
   if (--argc < 3){ return Usage(argv[0]);}
   else
   {
   	mode = argv[1];
 	if(argv[2][0] == '0') key  = "2667";  // "569"; // default public key.	
      	else key  = argv[2];
	if(argv[3][0] == '0') mod  = "4141";  // "33043";		// default modulus
      	else mod  = argv[3];
   }

   K = atoi(key.data());
   N = atoi(mod.data());

   if (mode[0] == 'e' || mode[0] == 'E')
   {
      while ( trans.ch2int() && col < 72 )
      {
      
         trans.putInt(modular_exponentiation(trans.getInt(), K, N));
         trans.wrtInt();  col += 4;
         if (col >= 72)
         {
            col = 0;
            cout << endl;
         }
      }
      cout << endl;
   }
   else if (mode[0] == 'd' || mode[0] == 'D')
   {
      while ( trans.int2ch() )
      {
         trans.putInt(modular_exponentiation(trans.getInt(), K, N));
         trans.wrtCh();
      }
      cout << flush;
   }
   else
   {
   	Usage(argv[0]);
   }

   return EXIT_SUCCESS;
}

