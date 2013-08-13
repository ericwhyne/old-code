#include <iostream.h>
int main()
{
	//This datatype can also be a char or even an array, but remember than an array's name is already a pointer.
	char *ptr;

 //This will reverse the pointer to the beginning of memory.
/*	while(*ptr != NULL)
	{
		ptr--;
	}

	ptr++;

*/
	int i = 1;
		
	while(*ptr != NULL)
	{
		i++;
		ptr++;
		cout<<*ptr<<endl;
	}
	cout<<endl<<i<<endl;
	return 0;
}
