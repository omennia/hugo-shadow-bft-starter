#!/bin/bash

# Setting global directives

HOME_DIR=/home/blue/hugo-shadow-bft-starter
TARGET=/home/blue/hugo-shadow-bft-starter/results
SHADOW_DIR=/home/blue/shadow
BFT_SMART_DIR=/home/blue/library
NUMBER_OF_NODES=7



# # Installing shadow dependencies
# if [ ! -d "$SHADOW_DIR" ]; then
#   echo "Shadow directory must be specified in hugo-run.sh."
#   echo "You can get it at: https://github.com/shadow/shadow"
#   echo "Now exiting.."
#   exit 0
# fi

if ! command -v "shadow" &> /dev/null
then
    echo "Shadow was not found in your system.."
    echo "Installing dependencies.."
    ./.install_shadow_deps
    exit
fi


# Checking if we cloned the repo BFT-SmaRT 
if [ ! -d "$BFT_SMART_DIR" ]; then
  echo "BFT-SmaRT directory must be specified in hugo-run.sh."
  echo "You can get it at: https://github.com/bft-smart/library"
  echo "Now exiting.."
  exit 0
fi


# First we clean the path
if [ -d "$TARGET" ]; then
  echo "  "
  printf '%s\n' "Removing directory ($TARGET)"
  rm -rf "$TARGET"
  echo "  "
fi


# Generating our graph ( Network )
printf 'Now at directory: '
pwd
printf '\n'
g++ -Wall -o mg ./hugo-utilities/make_graph.cpp && ./mg $NUMBER_OF_NODES > network.gml
rm mg


# Getting dependencies from library (BFT - smart)
echo "  "
if [ -d "config" ]; then
  rm -rf "config"
fi

if [ -d "lib" ]; then
  rm -rf "lib"
fi

cd $BFT_SMART_DIR
echo "Now at directory $BFT_SMART_DIR"
pwd
./gradlew installDist
pwd
cp -r ./build/install/library/config $HOME_DIR
cp -r ./build/install/library/lib $HOME_DIR
cd $HOME_DIR
echo " "


# Starting shadow
shadow shadow.yaml > hugo.log
# shadow shadow.yaml
# rm -r config
# rm -r lib
