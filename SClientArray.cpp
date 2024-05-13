// Copyright Eric Chauvin 2021 - 2024.



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "SClientArray.h"
#include "../CppBase/Casting.h"
#include "../Network/SocketsApi.h"



#include "../CppMem/MemoryWarnTop.h"



SClientArray::SClientArray( void )
{
// This calls the constructor for each SrvClPoint
// in the array.

sClPointAr = new SrvClPoint[Casting::i32ToU64(
                                  arraySize )];
}


SClientArray::SClientArray(
                          const SClientArray& in )
{
sClPointAr = new SrvClPoint[Casting::i32ToU64(
                                  arraySize )];

if( in.testForCopy )
  return;

throw "Copy constructor for SClientArray.";
}


SClientArray::~SClientArray( void )
{
delete[] sClPointAr;
}


bool SClientArray::addNewClient( SrvClient* toAdd )
{
// This becomes the owner of the object and
// it has to delete it when it's done with it.

// Something could just make a whole lot of
// connections to your server and if you keep
// allocating new space for more client objects
// then it will kill your server.

// Use the first available one.
for( Int32 count = 0; count < arraySize;
                                   count++ )
  {
  if( sClPointAr[count].srvClientP == nullptr )
    {
    sClPointAr[count].srvClientP = toAdd;
    return true;
    }
  }

// I would rather set this to have a million
// small objects in the array and then I know
// I can have up to a million socket connections.
// If I get a million connections then I have
// a problem like Disttibuted Denial of Service,
// or I have a whole lot of customers.
// If I have that many customers I need to
// have a more advanced, distributed server.
// And I need something more than just a
// simple small array.

tooManyConnections++;
return false;
}



void SClientArray::closeAllSockets( void )
{
for( Int32 count = 0; count < arraySize;
                                   count++ )
  {
  if( sClPointAr[count].srvClientP != nullptr )
    {
    // The destructor closes the socket.
    delete sClPointAr[count].srvClientP;
    sClPointAr[count].srvClientP = nullptr;
    }
  }
}



void SClientArray::processData( void )
{
for( Int32 count = 0; count < arraySize;
                                   count++ )
  {
  if( sClPointAr[count].srvClientP != nullptr )
    {
    // Let sub classes process data in the way
    // that a sub class does.

    Int32 result = sClPointAr[count].
           srvClientP->processData();

    if( result == 0 )
      {
      // Let it stay open until it times out
      // so that outgoing data will go out.
      sClPointAr[count].srvClientP->
                      setAllowReadFalse();
      }

    if( result < 0 )
      {
      // If it returned 0 then just let
      // it time out.
      // If processData returned < 0,
      // shut it down.  Closing the socket is
      // done in the destructor.
      delete sClPointAr[count].srvClientP;
      sClPointAr[count].srvClientP = nullptr;
      }
    }
  }
}



#include "../CppMem/MemoryWarnBottom.h"
