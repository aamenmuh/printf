#ifndef HELPER_H
#define HELPER_H
int countDigits(int num);
char *toString(int num);
char *toBinary(unsigned int num);
char *unsignedToStr(unsigned int num);
char *toAnyBase(int num, int base, char c);
int printConverted(char *str, int len);
char *convertStringtoASCii(char *str);
char *reverseString(char *str);
#endif
