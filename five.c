// Eric Whyne 1998
// Junk code that does something interesting.


#include <stdio.h> 
#include <stdlib.h>



int randnum()
{
  int x = rand() % 5;
  return(x);
}

void main()
{

int solve=0, count=0, startover[5], solved[5], a[5], b[5], c[5], d[5], e[5], x, FALSE=0, TRUE=1, randx=-1 , randy=-1, finished=FALSE;
int probability=0;
 
     for(x=0; x<=4; x++)
     {
       a[x]=FALSE; b[x]=FALSE; c[x]=FALSE; d[x]=FALSE; e[x]=FALSE; solved[x]=FALSE;
       startover[x]=FALSE;
     }

do
{
     randx=randnum();
     randy=randnum();

if(randy==0){if(randnum()>=probability){if(a[randx]==TRUE){randx=randnum();randy=randnum();}}}
if(randy==1){if(randnum()>=probability){if(b[randx]==TRUE){randx=randnum();randy=randnum();}}}
if(randy==2){if(randnum()>=probability){if(c[randx]==TRUE){randx=randnum();randy=randnum();}}}
if(randy==3){if(randnum()>=probability){if(d[randx]==TRUE){randx=randnum();randy=randnum();}}}
if(randy==4){if(randnum()>=probability){if(e[randx]==TRUE){randx=randnum();randy=randnum();}}}








if(randy==0)
  {
    if(randx!=0)
      {
	if(a[randx-1]==TRUE)a[randx-1]=FALSE; else a[randx-1]=TRUE;
      }
    if(a[randx]==TRUE)a[randx]=FALSE; else a[randx]=TRUE;
    if(randx!=4)
      {
	if(a[randx+1]==TRUE)a[randx+1]=FALSE; else a[randx+1]=TRUE;
      }
    if(b[randx]==TRUE)b[randx]=FALSE; else b[randx]=TRUE;
  }

if(randy==1)
  {
    if(a[randx]==TRUE)a[randx]=FALSE; else a[randx]=TRUE;
    if(randx!=0)
      {
	if(b[randx-1]==TRUE)b[randx-1]=FALSE; else b[randx-1]=TRUE;
      }
    if(b[randx]==TRUE)b[randx]=FALSE; else b[randx]=TRUE;
    if(randx!=4)
      {
	if(b[randx+1]==TRUE)b[randx+1]=FALSE; else b[randx+1]=TRUE;
      }
    if(c[randx]==TRUE)c[randx]=FALSE; else c[randx]=TRUE;
  }

if(randy==2)
  {
    if(b[randx]==TRUE)b[randx]=FALSE; else b[randx]=TRUE;
    if(randx!=0)
      {
	if(c[randx-1]==TRUE)c[randx-1]=FALSE; else c[randx-1]=TRUE;
      }
    if(c[randx]==TRUE)c[randx]=FALSE; else c[randx]=TRUE;
    if(randx!=4)
      {
	if(c[randx+1]==TRUE)c[randx+1]=FALSE; else c[randx+1]=TRUE;
      }
    if(d[randx]==TRUE)d[randx]=FALSE; else d[randx]=TRUE;
  }

if(randy==3)
  {
    if(c[randx]==TRUE)c[randx]=FALSE; else c[randx]=TRUE;
    if(randx!=0)
      {
	if(d[randx-1]==TRUE)d[randx-1]=FALSE; else d[randx-1]=TRUE;
      }
    if(d[randx]==TRUE)d[randx]=FALSE; else d[randx]=TRUE;
    if(randx!=4)
      {
	if(d[randx+1]==TRUE)d[randx+1]=FALSE; else d[randx+1]=TRUE;
      }
    if(e[randx]==TRUE)e[randx]=FALSE; else e[randx]=TRUE;
  }

if(randy==4)
  {
    if(d[randx]==TRUE)d[randx]=FALSE; else d[randx]=TRUE;
    if(randx!=0)
      {
	if(e[randx-1]==TRUE)e[randx-1]=FALSE; else e[randx-1]=TRUE;
      }
    if(e[randx]==TRUE)e[randx]=FALSE; else e[randx]=TRUE;
    if(randx!=4)
      {
	if(e[randx+1]==TRUE)e[randx+1]=FALSE; else e[randx+1]=TRUE;
      }
  }




count++;

printf("\n\nx = %d \ny = %d \n\n", randx+1, randy+1); 
if(a[0]==TRUE)printf(" *");else printf(" _");
if(a[1]==TRUE)printf(" *");else printf(" _");
if(a[2]==TRUE)printf(" *");else printf(" _");
if(a[3]==TRUE)printf(" *");else printf(" _");
if(a[4]==TRUE)printf(" *");else printf(" _");
printf("\n");
if(b[0]==TRUE)printf(" *");else printf(" _");
if(b[1]==TRUE)printf(" *");else printf(" _");
if(b[2]==TRUE)printf(" *");else printf(" _");
if(b[3]==TRUE)printf(" *");else printf(" _");
if(b[4]==TRUE)printf(" *");else printf(" _");
printf("\n");
if(c[0]==TRUE)printf(" *");else printf(" _");
if(c[1]==TRUE)printf(" *");else printf(" _");
if(c[2]==TRUE)printf(" *");else printf(" _");
if(c[3]==TRUE)printf(" *");else printf(" _");
if(c[4]==TRUE)printf(" *");else printf(" _");
printf("\n");
if(d[0]==TRUE)printf(" *");else printf(" _");
if(d[1]==TRUE)printf(" *");else printf(" _");
if(d[2]==TRUE)printf(" *");else printf(" _");
if(d[3]==TRUE)printf(" *");else printf(" _");
if(d[4]==TRUE)printf(" *");else printf(" _");
printf("\n");
if(e[0]==TRUE)printf(" *");else printf(" _");
if(e[1]==TRUE)printf(" *");else printf(" _");
if(e[2]==TRUE)printf(" *");else printf(" _");
if(e[3]==TRUE)printf(" *");else printf(" _");
if(e[4]==TRUE)printf(" *");else printf(" _");
printf("\n");
printf("\n Try number %d", count);


//if by some chance I manage to clear the board, I want it to restart the 
// counter
if(a[0]==FALSE && a[1]==FALSE && a[2]==FALSE && a[3]==FALSE && a[4]==FALSE)startover[0]=TRUE;
else startover[0]=FALSE;
if(b[0]==FALSE && b[1]==FALSE && b[2]==FALSE && b[3]==FALSE && b[4]==FALSE)startover[1]=TRUE;
else startover[1]=FALSE;
if(c[0]==FALSE && c[1]==FALSE && c[2]==FALSE && c[3]==FALSE && c[4]==FALSE)startover[2]=TRUE;
else startover[2]=FALSE;
if(d[0]==FALSE && d[1]==FALSE && d[2]==FALSE && d[3]==FALSE && d[4]==FALSE)startover[3]=TRUE;
else startover[3]=FALSE;
if(e[0]==FALSE && e[1]==FALSE && e[2]==FALSE && e[3]==FALSE && e[4]==FALSE)startover[4]=TRUE;
else startover[4]=FALSE;

if(startover[0]==TRUE && startover[1]==TRUE && startover[2]==TRUE && startover[3]==TRUE &&
startover[4]==TRUE)
    count = 0;
  



if(a[0]==TRUE && a[1]==TRUE && a[2]==TRUE && a[3]==TRUE && a[4]==TRUE)solved[0]=TRUE;
else solved[0]=FALSE;
if(b[0]==TRUE && b[1]==TRUE && b[2]==TRUE && b[3]==TRUE && b[4]==TRUE)solved[1]=TRUE;
else solved[1]=FALSE;
if(c[0]==TRUE && c[1]==TRUE && c[2]==TRUE && c[3]==TRUE && c[4]==TRUE)solved[2]=TRUE;
else solved[2]=FALSE;
if(d[0]==TRUE && d[1]==TRUE && d[2]==TRUE && d[3]==TRUE && d[4]==TRUE)solved[3]=TRUE;
else solved[3]=FALSE;
if(e[0]==TRUE && e[1]==TRUE && e[2]==TRUE && e[3]==TRUE && e[4]==TRUE)solved[4]=TRUE;
else solved[4]=FALSE;


if(solved[0]==TRUE && solved[1]==TRUE && solved[2]==TRUE && solved[3]==TRUE && 
   solved[4]==TRUE && count>=50){solve++; finished=TRUE;}

printf("\nSolved %d times.", solve);
/*
// This will make it keep trying until you get count under a certain number
if(solved[0]==TRUE && solved[1]==TRUE && solved[2]==TRUE && solved[3]==TRUE && solved[4]==TRUE 
&& count <= 50)
finished=TRUE;
*/


}
while(finished!=TRUE);

printf("\n\nIt only took me %d tries!\n\n",count);


return;
}
