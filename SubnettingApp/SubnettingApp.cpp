#include<iostream>
using namespace std;

// DEKLARACIJA FUNKCIJA

// binarno u decimalno
void binarno_u_decimalno();
void IPupis_binarno(int* oktet1, int* oktet2, int* oktet3, int* oktet4);
int binarno_u_decimalno(int a);
void ispis_decimalno(int oktet1, int oktet2, int oktet3, int oktet4);

// decimalno u binarno
void decimalno_u_binarno();
void IPupis_decimalno(int* oktet1, int* oktet2, int* oktet3, int* oktet4);
int decimalno_u_binarno(int a);
void ispis_binarno(int oktet1, int oktet2, int oktet3, int oktet4);

// podaci o mrezi
void podaci_o_mrezi();
void SMupis1(int* s1, int* s2, int* s3, int* s4);
void podaci_mreze_ispis(int oktet1, int oktet2, int oktet3, int oktet4, int s1, int s2, int s3, int s4);
int izracunaj(int oktet, int s);
void SMupis2(int* sm);
void SMpreracunaj(int sm, int* s1, int* s2, int* s3, int* s4);
int sm_preracunaj(int sm);

// mreza na zahtjev
void mreza_na_zahtjev();
void podaci_mreze_ispis(int* oktet1, int* oktet2, int* oktet3, int* oktet4, int s1, int s2, int s3, int s4);
void IPupis_decimalno_posebno(int* o1, int* o2, int* o3, int* o4);
void SMizracunaj(int zahtjev, int* sm);
void SMispis(int s1, int s2, int s3, int s4);



int main() {

	cout << "Dobrodosli u aplikaciju za subnetiranje!" << endl << endl;

	cout << "IZBORNIK:" << endl << endl;

	cout << "  (1)  pretvorba IP adrese iz binarnog u dekadski zapis" << endl;
	cout << "  (2)  pretvorba IP drese iz dekadskog u binarni zapis" << endl;
	cout << "  (3)  informacije o mrezi na temelju IP adrese racunala i subnet maske" << endl;
	cout << "  (4)  informacije o mrezi na temelju zahtjeva" << endl << endl;

	cout << "Molim Vas izaberite sto zelite napraviti (upisite broj): ";
	int izbor;
	cin >> izbor;

	system("cls");

	switch (izbor) {

	case 1:

		binarno_u_decimalno();

		break;

	case 2:

		decimalno_u_binarno();

		break;

	case 3:

		podaci_o_mrezi();

		break;

	case 4:

		mreza_na_zahtjev();

		break;

	}


	return 0;
}

// (1) BINARNO U DECIMALNO

void binarno_u_decimalno() {

	int oktet1, oktet2, oktet3, oktet4;

	IPupis_binarno(&oktet1, &oktet2, &oktet3, &oktet4);

	cout << endl << "ispis IP adrese u decimalnom obliku: ";
	ispis_decimalno(oktet1, oktet2, oktet3, oktet4);

}

void IPupis_binarno(int* oktet1, int* oktet2, int* oktet3, int* oktet4) {

	char tocka;

	cout << "Upisite IP adresu u binarnom zapisu: ";
	cin >> *oktet1;
	cin >> tocka;
	cin >> *oktet2;
	cin >> tocka;
	cin >> *oktet3;
	cin >> tocka;
	cin >> *oktet4;

}

int binarno_u_decimalno(int a) {

	int broj = 0, i = 0;
	while (a > 0) {

		broj += (a % 10) * pow(2, i);
		i++;
		a /= 10;

	}

	return broj;
}

void ispis_decimalno(int oktet1, int oktet2, int oktet3, int oktet4) {

	int oktet1_d = binarno_u_decimalno(oktet1);
	int oktet2_d = binarno_u_decimalno(oktet2);
	int oktet3_d = binarno_u_decimalno(oktet3);
	int oktet4_d = binarno_u_decimalno(oktet4);

	cout << oktet1_d << "." << oktet2_d << "." << oktet3_d << "." << oktet4_d << endl;
}

// (2) DECIMALNO U BINARNO

void decimalno_u_binarno() {

	int oktet1, oktet2, oktet3, oktet4;

	IPupis_decimalno(&oktet1, &oktet2, &oktet3, &oktet4);

	cout << endl << "ispis ip adrese u binarnom obliku: ";
	ispis_binarno(oktet1, oktet2, oktet3, oktet4);

}

void IPupis_decimalno(int* oktet1, int* oktet2, int* oktet3, int* oktet4) {

	char tocka;

	cout << "Upisite IP adresu u decimalnom zapisu: ";
	cin >> *oktet1;
	cin >> tocka;
	cin >> *oktet2;
	cin >> tocka;
	cin >> *oktet3;
	cin >> tocka;
	cin >> *oktet4;

}

