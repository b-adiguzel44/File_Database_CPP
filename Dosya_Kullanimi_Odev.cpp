// NOT : Birtakım hatalar olabilir özellikle güncelleme ve arama kısmında oluşan hataları çözemedim.

#include <iostream>
#include <fstream>	// Dosya işlemleri için kütüphane
#include <string>	// string işlemleri için kütüphane
#include <iomanip>	// setw() komutu için, Text dosyasında boşluklar ayarlamak için
using namespace std;

class Ogrenci 
{

private:
	string numara, ad, soyad, bolum, cinsiyet, d_yeri, yas, tel_no;
	fstream dosya;		// Dosya okuma-yazma işlemleri için
	ifstream Acma;		// Dosya okuma için
	ofstream Gecici;	// Dosya yazma için
	string kelime;		// KayitListeleme() metodunda kullanıyorum

public:


void KayitEkleme()
{
	dosya.open("ogrenci.dat", ios::in | ios::out | ios::ate | ios::app);
	cout.setf(ios::right);
	cout << setw(10) << "Numaranızı girin: ";
	cin >> numara;
	cout << setw(10) << "Adınızı girin: ";
	cin >> ad;
	cout << setw(10) << "Soyadınızı girin: ";
	cin >> soyad;
	cout << setw(10) << "Bölümünüzü girin: ";
	cin >> bolum;
	cout << setw(10) << "Cinsiyetinizi girin: ";
	cin >> cinsiyet;
	cout << setw(10) << "Doğum yerinizi girin: ";
	cin >> d_yeri;
	cout << setw(10) << "Yaşınızı girin : ";
	cin >> yas;
	cout << setw(10) << "Telefon No girin: ";
	cin >> tel_no;

	dosya.setf(ios::left);
	dosya << setw(10) << numara << setw(10) << ad << setw(10) << soyad << setw(10) << bolum << setw(10) << cinsiyet << setw(10) << d_yeri << setw(10) << yas << setw(10) << tel_no << "\n";
	dosya.close();
}
void KayitEkleme(string guncellenecek)
{
	cout.setf(ios::right);
	cout << setw(10) << "Numaranızı girin: ";
	cin >> numara;
	cout << setw(10) << "Adınızı girin: ";
	cin >> ad;
	cout << setw(10) << "Soyadınızı girin: ";
	cin >> soyad;
	cout << setw(10) << "Bölümünüzü girin: ";
	cin >> bolum;
	cout << setw(10) << "Cinsiyetinizi girin: ";
	cin >> cinsiyet;
	cout << setw(10) << "Doğum yerinizi girin: ";
	cin >> d_yeri;
	cout << setw(10) << "Yaşınızı girin : ";
	cin >> yas;
	cout << setw(10) << "Telefon No girin: ";
	cin >> tel_no;

	Gecici.setf(ios::left);
	Gecici << setw(10) << numara << setw(10) << ad << setw(10) << soyad << setw(10) << bolum << setw(10) << cinsiyet << setw(10) << d_yeri << setw(10) << yas << setw(10) << tel_no << "\n";
}
void KayitListeleme()
{
	dosya.open("ogrenci.dat");
	cout << endl;
	cout << "Kayıt Listesi\n**************************************************" << endl;
	while (getline(dosya,kelime))
	{
		cout << kelime << endl;
	}
	cout << "**************************************************" << endl;
	dosya.close();
}
void KayitArama(string aranacak)
{
	Acma.open("ogrenci.dat");
	int sayac = 0;

	while (!Acma.eof()) // End-of-Line : satır sonuna kadar bilgi çeker
	{
		Acma >> numara >> ad >> soyad >> bolum >> cinsiyet >> d_yeri >> yas >> tel_no;
		if (aranacak == numara)
		{
			cout.setf(ios::left);
			cout << endl;
			cout << setw(10) << numara << setw(10) << ad << setw(10) << soyad << setw(10) << bolum << setw(10) << cinsiyet << setw(10) << d_yeri << setw(10) << yas << setw(10) << tel_no;
			cout << endl;
			sayac++;
			break;
		}
		else if (aranacak == cinsiyet)
		{
			cout.setf(ios::left);
			cout << setw(10) << numara << setw(10) << ad << setw(10) << soyad << setw(10) << bolum << setw(10) << cinsiyet << setw(10) << d_yeri << setw(10) << yas << setw(10) << tel_no << endl;
			sayac++;
		}
		else if (aranacak == d_yeri)
		{
			cout.setf(ios::left);
			cout << setw(10) << numara << setw(10) << ad << setw(10) << soyad << setw(10) << bolum << setw(10) << cinsiyet << setw(10) << d_yeri << setw(10) << yas << setw(10) << tel_no << endl;
			sayac++;
		}
		else if (aranacak == bolum)
		{
			cout.setf(ios::left);
			cout << setw(10) << numara << setw(10) << ad << setw(10) << soyad << setw(10) << bolum << setw(10) << cinsiyet << setw(10) << d_yeri << setw(10) << yas << setw(10) << tel_no << endl;
			sayac++;
		}
		else
			continue;
	}

	cout << "**************************" << endl << sayac << " tane kayıt bulunmuştur." << endl;


	Acma.close();
}
void KayitDuzenleme(string guncellenecek)
{
	Acma.open("ogrenci.dat");
	Gecici.open("Gecici.txt");


	while (!Acma.eof())
	{
		Acma >> numara >> ad >> soyad >> bolum >> cinsiyet >> d_yeri >> yas >> tel_no;
		if (numara == guncellenecek)
		{
			KayitEkleme(guncellenecek);
		}
		else
		{
			Gecici.setf(ios::left);
			Gecici << setw(10) << numara << setw(10) << ad << setw(10) << soyad << setw(10) << bolum << setw(10) << cinsiyet << setw(10) << d_yeri << setw(10) << yas << setw(10) << tel_no << "\n";
		}
		
	}

	Acma.close();
	Gecici.close();

	remove("ogrenci.dat");
	rename("Gecici.txt","ogrenci.dat");
}

};


