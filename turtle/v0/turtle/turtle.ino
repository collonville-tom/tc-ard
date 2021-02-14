
#include <Servo.h>

Servo VHG;
Servo VHD;
Servo VAG;
Servo VAD;
Servo HHG;
Servo HHD;
Servo HAG;
Servo HAD;

int val_init = 90;

int VHGPIN = 2;
int HHGPIN = 3;
int VHDPIN = 4;
int HHDPIN = 5;
int VADPIN = 6;
int HADPIN = 7;
int HAGPIN = 14;
int VAGPIN = 15;

int delai = 1000;

void setup() {

  VHG.attach(VHGPIN);
  VHD.attach(VHDPIN);
  VAG.attach(VAGPIN);
  VAD.attach(VADPIN);
  HHG.attach(HHGPIN);
  HHD.attach(HHDPIN);
  HAG.attach(HAGPIN);
  HAD.attach(HADPIN);

  VHG.write(val_init);
  VHD.write(val_init);
  VAG.write(val_init);
  VAD.write(val_init);
  HHG.write(val_init);
  HHD.write(val_init);
  HAG.write(val_init);
  HAD.write(val_init);

  delay(2000);


}

void loop() {

}

void marcheBasic()
{
  protractionAG();
  protractionAD();

  protractionHD();
  protractionHG();

  retraction(110, 70, 130, 60);
}

////////////////////////////////// semi-cycle

void protractionHD()
{
  VHD_UP();
  HHD_FRONT();
  VHD_DOWN();
}

void protractionHG()
{
  VHG_UP();
  HHG_FRONT();
  VHG_DOWN();
}

void protractionAG()
{
  VAG_UP();
  HAG_FRONT();
  VAG_DOWN();
}

void protractionAD()
{
  VAD_UP();
  HAD_FRONT();
  VAD_DOWN();
}

void retraction(int curentHD, int curentHG, int curentAD, int curentAG)
{
  int HD_BUTTE = 55;
  int HG_BUTTE = 125;
  int AD_BUTTE = 70;
  int AG_BUTTE = 130;
  while (1)
  {
    if (curentHD != HD_BUTTE)
    {
      curentHD--;
      HHD.write(curentHD);
    }
    if (curentHG != HG_BUTTE)
    {
      curentHG++;
      HHG.write(curentHG);
    }
    if (curentAD != AD_BUTTE)
    {
      curentAD--;
      HAD.write(curentAD);
    }
    if (curentAG != AG_BUTTE)
    {
      curentAG++;
      HAG.write(curentAG);
    }
    delay(delai);
    if (( curentHD == HD_BUTTE) && (curentHG == HG_BUTTE) && (curentAD == AD_BUTTE) && (curentAG == AG_BUTTE))
      return ;
  }
}






///////////////////////////////////// mouvement elementaire patte ArD

void VAD_UP()
{
  VAD.write(130);
  delay(delai);
}

void VAD_DOWN()
{
  VAD.write(100);
  delay(delai);
}

void HAD_FRONT()
{
  HAD.write(140);
  delay(delai);
}

void HAD_BACK()
{
  HAD.write(70);
  delay(delai);
}


///////////////////////////////////// mouvement elementaire patte ArG

void VAG_UP()
{
  VAG.write(50);
  delay(delai);
}

void VAG_DOWN()
{
  VAG.write(80);
  delay(delai);
}

void HAG_FRONT()
{
  HAG.write(60);
  delay(delai);
}

void HAG_BACK()
{
  HAG.write(130);
  delay(delai);
}


///////////////////////////////////// mouvement elementaire patte AvD

void VHD_UP()
{
  VHD.write(50);
  delay(delai);
}

void VHD_DOWN()
{
  VHD.write(80);
  delay(delai);
}

void HHD_FRONT()
{
  HHD.write(110);
  delay(delai);
}

void HHD_BACK()
{
  HHD.write(55);
  delay(delai);
}


///////////////////////////////////// mouvement elementaire patte AvG

void VHG_UP()
{
  VHG.write(130);
  delay(delai);
}

void VHG_DOWN()
{
  VHG.write(100);
  delay(delai);
}

void HHG_FRONT()
{
  HHG.write(70);
  delay(delai);
}

void HHG_BACK()
{
  HHG.write(125);
  delay(delai);
}

////////////////////////////////// mouvemenent composite

void compositeMvt()
{
  VHG_UP();
  HHG_FRONT();
  VHG_DOWN();
  HHG_BACK();


  VHD_UP();
  HHD_FRONT();
  VHD_DOWN();
  HHD_BACK();

  VAD_UP();
  HAD_FRONT();
  VAD_DOWN();
  HAD_BACK();

  VAG_UP();
  HAG_FRONT();
  VAG_DOWN();
  HAG_BACK();
}
