// Copyright Eric Chauvin 2021 - 2024.



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once



#include "../CppBase/BasicTypes.h"
#include "../CppInt/IntegerMath.h"
#include "../CppInt/Mod.h"
#include "../CryptoBase/SPrimes.h"
#include "../Network/SocketsApi.h"
#include "../Network/Server.h"
#include "../Network/ServerTls.h"



class MainApp
  {
  private:
  // FileIO mainIO;
  Mod mod;
  IntegerMath intMath;
  SPrimes sPrimes;


  // The constructor for SocketsApi does
  // WSAStartup() and the destructor does
  // WSACleanup(). So the Windows dlls stay
  // going for the life of this app.

  SocketsApi socketsApi;
  ServerTls server;

  public:
  inline static const char* getVersionStr( void )
    {
    return "3/5/2024";
    }

  // Int32 mainLoop( Int32 argc, char* argv[] );
  Int32 mainLoop( void );
  void runServer( void );

  };
