// Copyright (c) 2015 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.


#ifndef _StdLPersistent_Variable_HeaderFile
#define _StdLPersistent_Variable_HeaderFile

#include <StdObjMgt_Attribute.hxx>
#include <StdLPersistent_HString.hxx>

#include <TDataStd_Variable.hxx>


class StdLPersistent_Variable : public StdObjMgt_Attribute<TDataStd_Variable>
{
public:
  //! Read persistent data from a file.
  inline void Read (StdObjMgt_ReadData& theReadData)
    { theReadData >> myIsConstant >> myUnit; }

  //! Import transient attribuite from the persistent data.
  void Import (const Handle(TDataStd_Variable)& theAttribute) const
  {
    theAttribute->Constant (myIsConstant);
    if (myUnit)
      theAttribute->Unit (myUnit->Value()->String());
  }

private:
  Standard_Boolean                      myIsConstant;
  Handle(StdLPersistent_HString::Ascii) myUnit;
};

#endif
