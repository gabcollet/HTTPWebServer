#ifndef __DEFINES_H__
#define __DEFINES_H__

#include <cstdlib>
#include <signal.h>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <iostream>

#include "colors.hpp"
#include "utils.hpp"

// DEBUG
# ifndef DEBUG
#  define DEBUG 0
# endif


// General Purpose defines
#define DEFAULT_CONFIG_FILE "config_files/default.conf"
#define WHITESPACES " \t\n\v\f\r"
#define CONFIG_BLOCKS_DELIMITERS "{};"
#define LOCALHOST "127.0.0.1"
#define LISTENPORT 8080
#define ROOT "./Cyborgab"

// Error codes
#define FILESTREAM_ERROR 1
#define PARSING_ERROR 2
#define INV_SOCKET 3
#define BINDING_ERR 4
#define OPT_ERR 5
#define LISTEN_ERR 6

// Other Macros
#define SIG_EXIT 0

// Various Typedefs
typedef std::vector<std::string> StringVector;
typedef std::vector<std::string>::iterator StringIterator;

// Print Client IP
#define PRINT_CLIENT_IP std::cout 	<< YELLOW\
									<< logEvent("Accepted Connection from: " + clientIP(client_fd, addrlen) + "\n")\
									<< END << std::endl;

// Debug Macros
#define DEBUG_DISPLAY_HEADER if (DEBUG) {\
		std::cout << TEAL << "\n+++ REQUEST HEADER +++\n\n"\
				  << END << YELLOW << "client fd: " << it->fd\
				  << END << "\n"\
				  << TEAL << str_buffer << END << std::endl; }

#define DEBUG_DISPLAY_RESP_HEADER if (DEBUG) {\
	std::cout	<< GREEN\
				<< "+++ RESPONSE +++\n\n"\
				<< END << header.data() << std::endl;\
}

#endif // __DEFINES_H__
