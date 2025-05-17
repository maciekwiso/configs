#!/bin/bash

me=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

#nvim lazy
cd ~/.config/nvim/
rm -r ${me}/nvim/lazy/*
cp -r init.lua lazy-lock.json lazyvim.json stylua.toml lua ${me}/nvim/lazy

#qmk
rm -r ${me}/qmk/keychron-k15max/*
cp -r /mnt/d/Dev/qmk_firmware/keyboards/keychron/k15_max/ansi_encoder/white/keymaps/ ${me}/qmk/keychron-k15max

#intellij
rm -r ${me}/intellij/*
cp -r /mnt/c/Users/macie/AppData/Roaming/JetBrains/IdeaIC2024.3/keymaps ${me}/intellij

#push to git
cd $me
git add .
git commit -m "updated config"
git push
