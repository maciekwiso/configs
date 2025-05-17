#!/bin/bash

me=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

#nvim lazy
cd ~/.config/nvim/
cp -r init.lua lazy-lock.json lazyvim.json stylua.toml lua ${me}/nvim/lazy

#push to git
cd $me
git add .
git commit -m "updated config"
git push
