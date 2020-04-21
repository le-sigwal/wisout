//-------------------------------------------------------------------------
/* File: wisout.cpp
 * Description: "WIth SOcket oUT" Project
 *                Simple socket reset
 * Authors: Bagad Sigwal
 * Copyright: 2020 Sigwal.info/github - All Rights Reserved
 * Last modification: 10/04/2020
 * Version: 20.04
 *
 * Change records:
 * SWL - 10/04/2020 - creation, added main() for debug
 *                    added printfa(), printfe(),
 *                    added send(), select(), recv(), closesocket(),
 *                      WSAStartup(), gethostbyname(), htons),
 *                      socket() & connect() for win32                   */
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
//[>DEFINITIONS]
//-------------------------------------------------------------------------
//[>STANDARD DEFINITIONS]
#include <iostream>
#ifdef WIN32
#  include <winsock2.h>
#  undef send
#  undef select
#  undef recv
#  undef closesocket
#  undef WSAStartup
#  undef gethostbyname
#  undef htons
#  undef socket
#  undef connect
#  undef WINSOCK_API_LINKAGE
#  define WINSOCK_API_LINKAGE
#endif
//[>EXTERN DEFINITIONS]
//[>PROJECT DEFINITIONS]
//[>LOCAL DEFINITIONS]
#define WISOUT_VERSION "20.04"
//
int wstfcn=0, wstfci;
//-------------------------------------------------------------------------
//[<DEFINITIONS]
//-------------------------------------------------------------------------

void wstprintfa(const char *cfichier, const char *cfonction){
	for(wstfci=0;wstfci<wstfcn;wstfci++){ std::cout<<"  "; } wstfcn++;
	std::cout<<"[>"<<cfichier<<"."<<cfonction<<"]"<<std::endl;
	std::cout.flush();
}

void wstprintfe(const char *cfichier, const char *cfonction){
	wstfcn--; for(wstfci=0;wstfci<wstfcn;wstfci++){ std::cout<<"  "; }
	printf("[<%s.%s]\n", cfichier, cfonction);
	std::cout<<"[<"<<cfichier<<"."<<cfonction<<"]"<<std::endl;
	std::cout.flush();
}

#ifdef WIN32
extern "C" int send(SOCKET s, const char *buf, int len, int flags){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return 0;
}

extern "C" int select(int nfds, fd_set *readfds, fd_set *writefds,
		fd_set *exceptfds, const PTIMEVAL timeout){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return 0;
}

extern "C" int recv(SOCKET s,char *buf,int len,int flags){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return 0;
}

extern "C" int closesocket(SOCKET s){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return 0;
}

extern "C" int WSAStartup(WORD wVersionRequested,LPWSADATA lpWSAData){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return 0;
}

extern "C" struct hostent *gethostbyname(const char *name){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return NULL;
}

extern "C" u_short htons(u_short hostshort){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return 0;
}

extern "C" SOCKET socket(int af,int type,int protocol){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return 0;
}

extern "C" int connect(SOCKET s,const struct sockaddr *name,int namelen){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return 0;
}

#endif
