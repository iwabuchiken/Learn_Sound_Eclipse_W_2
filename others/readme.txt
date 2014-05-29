------------------------


	To run the program
------------------------
# Win
pushd C:\WORKS\WS\Eclipse_Kepler\Learn_Sound_Eclipse_W
.\Debug\Learn_Sound_Eclipse_W.exe

# Gen_PPM
.\Debug\Learn_Sound_Eclipse_W.exe -app gen-ppm -dst images/test.ppm -size 255,255 

# Ubuntu

------------------------

    Ignored by file system
	
------------------------
^(CVS|SCCS|vssver.?\.scc|#.*#|%.*%|_svn)$|~$|^\.(?!htaccess$).*$


------------------------

	Log
------------------------
gedit /home/buchi/WORKS/WS/NetBeans/PNGtoPPM/log/exec_log.txt &

------------------------


	Git
------------------------
//REF http://tobysoft.net/wiki/index.php?git%2F%A5%B3%A5%DE%A5%F3%A5%C9%A4%CE%BE%CA%CE%AC(alias)%C0%DF%C4%EA%A4%F2%A4%B9%A4%EB%CA%FD%CB%A1#t6684adb
git config --global alias.co checkout
git config --global alias.c commit
git config --global alias.s status
git config --global alias.l log
git config --global user.email "iwabuchi.k.2010@gmail.com"
git config --global user.name "iwabuchiken"

------------------------


	Structure: include
------------------------
main.c  -> pnglib.h -> lib.h
                    -> img_lib.h

pgmlib.h    -> img_lib.h

================ EOF ================