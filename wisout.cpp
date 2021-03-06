//-------------------------------------------------------------------------
/* File: wisout.cpp
 * Description: "WIth SOcket oUT" Project
 *                Simple socket reset
 * Authors: Bagad Sigwal
 * Copyright: 2020-2021 Sigwal.info/github, All rights reserved
 * Last modification: 14/01/2021
 * Version: 21.01
 *
 * Change records:
 * SWL - 10/04/2020 - creation
 *                    added wstprintfa(), wstprintfe(),
 *                    added send(), select(), recv(), closesocket(),
 *                      WSAStartup(), gethostbyname(), htons(),
 *                      socket() & connect() for win32
 * SWL - 12/05/2020 - winsock2_wst.h inclusion
 * SWL - 14/05/2020 - added WINAPI
 * SWL - 14/01/2021 - added htonl() & ntohl()                            */
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
//[>DEFINITIONS]
//-------------------------------------------------------------------------
//[>STANDARD DEFINITIONS]
#include <iostream>
#ifdef WIN32
#  include <winsock2_wst.h>
#endif
//[>EXTERN DEFINITIONS]
//[>PROJECT DEFINITIONS]
//[>LOCAL DEFINITIONS]
#define WISOUT_VERSION "21.01"
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
	std::cout<<"[<"<<cfichier<<"."<<cfonction<<"]"<<std::endl;
	std::cout.flush();
}

#ifdef WIN32
extern "C" int WINAPI send(SOCKET s, const char *buf, int len, int flags){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return 0;
}

extern "C" int WINAPI select(int nfds, fd_set *readfds, fd_set *writefds,
		fd_set *exceptfds, const PTIMEVAL timeout){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return 0;
}

extern "C" int WINAPI recv(SOCKET s, char *buf, int len, int flags){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return 0;
}

extern "C" int WINAPI closesocket(SOCKET s){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return 0;
}

extern "C" int WINAPI WSAStartup(WORD wVersionRequested, LPWSADATA lpWSAData){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return 0;
}

extern "C" struct hostent *WINAPI gethostbyname(const char *name){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return NULL;
}

extern "C" u_long WINAPI htonl(u_long hostlong){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return 0;
}

extern "C" u_short WINAPI htons(u_short hostshort){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return 0;
}

extern "C" u_long WINAPI ntohl(u_long netlong){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return 0;
}

extern "C" SOCKET WINAPI socket(int af, int type, int protocol){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return 0;
}

extern "C" int WINAPI connect(SOCKET s, const struct sockaddr *name,
		int namelen){
	wstprintfa(__FILE__, __FUNCTION__);
	wstprintfe(__FILE__, __FUNCTION__);
	return 0;
}

#endif
