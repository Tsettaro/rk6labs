#include<iostream>
#include<sstream>
#include<sys/ioctl.h> //размер экрана
#include<fcntl.h> //перенаправление потока
#include<signal.h> //обработка сигналов
#include<unistd.h> //для usleep и read

static int done=0; //проверка завершения работы

using namespace std;

namespace con{

 	int comax(){ //определение ширины экрана
 		struct winsize w;
 		ioctl(0,TIOCGWINSZ, &w);
 		return(w.ws_col);
 	}
 	
 	int romax(){ //определение длины экрана
 		struct winsize w;
 		ioctl(0,TIOCGWINSZ, &w);
 		return(w.ws_row);
 	}
 	
 	ostream& ED(ostream& s){ //очистка экрана
 		return s<<string("\033[2J");
 	}
 	
 	class estream{
 	private:
 		string escape;
 	public:
 		estream(string e) : escape(e) {};
 		friend ostream& operator<<(ostream&,estream);
 	};
 	
 	ostream& operator<<(ostream& s,estream e){
 		s<<e.escape<<flush;
 		return s;
 	}
 	
 	estream CUP(int y,int x){ //управление курсором
 		ostringstream sout;
 		sout<<"\033["<<y<<";"<<x<<"H";
 		return estream(sout.str());
 	}
 	
 	estream SGR(int r){ //режим псевдографики
 		ostringstream sout;
 		sout<<"\033["<<r<<"m";
 		return estream(sout.str());
 	}
}

using con::SGR;
using con::CUP;

void interruptor(int signo){ //реализует обработку сигнала ^C
 	done=signo;
 	return;
}

int kbin(){
 	char buf[512];
 	int n=0;
 	int flags=fcntl(0,F_GETFL); //получение флагов файлового дескриптера
 	fcntl(0,F_SETFL,flags|O_NONBLOCK); //установка флага неблокируемого ввода-вывода
 	n=read(0,buf,512); //считывает то, что вводим
 	usleep(1);
 	fcntl(0,F_SETFL,flags); //флаги обновляются
 	return(n);
}

int main(int argc,char** argv){
 	int x1, x2, mid;
 	int f=40;
 	if(con::romax()%2==0)
 		mid=con::romax()/2;
 	else
 		mid=(con::romax()/2)+1;
 	signal(SIGINT,interruptor);
 	while(done<1){
 		for(x1=1,x2=con::romax();x1<=mid && x2>=mid;x1+=2,x2-=2){
 			for(int i = 0;i <= 1;i++)
 				for(int j = 1; j <= con::comax(); j++){
 					cout << SGR(f) << CUP(x1+i,j);
 					cout << " " << flush;
 					cout << SGR(f) << CUP(x2-i,j);
 					cout << " " << flush;
 					usleep(10000);
 				}
 			if (f < 47) f++;
 			else f = 40;
 		}
 		if (kbin() > 0)
			break;
 	    }
 	cout << CUP(1,1) << SGR(0) << con::ED;
} 