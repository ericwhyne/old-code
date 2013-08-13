/*

procinfo.c
Eric Whyne Feb 2003

This program is a quick program to grab some information from the /proc filesystem found on most unix machines.

Note: 
All of this information can be found without this program by typing in the following commands:

CPU information:
cat /proc/cpuinfo | grep -e vendor -e "model name"

Kernel information:
cat /proc/version

System uptime:
uptime


*/

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

void useage(char progname[]);

int main (int argc, char *argv[])
{
	FILE *InfoFile;
	char buffer;
	long utime;
	int days, hours, minutes, seconds;
	int used = FALSE;
	
	char *FileName; 
	FileName = malloc(50);

	if(FileName == NULL)
	{
		printf("Memmory Allocation Error.\n");
		return 1;
	}

	if(argv[1] == NULL)
	{
		useage(argv[0]);
		return 1;
	}

	if(argv[1][0] == 'k' || argv[1][1] == 'k' || argv[1][2] == 'k' || argv[1][3] == 'k')
	{
		FileName = "/proc/version";
		
		printf("\n Kernel Version Information:\n");

		if ((InfoFile = fopen(FileName, "r")) != NULL )
		{
			while( (buffer = fgetc(InfoFile)) != EOF)
			{
				printf("%c", buffer);
			}
		
			fclose(InfoFile);
		}
		else
		{
		printf("Could not read system information.\n
			Reason: Can not find correct proc file.\n");
		return 1;
		}
		used = TRUE;
	}	
	if(argv[1][0] == 'c' || argv[1][1] == 'c' || argv[1][2] == 'c' || argv[1][3] == 'c')
	{
		FileName = "/proc/cpuinfo";
		
		printf("\nCPU Information:\n");

		if ((InfoFile = fopen(FileName, "r")) != NULL )
		{
			int linecount = 1;
			while( (buffer = fgetc(InfoFile)) != EOF)
			{
				if(linecount == 2 || linecount == 5)
					printf("%c", buffer);
				if(buffer == '\n') linecount++;
			}
		
			fclose(InfoFile);
		}
		else
		{
		printf("Could not read system information.\n
			Reason: Can not find correct proc file.\n");
		return 1;
		}
		used = TRUE;
	}
	if(argv[1][0] == 'u' || argv[1][1] == 'u' || argv[1][2] == 'u' || argv[1][3] == 'u')
	{
		FileName = "/proc/uptime";
		

		if ((InfoFile = fopen(FileName, "r")) != NULL )
		{
			fscanf(InfoFile, "%d", &utime);
			fclose(InfoFile);
			minutes = utime / 60;
			hours = minutes / 60;
			days = hours / 24;
			seconds = utime % 60;
			minutes = minutes % 60;
			hours = hours % 24;
			printf("\nSystem Uptime: \nDays: %d  \nHours: %d  \nMinutes: %d  \nSeconds: %d\n", days, hours, minutes, seconds);
		}
		else
		{
		printf("Could not read system information.\n
			Reason: Can not find correct proc file.\n");
		return 1;
		}
		used = TRUE;
	}
	if(used == FALSE)
	{	
		useage(argv[0]);
		return 1;
	}

	printf("\n");
	
	return 0;
}

void useage(char progname[])
{
fprintf(stderr, "\nOutputs information about the system.\n   Useage: %s <options>\n Options:\n  
	-h     Display this help and exit.\n  
	-k     Display kernel information.\n  
	-c     Display cpu vendor and model.\n
	-u     Display system uptime.\n\n", progname);
};

