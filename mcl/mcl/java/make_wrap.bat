@echo off
call set-java-path.bat
set JAVA_INCLUDE=%JAVA_DIR%\include
set SWIG=..\..\..\p\swig\swig.exe
set PACKAGE_NAME=com.herumi.mcl
set PACKAGE_DIR=%PACKAGE_NAME:.=\%
if /i "%1"=="" (
	set NAME=elgamal
) else (
	set NAME=%1
)

echo [[run swig]]
mkdir %PACKAGE_DIR%
%SWIG% -java -package %PACKAGE_NAME% -outdir %PACKAGE_DIR% -c++ -Wall %NAME%.i
echo [[make dll]]
cl /MT /DNOMINMAX /LD /Ox /DNDEBUG /EHsc %NAME%_wrap.cxx ../src/fp.cpp -DMCL_NO_AUTOLINK -I%JAVA_INCLUDE% -I%JAVA_INCLUDE%\win32 -I../include -I../../cybozulib/include -I../../cybozulib_ext/include -I../../xbyak /link /LIBPATH:../../cybozulib_ext/lib /OUT:../bin/mcl_%NAME%.dll

call run-%NAME%.bat

echo [[make jar]]
%JAVA_DIR%\bin\jar cvf mcl.jar com
