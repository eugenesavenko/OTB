/*=========================================================================

  Programme :   OTB (ORFEO ToolBox)
  Auteurs   :   CS - T.Feuvrier
  Language  :   C++
  Date      :   4 avril 2005
  Version   :   
  Role      :   Classe de type Viewer, permettant de visualiser une image
  $Id$

=========================================================================*/
// OTB-FA-00026-CS
#ifndef __otbImageViewer_h
#define __otbImageViewer_h

#include <string>

#include "itkShrinkImageFilter.h"

#include "otbPrincipalImageView.h"
#include "otbScrollImageView.h"
#include "otbZoomImageView.h"
#include "otbImageViewerGUI.h"
#include "otbMultiChannelExtractROI.h"
#include "otbGLVectorImageViewBase.h"

namespace otb
{
/** \class ImageViewer
 * \brief Base class for viewing an image.
 *
 * This viewer show the image with two (or three) windows display. 
 * The 'Principal' window display de the image in entier resolution. 
 * The zoom window display a zoom of a part of the image.
 * If the image is big, a Scroll window is create, which contain the original image shrinked. 
 * Use FLTK gui.
 *
*/

template <class TPixel>
class ImageViewer :             public itk::ProcessObject,
                                public otbImageViewerGUI
                                
{
public:

   /**
   * Standard "Self" typedef.
   */
  typedef ImageViewer                 Self;
  typedef itk::ProcessObject          Superclass;
  /** 
   * Smart pointer typedef support.
   */
  typedef itk::SmartPointer<Self>        Pointer;
  typedef itk::SmartPointer<const Self>  ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(ImageViewer,itk::ProcessObject);

  typedef TPixel                      InputPixelType;

  typedef otb::MultiChannelExtractROI< InputPixelType, 
                                             InputPixelType >   ExtractROIFilterType;

  typedef typename ExtractROIFilterType::Pointer                ExtractROIFilterPointer;
 
  typedef PrincipalImageView<InputPixelType>                    PrincipalImageViewType;
  typedef typename PrincipalImageViewType::Pointer              PrincipalImageViewPointer;
  typedef ScrollImageView< InputPixelType >                     ScrollImageViewType;
  typedef typename ScrollImageViewType::Pointer                 ScrollImageViewPointer;
  typedef ZoomImageView< InputPixelType >                       ZoomImageViewType;
  typedef typename ZoomImageViewType::Pointer                   ZoomImageViewPointer;

  typedef GLVectorImageViewBase<InputPixelType>                 ImageViewBaseType;

  typedef typename ExtractROIFilterType::InputImageType         ImageType;
//  typedef typename PrincipalImageViewType::ImageType         ImageType;
  typedef typename ImageType::Pointer                           ImagePointer;
  typedef typename ImageType::ConstPointer                      ImageConstPointer;
  typedef typename ImageType::RegionType                        RegionType;
  typedef typename ImageType::SizeType                          SizeType;
  typedef typename ImageType::IndexType                         IndexType;
  typedef typename ImageType::PixelType                         PixelType;

  typedef itk::ShrinkImageFilter<ImageType,ImageType>           ShrinkImageFilterType;
  typedef typename ShrinkImageFilterType::Pointer               ShrinkImageFilterPointer;

    
  ImageViewer();
  virtual ~ImageViewer();
  /** Set the input image */
  virtual void SetImage(itk::ImageBase<2> * img);
  /** Show the viewer (Update) */
  virtual void Show(void);
  /** Hide all Image View Windows */
  virtual void Hide(void);
  /** Update */
  virtual void Update(void);
  
  virtual void BuildHMI(void);
  virtual void CreatePrincipalImageView( Fl_Group * g , Fl_Gl_Window * w );
  virtual void CreateScrollImageView( Fl_Group * g , Fl_Gl_Window * w );
  virtual void CreateZoomImageView( Fl_Group * g , Fl_Gl_Window * w );
//  virtual void SetLabel( const char * );
  virtual void ClickSelectCallBack(
                void (*newClickSelectArgCallBack)(float, float,
                                                  /*float,*/ float,
                                                  void *),
                     void * newClickSelectArg);
  virtual void ZoomAction(void);
  virtual void PrincipalResize(void);
  virtual void ScrollResize(void);
  virtual void PrincipalAction(const IndexType & index);
  virtual void ScrollAction(const IndexType & index);
  virtual void ExtractImagePrincipal(const RegionType & zone);

  virtual void GenerateChannelsInformations(void);
  
  typedef typename std::vector<int> ChannelsType;
  
  typedef typename ImageViewBaseType::ModeViewType ModeViewType; 
  typedef typename ImageViewBaseType::ChannelsType ChannelsType; 

  itkSetMacro(GrayLevelChannel,int);
  itkSetMacro(RedChannel,int);
  itkSetMacro(GreenChannel,int);
  itkSetMacro(BlueChannel,int);

  itkSetStringMacro(Label);
  itkGetStringMacro(Label);

  virtual void SetRGBChannels(int pRedChannel,int pGreenChannel, int pBlueChannel)
  {
        SetRedChannel(pRedChannel);
        SetGreenChannel(pGreenChannel);
        SetBlueChannel(pBlueChannel);
  }
  virtual void ClearSelectChannels(void);

private:

        virtual void SetChannelsInformationsToImagesView(void);
        virtual bool GenereImageScroll(unsigned int & pShrinkFactors);


        std::string m_Label;
        static const std::string m_SuffixPrincipalTitle;
        static const std::string m_SuffixZoomTitle;
        static const std::string m_SuffixScrollTitle;
        int m_NbDim;

        int  m_RedChannel;
        int  m_GreenChannel;
        int  m_BlueChannel;
        int  m_GrayLevelChannel;

        ModeViewType  m_ModeView;
        ChannelsType m_ChannelsWorks;

        //  GLImageViewType * glSliceView;
        PrincipalImageViewPointer       m_PrincipalView;
        ScrollImageViewPointer          m_ScrollView;
        ZoomImageViewPointer            m_ZoomView;
 
        typedef unsigned long WinSizeType;

        //Dimension de la fen�tre maximale, au dela de laquelle on cr�er une fen�tre Scroll
//        WinSizeType m_ScrollWinSizeMax;
        //Dimension par d�faut de la fenetre principal
        WinSizeType m_InitPrincipalWinSizeMax;
        //Initialisation de la dimension de la fen�tre dans le cas o� la fenetre Scroll est cr��.
        WinSizeType m_InitScrollWinSizeMax;




        ShrinkImageFilterPointer m_ShrinkImageFilter;
        ExtractROIFilterPointer m_ExtractROIFilter;
        ImageType * m_InputImage;
        
        ImageType * m_PrincipalImage;
        ImageType * m_ScrollImage;
        
        //Coordonn�es du point central de l'image Principal
        IndexType m_CenterPrincipalImage;
        //Coordonn�es du point central de l'image Zoom
        IndexType m_CenterZoomImage;
        
        bool m_ScrollImageView;
        unsigned int m_ShrinkFactors;

};


} // end namespace otb

#ifndef OTB_MANUAL_INSTANTIATION
#include "otbImageViewer.txx"
#endif


#endif
