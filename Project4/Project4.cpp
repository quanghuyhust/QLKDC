#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Nguoi
{
protected:
	string HoTen;
	int Tuoi;
	string NgheNghiep;
	int CMND;
public:
	Nguoi(string hoten, int tuoi, string nghenghiep, int cmnd): 
		HoTen(hoten),Tuoi(tuoi),NgheNghiep(nghenghiep),CMND(cmnd)
	{}
	Nguoi() {}
	~Nguoi() {}
	virtual void hienthi() 
	{
		cout << "Thong tin ca nhan cua " << HoTen << " la: " << endl;
		cout << "Tuoi: " << Tuoi << endl;
		cout << "Nghe nghiep : " << NgheNghiep << endl;
		cout << "So chung minh thu: " << CMND << endl;
	}
};

class HoGiaDinh
{

protected:
	vector <Nguoi> dsThanhVien;
	int SoThanhVien;
	int SoNha;
public:
	HoGiaDinh(int soTv, int soNha) :
		SoThanhVien(soTv),SoNha(soNha){}
	~HoGiaDinh() {}
	HoGiaDinh() {}
	void nhapThanhVien(Nguoi nguoi) 
	{
		dsThanhVien.push_back(nguoi);
	}
	void hienthi()
	{
		cout << "Ho gia dinh gom: " << SoThanhVien << " thanh vien." << endl;
		cout << "So nha: " << SoNha << endl;
		for (Nguoi nguoi : dsThanhVien) {
			nguoi.hienthi();
		}
	}
};

class KhuPho
{
private:
	vector <HoGiaDinh> dsHoGiaDinh;
	int soHoGD;
public:
	KhuPho(int sohoGD):soHoGD(sohoGD) {}
	~KhuPho() {}
	KhuPho() {}
	void nhapHoGD(HoGiaDinh hgd)
	{
		dsHoGiaDinh.push_back(hgd);
	}
	void hienthi() {
		cout << "So ho gia dinh trong khu la: " << soHoGD << endl;
		int i = 1;
			for (HoGiaDinh h : dsHoGiaDinh)
			{
				cout << "Gia dinh thu " << i << endl;
				h.hienthi();
				i++;
			}
	}

};

int main()
{
	int n;
	cout << "Nhap so ho gia dinh trong khu dan cu" << endl;
	cin >> n;
	KhuPho khupho(n);
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin ho gia dinh thu " << i + 1<<endl;
		cout << "Nhap so nguoi trong gia dinh " << endl;
		int songuoi, sonha;
		cin >> songuoi;
		cout << "Nhap so nha  " << endl;
		cin >> sonha;
		HoGiaDinh hogiadinh(songuoi,sonha);
		for (int j = 0; j < songuoi; j++) 
		{
			string ten, nghe;
			int tuoi, cmnd;
			cout << "Nhap nguoi thu " << j + 1<< endl;
			cout << "Nhap ho va ten: " << endl;
			cin.ignore();
			getline(cin, ten);
			cout << "Nhap tuoi: " << endl;
			cin >> tuoi;
			cout << "Nghe nghiep la: " << endl;
			cin.ignore();
			getline(cin, nghe);
			cout << "So chung minh nhan dan: " << endl;
			cin >> cmnd;
			Nguoi ng(ten,tuoi,nghe,cmnd);
			hogiadinh.nhapThanhVien(ng);
		}
		khupho.nhapHoGD(hogiadinh);
	}
	cout << "Hien thi thong tin khu pho " << endl;
	khupho.hienthi();

	return 0;
}

