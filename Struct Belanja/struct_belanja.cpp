#include<iostream>
#include<windows.h>
#define max 100
using namespace std;

string kodeB[max], namaB[max], namaToko;
int hargaB[max], jlhB[max], totalH[max], totalB=0, totalBay, potongan=0, j, tunai=0, kembalian=0;

void gotoxy(int x,int y)
{
	COORD crd;
	crd.X=x;
	crd.Y=y;
	SetConsoleCursorPosition(GetStdHandle
	(STD_OUTPUT_HANDLE),crd);
}

void nama_toko(){

	gotoxy(16,0);cout<<"~ TOKO "<<namaToko<<" Entry Penjualan ~"<<endl;
}

void keterangan_input(){
	cout<<"Kode barang   : "<<endl;
	cout<<"Nama barang   : "<<endl;
	cout<<"Harga satuan  : Rp. "<<endl;
	cout<<"Jumlah barang : "<<endl; 
}
void garis(){
	cout<<"+---------------------------------------------------------------+"<<endl;
}

void kepala_tabel(){
	garis();
	cout<<"| KODE BARANG   | NAMA BARANG                 | TOTAL HARGA     |"<<endl;
	garis();
}

void kolom(){
	cout<<"|               |                             |                 |"<<endl;
}

void kolom2(){
	cout<<"                                              |                 |"<<endl;
}

void input(char mhl='Y'){
	j=0;
	
	do{
		system("cls");
		nama_toko();
		cout<<"Barang ke-[ "<<j+1<<" ]"<<endl;
		keterangan_input();
		gotoxy(16,2); cin>>kodeB[j];
		fflush(stdin);
		gotoxy(16,3); getline(cin, namaB[j]);
		gotoxy(19,4); cin>>hargaB[j];
		gotoxy(16,5); cin>>jlhB[j];
		
		totalH[j]=hargaB[j]*jlhB[j];
		totalB=totalB+totalH[j];
		
		if(totalB >= 500000){
			potongan=(5*totalB)/100;
		} else if(totalB >= 250000){
			potongan=(2.5*totalB)/100;
		} else{
			potongan=(0*totalB)/100;
		}
		totalBay=totalB-potongan;
		
		j++;
		cout<<"Tambah data lagi? Y/T :"; cin>>mhl;
	} while(mhl=='Y' || mhl=='y');	
}



void proses_output(){
	gotoxy(16,0);cout<<"~ TOKO "<<namaToko<<" Struct Belanja ~"<<endl;
	kepala_tabel();
	for(int a=0; a<j; a++){
		gotoxy(0,4+a); kolom();
		gotoxy(2,4+a); cout<<kodeB[a];
		gotoxy(18,4+a); cout<<namaB[a]<<" x "<<jlhB[a]<<"Pcs";
		gotoxy(48,4+a); cout<<"Rp. "<<totalH[a];	
	}
	cout<<endl;
	garis();
	gotoxy(0,5+j); kolom2();
	gotoxy(0,5+j); cout<<"| Total Belanja";
	gotoxy(48,5+j); cout<<"Rp. "<<totalB<<endl;

	gotoxy(0,6+j); kolom2();
	gotoxy(0,6+j); cout<<"| Potongan";
	gotoxy(48,6+j); cout<<"Rp. "<<potongan<<endl;
	
	gotoxy(0,7+j); kolom2();
	gotoxy(0,7+j); cout<<"| Total Bayar";
	gotoxy(48,7+j); cout<<"Rp. "<<totalBay<<endl;
	
	gotoxy(0,8+j); kolom2();
	gotoxy(0,8+j); cout<<"| Tunai";
	gotoxy(48,8+j); cout<<"Rp. "<<tunai;
	
	gotoxy(0,9+j); kolom2();
	gotoxy(0,9+j); cout<<"| Kembalian";
	gotoxy(48,9+j); cout<<"Rp. "<<kembalian;
	
	gotoxy(0,10+j); garis();
}

void tumnai(){
	gotoxy(0,12+j); cout<<"+---------------------------+"<<endl;
				  cout<<"| TUNAI    Rp.              |";
	gotoxy(0,14+j); cout<<"+---------------------------+"<<endl;
	gotoxy(14,13+j); cin>>tunai;
	kembalian = tunai - totalBay;
}

int main(){
	cout<<"Nama Toko : "; cin>>namaToko;
	system("cls");
	input();
	system("cls");
	proses_output();
	tumnai();
	system("cls");
	proses_output();
}