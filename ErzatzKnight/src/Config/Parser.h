
#ifndef PARSER_H
#define PARSER_H

/*
*  Parser.hpp
*  Erzatz
*
*  Created by Alexandre KUSZLA on 21/03/10.
*  Copyright 2010 Alexandre KUSZLA. All rights reserved.
*
*/

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <iostream>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <sys/types.h>
#include <sys/stat.h> 
#include <errno.h>
//#include <unistd.h>
#include <stdexcept>
#include <xercesc/sax/HandlerBase.hpp>
#include <string>
#include <list>
#include <sstream>


using namespace xercesc;
using namespace std;



namespace Erzatz {
    namespace Utils {
        class Parser {
        private:
            string doc;
            xercesc::DOMDocument * document;
            DOMLSParser * parser;
            static list<const XMLCh *> * strings;
            static XMLCh * strXML;

        public:
            Parser();
            Parser(string doc);
            ~Parser();

            void init();

            // GETTERS AND SETTERS
            string getDoc();
            void setDoc(string doc);
            static DOMLSParser * createDOMParser();


            inline static const XMLCh * StringToXMLCh(string val) {
                XMLString::transcode(val.c_str(), strXML, 255);
                return strXML;
            }

            inline static const XMLCh * StringToXMLCh(string * val) {
                const XMLCh * tempStr = new XMLCh[0];
                return tempStr;
            }

            inline static const XMLCh* ChToXMLChT(string val) {
                XMLString::transcode(val.c_str(), strXML, 255);
                return strXML;
            }

            inline static void freeXMLCh(const XMLCh * val) {
                XMLString::release(((XMLCh **)&val));
            }

            inline static string XMLChToString( const XMLCh * val) {
                return XMLString::transcode(val);
            }

            inline static float StringToFloat(string number) {
                std::stringstream stream;
                // Cast to float...
                stream << number;
                float parsed;
                stream >> parsed;
                return parsed;
            }

            inline static float XMLChToFloat(const XMLCh * number) {
                std::stringstream stream;
                // Cast to float...
                stream << number;
                float parsed;
                stream >> parsed;
                return parsed;
            }

        };
    }
}

#endif
