#ifndef __RESPONSE_H__
#define __RESPONSE_H__

#include "defines.hpp"
#include <sstream>
#include <fstream>
#include "RequestParser.hpp"
#include "status_codes.hpp"
#include "Server.hpp"
#include "CGI.hpp"
#include "dirent.h"
#include "utils.hpp"

#define MAX_IMAGESIZE 1048576 // 1 mg

typedef enum MethodType {
	GET,
	POST,
	DELETE,
	NONE
} MethodType;

class Server;

class Response {

public:
	Response() {}
	Response(RequestParser* request, Server* server);
	~Response() {};

	std::string getResponseHeader() { return header; }
	std::string getResponseBody() { return body.str(); }
	size_t getHeaderSize() { return headerSize; }
	size_t getBodySize() { return bodySize; }

private:
	bool			autoindex;
	bool			redirection;
	bool 			cgiRequest;
	size_t 			headerSize;
	size_t 			bodySize;
	RequestParser	*request;
	std::string 	path;
	std::string 	header;
	std::string 	status_code;
	Server			*server;
	server_info		config;
	StatusCode 		status; // Status Code map
	std::stringstream body;

	typedef std::map<std::string, std::string>::iterator MapIterator;
	typedef std::vector<location_info>::iterator LocIterator;

	MethodType getType();

	int findSocket();
	void handleCGI();
	void responseGET();
	void responsePOST();
	void responseDELETE();
	void makeHeader(std::string& code);
	void makeFavicon();
	void makeImage();
	void makeAutoindex(std::string filepath);
	void readHTML(std::string filepath);
	void setConfig();
	void deletePath(std::string path);
	void responseMultipart();
	void writeToFile(size_t start, size_t pos);
	void setFilename();
	size_t findBodyEnd(size_t pos, std::string boundary);
	std::string lookForRoot(LocationVector& location);
	std::string setPath(LocationVector& location, StringVector& url_vec, size_t i, bool var);
	std::string lookForContent(LocationVector& location);
	std::string findUploadPath();


	size_t findBodyStart();
	void handleFile();

	// Image Methods
	typedef std::pair<char *, std::streampos> ImgInfo;
	std::pair<char *, std::streampos> getImageBinary(const char* path);

	// Error
	void errorBody(std::string& code);
};


#endif // __RESPONSE_H__