void Menu()
{
	cout << setw(20) << "ÖĞRENCİ KAYIT İŞLEMLERİ" << endl;
	cout << "**************************" << endl;
	cout << "1 - Kayıt Ekle" << endl;				// OK
	cout << "2 - Kayıtları listele" << endl;		// OK	
	cout << "3 - Kayıt Ara" << endl ;				// Minor problems (always prints the last record if prerequisites are met, such as same deparment names, gender etc.)
	cout << "4 - Kayıt Düzenle" << endl ;			// Minor/Major problems (always saves the last record)
	cout << "5 - Çıkış" << endl;					// OK 
}			



int main()
{
	
	char secim;
	string aranacak,duzenlenecek;
	setlocale(LC_ALL, "Turkish");

	Ogrenci O;


	Menu();
	do
	{
		cout << endl << "Lütfen seçiminizi giriniz: ";
		cin >> secim;

		switch (secim)
		{

		case '1' :
			O.KayitEkleme();
			cout << endl << "-- Kayıt başarılı bir şekilde eklenmiştir. --" << endl;
			break;

		case '2':
			O.KayitListeleme();
			break;

		case '3':
			cout << "Aranacak degeri giriniz(Bölüm,Cinsiyet vb.) : ";
			cin >> aranacak;
			cout << endl << "**************************" << endl;
			O.KayitArama(aranacak);

			break;
		case '4':

			cout << "Güncellenecek kaydın numarasını giriniz: ";
			cin >> duzenlenecek;
			O.KayitDuzenleme(duzenlenecek);

			break;
		case '5' :
			exit(0);
			break;
		default:
			cout << "Hatalı giriş! Lütfen doğru parametreleri giriniz.";
			break;
		}


	} while (1==1);
	
	
	
	
	
	
	return 0;
}
