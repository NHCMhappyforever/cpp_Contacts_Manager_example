#!/bin/bash

if ! command -v git &> /dev/null; then
    echo You need to install git to continue
    read -n1 -r -p "Press any key to continue..." key
    sudo apt install git
fi
git clone https://github.com/NHCMhappyforever/contacts_manager.git
cd contacts_manager
if ! command -v g++ &> /dev/null; then
    echo You need to install g++ compiler to continue
    read -n1 -r -p "Press any key to continue..." key
    sudo apt install g++
fi
sudo g++ NHCM_contacts_linux_amd64.cpp -o /usr/bin/contacts
