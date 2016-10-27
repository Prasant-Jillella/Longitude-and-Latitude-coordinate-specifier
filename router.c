#include<stdio.h>
#include<windows.h>
#include<conio.h>
int main()
{
	id:
	system("netsh wlan show hostednetwork >F:/show.txt");
	//creates a text copy of the mac addresses connected to the current network
	system("arp -d *");
	// deletes all the previous history and leaves behind the 
	//currently connected devices
	system("arp -a >F:/list1.txt");
	//provides the list of ip's and mac addresses on text format
	system("ftp -i 192.168.32.50");
	//connecting to the remote server
	system("user PrasantJillella  ");
	//entering the username and passord of the remote server
	system("lcd F:/");
	//locating the local file address
	system("put list1.txt");
	//transfering the file to the target system 
	system("put show.txt");
	//transfers the file to the target system
	system("quit");
	//exiting the command prompt
   Sleep(30000);
   goto id;
}

