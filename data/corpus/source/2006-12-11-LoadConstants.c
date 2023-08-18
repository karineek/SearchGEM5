// Modification timestamp: 2023-08-14 17:22:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2006-12-11-LoadConstants.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long zz() { return atoi(argv[1]); }
  long zs() { return atoi(argv[1]); }
  long zu() { return atoi(argv[1]); }
  long sz() { return atoi(argv[1]); }
  long ss() { return atoi(argv[1]); }
  long su() { return atoi(argv[1]); }
  long uz() { return atoi(argv[1]); }
  long us() { return atoi(argv[1]); }
  long uu() { return atoi(argv[1]); }

  long long zzzz() { return atoll(argv[1]); }
  long long zzzs() { return atoll(argv[1]); }
  long long zzzu() { return atoll(argv[1]); }
  long long zzsz() { return atoll(argv[1]); }
  long long zzss() { return atoll(argv[1]); }
  long long zzsu() { return atoll(argv[1]); }
  long long zzuz() { return atoll(argv[1]); }
  long long zzus() { return atoll(argv[1]); }
  long long zzuu() { return atoll(argv[1]); }
  long long zszz() { return atoll(argv[1]); }
  long long zszs() { return atoll(argv[1]); }
  long long zszu() { return atoll(argv[1]); }
  long long zssz() { return atoll(argv[1]); }
  long long zsss() { return atoll(argv[1]); }
  long long zssu() { return atoll(argv[1]); }
  long long zsuz() { return atoll(argv[1]); }
  long long zsus() { return atoll(argv[1]); }
  long long zsuu() { return atoll(argv[1]); }
  long long zuzz() { return atoll(argv[1]); }
  long long zuzs() { return atoll(argv[1]); }
  long long zuzu() { return atoll(argv[1]); }
  long long zusz() { return atoll(argv[1]); }
  long long zuss() { return atoll(argv[1]); }
  long long zusu() { return atoll(argv[1]); }
  long long zuuz() { return atoll(argv[1]); }
  long long zuus() { return atoll(argv[1]); }
  long long zuuu() { return atoll(argv[1]); }
  long long szzz() { return atoll(argv[1]); }
  long long szzs() { return atoll(argv[1]); }
  long long szzu() { return atoll(argv[1]); }
  long long szsz() { return atoll(argv[1]); }
  long long szss() { return atoll(argv[1]); }
  long long szsu() { return atoll(argv[1]); }
  long long szuz() { return atoll(argv[1]); }
  long long szus() { return atoll(argv[1]); }
  long long szuu() { return atoll(argv[1]); }
  long long sszz() { return atoll(argv[1]); }
  long long sszs() { return atoll(argv[1]); }
  long long sszu() { return atoll(argv[1]); }
  long long sssz() { return atoll(argv[1]); }
  long long ssss() { return atoll(argv[1]); }
  long long sssu() { return atoll(argv[1]); }
  long long ssuz() { return atoll(argv[1]); }
  long long ssus() { return atoll(argv[1]); }
  long long ssuu() { return atoll(argv[1]); }
  long long suzz() { return atoll(argv[1]); }
  long long suzs() { return atoll(argv[1]); }
  long long suzu() { return atoll(argv[1]); }
  long long susz() { return atoll(argv[1]); }
  long long suss() { return atoll(argv[1]); }
  long long susu() { return atoll(argv[1]); }
  long long suuz() { return atoll(argv[1]); }
  long long suus() { return atoll(argv[1]); }
  long long suuu() { return atoll(argv[1]); }
  long long uzzz() { return atoll(argv[1]); }
  long long uzzs() { return atoll(argv[1]); }
  long long uzzu() { return atoll(argv[1]); }
  long long uzsz() { return atoll(argv[1]); }
  long long uzss() { return atoll(argv[1]); }
  long long uzsu() { return atoll(argv[1]); }
  long long uzuz() { return atoll(argv[1]); }
  long long uzus() { return atoll(argv[1]); }
  long long uzuu() { return atoll(argv[1]); }
  long long uszz() { return atoll(argv[1]); }
  long long uszs() { return atoll(argv[1]); }
  long long uszu() { return atoll(argv[1]); }
  long long ussz() { return atoll(argv[1]); }
  long long usss() { return atoll(argv[1]); }
  long long ussu() { return atoll(argv[1]); }
  long long usuz() { return atoll(argv[1]); }
  long long usus() { return atoll(argv[1]); }
  long long usuu() { return atoll(argv[1]); }
  long long uuzz() { return atoll(argv[1]); }
  long long uuzs() { return atoll(argv[1]); }
  long long uuzu() { return atoll(argv[1]); }
  long long uusz() { return atoll(argv[1]); }
  long long uuss() { return atoll(argv[1]); }
  long long uusu() { return atoll(argv[1]); }
  long long uuuz() { return atoll(argv[1]); }
  long long uuus() { return atoll(argv[1]); }
  long long uuuu() { return atoll(argv[1]); }

  long long bit00() { return atoll(argv[1]); }
  long long bit01() { return atoll(argv[1]); }
  long long bit02() { return atoll(argv[1]); }
  long long bit03() { return atoll(argv[1]); }
  long long bit04() { return atoll(argv[1]); }
  long long bit05() { return atoll(argv[1]); }
  long long bit06() { return atoll(argv[1]); }
  long long bit07() { return atoll(argv[1]); }
  long long bit08() { return atoll(argv[1]); }
  long long bit09() { return atoll(argv[1]); }
  long long bit10() { return atoll(argv[1]); }
  long long bit11() { return atoll(argv[1]); }
  long long bit12() { return atoll(argv[1]); }
  long long bit13() { return atoll(argv[1]); }
  long long bit14() { return atoll(argv[1]); }
  long long bit15() { return atoll(argv[1]); }
  long long bit16() { return atoll(argv[1]); }
  long long bit17() { return atoll(argv[1]); }
  long long bit18() { return atoll(argv[1]); }
  long long bit19() { return atoll(argv[1]); }
  long long bit20() { return atoll(argv[1]); }
  long long bit21() { return atoll(argv[1]); }
  long long bit22() { return atoll(argv[1]); }
  long long bit23() { return atoll(argv[1]); }
  long long bit24() { return atoll(argv[1]); }
  long long bit25() { return atoll(argv[1]); }
  long long bit26() { return atoll(argv[1]); }
  long long bit27() { return atoll(argv[1]); }
  long long bit28() { return atoll(argv[1]); }
  long long bit29() { return atoll(argv[1]); }
  long long bit30() { return atoll(argv[1]); }
  long long bit31() { return atoll(argv[1]); }
  long long bit32() { return atoll(argv[1]); }
  long long bit33() { return atoll(argv[1]); }
  long long bit34() { return atoll(argv[1]); }
  long long bit35() { return atoll(argv[1]); }
  long long bit36() { return atoll(argv[1]); }
  long long bit37() { return atoll(argv[1]); }
  long long bit38() { return atoll(argv[1]); }
  long long bit39() { return atoll(argv[1]); }
  long long bit40() { return atoll(argv[1]); }
  long long bit41() { return atoll(argv[1]); }
  long long bit42() { return atoll(argv[1]); }
  long long bit43() { return atoll(argv[1]); }
  long long bit44() { return atoll(argv[1]); }
  long long bit45() { return atoll(argv[1]); }
  long long bit46() { return atoll(argv[1]); }
  long long bit47() { return atoll(argv[1]); }
  long long bit48() { return atoll(argv[1]); }
  long long bit49() { return atoll(argv[1]); }
  long long bit50() { return atoll(argv[1]); }
  long long bit51() { return atoll(argv[1]); }
  long long bit52() { return atoll(argv[1]); }
  long long bit53() { return atoll(argv[1]); }
  long long bit54() { return atoll(argv[1]); }
  long long bit55() { return atoll(argv[1]); }
  long long bit56() { return atoll(argv[1]); }
  long long bit57() { return atoll(argv[1]); }
  long long bit58() { return atoll(argv[1]); }
  long long bit59() { return atoll(argv[1]); }
  long long bit60() { return atoll(argv[1]); }
  long long bit61() { return atoll(argv[1]); }
  long long bit62() { return atoll(argv[1]); }
  long long bit63() { return atoll(argv[1]); }


  printf("%08x\n", zz());
  printf("%08x\n", zs());
  printf("%08x\n", zu());
  printf("%08x\n", sz());
  printf("%08x\n", ss());
  printf("%08x\n", su());
  printf("%08x\n", uz());
  printf("%08x\n", us());
  printf("%08x\n", uu());

  printf("%016llx\n", zzzz());
  printf("%016llx\n", zzzs());
  printf("%016llx\n", zzzu());
  printf("%016llx\n", zzsz());
  printf("%016llx\n", zzss());
  printf("%016llx\n", zzsu());
  printf("%016llx\n", zzuz());
  printf("%016llx\n", zzus());
  printf("%016llx\n", zzuu());
  printf("%016llx\n", zszz());
  printf("%016llx\n", zszs());
  printf("%016llx\n", zszu());
  printf("%016llx\n", zssz());
  printf("%016llx\n", zsss());
  printf("%016llx\n", zssu());
  printf("%016llx\n", zsuz());
  printf("%016llx\n", zsus());
  printf("%016llx\n", zsuu());
  printf("%016llx\n", zuzz());
  printf("%016llx\n", zuzs());
  printf("%016llx\n", zuzu());
  printf("%016llx\n", zusz());
  printf("%016llx\n", zuss());
  printf("%016llx\n", zusu());
  printf("%016llx\n", zuuz());
  printf("%016llx\n", zuus());
  printf("%016llx\n", zuuu());
  printf("%016llx\n", szzz());
  printf("%016llx\n", szzs());
  printf("%016llx\n", szzu());
  printf("%016llx\n", szsz());
  printf("%016llx\n", szss());
  printf("%016llx\n", szsu());
  printf("%016llx\n", szuz());
  printf("%016llx\n", szus());
  printf("%016llx\n", szuu());
  printf("%016llx\n", sszz());
  printf("%016llx\n", sszs());
  printf("%016llx\n", sszu());
  printf("%016llx\n", sssz());
  printf("%016llx\n", ssss());
  printf("%016llx\n", sssu());
  printf("%016llx\n", ssuz());
  printf("%016llx\n", ssus());
  printf("%016llx\n", ssuu());
  printf("%016llx\n", suzz());
  printf("%016llx\n", suzs());
  printf("%016llx\n", suzu());
  printf("%016llx\n", susz());
  printf("%016llx\n", suss());
  printf("%016llx\n", susu());
  printf("%016llx\n", suuz());
  printf("%016llx\n", suus());
  printf("%016llx\n", suuu());
  printf("%016llx\n", uzzz());
  printf("%016llx\n", uzzs());
  printf("%016llx\n", uzzu());
  printf("%016llx\n", uzsz());
  printf("%016llx\n", uzss());
  printf("%016llx\n", uzsu());
  printf("%016llx\n", uzuz());
  printf("%016llx\n", uzus());
  printf("%016llx\n", uzuu());
  printf("%016llx\n", uszz());
  printf("%016llx\n", uszs());
  printf("%016llx\n", uszu());
  printf("%016llx\n", ussz());
  printf("%016llx\n", usss());
  printf("%016llx\n", ussu());
  printf("%016llx\n", usuz());
  printf("%016llx\n", usus());
  printf("%016llx\n", usuu());
  printf("%016llx\n", uuzz());
  printf("%016llx\n", uuzs());
  printf("%016llx\n", uuzu());
  printf("%016llx\n", uusz());
  printf("%016llx\n", uuss());
  printf("%016llx\n", uusu());
  printf("%016llx\n", uuuz());
  printf("%016llx\n", uuus());
  printf("%016llx\n", uuuu());

  printf("%016llx\n", bit00());
  printf("%016llx\n", bit01());
  printf("%016llx\n", bit02());
  printf("%016llx\n", bit03());
  printf("%016llx\n", bit04());
  printf("%016llx\n", bit05());
  printf("%016llx\n", bit06());
  printf("%016llx\n", bit07());
  printf("%016llx\n", bit08());
  printf("%016llx\n", bit09());
  printf("%016llx\n", bit10());
  printf("%016llx\n", bit11());
  printf("%016llx\n", bit12());
  printf("%016llx\n", bit13());
  printf("%016llx\n", bit14());
  printf("%016llx\n", bit15());
  printf("%016llx\n", bit16());
  printf("%016llx\n", bit17());
  printf("%016llx\n", bit18());
  printf("%016llx\n", bit19());
  printf("%016llx\n", bit20());
  printf("%016llx\n", bit21());
  printf("%016llx\n", bit22());
  printf("%016llx\n", bit23());
  printf("%016llx\n", bit24());
  printf("%016llx\n", bit25());
  printf("%016llx\n", bit26());
  printf("%016llx\n", bit27());
  printf("%016llx\n", bit28());
  printf("%016llx\n", bit29());
  printf("%016llx\n", bit30());
  printf("%016llx\n", bit31());
  printf("%016llx\n", bit32());
  printf("%016llx\n", bit33());
  printf("%016llx\n", bit34());
  printf("%016llx\n", bit35());
  printf("%016llx\n", bit36());
  printf("%016llx\n", bit37());
  printf("%016llx\n", bit38());
  printf("%016llx\n", bit39());
  printf("%016llx\n", bit40());
  printf("%016llx\n", bit41());
  printf("%016llx\n", bit42());
  printf("%016llx\n", bit43());
  printf("%016llx\n", bit44());
  printf("%016llx\n", bit45());
  printf("%016llx\n", bit46());
  printf("%016llx\n", bit47());
  printf("%016llx\n", bit48());
  printf("%016llx\n", bit49());
  printf("%016llx\n", bit50());
  printf("%016llx\n", bit51());
  printf("%016llx\n", bit52());
  printf("%016llx\n", bit53());
  printf("%016llx\n", bit54());
  printf("%016llx\n", bit55());
  printf("%016llx\n", bit56());
  printf("%016llx\n", bit57());
  printf("%016llx\n", bit58());
  printf("%016llx\n", bit59());
  printf("%016llx\n", bit60());
  printf("%016llx\n", bit61());
  printf("%016llx\n", bit62());
  printf("%016llx\n", bit63());

  return 0;
}
