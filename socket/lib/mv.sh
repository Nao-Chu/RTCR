#! /bin/bash

str=`find *.so*`
mvstr=${str:0:14}
make clean

echo $mvstr
ls /usr/lib/$mvstr*
sudo rm /usr/lib/$mvstr*


