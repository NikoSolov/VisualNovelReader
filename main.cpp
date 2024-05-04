#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream> 
#include <conio.h>
#include <windows.h>
#include "mmsystem.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void SetWindow(int X, int Y){
/*	
  SMALL_RECT windowSize = {0, 0, width-1, height-1};
  COORD bufferSize = {width, height};
  
  HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
  HANDLE rHnd = GetStdHandle(STD_INPUT_HANDLE);
  
  SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
  SetConsoleScreenBufferSize(wHnd, bufferSize);
  
  HWND consoleWindow = GetConsoleWindow();
  SetWindowPos( consoleWindow, 0, X, Y, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
*/  
HANDLE buff = GetStdHandle(STD_OUTPUT_HANDLE);
COORD sizeOfBuff;
sizeOfBuff.X=X;
sizeOfBuff.Y=Y;
SetConsoleScreenBufferSize(buff,sizeOfBuff);
}

void fontsize(int a, int b){ 
CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 0;
cfi.dwFontSize.X = 0;                   // Width of each character in the font
cfi.dwFontSize.Y = 24;                  // Height
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_NORMAL;
if (b==0){wcscpy(cfi.FaceName, L"Terminal");}
else if (b==1){wcscpy(cfi.FaceName, L"Consolas");}
else if (b==2){wcscpy(cfi.FaceName, L"Courier New");}
else if (b==3){wcscpy(cfi.FaceName, L"Luicida Console");}
else if (b==4){wcscpy(cfi.FaceName, L"MS Gothic");}
else if (b==5){wcscpy(cfi.FaceName, L"NSimSun");}
else if (b==6){wcscpy(cfi.FaceName, L"SimSun-ExtB");}
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
 }  
//-------------------------------------------------------------------

int main(int argc, char** argv) {
	string str="\n	VISUAL NOVEL READER BY Niko Solov";
	string s, c, d, x, y, n, m;
	int color, speed,delay, X, Y, F1, F2;
	
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	
	ifstream txt;
	txt.open("text.txt");
	
	char name[100]="VISUAL NOVEL READER";
	SetConsoleTitle(name);
	
	HWND consoleWindow = GetConsoleWindow();
/*	for (int i(0); i<500; i++){
	SetWindowPos( consoleWindow, 0, i, i, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
	Sleep(100);
	}
*/	
	for (int i=0; i<str.size(); i++){cout<<str[i]; Sleep(50);}
/*	for (int i(0); i<7; i++){
	fontsize(28, i);
	Sleep(2000);
	}*/
	Sleep(1000);
	Beep(3000, 100);
	Sleep(100);
	Beep(4000, 100);
	Sleep(100);
	Beep(4040, 500);
	Sleep(1000);
	system("cls");
	Sleep(1000);
	str="";
	


	
	
while (true){
getline(txt, str, '\n');
		
for (int i=0; i<str.size(); i++){
	
	if (str[i]=='`'){ i+=1;
	
		if (str[i]=='s'){i+=1; s=str[i]; i+=1; while(str[i]!='`'){s+=str[i];i+=1;} speed=atoi(s.c_str()); }

		else if (str[i]=='c'){i+=1; c=str[i]; i+=1; while(str[i]!='`'){c+=str[i];i+=1;} color=atoi(c.c_str() ); HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(console, color);}
	
		else if (str[i]=='d'){i+=1; d=str[i]; i+=1; while(str[i]!='`'){d+=str[i];i+=1;} int delay=atoi(d.c_str() ); Sleep(delay);}
			
		else if (str[i]=='w'){i+=1;
				 
			if (str[i]=='n'){ i+=1; n=str[i]; i+=1; while(str[i]!='`'){n+=str[i]; i+=1;} char *cstr = new char[n.length() + 1]; strcpy(cstr, n.c_str()); SetConsoleTitle(cstr); delete [] cstr;}
			if (str[i]=='x'){ i+=1; x=str[i]; i+=1; while(str[i]!='`'){x+=str[i]; i+=1;} X=atoi(x.c_str());} 
			if (str[i]=='y'){ i+=1; y=str[i]; i+=1; while(str[i]!='`'){y+=str[i]; i+=1;} Y=atoi(y.c_str());}
			else {i+=1; while(!getch()){} i+=1;}	
//			SetWindow(128, 64, X, Y);	
		}
		else if (str[i]=='m'){i+=1; 
				
			if (str[i]=='s'){PlaySound(NULL, NULL, SND_ASYNC|SND_LOOP|SND_NODEFAULT);}
			
			if (str[i]=='l'){i+=1; m=str[i]; i+=1; while(str[i]!='`'){m+=str[i];i+=1;} LPCSTR music=m.c_str(); PlaySound(music, NULL, SND_ASYNC|SND_LOOP|SND_NODEFAULT);}
			
			else {m=str[i]; i+=1; while(str[i]!='`'){m+=str[i];i+=1;}  LPCSTR music=m.c_str(); PlaySound(music, NULL, SND_ASYNC|SND_NODEFAULT);}}

		else if (str[i]=='`'){cout<<endl;}
		
		else {system("cls");}
			
		}
			
	else{cout<<str[i]; Sleep(speed); } 
	}
}
	return 0;
}
