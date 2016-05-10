#!/bin/bash
VERSION=1.0.0
SOFTWARE="libomi-gettext"
DESCRIPTION="Library Open Modular Interpreter Gettext"
DEPENDS="omi"
#DEPENDS=""
ARCH="all"
PRIORITY="optional"
AUTOR="Fco. Javier Bohórquez Ogalla"
PATHS="/usr/local/share/omi/libs/libomi_gettext.so"
[ -d ${SOFTWARE}_$VERSION ] && rm -R ${SOFTWARE}_$VERSION
mkdir -p ${SOFTWARE}_$VERSION/DEBIAN

echo -e "Package: ${SOFTWARE}" > ${SOFTWARE}_$VERSION/DEBIAN/control
echo -e "Architecture: $ARCH" >> ${SOFTWARE}_$VERSION/DEBIAN/control
echo -e "Maintainer: $AUTOR" >> ${SOFTWARE}_$VERSION/DEBIAN/control
[[ "$DEPENDS" != "" ]] && echo -e "Depends: $DEPENDS" >> ${SOFTWARE}_$VERSION/DEBIAN/control
echo -e "Priority: $PRIORITY" >> ${SOFTWARE}_$VERSION/DEBIAN/control
echo -e "Version: $VERSION" >> ${SOFTWARE}_$VERSION/DEBIAN/control
echo -e "Description: $DESCRIPTION" >> ${SOFTWARE}_$VERSION/DEBIAN/control

echo -e "#/bin/sh" > ${SOFTWARE}_$VERSION/DEBIAN/postinst
echo -e "echo '/usr/local/share/omi/libs/libomi_gettext.so' >> /usr/local/share/omi/libs.ini" >> ${SOFTWARE}_$VERSION/DEBIAN/postinst

for P in $PATHS; do 
   cp -R --parents $P ${SOFTWARE}_$VERSION
done

chown -R root:root ${SOFTWARE}_$VERSION
chmod 0775 ${SOFTWARE}_$VERSION/DEBIAN/postinst
dpkg-deb --build ${SOFTWARE}_$VERSION
 
