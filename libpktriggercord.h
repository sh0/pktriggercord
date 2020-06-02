/*
    Header file for libpktriggercord
    Shared library wrapper for pkTriggerCord
    Copyright (c) 2020 Karl Rees

    for:

    pkTriggerCord
    Remote control of Pentax DSLR cameras.
    Copyright (C) 2011-2019 Andras Salamon <andras.salamon@melda.info>

    which is based on:

    pslr-shoot

    Command line remote control of Pentax DSLR cameras.
    Copyright (C) 2009 Ramiro Barreiro <ramiro_barreiro69@yahoo.es>
    With fragments of code from PK-Remote by Pontus Lidman.
    <https://sourceforge.net/projects/pkremote>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU General Public License
    and GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBPKTRIGGERCORD_H
#define LIBPKTRIGGERCORD_H



#ifdef WIN32
#define FILE_ACCESS O_WRONLY | O_CREAT | O_TRUNC | O_BINARY
#else
#define FILE_ACCESS O_WRONLY | O_CREAT | O_TRUNC
#endif

// Generic helper definitions for shared library support
#ifdef WIN32
#define PK_HELPER_LIB_IMPORT    __declspec(dllimport)
#define PK_HELPER_LIB_EXPORT    __declspec(dllexport)
#define PK_HELPER_LOCAL
#else
#define PK_HELPER_LIB_IMPORT    __attribute__ ((visibility ("default")))
#define PK_HELPER_LIB_EXPORT    __attribute__ ((visibility ("default")))
#define PK_HELPER_LOCAL         __attribute__ ((visibility ("hidden")))
#endif

#ifdef PK_LIB_EXPORTS
// defined if pktriggercord is compiled as a shared lib
#define PK_API          PK_HELPER_LIB_EXPORT
#define PK_API_LOCAL    PK_HELPER_LOCAL
#else // PK_LIB_EXPORTS
#ifdef PK_LIB_STATIC
// defined if pktriggercord is compiled or used as a static lib
#define PK_API          
#define PK_API_LOCAL    
#else // PK_LIB_STATIC
// defined if pktriggercord is used as a shared lib.
// This is the default, non specified option so that an external code does not
// need to know about this mechanics and can just import and use the header
#define PK_API          PK_HELPER_LIB_IMPORT
#define PK_API_LOCAL    PK_HELPER_LOCAL
#endif // PK_LIB_STATIC
#endif // PK_LIB_EXPORTS

#include "pslr.h"
#include "pktriggercord-servermode.h"

extern bool debug;

#endif