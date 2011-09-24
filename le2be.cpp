/**
 * file   : le2be.c
 * author : lo sauer
 * info   : Convert a number from Little Endian (Intel) to Big Endian.
**/
void le2be(int &num) {
  int lby = num & 0x0000FFFF;
  lby <<= 16;
  num >>= 16;
  num |= lby;
}