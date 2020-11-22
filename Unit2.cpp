//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include <stdio.h>
#include <stdlib>
#include <windows.h>


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
   portserie.Ouvrirport();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button4Click(TObject *Sender)
{                           //gauche
	char trame[9];

	trame[0] = 0x81;   //indique le port
	trame[1] = 0x01;
	trame[2] = 0x06;
	trame[3] = 0x01;
	trame[4] = 0x18;
	trame[5] = 0x14;   //gere la vitesse
	trame[6] = 0x01;   //gere la vitesse
	trame[7] = 0x03;
	trame[8] = 0xFF;

	bool testsend = portserie.envoitrame(trame);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
    char trame[9];

	trame[0] = 0x81;  //indique le port
	trame[1] = 0x01;
	trame[2] = 0x06;
	trame[3] = 0x01;
	trame[4] = 0x18;  //gere la vitesse
	trame[5] = 0x14;  //gere la vitesse
	trame[6] = 0x03;
	trame[7] = 0x01;
	trame[8] = 0xFF;

	bool testsend = portserie.envoitrame(trame);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button5Click(TObject *Sender)
{                         //droite
   	char trame[9];

	trame[0] = 0x81;   //indique le port
	trame[1] = 0x01;
	trame[2] = 0x06;
	trame[3] = 0x01;
	trame[4] = 0x18;
	trame[5] = 0x14;   //gere la vitesse
	trame[6] = 0x02;   //gere la vitesse
	trame[7] = 0x03;
	trame[8] = 0xFF;

	bool testsend = portserie.envoitrame(trame);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button6Click(TObject *Sender)
{
    char trame[9];

	trame[0] = 0x81;   //indique le port
	trame[1] = 0x01;
	trame[2] = 0x06;
	trame[3] = 0x01;
	trame[4] = 0x18;
	trame[5] = 0x14;   //gere la vitesse
	trame[6] = 0x03;   //gere la vitesse
	trame[7] = 0x02;
	trame[8] = 0xFF;

	bool testsend = portserie.envoitrame(trame);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	char trame[5];

	trame[0] = 0x81;
	trame[1] = 0x01;
	trame[2] = 0x06;
	trame[3] = 0x04;
	trame[4] = 0xFF;

	bool testsend = portserie.envoitrame(trame);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::TrackBar1Change(TObject *Sender)
{
	char trame[6];

	trame[0]= 0x81;
	trame[1]= 0x01;
	trame[2]= 0x04;
	trame[3]= 0x07;
	trame[4]= 0x02;
	trame[5]= 0xFF;

	char zoomordezoom;
	zoomordezoom = TrackBar1->Position;
	trame[4] = zoomordezoom;

	bool testsend = portserie.envoitrame(trame);


}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button7Click(TObject *Sender)
{
	char trame[9];


	for(int i=0;i<3;i++)
	{
		trame[0] = 0x81;         //droite
		trame[1] = 0x01;
		trame[2] = 0x06;
		trame[3] = 0x01;
		trame[4] = 0x18;
		trame[5] = 0x14;
		trame[6] = 0x02;
		trame[7] = 0x03;
		trame[8] = 0xFF;

		portserie.envoitrame(trame);
		Sleep(3000);

		trame[0] = 0x81;           //gauche
		trame[1] = 0x01;
		trame[2] = 0x06;
		trame[3] = 0x01;
		trame[4] = 0x18;
		trame[5] = 0x14;
		trame[6] = 0x01;
		trame[7] = 0x03;
		trame[8] = 0xFF;

		portserie.envoitrame(trame);
		Sleep(3000);


	}
}
//---------------------------------------------------------------------------
