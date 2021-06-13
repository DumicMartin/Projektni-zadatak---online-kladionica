#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

struct tobusdobil
{
	int kofa;
	string utakmica;
	string ishod;
};
struct profili
{
	int OIB;
	string imePrezime;
	string korisnik;
};
int main()
{
	int ulog, n = 1, m = 7, temp1, temp2, broj, priv, number, brojac = 0, odabir, tim1, tim2, novac, pobjeda, o, a, u, unos, brIgraca = 0, brNagrade = 0, pocetniOdabir, profilOdabir, pocetak = 1, odabNags, odabNagk;
	int ozbac = 1, odabircek;
	profili igrac[100];
	tobusdobil kofe[100];
	time_t t;
	while (1)
	{
		if (pocetak == 1 || pocetniOdabir == 4 || odabir == 6)
		{
			system("cls");
			printf("\n=====================================================");
			printf("\n||                ---------------------            ||");
			printf("\n||                | Online kladionica |            ||");
			printf("\n||                ---------------------            ||");
			printf("\n||                                                 ||");
			printf("\n||                       |Menu|                    ||");
			printf("\n||                                                 ||");
			printf("\n||    1. Profili                                   ||");
			printf("\n||    2. Pravila i nagrade                         ||");
			printf("\n||    3. Igre                                      ||");
			printf("\n||    4. Izlaz                                     ||");
			printf("\n||                                                 ||");
			printf("\n=====================================================");
			printf("\n\nUpisite broj odabira:");
			cin >> pocetniOdabir;
			if (pocetniOdabir == 1)
			{
				system("cls");
				printf("\n=====================================================");
				printf("\n||                                                 ||");
				printf("\n||                     |Profili|                   ||");
				printf("\n||                                                 ||");
				printf("\n||   1. Kreiraj Profil                             ||");
				printf("\n||   2. Prikazi profile                            ||");
				printf("\n||   3. Povratak na pocetni menu                   ||");
				printf("\n||                                                 ||");
				printf("\n=====================================================");
				printf("\n\nUpisite vas odabir: ");
				cin >> profilOdabir;
				if (profilOdabir == 1)
				{
					system("cls");
					brIgraca = 0;
					ifstream profil("profil.txt", ios::binary);
					if (profil.is_open())
					{
						while (!profil.eof())
						{
							profil.read((char*)&igrac[brIgraca], sizeof(igrac[brIgraca]));
							brIgraca++;
						}
						brIgraca--;
					}
					profil.close();
					printf("\n\t\t\t\t|Kreiraj Profil|\n\n");
					printf("Unesite vas OIB: ");
					cin >> igrac[brIgraca].OIB;
					printf("Unesite ime i prezime: ");
					cin.ignore();
					getline(cin, igrac[brIgraca].imePrezime);
					printf("Upisite vasu klasu (korsinik ili zaposlenik): ");
					getline(cin, igrac[brIgraca].korisnik);
					brIgraca++;
					ofstream profil1("profil.txt", ios::binary);
					for (int i = 0; i < brIgraca; i++)
					{
						profil1.write((char*)&igrac[i], sizeof(igrac[i]));
					}
					profil1.close();
				}
				else if (profilOdabir == 2)
				{
					system("cls");
					brIgraca = 0;
					ifstream profil("profil.txt", ios::binary);
					if (profil.is_open())
					{
						while (!profil.eof())
						{
							profil.read((char*)&igrac[brIgraca], sizeof(igrac[brIgraca]));
							brIgraca++;
						}
						brIgraca--;
					}
					profil.close();
					printf("\n\t\t\t\t|Prikaz Profila|\n\n");
					for (int i = 0; i < brIgraca; i++)
					{
						cout << "OIB igraca: " << igrac[i].OIB << endl;
						cout << "Ime i prezime igraca: " << igrac[i].imePrezime << endl;
						cout << "Uloga: " << igrac[i].korisnik << "\n" << endl;
					}
					system("pause");
				}
				else if (profilOdabir > 3)
				{
					cout << "Krivi unos!" << endl;
					system("pause");
				}
			}
			else if (pocetniOdabir == 2)
			{
				system("cls");
				string uns;
				printf("\n               ------------------- ");
				printf("\n               |Pravila i nagrade| ");
				printf("\n               -------------------\n\n ");
				cout << "Unesite vase ime i prezime:";
				cin.ignore();
				getline(cin, uns);
				for (int i = 0; i < brIgraca; i++)
				{
					if (uns == igrac[i].imePrezime)
					{
						if (igrac[i].korisnik == "zaposlenik")
						{
							system("cls");
							printf("\n=====================================================");
							printf("\n||                -------------------              ||");
							printf("\n||                |Pravila i nagrade|              ||");
							printf("\n||                -------------------              ||");
							printf("\n||                                                 ||");
							printf("\n||   1. Utrka konja                                ||");
							printf("\n||   2. Loto 7/39                                  ||");
							printf("\n||   3. Bingo                                      ||");
							printf("\n||   4. Nogomente utakmice                         ||");
							printf("\n||   5. Milijunas                                  ||");
							printf("\n||   6. Povratak na menu                           ||");
							printf("\n||                                                 ||");
							printf("\n=====================================================");
							printf("\n\nUpisite vas odabir: ");
							cin >> odabircek;
							if (odabircek == 1)
							{
								system("cls");
								brNagrade = 0;
								ifstream utrke("utrkakonja.txt", ios::binary);
								if (utrke.is_open())
								{
									while (!utrke.eof())
									{
										utrke.read((char*)&kofe[brNagrade], sizeof(kofe[brNagrade]));
										brNagrade++;
									}
									brNagrade--;
								}
								utrke.close();
								printf("\n\t\t\t\t|Utrka konja|\n\n");
								printf("Upisite poziciju konja: ");
								cin.ignore();
								getline(cin, kofe[brNagrade].utakmica);
								printf("Upisite vrijednost nagrade: ");
								cin >> kofe[brNagrade].kofa;
								brNagrade++;
								ofstream utrka1("utrkakonja.txt", ios::binary);
								for (int i = 0; i < brNagrade; i++)
								{
									utrka1.write((char*)&kofe[i], sizeof(kofe[i]));
								}
								utrka1.close();
							}
							if (odabircek == 2)
							{
								system("cls");
								brNagrade = 0;
								ifstream loto("loto739.txt", ios::binary);
								if (loto.is_open())
								{
									while (!loto.eof())
									{
										loto.read((char*)&kofe[brNagrade], sizeof(kofe[brNagrade]));
										brNagrade++;
									}
									brNagrade--;
								}
								loto.close();
								printf("\n\t\t\t\t|Loto 7/39|\n\n");
								printf("Upisite broj pogodjenih brojeva: ");
								cin.ignore();
								getline(cin, kofe[brNagrade].utakmica);
								printf("Upisite vrijednost nagrade: ");
								cin >> kofe[brNagrade].kofa;
								brNagrade++;
								ofstream loto1("loto739.txt", ios::binary);
								for (int i = 0; i < brNagrade; i++)
								{
									loto1.write((char*)&kofe[i], sizeof(kofe[i]));
								}
								loto1.close();
							}
							if (odabircek == 3)
							{
								system("cls");
								brNagrade = 0;
								ifstream bingo("bingo.txt", ios::binary);
								if (bingo.is_open())
								{
									while (!bingo.eof())
									{
										bingo.read((char*)&kofe[brNagrade], sizeof(kofe[brNagrade]));
										brNagrade++;
									}
									brNagrade--;
								}
								bingo.close();
								printf("\n\t\t\t\t|Bingo|\n\n");
								printf("Unesite broj ponovljenih brojeva: ");
								cin.ignore();
								getline(cin, kofe[brNagrade].utakmica);
								printf("Unesite vrijednost nagrade: ");
								cin >> kofe[brNagrade].kofa;
								brNagrade++;
								ofstream bingo1("bingo.txt", ios::binary);
								for (int i = 0; i < brNagrade; i++)
								{
									bingo1.write((char*)&kofe[i], sizeof(kofe[i]));
								}
								bingo1.close();
							}
							if (odabircek == 4)
							{
								system("cls");
								brNagrade = 0;
								ifstream nogut("nogometneutakmice.txt", ios::binary);
								if (nogut.is_open())
								{
									while (!nogut.eof())
									{
										nogut.read((char*)&kofe[brNagrade], sizeof(kofe[brNagrade]));
										brNagrade++;
									}
									brNagrade--;
								}
								nogut.close();
								printf("\n\t\t\t\t|Nogometne utakmice|\n\n");
								printf("Unesite ishod utakmice: ");
								cin.ignore();
								getline(cin, kofe[brNagrade].utakmica);
								printf("Unesite vrijednost nagrade: ");
								getline(cin, kofe[i].ishod);
								brNagrade++;
								ofstream nogut1("nogometneutakmice.txt", ios::binary);
								for (int i = 0; i < brNagrade; i++)
								{
									nogut1.write((char*)&kofe[i], sizeof(kofe[i]));
								}
								nogut1.close();
							}
							if (odabircek == 5)
							{
								system("cls");
								brNagrade = 0;
								ifstream milijun("milijunas.txt", ios::binary);
								if (milijun.is_open())
								{
									while (!milijun.eof())
									{
										milijun.read((char*)&kofe[brNagrade], sizeof(kofe[brNagrade]));
										brNagrade++;
									}
									brNagrade--;
								}
								milijun.close();
								printf("\n\t\t\t\t|Milijunas|\n\n");
								printf("Unesite broj pogodenih brojeva: ");
								cin.ignore();
								getline(cin, kofe[brNagrade].utakmica);
								printf("Unesite vrijednost nagrade: ");
								cin >> kofe[brNagrade].kofa;
								brNagrade++;
								ofstream milijun1("milijunas.txt", ios::binary);
								for (int i = 0; i < brNagrade; i++)
								{
									milijun1.write((char*)&kofe[i], sizeof(kofe[i]));
								}
								milijun1.close();
							}
							else if (odabircek > 6)
							{
								cout << "Krivi unos!" << endl;
								system("pause");
							}
						}
						else if (igrac[i].korisnik == "korisnik")
						{
							system("cls");
							printf("\n=====================================================");
							printf("\n||                -------------------              ||");
							printf("\n||                |Pravila i nagrade|              ||");
							printf("\n||                -------------------              ||");
							printf("\n||                                                 ||");
							printf("\n||   1. Utrka konja                                ||");
							printf("\n||   2. Loto 7/39                                  ||");
							printf("\n||   3. Bingo                                      ||");
							printf("\n||   4. Nogomente utakmice                         ||");
							printf("\n||   5. Milijunas                                  ||");
							printf("\n||   6. Povratak na meni                           ||");
							printf("\n||                                                 ||");
							printf("\n=====================================================");
							printf("\n\nUpisite broj odabira:");
							cin >> odabNagk;
							if (odabNagk == 1)
							{
								system("cls");
								brNagrade = 0;
								ifstream utrkekonja("utrkakonja.txt", ios::binary);
								if (utrkekonja.is_open())
								{
									while (!utrkekonja.eof())
									{
										utrkekonja.read((char*)&kofe[brNagrade], sizeof(kofe[brNagrade]));
										brNagrade++;
									}
									brNagrade--;
								}
								utrkekonja.close();
								printf("\n\t\t\t\t|Utrke konja|\n\n");
								for (int i = 0; i < brNagrade; i++)
								{

									cout << "Pogodena pozicija " << kofe[i].utakmica << endl;
									cout << "Vrijednost nagrade: " << kofe[i].kofa << "kn" << "\n" << endl;
								}
								system("pause");
							}
							if (odabNagk == 2)
							{
								system("cls");
								brNagrade = 0;
								ifstream loto("loto739.txt", ios::binary);
								if (loto.is_open())
								{
									while (!loto.eof())
									{
										loto.read((char*)&kofe[brNagrade], sizeof(kofe[brNagrade]));
										brNagrade++;
									}
									brNagrade--;
								}
								loto.close();
								printf("\n\t\t\t\t|Loto 7/39|\n\n");
								for (int i = 0; i < brNagrade; i++)
								{
									cout << "Broj pogodjenih brojeva: " << kofe[i].utakmica << endl;
									cout << "Vrijednost nagrade: " << kofe[i].kofa << "kn" << "\n" << endl;
								}
								system("pause");
							}
							if (odabNagk == 3)
							{
								system("cls");
								brNagrade = 0;
								ifstream bingo("bingo.txt", ios::binary);
								if (bingo.is_open())
								{
									while (!bingo.eof())
									{
										bingo.read((char*)&kofe[brNagrade], sizeof(kofe[brNagrade]));
										brNagrade++;
									}
									brNagrade--;
								}
								bingo.close();
								printf("\n\t\t\t\t|Bingo|\n\n");
								for (int i = 0; i < brNagrade; i++)
								{
									cout << "Broj ponovljenih brojeva: " << kofe[i].utakmica << endl;
									cout << "Vrijednost nagrade: " << kofe[i].kofa << "kn" << "\n" << endl;
								}
								system("pause");
							}
							if (odabNagk == 4)
							{
								system("cls");
								brNagrade = 0;
								ifstream noguta("nogometneutakmice.txt", ios::binary);
								if (noguta.is_open())
								{
									while (!noguta.eof())
									{
										noguta.read((char*)&kofe[brNagrade], sizeof(kofe[brNagrade]));
										brNagrade++;
									}
									brNagrade--;
								}
								noguta.close();
								printf("\n\t\t\t\t|Nogometne utakmice|\n\n");
								for (int i = 0; i < brNagrade; i++)
								{
									cout << "Ishod utakmice: " << kofe[i].utakmica << endl;
									cout << "Vrijednost nagrade: " << kofe[i].ishod << "\n" << endl;
								}
								system("pause");
							}
							if (odabNagk == 5)
							{
								system("cls");
								brNagrade = 0;
								ifstream milijun("milijunas.txt", ios::binary);
								if (milijun.is_open())
								{
									while (!milijun.eof())
									{
										milijun.read((char*)&kofe[brNagrade], sizeof(kofe[brNagrade]));
										brNagrade++;
									}
									brNagrade--;
								}
								milijun.close();
								printf("\n\t\t\t\t|Milijunas|\n\n");
								for (int i = 0; i < brNagrade; i++)
								{
									cout << "Broj pogodenih brojeva: " << kofe[i].utakmica << endl;
									cout << "Vrijednost nagrade: " << kofe[i].kofa << "kn" << "\n" << endl;
								}
								system("pause");
							}
							else if (odabNagk > 6)
							{
								cout << "Krivi unos!" << endl;
								system("pause");
							}
						}
					}
				}
			}
			else if (pocetniOdabir == 3)
			{
				system("cls");
				printf("\n=====================================================");
				printf("\n||                                                 ||");
				printf("\n||                       |Igre|                    ||");
				printf("\n||                                                 ||");
				printf("\n||   1. Utrka konja                                ||");
				printf("\n||   2. Loto 7/39                                  ||");
				printf("\n||   3. Bingo                                      ||");
				printf("\n||   4. Nogomente utakmice                         ||");
				printf("\n||   5. Milijunas                                  ||");
				printf("\n||   6.Povratak na pocetni meni                    ||");
				printf("\n||                                                 ||");
				printf("\n=====================================================");
				printf("\n\nUpisite vas odabir: ");
				cin >> odabir;
				if (odabir == 1)
				{
					system("cls");
					printf("\n\t\t\t\t|Dobrodosli u Utrku konja|\n\nPravila igre:Izaberite jedan broj izmedu 1 i 5 koji ce odgovarati broju vaseg konja.\nUkratko utrka se sastoji od 5 konja i samo je jedan pobjednik.\nVas dobitak ovisiti ce o poziciji vaseg konja u utrci.\n\n");
					srand((unsigned)time(&t));
					for (int i = 0; i < n; i++)
					{
						printf("Izaberite broj konja na kojeg se kladite:  ");
						cin >> broj;
						if (broj < 1 || broj>5)
						{
							printf("\nKrivi unos!\n\n\n");
							system("pause");
						}
						temp1 = rand() % 6;
					}
					if (temp1 == broj)
					{
						printf("\nPobijedili ste.\n");
						printf("Vas dobitak je 500kn.\n\n\n");
					}
					else
					{
						printf("\nNiste pobijedili.\n");
						do
						{
							srand((unsigned)time(&t));
							for (int j = 0; j < n; j++)
							{
								temp2 = rand() % 6;
							}
						} while (temp2 == 0 || temp2 == 1);
						printf("Konj na kojeg ste se kladili je zavrsio %d.\n", temp2);
						if (temp2 == 2)
						{
							printf("Vas dobitak je 250kn.\n\n\n");
						}
						else if (temp2 == 3)
						{
							printf("Vas dobitak je 100kn.\n\n\n");
						}
						else if (temp2 > 3)
						{
							printf("Vas konj je bio toliko los da niste nista osvojili. Vise srece drugi put!\n\n\n");
						}
					}
					system("pause");
				}
				else if (odabir == 2)
				{
					system("cls");
					printf("\n\t\t\t\t|Dobrodosli u Loto 7/39|\n\nPravila igre: morate izabrati 7 brojeva izmedu 1 i 39.\nKolicina pogodenih brojeva ce odgovarati svoti novca koju ste osvojili.\nBrojeve upisujete jedan po jedan.\n");
					srand((unsigned)time(&t));
					brojac = 0;
					for (int x = 0; x < m; x++)
					{
						printf("\nUpisite broj: ");
						cin >> number;
						if (number < 1 || number>39)
						{
							printf("Upisali ste pogresan broj.\n\n");
							system("pause");
						}
						do
						{
							srand((unsigned)time(&t));
							for (int y = 0; y < m; y++)
							{
								priv = rand() % 40;
							}
						} while (priv == 0);
						if (number == priv)
						{
							printf("Pogodili ste broj!\n");
							brojac ++;
						}
					}
					for (int i = 0; i <= 39; i++)
					{
						if (brojac == i)
						{
							printf("\nPogodeni brojevi: %d\n", i);
							printf("Dobitak: %dkn\n", i * 1000);
						}
					}
					system("pause");
				}
				else if (odabir == 3)
				{
					system("cls");
					printf("\n\t\t\t\t\t|Dobrodosli u Bingo|\n\nPravila igre: Da bi zapoceli ovu igru potrebno je unaprijed uloziti 100kn.\nU ovoj igri ce se nasumicno izabrati tri broja izmedu 1 i 9.\nAko se brojevi ponove dva ili tri puta osvajate nagradu ovisno o kolicini ponovljenih brojeva.");
					printf("\n\nZelite li zapoceti igru tako da ulozite 100kn?(1==DA/2==NE): ");
					cin >> ulog;
					if (ulog == 1)
					{
						for (int i = 0; i < n; i++)
						{
							srand(time(NULL));
							int a = rand() % 10;
							int b = rand() % 10;
							int c = rand() % 10;
							if(a < 1 || b < 1 || c < 1)
							{
								do
								{
									a = rand() % 10;
									b = rand() % 10;
									c = rand() % 10;
								} while (a < 1 || b < 1 || c < 1);
							}
							printf("\n\nDobijeni brojevi su |%d|%d|%d|", a, b, c);
							if (a == b && a == c && b == c)
							{
								printf("\nCestitamo na pobjedi.\nOsvojili ste 500kn.\n\n");
							}
							else if (a == b)
							{
								printf("\nCestitamo! Osvojili ste 200 kn\n\n");
							}
							else if (a == c)
							{
								printf("\nCestitamo! Osvojili ste 200 kn\n\n");
							}
							else if (b == c)
							{
								printf("\nCestitamo! Osvojili ste 200 kn\n\n");
							}
							else
							{
								printf("\n\nNazalost niste nista osvojili.\nVise srece drugi put.\n\n");
							}
						}
					}
					else if (ulog == 2)
					{
						cout << "OK vidimo se!" << endl;
					}
					else
					{
						cout << "Krivi unos!" << endl;

					}
					system("pause");
				}
				else if (odabir == 4)
				{
					system("cls");
					srand(time(NULL));
					tim1 = rand() % 4;
					tim2 = rand() % 4;
					printf("\n                   |Nogometne utakmice|");
					printf("\n\nUtakmice na koje se mozete kladiti su:");
					printf("\n\n1.Engleska - Hrvatska");
					printf("\n2.Skotska - Ceska");
					printf("\n3.Hrvatska - Ceska");
					printf("\n4.Engleska - Skotska");
					printf("\n5.Ceska - Engleska");
					printf("\n6.Hrvatska - Skotska");
					printf("\n7.Turska - Italija");
					printf("\n8.Wales - Svicarska");
					printf("\n9.Turska - Wales");
					printf("\n\nUpisite broj utakmice na koju se zelite kladiti:");
					cin >> o;
					if (o > 9 || o < 0)
					{
						cout << "Krivi unos" << endl;
					}
					else if (o <= 9 && o >= 0)
					{
						int choice;
						if (o == 1)
						{
							printf("\n\t\t\t|1.Engleska - 2.Hrvatska|");
							printf("\n\nUpisite broj na koji tim se zelite kladiti, a kao mislite da ce biti izjednaceno upisite 0: \n");
							cin >> choice;
						}
						else if (o == 2)
						{
							printf("\n\t\t\t|1.Skotska - 2.Ceska|");
							printf("\n\nUpisite broj na koji tim se zelite kladiti, a kao mislite da ce biti izjednaceno upisite 0: \n");
							cin >> choice;
						}
						else if (o == 3)
						{
							printf("\n\t\t\t|1.Hrvatska - 2.Ceska|");
							printf("\n\nUpisite broj na koji tim se zelite kladiti, a kao mislite da ce biti izjednaceno upisite 0: \n");
							cin >> choice;
						}
						else if (o == 4)
						{
							printf("\n\t\t\t|1.Engleska - 2.Skotska|");
							printf("\n\nUpisite broj na koji tim se zelite kladiti, a kao mislite da ce biti izjednaceno upisite 0: \n");
							cin >> choice;
						}
						else if (o == 5)
						{
							printf("\n\t\t\t|1.Ceska - 2.Engleska|");
							printf("\n\nUpisite broj na koji tim se zelite kladiti, a kao mislite da ce biti izjednaceno upisite 0: \n");
							cin >> choice;
						}
						else if (o == 6)
						{
							printf("\n\t\t\t|1.Hrvatska - 2.Skotska|");
							printf("\n\nUpisite broj na koji tim se zelite kladiti, a kao mislite da ce biti izjednaceno upisite 0: \n");
							cin >> choice;
						}
						else if (o == 7)
						{
							printf("\n\t\t\t|1.Turska - 2.Italija|");
							printf("\n\nUpisite broj na koji tim se zelite kladiti, a kao mislite da ce biti izjednaceno upisite 0: \n");
							cin >> choice;
						}
						else if (o == 8)
						{
							printf("\n\t\t\t|1.Wales - 2.Svicarksa|");
							printf("\n\nUpisite broj na koji tim se zelite kladiti, a kao mislite da ce biti izjednaceno upisite 0: \n");
							cin >> choice;
						}
						else if (o == 9)
						{
							printf("\n\t\t\t|1.Turska - 2.Wales|");
							printf("\n\nUpisite broj na koji tim se zelite kladiti, a kao mislite da ce biti izjednaceno upisite 0: \n");
							cin >> choice;
						}
						printf("\nVas ulog: ");
						cin >> novac;
						if (choice == 0 && tim1 > tim2)
						{
							printf("Prvi tim je pobjedio.Niste nista osvojili.\n\n");
						}
						else if (tim1 > tim2)
						{
							printf("\nPobijedio je vas tim, sa rezultatom %d:%d", tim1, tim2);
							novac = novac * 3;
							printf("\nOsvojili ste %dkn.\n\n", novac);

						}
						else if (choice == 0 && tim2 > tim1)
						{
							printf("Pobjedio je drugi tim.Niste nista osvojili.\n\n");
						}
						else if (tim2 > tim1)
						{
							printf("\nPobijedio je protivnicki tim, sa rezultatom %d:%d", tim1, tim2);
							printf("\nNiste nista osvojili, vas tim je izgubio.\n\n");

						}
						else if (choice == 0 && tim1 == tim2)
						{
							novac = novac * 3;
							printf("Utakmica je odigrana izjednaceno.Osvojili ste: %dkn\n\n", novac);
						}
						else if (tim1 == tim2)
						{
							printf("\nUtakmica je odigrana izjednaceno, sa rezultatom %d:%d\n\n", tim1, tim2);
						}
					}
					system("pause");
				}
				else if (odabir == 5)
				{
					system("cls");
					printf("\n\n\t\t\t\t\t\t|Milijunas|");
					printf("\n\nPravila igre: Unosite brojeve izmedu 1 i 5 i ako pogodite broj nastavljate dalje,\nsvakim se pogotkom nagrada povecava.");
					srand(time(NULL));
					a = rand() % 6;
					if (a < 1)
					{
						do
						{
							a = rand() % 6;
						} while (a < 1);
					}
					printf("\n\nUnesite broj: ");
					cin >> unos;
					if (unos < 1 || unos > 5)
					{
						cout << "Krivi unos" << endl;
					}
					else if (unos >= 0 && unos <= 5)
					{
						if (unos == a)
						{
							printf("\nPogodili ste broj i osvojili 1000kn");
							printf("\nUkupna zarada: 1000kn");
							printf("\n\nUnesite broj: ");
							a = rand() % 6;
							if (a < 1)
							{
								do
								{
									a = rand() % 6;
								} while (a < 1);
							}
							cin >> unos;
							if (unos == a)
							{
								printf("\nPogodili ste broj i osvojili 2000kn");
								printf("\nUkupna zarada: 3000kn");
								a = rand() % 6;
								if (a < 1)
								{
									do
									{
										a = rand() % 6;
									} while (a < 1);
								}
								printf("\n\nUnesite broj: ");
								cin >> unos;
								if (unos == a)
								{
									printf("\nPogodili ste broj i osvojili 5000kn");
									printf("\nUkupna zarada: 8000kn");
									a = rand() % 6;
									if (a < 1)
									{
										do
										{
											a = rand() % 6;
										} while (a < 1);
									}
									printf("\n\nUnesite broj: ");
									cin >> unos;
									if (unos == a)
									{
										printf("\nPogodili ste broj i osvojili 10000kn");
										printf("\nUkupna zarada: 18000kn");
										printf("\n\nAko zelite sada mozete uzeti 18000kn i zaustaviti igru tako da unesete broj 1,\na ako zelite nastaviti i osvojiti jos unesite broj 2.");
										printf("\n\nUnesite broj: ");
										cin >> u;
										if (u == 2)
										{
											printf("\n\nNastavljate dalje.");
											a = rand() % 6;
											if (a < 1)
											{
												do
												{
													a = rand() % 6;
												} while (a < 1);
											}
											printf("\n\nUnesite broj: ");
											cin >> unos;
											if (unos == a)
											{
												printf("\nPogodili ste broj i osvojili 20000kn");
												printf("\nUkupna zarada: 38000kn");
												a = rand() % 6;
												if (a < 1)
												{
													do
													{
														a = rand() % 6;
													} while (a < 1);
												}
												printf("\n\nUnesite broj: ");
												cin >> unos;
												if (unos == a)
												{
													printf("\nPogodili ste broj i osvojili 50000kn");
													printf("\nUkupna zarada: 88000kn");
													a = rand() % 6;
													if (a < 1)
													{
														do
														{
															a = rand() % 6;
														} while (a < 1);
													}
													printf("\n\nUnesite broj: ");
													cin >> unos;
													if (unos == a)
													{
														printf("\nPogodili ste broj i osvojili 100000kn");
														printf("\nUkupna zarada: 188000kn");
														a = rand() % 6;
														if (a < 1)
														{
															do
															{
																a = rand() % 6;
															} while (a < 1);
														}
														printf("\n\nUnesite broj: ");
														cin >> unos;
														if (unos == a)
														{
															printf("\nPogodili ste broj i osvojili 200000kn");
															printf("\nUkupna zarada: 388000kn");
															printf("\n\nAko zelite sada mozete uzeti 388000kn i zaustaviti igru tako da unesete broj 1,\na ako zelite nastaviti i osvojiti jos unesite broj 2.");
															printf("\n\nUnesite broj: ");
															cin >> u;
															if (u == 2)
															{
																printf("\n\nNastavljate dalje.");
																a = rand() % 6;
																if (a < 1)
																{
																	do
																	{
																		a = rand() % 6;
																	} while (a < 1);
																}
																printf("\n\nUnesite broj: ");
																cin >> unos;
																if (unos == a)
																{
																	printf("\nPogodili ste broj i osvojili 500000kn");
																	printf("\nUkupna zarada: 888000kn");
																	a = rand() % 6;
																	if (a < 1)
																	{
																		do
																		{
																			a = rand() % 6;
																		} while (a < 1);
																	}
																	printf("\n\nUnesite broj: ");
																	cin >> unos;
																	if (unos == a)
																	{
																		printf("\nPogodili ste broj i osvojili 112000kn");
																		printf("\nUkupna zarada: 1000000kn");
																		printf("\nCestitamo pobjedili ste.");
																	}
																}
																else
																{
																	printf("\nNiste pogodili broj");
																	printf("\nBroj je bio %d.\n\n", a);
																}
															}
															else
															{
																exit(1);
															}
														}
														else
														{
															printf("\nNiste pogodili broj");
															printf("\nBroj je bio %d.\n\n", a);
														}
													}
													else
													{
														printf("\nNiste pogodili broj");
														printf("\nBroj je bio %d.\n\n", a);
													}
												}
												else
												{
													printf("\nNiste pogodili broj");
													printf("\nBroj je bio %d.\n\n", a);
												}
											}
											else
											{
												printf("\nNiste pogodili broj");
												printf("\nBroj je bio %d.\n\n", a);
											}
										}
										else
										{
											exit(1);
										}
									}
									else
									{
										printf("\nNiste pogodili broj");
										printf("\nBroj je bio %d.\n\n", a);
									}
								}
								else
								{
									printf("\nNiste pogodili broj.");
									printf("\nBroj je bio %d.\n\n", a);
								}
							}
							else
							{
								printf("\nNiste pogodili broj.");
								printf("\nBroj je bio %d.\n\n", a);
							}
						}
						else
						{
							printf("\nNiste pogodili broj.");
							printf("\nBroj je bio %d.\n\n", a);
						}
					}
					system("pause");
				}

			}
			else if (pocetniOdabir == 4)
			{
				cout << "Dovidjenja!" << endl;
				break;
			}
			else
			{
				cout << "Krivi unos!" << endl;
				system("pause"); 
			}
		}
	}
}