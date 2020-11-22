//---------------------------------------------------------------------------

#pragma hdrstop

#include "Liaison.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <winsock.h>
#include <stdlib>
#include <stdio.h>


bool Liaison::Ouvrirport()   //on ouvre le port souhaite et on le configure
{
  this->hcom = CreateFileA("COM1",GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_FLAG_NO_BUFFERING,NULL);   //3e valeur = sécu,4e = ouvrir un port existant

  if(hcom == INVALID_HANDLE_VALUE)
  {
	  return false;

  }
  else
  {
	bool handleistested;
	DCB conf;

	handleistested = GetCommState(this->hcom,&conf);

	conf.BaudRate = CBR_9600;          //on parametre la liaison serie via la structure conf
	conf.StopBits = ONESTOPBIT;
	conf.Parity = NOPARITY;
	conf.ByteSize=8;
	SetCommState(this->hcom,&conf);
	COMMTIMEOUTS comm;
	comm.ReadIntervalTimeout = MAXDWORD;
	comm.ReadTotalTimeoutMultiplier=0;
	comm.ReadTotalTimeoutConstant=0;
	comm.WriteTotalTimeoutMultiplier=0;
	comm.WriteTotalTimeoutConstant=0;

	SetCommTimeouts(hcom,&comm);


    return true;

  }


}
bool Liaison::envoitrame(char* buffer)
{

	bool okayornot = false;
	unsigned long numberofbytewritten;





	okayornot = WriteFile(this->hcom,buffer,strlen(buffer),&numberofbytewritten,NULL);

	if(okayornot == true)
	{
        return true;
	}
	else
	{
        return false;
	}


}




bool Liaison::fermerport()
{
	bool isclose;

	isclose = CloseHandle(this->hcom);

    return isclose;
}