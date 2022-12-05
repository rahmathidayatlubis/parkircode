#include <iostream>
#include<conio.h>
using namespace std;

struct Mhs
{
	string nama;
	int nim, nilai;
	Mhs *next;
};
Mhs *head, *tail, *baru, *cur, *del;


// create data
void create()
{
	head = new Mhs;
	cout << " Nama  : "; cin >> head->nama;
	cout << " NIM   : "; cin >> head->nim;
	cout << " Nilai : "; cin >> head->nilai;
	cout << endl;
	cout<<" Data berhasil ditambahkan\n\n";
	head->next = NULL;
	tail = head;
}

// addFirst
void addF(){
	baru = new Mhs;
	cout << " Nama  : "; cin >> baru->nama;
	cout << " NIM   : "; cin >> baru->nim;
	cout << " Nilai : "; cin >> baru->nilai;
	cout<<endl;
	cout<<" Data berhasil ditambahkan\n\n";
	baru->next = head;
	head = baru;
	
}

// Tambah data atau Buat data
void createAddF(){
	if(head == NULL){
		create();
	} else{
		addF();
	}
}

// addLast
void addLast()
{
	baru = new Mhs;
	cout << " Nama  : "; cin >> baru->nama;
	cout << " NIM   : "; cin >> baru->nim;
	cout << " Nilai : "; cin >> baru->nilai;
	cout << endl;
	baru->next = NULL;
	tail->next = baru;
	tail = baru;
}

// remove first
void removeFirst(){
	del = head;
	head = head->next;
	delete del;
}

// remove last
void removeLast(){
	del = tail;
	cur = head;
	while(cur->next != tail){
		cur = cur->next;
	}
	tail = cur;
	tail->next = NULL;
	delete del;
}

// display
void display()
{
	if(head == NULL){
		cout<<" Data masih kosong\n";
	} else{
		cur = head; // asignment
		while (cur != NULL)
		{ // pengecekan terhadap isi node1
			cout << " Nama  : " << cur->nama << endl;
			cout << " Nilai : " << cur->nilai << endl;
			cout << " NIM   : " << cur->nim << endl<<endl;
	
			cur = cur->next; // asignment nilai cur ke link
		}
	}
	
}


int main()
{
	int pil;
	
	do{
		system("cls");
		cout<<"%---------------------------------------%\n";
		cout<<"| 1. Display\t\t\t\t|\n";
	    cout<<"| 2. Create / Add first\t\t\t|\n";
	    cout<<"| 3. Add last\t\t\t\t|\n";
	    cout<<"| 4. Del first\t\t\t\t|\n";
	    cout<<"| 5. Del last\t\t\t\t|\n";
	    cout<<"| 9. Exit\t\t\t\t|\n";
		cout<<"| https://github.com/rahmathidayatlubis |\n";
	    cout<<"%---------------------------------------%\n";
	    
	    cout<<" Pilih : "; cin>>pil;
	    cout<<endl;;
	    
	    switch(pil){
	    	case 1:
	    		display();
	    		break;
	    	case 2:
	    		createAddF();
	    		break;
	    	case 3:
	    		addLast();
	    		break;
	    	case 4:
	    		removeFirst();
	    		break;
	    	case 5:
	    		removeLast();
	    		break;
	    	case 9:
	    		exit(1);
	    	default:
	    		cout<<"Inputan salah\n";
		}
		
		cout<<"\n Press any key to continue...";
		getch();
	} while(pil != 9);
    
}
