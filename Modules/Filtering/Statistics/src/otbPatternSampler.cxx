/*=========================================================================

  Program:   ORFEO Toolbox
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) Centre National d'Etudes Spatiales. All rights reserved.
  See OTBCopyright.txt for details.


     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#include "otbPatternSampler.h"
#include "otbMath.h"
#include "otbMacro.h"
#include <algorithm>

namespace otb
{

bool
PatternSampler::ParameterType::operator!=(const PatternSampler::ParameterType & param) const
{
  return bool((MaxPatternSize != param.MaxPatternSize)||
              (Pattern1 != param.Pattern1)||
              (Pattern2 != param.Pattern2)||
              (Seed != param.Seed));
}

PatternSampler::PatternSampler()
  : m_Index1(0UL)
  , m_Index2(0UL)
{
  this->m_Parameters.MaxPatternSize = 256;
  this->m_Parameters.Pattern1.clear();
  this->m_Parameters.Pattern2.clear();
  this->m_Parameters.Seed = 121212;
}

void
PatternSampler::Reset(void)
{
  Superclass::Reset();
  m_Index1 = 0UL;
  m_Index2 = 0UL;

  // if seed is not 0, generate patterns
  // since the pattern depend on the sampling rate they should be regenerated
  // in order to keep existing patterns, the seed should be set to 0
  if (this->m_Parameters.Seed)
    {
    unsigned long T1 = FindBestSize(this->GetTotalElements());
    unsigned long N1 = static_cast<unsigned long>(vcl_floor( this->GetRate() * T1 ));

    double selected_ratio = static_cast<double>(N1)/static_cast<double>(T1);

    unsigned long taken = static_cast<unsigned long>(selected_ratio*static_cast<double>(this->GetTotalElements()));
    unsigned long left = this->GetNeededElements() - taken;
    unsigned long newtot = this->GetTotalElements() - taken;

    unsigned long T2 = 0;
    unsigned long N2 = 0;
    if (left>0)
      {
      double ratio2 = 0.0;
      if (newtot>0)
        ratio2 = static_cast<double>(left)/static_cast<double>(newtot);

      T2 = FindBestSize(this->GetTotalElements()/T1*(T1-N1));
      if (T2>0)
        {
        N2 = static_cast<unsigned long>(vcl_ceil( ratio2 * T2 ));
        }   
      }

    std::srand ( m_Parameters.Seed );
    this->m_Parameters.Pattern1 = RandArray(N1,T1);
    if (T2>0)
       this->m_Parameters.Pattern2 = RandArray(N2,T2);
    }
}

bool
PatternSampler::TakeSample(void)
{
  bool ret = false;
  this->m_ProcessedElements += 1UL;
  if (this->m_ChosenElements >= this->GetNeededElements())
    return false;    

  // Test selection with first pattern 
  ret = this->m_Parameters.Pattern1[m_Index1];
  m_Index1++;
  if (m_Index1 >= this->m_Parameters.Pattern1.size())
     m_Index1=0UL;

  if(!ret && this->m_Parameters.Pattern2.size())
    {
    // Test selection with second pattern
    ret = this->m_Parameters.Pattern2[m_Index2];
    m_Index2++;
    if (m_Index2 >= this->m_Parameters.Pattern2.size())
      m_Index2=0UL;
    }
  if (ret)
    {
    this->m_ChosenElements += 1UL;
    }
  return ret;
}

std::vector<bool>
PatternSampler::RandArray(unsigned long N,unsigned long T)
{
   if (N>T)
     itkGenericExceptionMacro(<< "N must be <= to T (aka m_SamplingTabSize)." << std::endl);

   std::vector<bool> res(T,0);
   for(unsigned long i=0; i<N;i++)
       res[i]=1;

   std::random_shuffle ( res.begin(), res.end() );
   
   return res;
}


unsigned long
PatternSampler::FindBestSize(unsigned long tot)
{
  // handle small values
  if (tot<=m_Parameters.MaxPatternSize)
    return tot;

  // try to find a sub-period in tot, between 20 and MaxPatternSize
  for(unsigned long size = m_Parameters.MaxPatternSize; size >= 20; size--)
    if (tot%size == 0)
      return size;
      
  otbWarningMacro(<<"prime number > m_Parameters.MaxPatternSize (" << tot << ">" << m_Parameters.MaxPatternSize << ")."<< std::endl );
  // fallback : return the maximum size
  return m_Parameters.MaxPatternSize;
}

} // namespace otb
