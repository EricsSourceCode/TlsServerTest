// Copyright Eric Chauvin 2022 - 2024.



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#pragma once


#include "../CppBase/BasicTypes.h"
#include "SrvClient.h"
#include "../Network/SocketsApi.h"




class SrvClPoint
  {
  private:
  bool testForCopy = false;

  protected:

  public:
  // An object with just one pointer in it.
  SrvClient* srvClientP = nullptr;

  inline SrvClPoint( void )
    {
    }

  inline SrvClPoint( const SrvClPoint &in )
    {
    if( in.testForCopy )
      return;

    throw "SrvClPoint copy constructor.";
    }

  // ~SrvClPoint( void );

  };
