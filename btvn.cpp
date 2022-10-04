#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class sinhvien{
	private:
		char hoten[30];
		int renluyen;
		float diemtoan;
		float diemtin;
		float diemanh;
		float heso4;
		float heso10;
		char xeploai[20];
		char hocbong[20];
	public:
		sinhvien(){
			strcpy(hoten, "");
			diemtoan = 0;
			diemtin = 0;
			diemanh = 0; 
			renluyen = 0;
		}
		sinhvien(char *ten, int a, float b, float c, float d){
			strcpy(this->hoten, ten);
			this->renluyen = a;
			this->diemtoan = b;
			this->diemtin = c;
			this->diemanh = d;
		}
		~sinhvien(){}
		void nhap(sinhvien sv[], int &n);
		void xuat(sinhvien sv[], int n);
		void tbcHe4(sinhvien sv[], int n);
		void tbcHe10(sinhvien sv[], int n);
		void ranked(sinhvien sv[], int n);
		void xetHb(sinhvien sv[], int n);		
};
void sinhvien::xetHb(sinhvien sv[], int n){
	for(int i=0; i<n; i++){
		if(sv[i].heso10 >= 9.0 && sv[i].renluyen >= 90){
			strcpy(sv[i].hocbong, "Hang 1");
		}else if(sv[i].heso10 >= 8.0 && sv[i].renluyen >=75){
			strcpy(sv[i].hocbong, "Hang 2");
		}else{
			strcpy(sv[i].hocbong, "Khong co");
		}
	}
}
void sinhvien::ranked(sinhvien sv[], int n){
	for(int i=0; i<n; i++){
		if(sv[i].heso10 >= 9.0){
			strcpy(sv[i].xeploai, "Xuat sac");
		}else if(sv[i].heso10 >= 8.0){
			strcpy(sv[i].xeploai, "Gioi");
		}else{
			strcpy(sv[i].xeploai, "Kha");
		}
	}
}
float convert(float a){
	float temp = 0;
	temp = (a/10)*4;
	return temp;
}
void sinhvien::nhap(sinhvien sv[], int &n){
	for(int i=0; i<n; i++){
		cout<<"Nhap thong tin sinh vien thu "<<i+1<<endl;
		fflush(stdin);
		cout<<"Nhap ten sinh vien: ";
		cin.getline(sv[i].hoten, 30);
		cout<<"Nhap diem toan: ";
		cin>>sv[i].diemtoan;
		cout<<"Nhap diem tin: ";
		cin>>sv[i].diemtin;
		cout<<"Nhap diem anh: ";
		cin>>sv[i].diemanh;
		cout<<"Nhap diem ren luyen: ";
		cin>>sv[i].renluyen;
		cout<<endl;
	}
}
void sinhvien::xuat(sinhvien sv[], int n){
	for(int i=0; i<n; i++){
		cout<<setw(10)<<sv[i].hoten
			<<setw(10)<<sv[i].diemtoan
			<<setw(10)<<sv[i].diemtin
			<<setw(10)<<sv[i].diemanh
			<<setw(10)<<sv[i].renluyen
			<<setw(13)<<sv[i].heso4
			<<setw(10)<<sv[i].heso10
			<<setw(12)<<sv[i].xeploai
			<<setw(10)<<sv[i].hocbong<<endl;
	}
}
void tieude(){
		cout<<setw(10)<<"Ho ten"
			<<setw(10)<<"Toan"
			<<setw(10)<<"Tin"
			<<setw(10)<<"Anh"
			<<setw(15)<<"Ren luyen"
			<<setw(10)<<"Heso 4"
			<<setw(10)<<"Heso 10"
			<<setw(10)<<"Xep loai"
			<<setw(10)<<"Hoc bong"<<endl;
}
void sinhvien::tbcHe4(sinhvien sv[], int n){
	for(int i=0; i<n; i++){
		sv[i].heso4 = (convert(sv[i].diemtoan) + convert(sv[i].diemtin) + convert(sv[i].diemanh))/3;
	}
}
void sinhvien::tbcHe10(sinhvien sv[], int n){
	for(int i=0; i<n; i++){
		sv[i].heso10 = (sv[i].diemtoan + sv[i].diemtin + sv[i].diemanh)/3;
	}
}
int main(){
	int n;
	cout<<"Nhap vao so luong sinh vien: ";
	do{
		cin>>n;
		if(n<=0){
			cout<<"Vui long nhap lai n: ";
		}
	}while(n<=0);
	sinhvien sv[n];
	sv->nhap(sv,n);
	cout<<"\t\t\tBang diem cua sinh vien la: "<<endl;
	sv->tbcHe4(sv,n);
	sv->tbcHe10(sv,n);
	sv->ranked(sv,n);
	sv->xetHb(sv,n);
	tieude();
	sv->xuat(sv,n);
	return 0;
}
