#ifndef PLATFORM_HPP
#define PLATFORM_HPP

/*
*  Platform.hpp
*  Erzatz
*
*  Created by Alexandre KUSZLA on 28/02/10.
*  Copyright 2010 Alexandre KUSZLA. All rights reserved.
*
*/

#include <string>
using namespace std;


#if defined(_WIN32) || defined(__WIN32__)
#define PATH ""

#elif defined(linux) || defined(__linux)
#define PATH "./"


#elif defined(__APPLE__) || defined(MACOSX) || defined(macintosh) || defined(Macintosh)
#define PATH "../../../"

#endif

namespace ErzatzKnight {
    namespace Config {
        class Platform {

        public:
            inline static string GetPath(string path) {
                return string(PATH + path);
            }

            inline static string GetPath(char* path) {
                return string(PATH + string(path));
            }

            static const std::string platform_path() {
                return PATH;
            }
        };
    }
}

#endif