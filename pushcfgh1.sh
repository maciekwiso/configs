#!/bin/bash

me=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

#nvim lazy
cd ~/.config/nvim/
cp -r init.lua lazy-lock.json lazyvim.json stylua.toml lua ${me}/nvim/lazy

#qmk
cp -r /mnt/d/Dev/qmk_firmware/keyboards/keychron/k15_max/ansi_encoder/white/keymaps/ ${me}/qmk/keychron-k15max

#push to git
cd $me
git add .
git commit -m "updated config"
git push
