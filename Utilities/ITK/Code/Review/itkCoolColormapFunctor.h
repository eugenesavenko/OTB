/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSfile: itkCoolColormapFunctor.h,v $
  Language:  C++
  Date:      $Date: 2009-05-15 19:08:09 $
  Version:   $Revision: 1.2 $

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkCoolColormapFunctor_h
#define __itkCoolColormapFunctor_h

#include "itkColormapFunctor.h"

namespace itk {

namespace Functor {  

/**
 * \class CoolColormapFunctor
 * \brief Function object which maps a scalar value into an RGB colormap value.
 *
 * 
 * \author Nicholas Tustison, Hui Zhang, Gaetan Lehmann, Paul Yushkevich and ̈James C. Gee
 * 
 * This code was contributed in the Insight Journal paper:
 *
 * "Meeting Andy Warhol Somewhere Over the Rainbow: RGB Colormapping and ITK"
 * http://www.insight-journal.org/browse/publication/285
 * http://hdl.handle.net/1926/1452
 *
 */
template< class TScalar, class TRGBPixel >
class ITK_EXPORT CoolColormapFunctor
: public ColormapFunctor<TScalar, TRGBPixel>
{
public:

  typedef CoolColormapFunctor                    Self;
  typedef ColormapFunctor<TScalar, TRGBPixel>    Superclass;
  typedef SmartPointer<Self>                     Pointer;
  typedef SmartPointer<const Self>               ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro( Self );

  typedef typename Superclass::RGBPixelType      RGBPixelType;
  typedef typename Superclass::ScalarType        ScalarType;  
  typedef typename Superclass::RealType          RealType;
  
  virtual RGBPixelType operator()( const TScalar & ) const;

protected:
  CoolColormapFunctor() {};
  ~CoolColormapFunctor() {};

private:
  CoolColormapFunctor(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

};
  
} // end namespace functor

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkCoolColormapFunctor.txx"
#endif

#endif