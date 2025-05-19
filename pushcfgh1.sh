#!/bin/bash

me=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

#nvim lazy
lazyname='lazy-java'
cd ~/.config/nvim/
rm -fr ${me}/nvim/${lazyname}/*
cp -r init.lua lazy-lock.json lazyvim.json stylua.toml lua ${me}/nvim/${lazyname}

#qmk
rm -r ${me}/qmk/keychron-k15max/*
cp -r /mnt/d/Dev/qmk_firmware/keyboards/keychron/k15_max/ansi_encoder/white/keymaps/ ${me}/qmk/keychron-k15max

#intellij
rm -r ${me}/intellij/keymaps/*
cp -r /mnt/c/Users/macie/AppData/Roaming/JetBrains/IdeaIC2024.3/keymaps ${me}/intellij
cp /mnt/c/Users/macie/.ideavimrc ${me}/intellij

#wsl
rm -rf ${me}/wsl/*
cp ~/.bashrc ${me}/wsl

#push to git
cd $me
git add .
git commit -m "updated config"
git push
