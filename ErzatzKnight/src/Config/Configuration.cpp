/*
*  Configuration.cpp
*  Erzatz
*
*  Created by Alexandre KUSZLA on 11/02/10.
*  Copyright 2010 Alexandre KUSZLA. All rights reserved.
*
*/

#include "Configuration.h"
//#include <xercesc/dom/DOM.hpp>
//#include <xercesc/util/PlatformUtils.hpp>
#include <iostream>
//#include <xercesc/parsers/XercesDOMParser.hpp>
//#include <xercesc/dom/DOM.hpp>
//#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <sys/types.h>
#include <sys/stat.h> 
#include <errno.h>
#include <stdexcept>
//#include <xercesc/sax/HandlerBase.hpp>
#include <Config/Platform.h>



using namespace std;
/*using namespace xercesc;
using namespace ErzatzKnight::Config;

Configuration::Configuration() {
    this->datas = new map<string, string>();
    this->name = "";
    this->version = "0";
    init();
}

Configuration::~Configuration() {

}

void Configuration::init() {
    try {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch) {
        // Do your failure processing here

    }

    struct stat fileStatus;

    int iretStat = stat("configuration.xml", &fileStatus);
    if( iretStat == ENOENT )
        throw ( std::runtime_error("Path file_name does not exist, or path is an empty string.") );
    else if( iretStat == ENOTDIR )
        throw ( std::runtime_error("A component of the path is not a directory."));
    else if( iretStat == ELOOP )
        throw ( std::runtime_error("Too many symbolic links encountered while traversing the path."));
    else if( iretStat == EACCES )
        throw ( std::runtime_error("Permission denied."));
    else if( iretStat == ENAMETOOLONG )
        throw ( std::runtime_error("File can not be read\n"));
    //else if( iretStat == -1) {
    //throw (std::runtime_error("File doesn't seem to exist"));
    //}

    try {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Error during initialization! :\n"
            << message << "\n";
        XMLString::release(&message);
        //return 1;
    }


    XMLCh tempStr[100];
    XMLString::transcode("LS", tempStr, 99);
    DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempStr);
    DOMLSParser* parser = ((DOMImplementationLS*)impl)->createLSParser(DOMImplementationLS::MODE_SYNCHRONOUS, 0);

    // optionally you can set some features on this builder
    if (parser->getDomConfig()->canSetParameter(XMLUni::fgDOMValidate, true))
        parser->getDomConfig()->setParameter(XMLUni::fgDOMValidate, true);
    if (parser->getDomConfig()->canSetParameter(XMLUni::fgDOMNamespaces, true))
        parser->getDomConfig()->setParameter(XMLUni::fgDOMNamespaces, true);
    if (parser->getDomConfig()->canSetParameter(XMLUni::fgDOMDatatypeNormalization, true))
        parser->getDomConfig()->setParameter(XMLUni::fgDOMDatatypeNormalization, true);


    // optionally you can implement your DOMErrorHandler (e.g. MyDOMErrorHandler)
    // and set it to the builder
    //MyDOMErrorHandler* errHandler = new myDOMErrorHandler();
    ErrorHandler* errHandler = (ErrorHandler*) new HandlerBase();
    parser->getDomConfig()->setParameter(XMLUni::fgDOMErrorHandler, errHandler);

    char* xmlFile = "configuration.xml";
    DOMDocument *doc = 0;

    try {
        doc = parser->parseURI(xmlFile);

        cout << doc->getChildNodes()->getLength() << endl;
        cout << doc->getDocumentElement()->getChildElementCount() << endl;
        cout << XMLString::transcode(doc->getDocumentElement()->getNodeName()) << endl;
        cout << XMLString::transcode(doc->getDocumentElement()->getChildNodes()->item(1)->getNodeName());
        DOMNode * configuration = doc->getDocumentElement()->getChildNodes()->item(1);
        //this->version = configuration->getAttributes();
    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Exception message is: \n"
            << message << "\n";
        XMLString::release(&message);
        //return -1;
    }
    catch (const DOMException& toCatch) {
        char* message = XMLString::transcode(toCatch.msg);
        cout << "Exception message is: \n"
            << message << "\n";
        XMLString::release(&message);
        //return -1;
    }
    catch (...) {
        cout << "Unexpected Exception \n" ;
        //return -1;
    }

    parser->release();
    //delete errHandler;

}*/