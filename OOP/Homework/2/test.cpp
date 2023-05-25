#include<iostream>
#include<sstream>
#include<sys/ioctl.h>
#include<fcntl.h>
#include<signal.h>
#include<unistd.h>

static int done = 0;
static int mid = 0;

using namespace std;

namespace con{

 	int comax(){
 		struct winsize w;
 		ioctl(0,TIOCGWINSZ, &w);
 		return(w.ws_col);
 	}
 	
 	int romax(){
 		struct winsize w;
 		ioctl(0,TIOCGWINSZ, &w);
 		return(w.ws_row);
 	}
 	
 	
 	class estream{
 	private:
 		string escape;
 	public:
 		estream(string e) : escape(e) {};
 		friend ostream& operator<<(ostream&,estream);
 	};
 	
 	ostream& operator <<(ostream& s,estream e){
 		s << e.escape << flush;
 		return s;
 	}
 	
	ostream& ED(ostream& s){
 		return s<<string("\033[2J");
 	}

 	estream CUP(int y,int x){
 		ostringstream sout;
 		sout << "\033[" << y << ";" << x << "H";
 		return estream(sout.str());
 	}
 	
 	estream SGR(int r){
 		ostringstream sout;
 		sout<<"\033["<< r <<"m";
 		return estream(sout.str());
 	}
}

using con::SGR;
using con::CUP;

void interruptor(int signo){
 	done=signo;
 	return;
}

void resizeHandler(int signo) {
    if (con::romax() % 2 == 0)
        mid = con::romax() / 2;
    else
        mid = (con::romax() / 2) + 1;
}

int kbin(){
 	char buf[512];
 	int n=0;
 	int flags=fcntl(0,F_GETFL);
 	fcntl(0,F_SETFL,flags|O_NONBLOCK);
 	n=read(0,buf,512);
 	usleep(1);
 	fcntl(0,F_SETFL,flags);
 	return(n);
}

int main(int argc,char** argv){
 	int f = 40;
	int x1, x2;
 	if(con::romax()%2 == 0)
 		mid=con::romax()/2;
 	else
 		mid = (con::romax()/2) + 1;

 	signal(SIGINT,interruptor);
	signal(SIGWINCH, resizeHandler);
 	while(done < 1){
 		for(x1 = 1, x2 = con::romax(); x1 <= mid && x2 >= mid;x1 += 2,x2 -= 2){
 			for(int i = 0; i < 2; i++)
 				for(int j = 1; j <= con::comax(); j++){
 					cout << SGR(f) << CUP(x1+i,j);
 					cout << " " << flush;
 					cout << SGR(f) << CUP(x2-i,j);
 					cout << " " << flush;
 					usleep(1000);
 				}
 			if (f < 47) f++;
 			else f = 40;
 		}
		if (kbin() > 0)
			break;
 	}
 	cout << CUP(1,1) << SGR(0) << con::ED << flush;
} 