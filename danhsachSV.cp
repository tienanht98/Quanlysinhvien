#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<iomanip>
#include<stdlib.h>
#include<fstream>
#include<ctype.h>
#include<string.h>
#include"List.h"
#define TenFile "DanhSachSinhVien.dat"
using namespace std;
void gotoxy(short x, short y)   // Ham gotoxy
{
	
	HANDLE hConsoleOutput;
 	COORD Cursor_an_Pos = { x,y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

//set mau chu cho doan text
void setColor(WORD color){
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	
	CONSOLE_SCREEN_BUFFER_INFO screen;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen);
	
	WORD wAttributes = screen.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
	
}
//tra ve toa do x hien tai cua con nhay trong console
int whereX(void){
	HANDLE hConsloseOutput;
	hConsloseOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	GetConsoleScreenBufferInfo(hConsloseOutput, &coninfo);
	return coninfo.dwCursorPosition.X;
}
//tra ve toa do y hien tai cua nhay trong console
int whereY(void){
	HANDLE hConsloseOutput;
	hConsloseOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	GetConsoleScreenBufferInfo(hConsloseOutput, &coninfo);
	return coninfo.dwCursorPosition.Y;
}
//tao thanh hinh du 4 canh
void Make_Single_Border(int x, int y, int width, int height){
    gotoxy(x,y);
    printf("%c",218); // goc tren trai
    for(int i=1;i<width;i++){
        gotoxy(x+i,y);
        printf("%c",196);
    }
    gotoxy(x+width,y); // goc tren phai
    printf("%c",191);
    for(int i = 1;i<height;i++){
        gotoxy(x,y+i);
        printf("%c",179);
    }
    gotoxy(x,y+height); // goc duoi trai
    printf("%c",192);
    for(int i=1;i<width;i++){
        gotoxy(x+i,y+height);
        printf("%c",196);
    }
    gotoxy(x+width,y+height);  // goc duoi phai
    printf("%c",217);
    for(int i =1;i<height;i++){
        gotoxy(x+width,y+i);
        printf("%c",179);
    } 
}

//an hien cin nhay trong console
void showCursor(bool i){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = i;
	SetConsoleCursorInfo(consoleHandle, &info);
	//true hien con nhay
	//false la an con nhay
}
void Border(int x, int y, int width, int height){

	gotoxy(x,y);
    printf("%c",201); // goc tren trai
    for(int i=1;i<width;i++){
        gotoxy(x+i,y);
        if(i == 6 || i == 22 || i == 32 || i == 73 || i == 88)  {
        	printf("%c",209);
        	int t = y;
        	if(t%2==0){
        	  for(;t<=height;t++){
        		gotoxy(x+i,t+1);
				if(t % 2 == 0) printf("%c",179);
        	    else printf("%c",197); 
			  }
		    } else{
		    	for(;t<=height+1;t++){
        		gotoxy(x+i,t+1);
				if(t % 2 == 1) printf("%c",179);
        	    else printf("%c",197); 
			  }
			}
		    
		}
        else printf("%c",205);
    }
    gotoxy(x+width,y); // goc tren phai
    printf("%c",187);
    for(int i = 1;i<height;i++){
        gotoxy(x,y+i);
        if(i % 2 == 0 ) {
        	printf("%c",199);
        	int t =x+width;
        	for(;t >10; t--){
        		gotoxy(t,y+i);
        		printf("%c",196);
        		if(t == 97 || t == 82 || t == 41 || t == 31 || t == 15) printf("%c",197);
			}
		}
        else
        printf("%c",186);
    }
    gotoxy(x,y+height); // goc duoi trai
    printf("%c",200);
    for(int i=1;i<width;i++){
        gotoxy(x+i,y+height);
        if(i == 6 || i == 22 || i == 32 || i == 73 || i == 88) printf("%c",207);
        else {
        	printf("%c",205);
		}
    }
    gotoxy(x+width,y+height);  // goc duoi phai
    printf("%c",188);
    for(int i =1;i<height;i++){
        gotoxy(x+width,y+i);
        if(i % 2 == 0 ) {
        	printf("%c",182);
		}
        else printf("%c",186);
    }
}

int nhuan(int n){
	return (n%4 == 0) && (n%100 != 0)|| (n%400 == 0);
}
int soNgayCuaThang(int t,int n){
	return (t==4)||(t==6)||(t==9)||(t==11)?30:(t==2)?28+nhuan(n):31;
}
bool testD(int d){
	bool k;
	if(d>0 && d<31) k = true;
	else k = false;
	return k;
}
bool testM(int m){
	bool k;
	if ( (m >= 1) && (m <= 12) )  k = true;
	else k = false;
	return k;
}
bool testDay(int d, int m, int n){
	bool k;
	int S = soNgayCuaThang(m,n);
	if ((d > 0) && (d <= S) && (m >= 1) && (m <= 12) && n >1969 && n<4000)  k = true;
	else k = false;
	return k;
}

bool testMSV(char *n){
	bool t;
	if(strlen(n)>6 && strlen(n) < 9) t= true;
	else t = false;
	return t;
}

bool test(float n){
	bool tg = false;
	if(n>0 && n<=10) tg = true;
	else tg = false;
	return tg;
}

void strdelete(char *s,int vt,int sl) {
	int n=strlen(s),i;
	for (i=vt; i<=n-sl; ++i)
		s[i]=s[i+sl];
}
void chuanhoa(char a[]) {
	int i;
	while(a[strlen(a)-1]==' ')// xoa het cac ki tu trong o cuoi chuoi
		a[strlen(a)-1]=0;
	while(a[0]==' ')          //xoa het cac ki tu trong o dau chuoi
		strdelete(a,0,1);
	for(i=0; i<strlen(a); ++i)
		if((a[i]>=65)&&(a[i]<=90))  //kiem tra co phai la ky tu hoa
			a[i]+=32;        //chuyen tat ca ve ky tu thuong

	i=0;
	while(i<strlen(a))                //xoa hai ki tu trong lien tiep
		if((a[i]==' ')&&(a[i+1]==' '))
			strdelete(a,i,1);
		else ++i;

	for(i=0; i<strlen(a); i++)
		if(a[i]==' ')
			a[i+1]-=32;  //chuyen chu cai sau khoang trang thanh chu hoa

	a[0]=toupper(a[0]);//chuyen chu cai dau tien thanh chu hoa


	i=0;
	while(i<strlen(a))    //xoa cac ki tu khong phai la chu cai
		if((a[i]!=' ')&&(!isalpha(a[i])))
			strdelete(a,i,1);
		else ++i;
}
void readFile(List &l)
{
	fstream fin(TenFile ,ios::binary|ios::in);
	if(fin==NULL) return;
	SinhVien sv;
	while(!fin.eof()){
		fin.read((char*)&sv,sizeof(SinhVien));
		if(!fin.eof()) vht(l,sv);
	}
	fin.close();
}
void writeFile(List l)
{
	node *temp; temp=l.first;
	if(temp==NULL) return;
	fstream fout(TenFile ,ios::trunc|ios::binary|ios::out);
	int n=0;
	while(temp != NULL){
		n++;
		fout.write((const char*)&temp->info,sizeof(SinhVien));
        temp=temp->next;
	}
	fout.close();
}

//nhap thog tin 1 sinh vien
void BangNhap(){
	system("color 03");
	gotoxy(15,2); cout<<"\nMa sinh vien: ";
	Make_Single_Border(15,2,13,2);
	gotoxy(15,5); cout<<"\nMa lop: ";
	Make_Single_Border(15,5,13,2);
	gotoxy(15,8); cout<<"\nHo va ten: ";
	Make_Single_Border(15,8,27,2);
	gotoxy(15,11); cout<<"\nNgay sinh: ";
	Make_Single_Border(15,11,5,2);
	Make_Single_Border(21,11,5,2);
	Make_Single_Border(27,11,9,2);
	gotoxy(15,14); cout<<"\nDiem TBTL: ";
	Make_Single_Border(15,14,7,2);
}

SinhVien nhap() {
	List l;
	Init(l);
	SinhVien x;
	int n,t=0;
	setColor(2);
	do {
		BangNhap();
		gotoxy(16,3);
		cin>>x.maSV;
		if(testMSV(x.maSV)==true) 
		{
			gotoxy(30,3);
			cout<<"                     ";
		} 
		else 
		{
			gotoxy(30,3);
			cout<<"nhap lai ma sinh vien";
		}
	}
	 while(testMSV(x.maSV) == false);
	fflush(stdin);
	do {
		BangNhap();
		gotoxy(16,3);
		cout<<x.maSV;
		gotoxy(16,6);
		cin>>x.maLop;
		fflush(stdin);
	} while(strlen(x.maLop) < 1 || strlen(x.maLop) >8);
	do {
		BangNhap();
		gotoxy(16,3);
		cout<<x.maSV;
		gotoxy(16,6);
		cout<<x.maLop;
		gotoxy(16,9);
		gets(x.hoTen);
		chuanhoa(x.hoTen);
		fflush(stdin);
	} while(strlen(x.hoTen) < 2 || strlen(x.hoTen) > 25);
	do {
		BangNhap();
		gotoxy(16,3);
		cout<<x.maSV;
		gotoxy(16,6);
		cout<<x.maLop;
		gotoxy(16,9);
		cout<<x.hoTen;
		do {
			gotoxy(17,12);
			cin>>x.ngay;
			
            if(testD(x.ngay)==true) 
		{
			gotoxy(38,12);
			cout<<"              ";
		} 
		else 
		{
			gotoxy(38,12);
			cout<<"nhap lai ngay";
		}
		
		} while(testD(x.ngay) == false);
		do {
			gotoxy(23,12);
			cin>>x.thang;
			  if(testM(x.thang)==true) 
		{
			gotoxy(38,12);
			cout<<"              ";
		} 
		else 
		{
			gotoxy(38,12);
			cout<<"nhap lai thang";
		}
		} while(testM(x.thang) == false);
		gotoxy(29,12);
		cin>>x.nam;
		fflush(stdin);
		 if(testDay(x.ngay,x.thang,x.nam)==true) 
		{
			gotoxy(38,12);
			cout<<"                            ";
		} 
		else 
		{
			gotoxy(38,12);
			cout<<"nhap lai ngay , thang , nam ";
		}
		
	} while(testDay(x.ngay,x.thang,x.nam) == false);
	do {
		BangNhap();
		gotoxy(16,3);
		cout<<x.maSV;
		gotoxy(16,6);
		cout<<x.maLop;
		gotoxy(16,9);
		cout<<x.hoTen;
		gotoxy(17,12);
		cout<<x.ngay;
		gotoxy(23,12);
		cout<<x.thang;
		gotoxy(29,12);
		cout<<x.nam;
		gotoxy(17,15);
		cin>>x.dtb;
		fflush(stdin);
	} while(test(x.dtb) == false);
	return x;
}	
//nhap danh sach
void NhapDS(List &L){
    int t=0;
   while(t!=27)
   {
	showCursor(true);
	SinhVien x;
	system("cls");
	gotoxy(5,1);
	cout<<"NHAP THONG TIN SINH VIEN : "<<endl;
	x = nhap();
	vht(L,x);	
	writeFile(L);
	cout<<endl;
//	system("pause");
	system("cls");
	cout<<"Ban co muon nhap tiep "<<endl;
	    t=getch();

	if(t==27) break;
   }
}


//in ra thong tin 1 SV
void in(SinhVien &sv, int n){
	int xx = 10, y=3; 
	int stt=n; n=n%5+1;//chu y
	Border(xx,y,100,2*(n+1));
	gotoxy(xx+2,y+2*n+1); cout<<stt; 
	gotoxy(xx+8,y+2*n+1); cout<<sv.maSV;
	gotoxy(xx+24,y+2*n+1); cout<<strupr(sv.maLop);
	gotoxy(xx+45,y+2*n+1); cout<<sv.hoTen;
	gotoxy(xx+77,y+2*n+1); 
	if(sv.ngay < 10 && sv.thang < 10)
	cout<<"0"<<sv.ngay<<"/0"<<sv.thang<<"/"<<sv.nam;
	if(sv.thang >=10 && sv.ngay < 10) 
	cout<<"0"<<sv.ngay<<"/"<<sv.thang<<"/"<<sv.nam;
	if(sv.thang <10 && sv.ngay >= 10)
	cout<<sv.ngay<<"/0"<<sv.thang<<"/"<<sv.nam;
	if(sv.thang >= 10 && sv.ngay >= 10)
	cout<<sv.ngay<<"/"<<sv.thang<<"/"<<sv.nam;
	fflush(stdout);
	gotoxy(xx+93,y+2*n+1); cout<<sv.dtb;
	
}
//in danh sach

void InDS(List &L){
	system("color 03");
	showCursor(false);
	int i=0,dem =1,t=0;
	if(L.first == NULL){
		cout<<"Danh sach chua co sinh vien"<<endl;
		cout<<"Ban phai tao danh sach de co the in"<<endl;
		NhapDS(L);
	}
	node *p = L.first;
	int xx =10, y = 3;
	gotoxy(xx+2,y+1); cout<<"STT";
	gotoxy(xx+8,y+1); cout<<"MA SINH VIEN";
	gotoxy(xx+24,y+1); cout<<"MA LOP";
	gotoxy(xx+49,y+1); cout<<"HO VA TEN";
	gotoxy(xx+76,y+1); cout<<"NGAY SINH";
	gotoxy(xx+90,y+1); cout<<"DIEM TBTL";
	while(p!= NULL){
		dem++;
		in(p->info,i);
		  if(p==NULL) cout<<endl<<endl;
		if(dem%6==0)
		{       system("pause");
		        system("cls");
		        gotoxy(8,87); cout<<"BAN CO MUON XEM TIEP"<<endl;
				
			   t=getch();
			   if(t==13)
				{   i++;
				    system("cls");
				    int xx =10, y = 3;
					gotoxy(xx+2,y+1); cout<<"STT";
					gotoxy(xx+8,y+1); cout<<"MA SINH VIEN";
					gotoxy(xx+24,y+1); cout<<"MA LOP";
					gotoxy(xx+49,y+1); cout<<"HO VA TEN";
					gotoxy(xx+76,y+1); cout<<"NGAY SINH";
					gotoxy(xx+90,y+1); cout<<"DIEM TBTL";
				    in(p->info,i);
				    if(p==NULL) cout<<endl<<endl;
				    
				}	
				else  break;
				
		}
		p = p->next;
		i++;
	}
	cout<<endl<<endl;
//	system("pause");
//	system("cls");
}


int menuChinh(int chon){
	system ( "color 04" );
	system("cls");
	int i=0;
	Make_Single_Border(0,0,33,12);
    Make_Single_Border(34,0,88,12);
	int x=1,y=1;
	int k=2,dem=0;gotoxy(1,11);
	gotoxy(x,y);
	HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    string a[]={"Them ho so moi          ",
     "In danh sach               ","Sap xep              ",
    "Tim kiem              ","Thong ke                ","Thoat        "	};
	cout<<"\n (*;*)><Quan li sinh vien><(*..*)"<<endl<<"\n";
     SetConsoleTextAttribute(hConsoleColor, 10);
    gotoxy(38,4);cout<<"                    TRAN TIEN ANH                          ";
    gotoxy(38,5);cout<<"                      KHMT 15-3                        ";
    gotoxy(38,6);cout<<"                                 ";
		int t=0;
		while(t!=13)
		{
			
			for(int i=0;i<6;i++){
				
		    	if(i==chon){
		    		setColor(14);
				}
			        
		    	else{
		    		setColor(9);
		    	}
		        	gotoxy(1,i+4);
		    	cout<<a[i]<<endl;
		    }
		t=getch();
		if(t == 224)
		{
			t=getch();
			if(t == 80 ){   //ba nut di xuong
				chon++;
				if(chon > 6) {  //khi dang o cuoi bam down no ve dau menu
					gotoxy(0,4);
					chon = 0;
				}
 			}
			else if(t == 72 ){   //bam nut di len
				chon--;
		    	if(chon < 0) {  //khi dang o dau menu bam up se di ve cuoi
		    		gotoxy(6,10);
		    		chon = 5;
			    }
		    }
		}
	}
	return chon+1;
}


int menusapxep(int chon)
{
	system("cls");
	setColor(15);
	cout<<"Ban muon sap xep theo:"<<endl;
	string a[]={" 1.Ma sinh vien"," 2.Ma lop"," 3.Ho va ten"," 4.Diem trung binh (tang dan)"," 5.Ngay sinh"," 6.Quay lai"};
	int t=0;
		while(t!=13)
		{
			
			for(int i=0;i<6;i++){
				
		    	if(i==chon){
		    		setColor(14);
				}
			        
		    	else{
		    		setColor(9);
		    	}
		        	gotoxy(1,i+4);
		    	cout<<a[i]<<endl;
		    }
		t=getch();
		if(t == 224)
		{
			t=getch();
			if(t == 80 ){   //bam nut di xuong
				chon++;
				if(chon > 6) {  //khi dang o cuoi baam down n c=ve dau menu
					gotoxy(0,4);
					chon = 0;
				}
 			}
			else if(t == 72 ){   //bam nut di len
				chon--;
		    	if(chon < 0) {  //khi dang o dau menu bam up se di ve cuoi
		    		gotoxy(6,10);
		    		chon = 6;
			    }
		    }
		}
	}
	return chon+1;
}	
//sap xep
void chialane(char *mid, char*top, char*bot, char*all) { // Hàm tách ho và Tên
	int nDo_Dai = strlen(all);
	int i;
	for (i = 0; i < nDo_Dai - 1; i++) {
		if (all[i] == ' ' || all[i] == '/') {
			break;
		}
		bot[i] = all[i];
	}
	bot[i] = '\0';
	int x = i + 1;
	for (i = nDo_Dai - 1; i > 0; i--) {
		if (all[i - 1] == ' ' || all[i] == '/') {
			break;
		}
	}
	int y = i - 1;
	int t = 0;
	for (i; i < nDo_Dai; i++) {
		top[t++] = all[i];
	}
	top[t] = '\0';
	int d = 0;
	for (x; x < y; x++) {
		mid[d++] = all[x];
	}
	mid[d] = '\0';
}
int SoloKill(char *x, char *y) {
	int nDo_Dai_x = strlen(x);
	int nDo_Dai_y = strlen(y);
	int nDo_Dai_min = nDo_Dai_x;
	int nDo_Dai_max = nDo_Dai_y;
	if (nDo_Dai_x > nDo_Dai_y) {
		nDo_Dai_min = nDo_Dai_y;
		nDo_Dai_max = nDo_Dai_x;
	}
	int i;
	for (i = 0; i < nDo_Dai_min; i++) {
		if (x[i] < y[i]) {
			return -1;
		}
		else if (x[i] > y[i]) {
			return 1;
		}
	}

	if (i == nDo_Dai_max) {
		return 0;
	}

	if (i == nDo_Dai_x) {
		return 1;
	}
	else {
		return -1;
	}
}
void Swap(SinhVien &a, SinhVien &b) 
{ 
     SinhVien c;
     c=a;
     a=b;
     b=c;
}
void CompareD(SinhVien &a, SinhVien &b){
	if(a.nam > b.nam ||a.nam == b.nam && a.thang > b.thang || a.nam == b.nam && b.thang == a.thang && a.ngay < b.ngay)
	 swap(a,b);
}


char *chuyendoi(char s[50])
  {
    int i = 0, n;
    char tam[10], ten[50];
   
    n = strlen(s) - 1;
    while (s[n]!= ' '&&n>=0)
    {
        tam[i++] = s[n];
        n--;
    }
 
    tam[i++] = '\0';
    s[n] = '\0';
 
    strcpy(ten, strrev(tam));
    strcat(ten, " ");
    strcat(ten, s);
   
    strcpy(s, ten);
 
    return s;
}
void SelectionSort(List &L,int n){//sap xep lua chon
	switch(n){
	case 1:{
		List Lr;
		Init(Lr);
		node *min;
		node *p,*q, *minprev;
	   while(L.first != NULL){
	     	p = L.first;
	    	q = p -> next;
	    	min = p;
	    	minprev = NULL;
	    	while(q  != NULL){
	    		if(strcmp(q->info.maSV , min->info.maSV)>0)// so sanh do dai chuoi
				{
		        	min = q;
		        	minprev = p;
		        }
		        p = q;
	    	    q = q->next;
            }
            if(minprev != NULL)  minprev->next = min->next;
            else L.first = min->next;
            min->next = NULL;
            vht(Lr,min->info);
       }
       L = Lr;
	   break;
	   }
	case 2:{
		List Lr;
		Init(Lr);
		node *min;
		node *p,*q, *minprev;
	   while(L.first != NULL){
	   	   p = L.first;
		   q = p -> next;
		   min = p;
		   minprev = NULL;
	    	while(q  != NULL){
	    		if(strcmp(q->info.maLop , min->info.maLop)>0){
		    	   min = q;
		    	   minprev = p;
		        }
		        p = q;
		        q = q->next;
            }
            if(minprev != NULL)  minprev->next = min->next;
            else L.first = min->next;
            min->next = NULL;
            vht(Lr,min->info);
       }
       L = Lr;
	   break;
	   }
    case 3:{
		List Lr;
		Init(Lr);
		node *min;
		node *p,*q, *minprev;
	   while(L.first != NULL){
	   	   p = L.first;
		   q = p -> next;
		   min = p;
		   minprev = NULL;
	    	while(q  != NULL){
	    		char a[23],b[23] ;
				strcpy(a, q->info.hoTen);
	            strcpy(b,min->info.hoTen) ;
	    		if(strcmp(chuyendoi(a) , chuyendoi(b))>0){
		        	min = q;
		        	minprev = p;
		        }
		        p = q;
		        q = q->next;
            }
            if(minprev != NULL)  minprev->next = min->next;
            else L.first = min->next;
            min->next = NULL;
            vht(Lr,min->info);
       }
       L = Lr;
	   break;
	   }
    case 4:{
		List Lr;
		Init(Lr);
		node *min;
		node *p,*q, *minprev;
	   while(L.first != NULL){
	   	   p = L.first;
		   q = p -> next;
		   min = p;
		   minprev = NULL;
	    	while(q  != NULL){
	    		if(q->info.dtb > min->info.dtb){
		        	min = q;
		        	minprev = p;
		        }
		        p = q;
		        q = q->next;
            }
            if(minprev != NULL)  minprev->next = min->next;
            else L.first = min->next;
            min->next = NULL;
            vht(Lr,min->info);
       }
       L = Lr;
	   break;
	   }
	case 5:{
		List Lr;
		Init(Lr);
		node *min;
		node *p,*q, *minprev;
	   while(L.first != NULL){
	   	   p = L.first;
		   q = p -> next;
		   min = p;
		   minprev = NULL;
	    	while(q  != NULL){
		        CompareD(p->info,min->info);
		        p = q;
		        q = q->next;
            }
            if(minprev != NULL)  minprev->next = min->next;
            else L.first = min->next;
            min->next = NULL;
            vht(Lr,min->info);
       }
       L = Lr;
		break;
	}
    case 6: 
       cout<<"thoat"<<endl;
       break;
    }
}
int menuTimkiem(int chon){
	system("cls");
	cout<<"Tim kiem: "<<endl;
	string a[] ={" 1.Theo ten"," 2.Theo ma sinh vien"," 3.Ma lop"," 4.Diem trung binh"," 5.Quay lai"};
	int t=0;
		while(t != 13)
		{
			
			for(int i=0;i<5;i++){
				
		    	if(i==chon){
		    		setColor(14);
				}
			        
		    	else{
		    		setColor(9);
		    	}
		        	gotoxy(1,i+4);
		    	cout<<a[i]<<endl;
		    }
		t=getch();
		
		if(t == 224)
		{
			t=getch();
			if(t == 80 ){   //bam nut di xuong
				chon++;
				if(chon > 5) {  //khi dang o cuoi baam down n c=ve dau menu
					gotoxy(0,4);
					chon = 0;
				}
 			}
			else if(t == 72 ){   //bam nut di len
				chon--;
		    	if(chon < 0) {  //khi dang o dau menu bam up se di ve cuoi
		    		gotoxy(6,10);
		    		chon = 5;
			    }
		    }
		}
	}
	return chon+1;
}	
void Doi(List &L, SinhVien sv[]){
	int i = 0;
	if(L.first == NULL) return;
	node *p = L.first;
	while(p != NULL){
		sv[i] = p->info;
		p = p->next;
		i++;
	}
}

void Timkiem(SinhVien sv[],char truytim[], int dem,int n){
	int ktr = 0, stt = 1;
	int xx =10, y = 3;
	char *op;
	gotoxy(xx+2,y+1); cout<<"STT";
	gotoxy(xx+8,y+1); cout<<"MA SINH VIEN";
	gotoxy(xx+24,y+1); cout<<"MA LOP";
	gotoxy(xx+49,y+1); cout<<"HO VA TEN";
	gotoxy(xx+76,y+1); cout<<"NGAY SINH";
	gotoxy(xx+90,y+1); cout<<"DIEM TBTL";

	if(n == 2){
		char kk[15];
		strcpy(kk, truytim);
		for(int i = 0; i < dem; i++){
			if(strstr(sv[i].maSV,truytim) != NULL){
				in(sv[i],stt);
				stt++;
			}
		}
		
		if(stt == 1)
		{
		  cout<<endl<<"khong tim thay!"<<endl;
		  getch();
		  system("pause");
		  		menuTimkiem(n);

	}
		else{
			Make_Single_Border(80,0,25,2);
			gotoxy(82,1); cout<<"Tong so: "<<stt-1;
			system("pause");
					  getch();




				menuTimkiem(n-1);
		}
		
	
	}
	if(n == 3){
		char kk[15];
		strcpy(kk, truytim);
		for(int i = 0; i< dem;i++){
			if(strstr(sv[i].maLop,strupr(kk)) != NULL){
				in(sv[i],stt);
				stt++;
			}
		}
		if(stt == 1) cout<<endl<<"khong tim thay!"<<endl;
		
		else{
			Make_Single_Border(80,0,25,2);
			gotoxy(82,1); cout<<"Tong so: "<<stt-1;
		}
		getch();
	}
		
    if(n == 1){
    	
		chuanhoa(truytim);
		for(int i = 0; i < dem; i++){
			op=strstr(sv[i].hoTen,truytim);
			if(op!=NULL){
				in(sv[i],stt);
				stt++;
			}
		}
		if(stt == 1) cout<<endl<<"khong tim thay!"<<endl;
		else{
			Make_Single_Border(80,0,25,2);
			gotoxy(82,1); cout<<"Tong so: "<<stt-1;
		}
		getch();
	}
	if(n == 4){
        float a = atof(truytim);   //atof chuyen strinh thanh so thap phan
        for(int i = 0;i<dem;i++){
        	if(sv[i].dtb == a) {
        		in(sv[i],stt);
        		stt++;
			}
		}
		if(stt == 1) cout<<endl<<"khong tim thay!"<<endl;
		else{
			Make_Single_Border(80,0,25,2);
			gotoxy(82,1); cout<<"Tong so: "<<stt-1;
		}
		getch();
	}
	
}
int menuThongKe()
{
	system("cls");
	setColor(28);
	cout<<"Ban muon sap xep theo:"<<endl;
	string a[]={" 1.Diem trung binh"," 2.Ma lop"," 3.Quay lai"};
	int chon=0,t=0;
		while(t!=13)
		{

			for(int i=0;i<3;i++){

		    	if(i==chon){
		    		setColor(14);
				}

		    	else{
		    		setColor(9);
		    	}
		        	gotoxy(1,i+4);
		    	cout<<a[i]<<endl;
		    }
		t=getch();
		if(t == 224)
		{
			t=getch();
			if(t == 80 ){   //ba nut di xuong
				chon++;
				if(chon > 2) {  //khi dang o cuoi baam down n c=ve dau menu
					gotoxy(0,4);
					chon = 0;
				}
 			}
			else if(t == 72 ){   //bam nut di len
				chon--;
		    	if(chon < 0) {  //khi dang o dau menu bam up se di ve cuoi
		    		gotoxy(6,10);
		    		chon = 2;
			    }
		    }
		}
	}
	return chon+1;
}
//thong ke
void Thongkelop(List &L){
	system("cls");
	int stt = 0;
	char a[10];
	node *p = L.first;
	int xx =10, y = 3;

	Make_Single_Border(0,0,35,2);
	InDS(L);
	gotoxy(1,1); cout<<"Can thong ke lop: ";
	gotoxy(19,1); fflush(stdin); gets(a);
	strupr(a);
	system("cls");
	gotoxy(xx+2,y+1); cout<<"STT";
	gotoxy(xx+8,y+1); cout<<"MA SINH VIEN";
	gotoxy(xx+24,y+1); cout<<"MA LOP";
	gotoxy(xx+49,y+1); cout<<"HO VA TEN";
	gotoxy(xx+76,y+1); cout<<"NGAY SINH";
	gotoxy(xx+90,y+1); cout<<"DIEM TBTL";
	while(p !=NULL){
		if(strcmp(p->info.maLop,a) == 0){
			in(p->info,stt);
			stt++;
		}
		p=p->next;
	}
	Make_Single_Border(80,0,25,2);
	gotoxy(81,1); cout<<"Tong so: "<<stt;
    getch();
	system("cls");
}
struct XepLoai{
	float xs;
	float gioi;
	float kha;
	float tb;
	float yeu;
};
void Thongkedanhdau(List &L){
	system("cls");
	int l = length(L);
	XepLoai xl;
	xl.xs = xl.gioi = xl.kha = xl.tb = xl.yeu =0;
	node *p =L.first;
	while(p != NULL){
		if(p->info.dtb >= 9)  xl.xs++;
		if(p->info.dtb < 9 && p->info.dtb >= 8) xl.gioi++;
		if(p->info.dtb < 8 && p->info.dtb >= 6.5) xl.kha++;
		if(p->info.dtb < 6.5 && p->info.dtb >= 4) xl.tb++;
		if(p->info.dtb < 4) xl.yeu++;
		p =p->next;
	}
	setColor(15);
	gotoxy(25,4); cout<<"THONG KE KET QUA HOC TAP SINH VIEN"<<endl;
	Make_Single_Border(18,6,50,10);
	setColor(27);
	gotoxy(23,7);  cout<<"Phan tram sinh vien xuat sac  : "<<(float)((xl.xs/l)*100)<<"%";
	gotoxy(23,8);  cout<<"Phan tram sinh vien gioi      : "<<(float)((xl.gioi/l)*100)<<"%";
	gotoxy(23,9);  cout<<"Phan tram sinh vien kha       : "<<(float)((xl.kha/l)*100)<<"%";
	gotoxy(23,10); cout<<"Phan tram sinh vien trung binh: "<<(float)((xl.tb/l)*100)<<"%";
    gotoxy(23,11); cout<<"Phan tram sinh vien yeu       : "<<(float)((xl.yeu/l)*100)<<"%";
    setColor(15);
    Make_Single_Border(30,13,24,2);
    gotoxy(33,14); cout<<"Tong so sinh vien: "<<l;
	gotoxy(23,15); cout<<endl<<endl;
	system("pause");
	system("cls");
}

void menu(){
	int n;
	List L;
	Init(L);
	readFile(L);
	do{
	n = menuChinh(0);
		system("cls");
		switch(n){
			case 1:{
				NhapDS(L);
				InDS(L);
				system("pause");
				system("cls");
				break;
			}
			
			case 2:{
				system("cls");
				InDS(L);
				system("pause");
				system("cls");
				system ( "color 04" );
				menuChinh(1);
				break;
			}
			case 3:{
				int item; 
				do{
					    item = menusapxep(0);
						if(item==6)break;
						else{
								SelectionSort(L, item);
								system("cls");
								InDS(L);
								system("pause");
							    system("cls");
					    }		
				}while(item!=6);
				system("cls");
				system ( "color 04" );
				menuChinh(2);
				break;
			}
			case 4:{
				int item, i = 0, dem;
				do{
							system("cls");
							SinhVien *sv;
			            	item = menuTimkiem(0);
							if ( item == 5) break;
			            	char a[40];
			            	dem = length(L);
			            	system("cls");
			            	InDS(L);
							Make_Single_Border(0,0,30,2);
			    	        gotoxy(1,1); cout<<"Tim kiem  :   ";
			    	        gotoxy(13,1); gets(a);
			    	        system("cls");
			    	        Doi(L,sv);
			    	        system("cls");
							break;
				}while(item != 5);
				system("cls");
				system ( "color 04" );
				menuChinh(3);
		   		break;
			}
			case 5:{
				
				system("cls");
				system ( "color 04" );
				int item;
				do{
					item = menuThongKe();
					if(item == 1) Thongkedanhdau(L);
					if(item == 2) Thongkelop(L);
					if(item == 3) break;
				}while(item != 3);
				break;
				menuChinh(4);
				break;
			}
			case 6:{
				system("cls");
				
				gotoxy(45,5);
				
				cout<<"Cam on da xem!!!";
				gotoxy(45,6); cout<<"Hen gap lai!!!"<<endl<<endl<<endl;				
				break;

			}
			
				
				
				
                

			
		}
		if(L.first!=NULL)
	    writeFile(L);	
	}while(n != 7);
}
int main(){
	system("chcp 437");
	system("MODE CON COLS=125 LINES=18");
	system("color 10");
	menu();
	return 0;
}







