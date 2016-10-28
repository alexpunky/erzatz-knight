#ifndef CONFIGURATION_H
#define CONFIGURATION_H

/*
*  Configuration.hpp
*  Erzatz
*
*  Created by Alexandre KUSZLA on 11/02/10.
*  Copyright 2010 Alexandre KUSZLA. All rights reserved.
*
*/

#include <string>
//#include <xercesc/dom/DOM.hpp>
#include <map>

using namespace std;
//using namespace xercesc;

namespace ErzatzKnight {
    namespace Config {
        class Configuration {
        public:
            map<string, string>* datas;
            string version;
            string name;

            Configuration();
            ~Configuration();

        private:
            void init();
        };
    }
}

#endif