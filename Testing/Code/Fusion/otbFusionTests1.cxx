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

// this file defines the otbCommonTest for the test driver
// and all it expects is that you have a function called RegisterTests


#include "otbTestMain.h"

void RegisterTests()
{
  REGISTER_TEST(otbBayesianFusionFilterNew);
  REGISTER_TEST(otbBayesianFusionFilter);
  REGISTER_TEST(otbFusionImageBaseNew);
  REGISTER_TEST(otbSimpleRcsPanSharpeningFusionImageFilterNew);
  REGISTER_TEST(otbSimpleRcsPanSharpeningFusionImageFilter);
  REGISTER_TEST(otbLmvmPanSharpeningFusionImageFilterNew);
  REGISTER_TEST(otbLmvmPanSharpeningFusionImageFilter);
}