int decimalno_u_binarno(int a) {

	int broj = 0;
	int i = 0;

	while (a > 0) {

		broj += (a % 2) * pow(10, i);
		i++;
		a /= 2;
	}

	return broj;
}

void ispis_binarno(int oktet1, int oktet2, int oktet3, int oktet4) {

	int oktet1_b = decimalno_u_binarno(oktet1);
	int oktet2_b = decimalno_u_binarno(oktet2);
	int oktet3_b = decimalno_u_binarno(oktet3);
	int oktet4_b = decimalno_u_binarno(oktet4);

	cout << oktet1_b << "." << oktet2_b << "." << oktet3_b << "." << oktet4_b << endl;

}

// (3) PODACI O MREZI

void podaci_o_mrezi() {

	int oktet1, oktet2, oktet3, oktet4;
	int dalje;

	do {
		IPupis_decimalno(&oktet1, &oktet2, &oktet3, &oktet4);

		int odg;
		int s1, s2, s3, s4;

		cout << "Zelite li upisati subnet masku u obliku x.y.z.w (1) ili u obliku /x (2): ";
		cin >> odg;
		if (odg == 1) {

			SMupis1(&s1, &s2, &s3, &s4);
			podaci_mreze_ispis(oktet1, oktet2, oktet3, oktet4, s1, s2, s3, s4);
		}
		else {

			int sm;
			SMupis2(&sm);
			SMpreracunaj(sm, &s1, &s2, &s3, &s4);
			podaci_mreze_ispis(oktet1, oktet2, oktet3, oktet4, s1, s2, s3, s4);

		}

		cout << endl << "Zelite li upisati jos jednu ip adresu? (1=da/0=ne): ";
		cin >> dalje;

	} while (dalje);

}

void SMupis1(int* s1, int* s2, int* s3, int* s4) {

	char tocka;

	cout << "Upisite subnet masku u decimalnom obliku (x.y.z.w): ";
	cin >> *s1;
	cin >> tocka;
	cin >> *s2;
	cin >> tocka;
	cin >> *s3;
	cin >> tocka;
	cin >> *s4;

}

void podaci_mreze_ispis(int oktet1, int oktet2, int oktet3, int oktet4, int s1, int s2, int s3, int s4) {

	int n1 = oktet1, n2 = oktet2, n3 = oktet3, n4 = oktet4;
	int b1 = oktet1, b2 = oktet2, b3 = oktet3, b4 = oktet4;

	if (s1 < 255) {

		n1 = izracunaj(oktet1, s1);
		n2 = 0;
		n3 = 0;
		n4 = 0;

		b1 = n1 + 255 - s1;
		b2 = 255;
		b3 = 255;
		b4 = 255;

	}
	else if (s2 < 255) {

		n2 = izracunaj(oktet2, s2);
		n3 = 0;
		n4 = 0;

		b2 = n2 + 255 - s2;
		b3 = 255;
		b4 = 255;

	}
	else if (s3 < 255) {

		n3 = izracunaj(oktet3, s3);;
		n4 = 0;

		b3 = n3 + 255 - s3;
		b4 = 255;

	}
	else if (s4 < 255) {

		n4 = izracunaj(oktet4, s4);;

		b4 = n4 + 255 - s4;
	}

	cout << endl;
	cout << "adresa mreze: " << n1 << "." << n2 << "." << n3 << "." << n4 << endl;
	cout << "prva korisna: " << n1 << "." << n2 << "." << n3 << "." << n4 + 1 << endl;
	cout << "broadcast: " << b1 << "." << b2 << "." << b3 << "." << b4 << endl;
	cout << "zadnja korisna: " << b1 << "." << b2 << "." << b3 << "." << b4 - 1 << endl;

}

int izracunaj(int oktet, int s) {

	oktet = decimalno_u_binarno(oktet);

	switch (s) {

	case 254:
		oktet /= pow(10, 1);
		oktet *= pow(10, 1);
		break;

	case 252:
		oktet /= pow(10, 2);
		oktet *= pow(10, 2);
		break;

	case 248:
		oktet /= pow(10, 3);
		oktet *= pow(10, 3);
		break;

	case 240:
		oktet /= pow(10, 4);
		oktet *= pow(10, 4);
		break;

	case 224:
		oktet /= pow(10, 5);
		oktet *= pow(10, 5);
		break;

	case 192:
		oktet /= pow(10, 6);
		oktet *= pow(10, 6);
		break;

	case 128:
		oktet /= pow(10, 7);
		oktet *= pow(10, 7);
		break;

	case 0:
		return 0;
		break;

	}

	return binarno_u_decimalno(oktet);
}

