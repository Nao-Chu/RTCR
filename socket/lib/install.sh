#! /bin/bash
make
str=`find *.so*`

echo "cp $str /usr/lib/."
sudo cp $str /usr/lib/.

echo "ldconfig"
sudo ldconfig

lnstr=${str:0:14}
echo $lnstr

ls /usr/lib/$str*

sudo ln -s /usr/lib/$str /usr/lib/$lnstr
ls /usr/lib/$lnstr*

echo "cp my_socket.h /usr/include/."
sudo cp ../inc/my_socket.h /usr/include/.
