# C language tests

Tests of the optimizations of the code written on C


*strict_aliasing.c*


1) gcc -fstrict-aliasing -Wstrict-aliasing strict-aliasing.c 

./a.out 159 178

time: 5.463415


2) gcc -fno-strict-aliasing -Wstrict-aliasing strict-aliasing.c 

./a.out 159 178

time: 5.541054


3) gcc -fno-strict-aliasing -Wstrict-aliasing -DVIOLATE_STRICT_ALIASING strict-aliasing.c

./a.out 159 178

time: 6.588122


4) gcc -fstrict-aliasing -Wstrict-aliasing -DVIOLATE_STRICT_ALIASING strict-aliasing.c 

./a.out 159 178

time: 6.649486

-----------------------------------------------------------------------
