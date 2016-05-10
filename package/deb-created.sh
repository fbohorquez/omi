#!/bin/bash
VERSION=1.0.0
SOFTWARE="omi"
DESCRIPTION="Open Modular Interpreter"
DEPENDS="libboost-regex-dev, libreadline5, libc6"
#DEPENDS=""
ARCH="all"
PRIORITY="optional"
AUTOR="Fco. Javier Bohórquez Ogalla"
PATHS="/usr/local/bin/omi /usr/local/share/omi"
[ -d ${SOFTWARE}_$VERSION ] && rm -R ${SOFTWARE}_$VERSION
mkdir -p ${SOFTWARE}_$VERSION/DEBIAN

echo -e "Package: ${SOFTWARE}" > ${SOFTWARE}_$VERSION/DEBIAN/control
echo -e "Architecture: $ARCH" >> ${SOFTWARE}_$VERSION/DEBIAN/control
echo -e "Maintainer: $AUTOR" >> ${SOFTWARE}_$VERSION/DEBIAN/control
[[ "$DEPENDS" != "" ]] && echo -e "Depends: $DEPENDS" >> ${SOFTWARE}_$VERSION/DEBIAN/control
echo -e "Priority: $PRIORITY" >> ${SOFTWARE}_$VERSION/DEBIAN/control
echo -e "Version: $VERSION" >> ${SOFTWARE}_$VERSION/DEBIAN/control
echo -e "Description: $DESCRIPTION" >> ${SOFTWARE}_$VERSION/DEBIAN/control

echo -e "dpkg-shlibdeps /usr/local/bin/omi" >> ${SOFTWARE}_$VERSION/DEBIAN/rules

#echo -e "Description: $DESCRIPTION" >> ${SOFTWARE}_$VERSION/DEBIAN/postinst

for P in $PATHS; do 
   cp -R --parents $P ${SOFTWARE}_$VERSION
done

chown -R root:root ${SOFTWARE}_$VERSION
dpkg-deb --build ${SOFTWARE}_$VERSION
 
