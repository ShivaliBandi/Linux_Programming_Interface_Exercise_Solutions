#include<stdio.h>
#include<unistd.h>
#include<assert.h>
#include <fcntl.h>
#include<string.h>
int TeeCommandImplementation(const char filemode,const char *inputfileName,const char *outputfileName);
int main(int argc,char **argv)
{
    char filemode;
    int ret=-1;
    ret=getopt(argc,argv,"a:");
    
    switch (ret)
    {
        case 'a':
           filemode='a';
            break;
        
        case '?':
            filemode='w';
            break;
    }
    

    assert(argc>1);
   
        ret=TeeCommandImplementation(filemode,argv[2],argv[3]);
        if(ret==1)
            printf("\nData appended successfully..!\n");
        else
            printf("Unable to write data into file successfully");
    
}
int TeeCommandImplementation(const char filemode,const char *inputfileName,const char *outputfileName)
{
    int mode=0,fdoutput,fdinput,writeByte,readByte;
    char buffer[1024]={'\0'};
    if(filemode=='a')
        mode=O_APPEND | O_CREAT | O_WRONLY;
    else
        mode=O_TRUNC | O_WRONLY| O_CREAT;
    fdoutput=open(outputfileName,mode,07777);
    fdinput=open(inputfileName,O_RDONLY);
   
    if(fdoutput==-1 || fdinput==-1)
        return 0;


    while((readByte=read(fdinput,buffer,sizeof(buffer)))>0)
    {
        
        writeByte=write(fdoutput,buffer,strlen(buffer));
        memset(buffer, 0, strlen(buffer));

    }
    close(fdoutput);
    close(fdinput);
    return 1;
}