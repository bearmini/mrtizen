#!/bin/sh
SDKHOMEDIR="$HOME/tizen-sdk"
WORKDIR=$(cd $(dirname $0);pwd)
#echo $WORKDIR

PACKAGE_ID=`cat .package_id`
PACKAGE_VERSION=`cat .version`
AUTHOR_CERT=mrtizen-example.p12
AUTHOR_CERT_PASS=mrtizen-example

# Copy
echo "Copying files..."
rm -rfv "$WORKDIR/.tpk"
rm -rfv "$WORKDIR/"*.tpk
mkdir -p "$WORKDIR/.tpk/bin"
mkdir -p "$WORKDIR/.tpk/info"
mkdir -p "$WORKDIR/.tpk/shared"
mkdir -p "$WORKDIR/.tpk/shared/data"
mkdir -p "$WORKDIR/.tpk/shared/trusted"

cp -rfv "$WORKDIR/"*.exe                 "$WORKDIR/.tpk/bin/"
cp -rfv "$WORKDIR/../data"               "$WORKDIR/.tpk/data"
cp -rfv "$WORKDIR/../manifest.xml"       "$WORKDIR/.tpk/info/manifest.xml"
cp -rfv "$WORKDIR/../lib"                "$WORKDIR/.tpk/lib"
cp -rfv "$WORKDIR/../res"                "$WORKDIR/.tpk/res"
cp -rfv "$WORKDIR/../setting"            "$WORKDIR/.tpk/setting"
cp -rfv "$WORKDIR/../shared/res"         "$WORKDIR/.tpk/shared/res"

# Sign
echo "Signing..."
"$SDKHOMEDIR/tools/smart-build-interface/../ide/bin/native-signing" "./.tpk" "$SDKHOMEDIR/tools/certificate-generator/certificates/developer/tizen-developer-ca.cer" "$AUTHOR_CERT" "$AUTHOR_CERT_PASS" "$SDKHOMEDIR/tools/certificate-generator/certificates/distributor/tizen-distributor-signer.p12" "tizenpkcs12passfordsigner" "$SDKHOMEDIR/tools/certificate-generator/certificates/distributor/tizen-distributor-ca.cer" "" "" "" ""

# Zip
TPK_PATH="../$PACKAGE_ID-$PACKAGE_VERSION-arm.tpk"

cd .tpk && zip -rv "$TPK_PATH" *

unzip -lv "$TPK_PATH" | awk '$2 == "Defl:N" || $2 == "Stored" { print $8 }' | sort > $WORKDIR/filelist
