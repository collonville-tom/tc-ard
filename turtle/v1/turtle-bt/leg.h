#include "./leg-basic.h"



//void retraction(int curentHD, int curentHG, int curentAD, int curentAG)
//{
//  int HD_BUTTE = 55;
//  int HG_BUTTE = 125;
//  int AD_BUTTE = 70;
//  int AG_BUTTE = 130;
//  while (1)
//  {
//    if (curentHD != HD_BUTTE)
//    {
//      curentHD--;
//      HHD.write(curentHD);
//    }
//    if (curentHG != HG_BUTTE)
//    {
//      curentHG++;
//      HHG.write(curentHG);
//    }
//    if (curentAD != AD_BUTTE)
//    {
//      curentAD--;
//      HAD.write(curentAD);
//    }
//    if (curentAG != AG_BUTTE)
//    {
//      curentAG++;
//      HAG.write(curentAG);
//    }
//    delay(delai);
//    if (( curentHD == HD_BUTTE) && (curentHG == HG_BUTTE) && (curentAD == AD_BUTTE) && (curentAG == AG_BUTTE))
//      return ;
//  }
//}





////////////////////////////////// semi-cycle

//void protractionHD()
//{
//  VHD_UP();
//  HHD_FRONT();
//  VHD_DOWN();
//}
//
//void protractionHG()
//{
//  VHG_UP();
//  HHG_FRONT();
//  VHG_DOWN();
//}
//
//void protractionAG()
//{
//  VAG_UP();
//  HAG_FRONT();
//  VAG_DOWN();
//}
//
//void protractionAD()
//{
//  VAD_UP();
//  HAD_FRONT();
//  VAD_DOWN();
//}

////////////////////////////////// mouvemenent composite

//void compositeMvt()
//{
//  VHG_UP();
//  HHG_FRONT();
//  VHG_DOWN();
//  HHG_BACK();
//
//
//  VHD_UP();
//  HHD_FRONT();
//  VHD_DOWN();
//  HHD_BACK();
//
//  VAD_UP();
//  HAD_FRONT();
//  VAD_DOWN();
//  HAD_BACK();
//
//  VAG_UP();
//  HAG_FRONT();
//  VAG_DOWN();
//  HAG_BACK();
//}

////////////////////////////////// marche basic

//
//void marcheBasic()
//{
//  protractionAG();
//  protractionAD();
//
//  protractionHD();
//  protractionHG();
//
//  retraction(110, 70, 130, 60);
//}
