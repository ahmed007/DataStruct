#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int quick(int x[],int lb,int ub);
int main()
{
   // int array[] = {2, 4, 1, 3, 5};
	int array[100000];
	size_t bytes_read;
	int i,j=0,k=0;
	int fd=-1;

	//int a[10]={34,18,32,12,54,76,65,43,2,1};
	char buffer[1025];
	char str[80];
	
	
	fd = open("file.txt",O_RDONLY);

	if(fd == -1)
		return 0;
	else
	{
		while(bytes_read=read(fd,buffer,1024))
		{
		for(i=0;i<=bytes_read;i++){
		if(buffer[i] == '\n' )
		{
			array[j++]=atoi(str);
			memset(str,'\0',80);
			k=0;
		}
		else
		{
			if(buffer[i] != '\0')
				str[k++]=buffer[i];
		}
			
			
		}
		}
	}

	close(fd);	
	
	#ifdef q
	quick(array,0,sizeof(array) / sizeof(array[0]));
	#elif s
	 selectionsort(array,sizeof(array) / sizeof(array[0]));
	#endif
	
	for(i=0;i<sizeof(array) / sizeof(array[0]);i++)
		printf(" %d ",array[i]);
	
}

/*
int main()
{
	int a[]={25,57,48,37,12,92,86,33};
	int i;
	
	quick(a,0,8);
	
	for(i=0;i<8;i++)
		printf(" %d ",a[i]);
}
*/
int quick(int x[],int lb,int ub){
	int j=0;
	if(lb>=ub)
		return;

	partition(x,lb,ub,&j);
	quick(x,lb,j-1);
	quick(x,j+1,ub);

}

void partition(int x[],int lb,int ub,int *pj){
int a,down,temp,up;

a=x[lb];

down=lb;
up=ub;

while(down<up){
	while(x[down]<=a && down < ub)
		down++;
	while(x[up] > a)
		up--;
	if(down < up){
	temp = x[down];
	x[down]=x[up];
	x[up]=temp;
	}

}//end while
x[lb]=x[up];
x[up]=a;
*pj=up;

}


