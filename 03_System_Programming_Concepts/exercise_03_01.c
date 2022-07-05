#include <linux/reboot.h> /*we include this library for this->LINUX_REBOOT_MAGIC1 flag*/
#include <unistd.h>
#include<stdio.h>
int main(int argc,char **argv)
{
    printf("LINUX_REBOOT_MAGIC1:%x\n",LINUX_REBOOT_MAGIC1);
    printf("LINUX_REBOOT_MAGIC2:%d\n",LINUX_REBOOT_MAGIC2);
    printf("LINUX_REBOOT_MAGIC2A:%x\n",LINUX_REBOOT_MAGIC2A);
    printf("LINUX_REBOOT_MAGIC2A:%x\n",LINUX_REBOOT_MAGIC2A);
    printf("LINUX_REBOOT_MAGIC2A:%x\n",LINUX_REBOOT_MAGIC2B);
    printf("LINUX_REBOOT_MAGIC2A:%x\n",LINUX_REBOOT_MAGIC2C);
    /*
    
    The meaning of these numbers is more prosaic.
    When represented in hexadecimal numeral system, they equal 28121969, 05121996, 16041998 and 20112000 respectively;
    the first of which is the date of birth of Linus Torvalds himself, 
    and the latter three are the dates of birth of his daughters Patricia, Daniela and Celeste respectively. 
    
    */
    return 0;
}