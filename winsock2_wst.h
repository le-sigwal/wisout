//-------------------------------------------------------------------------
/* File: winsock2_wst.h
 * Description:  winsock2 type definition
 *               "WIth SOcket oUT" Project (Simple socket reset)
 * Authors: Bagad Sigwal
 * Copyright: 2020 Sigwal.info/github - All Rights Reserved
 * Last modification: 12/05/2020
 * Version: 20.05
 *
 * Change records:
 * SWL - 12/05/2020 - creation                                           */
//-------------------------------------------------------------------------

#ifndef WINSOCK2_WST_H_
#  define WINSOCK2_WST_H_

typedef unsigned int	   u_int;
typedef unsigned short	   u_short;

#  ifdef _WIN64
typedef unsigned long long SOCKET;
#  else
typedef unsigned int       SOCKET;
#  endif

#  define FD_SETSIZE 64
typedef struct fd_set_s {
	u_int	fd_count;
	SOCKET	fd_array[FD_SETSIZE];
} fd_set;

struct timeval {
	long tv_sec;
	long tv_usec;
};
typedef struct timeval *PTIMEVAL;

typedef unsigned short WORD;

#define WSADESCRIPTION_LEN	256
#define WSASYS_STATUS_LEN	128
typedef struct WSADATA_s {
	WORD		wVersion;
	WORD		wHighVersion;
#ifdef _WIN64
	unsigned short	iMaxSockets;
	unsigned short	iMaxUdpDg;
	char		*lpVendorInfo;
	char		szDescription[WSADESCRIPTION_LEN+1];
	char		szSystemStatus[WSASYS_STATUS_LEN+1];
#else
	char		szDescription[WSADESCRIPTION_LEN+1];
	char		szSystemStatus[WSASYS_STATUS_LEN+1];
	unsigned short	iMaxSockets;
	unsigned short	iMaxUdpDg;
	char		*lpVendorInfo;
#endif
} WSADATA, *LPWSADATA;

struct hostent {
	char	*h_name;
	char	**h_aliases;
	short	h_addrtype;
	short	h_length;
	char	**h_addr_list;
};

struct sockaddr {
	u_short	sa_family;
	char	sa_data[14];
};

#endif /*[<WINSOCK2_WST_H_]*/
