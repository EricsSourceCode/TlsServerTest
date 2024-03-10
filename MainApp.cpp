// Copyright Eric Chauvin, 2021 - 2024.



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#include "MainApp.h"
#include "../CppBase/StIO.h"
// #include "../LinuxApi/SetStack.h"
// #include "../CppBase/Casting.h"
#include "../CppBase/Threads.h"
#include "../WinApi/Signals.h"
// #include "../LinuxApi/Signals.h"
#include "../CryptoBase/RsaTest.h"
#include "../CryptoBase/Sha256.h"




// int MainApp::mainLoop( int argc, char* argv[] )
int MainApp::mainLoop( void )
{
Int32 delay = 200; // milliseconds.

try
{
// Throws an exception if things are not right.
BasicTypes::thingsAreRight();

StIO::putS( "Programming by Eric Chauvin." );
StIO::printF( "Version date: " );
StIO::putS( getVersionStr() );
StIO::printF( "\n" );

StIO::printFStack();

// StIO::printF( "Wide char: " );
// StIO::putWChar( 0x2190 );
// StIO::printF( "\n" );

// For Linux:
// Int32 stackSize = SetStack::getSize();
// Str showS( stackSize );
// mainIO.appendChars( "Stack size: " );
// mainIO.appendStr( showS );
// mainIO.appendChars( "\n\n" );

Signals::setupControlCSignal();
Signals::setupFpeSignal();
Signals::setupIllegalOpSignal();
Signals::setupBadMemSignal();


// Sha256 shaTest;
// CharBuf result;
// CharBuf key( "key" );
// CharBuf message(
//  "The quick brown fox jumps over the lazy dog" );

// shaTest.hMac( result, key, message );

// RsaTest rsaTest;
// rsaTest.test( mod, intMath, sPrimes );

runServer();


StIO::putS( "End of main app." );

Threads::sleep( delay );

return 0;
}
catch( const char* in )
  {
  StIO::putS( "Exception in main loop.\n" );
  StIO::putS( in );
  Threads::sleep( delay );
  return 1;
  }

catch( ... )
  {
  const char* in = "An unknown exception"
               " happened in the main loop.\n";

  StIO::putS( in );
  Threads::sleep( delay );
  return 1;
  }
}



void MainApp::runServer( void )
{
if( !server.startServer( "127.0.0.1", "443" ))
  return;

server.mainLoop();
}
