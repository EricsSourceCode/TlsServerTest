/*

// Copyright Eric Chauvin 2022 - 2023.



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#pragma once


#include "../CppBase/BasicTypes.h"
#include "SrvClient.h"
#include "NetClient.h"


// A pass-through SrvClient.


class SrvClPass: public SrvClient
  {
  private:
  NetClient netClient;
  CharBuf clientAddress;

  protected:
  SrvClPass( void );

  public:
  SrvClPass( SocketCpp useSocket,
             const CharBuf& address );
  ~SrvClPass( void ) override;
  Int32 processData( void ) override;

  };
*/