void SMupis2(int* sm) {

	cout << "Upisite subnet masku u obliku /x: /";
	cin >> *sm;

}

void SMpreracunaj(int sm, int* s1, int* s2, int* s3, int* s4) {

	if (sm >= 1 && sm <= 8) {

		*s1 = sm_preracunaj(8 - sm);
		*s2 = 0;
		*s3 = 0;
		*s4 = 0;

	}
	else if (sm >= 9 && sm <= 16) {

		*s1 = 255;
		*s2 = sm_preracunaj(16 - sm);
		*s3 = 0;
		*s4 = 0;

	}
	else if (sm >= 17 && sm <= 24) {

		*s1 = 255;
		*s2 = 255;
		*s3 = sm_preracunaj(24 - sm);
		*s4 = 0;

	}
	else if (sm >= 25 && sm <= 32) {

		*s1 = 255;
		*s2 = 255;
		*s3 = 255;
		*s4 = sm_preracunaj(32 - sm);

	}
	else cout << "Greska: subnet maska mora biti u rasponu od 1-32.";

}

int sm_preracunaj(int sm) {

	int broj = 0;

	for (int i = 0; i < 8; i++) {

		if (sm < 1) broj += pow(2, i);
		sm--;

	}
	return broj;
}

// (4) MREZA NA ZAHTJEV

void mreza_na_zahtjev() {

	int o1, o2, o3, o4;

	cout << "Unesite klasu privatnih IP adresa koju zelite koristiti: ";
	IPupis_decimalno_posebno(&o1, &o2, &o3, &o4);

	int dalje, zahtjev;
	int sm, s1, s2, s3, s4;

	do {

		cout << "unesite zahtjev: ";
		cin >> zahtjev;

		SMizracunaj(zahtjev, &sm);
		SMpreracunaj(sm, &s1, &s2, &s3, &s4);
		SMispis(s1, s2, s3, s4);
		podaci_mreze_ispis(&o1, &o2, &o3, &o4, s1, s2, s3, s4);

		cout << endl << "zelite li unjeti jos jedan zahtjev? (1=da/0=ne): ";
		cin >> dalje;


	} while (dalje);

}

void podaci_mreze_ispis(int* oktet1, int* oktet2, int* oktet3, int* oktet4, int s1, int s2, int s3, int s4) {

	int n1 = *oktet1, n2 = *oktet2, n3 = *oktet3, n4 = *oktet4;
	int b1 = *oktet1, b2 = *oktet2, b3 = *oktet3, b4 = *oktet4;

	if (s1 < 255) {

		b1 = n1 + 255 - s1;
		b2 = 255;
		b3 = 255;
		b4 = 255;

	}
	else if (s2 < 255) {

		b2 = n2 + 255 - s2;
		b3 = 255;
		b4 = 255;

	}
	else if (s3 < 255) {

		b3 = n3 + 255 - s3;
		b4 = 255;

	}
	else if (s4 < 255) {

		b4 = n4 + 255 - s4;
	}

	cout << endl;
	cout << "adresa mreze: " << n1 << "." << n2 << "." << n3 << "." << n4 << endl;
	cout << "prva korisna: " << n1 << "." << n2 << "." << n3 << "." << n4 + 1 << endl;
	cout << "broadcast: " << b1 << "." << b2 << "." << b3 << "." << b4 << endl;
	cout << "zadnja korisna: " << b1 << "." << b2 << "." << b3 << "." << b4 - 1 << endl;

	// RACUNANJE POCETKA NOVE MREZE

	*oktet1 = b1; *oktet2 = b2; *oktet3 = b3; *oktet4 = b4;

	if (b2 == 255 && b3 == 255 && b4 == 255) { *oktet1 += 1; *oktet2 = 0; *oktet3 = 0; *oktet4 = 0; }
	else if (b3 == 255 && b4 == 255) { *oktet2 += 1; *oktet3 = 0; *oktet4 = 0; }
	else if (b4 == 255) { *oktet3 += 1; *oktet4 = 0; }
	else *oktet4 += 1;
}

void IPupis_decimalno_posebno(int* o1, int* o2, int* o3, int* o4) {

	char tocka;

	cin >> *o1;
	cin >> tocka;
	cin >> *o2;
	cin >> tocka;
	cin >> *o3;
	cin >> tocka;
	cin >> *o4;

}

void SMizracunaj(int zahtjev, int* sm) {

	for (int i = 0; 1; i++) {

		if (pow(2, i) >= (zahtjev - 2)) { *sm = 32 - i; break; }

	}

}

void SMispis(int s1, int s2, int s3, int s4) {

	cout << "subnet maska: " << s1 << "." << s2 << "." << s3 << "." << s4;

}